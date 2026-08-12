#include "Utility/FSMCreateActorHelper.h"

#include "FlowStateCollectInterface.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"

class UWorld* UFSMCreateActorHelper::GetWorld() const
{
    if (GetOuter() == nullptr)
    {
        return nullptr;
    }
    // Special case for behavior tree nodes in the editor
    if (Cast<UPackage>(GetOuter()) != nullptr)
    {
        // GetOuter should return a UPackage and its Outer is a UWorld
        return Cast<UWorld>(GetOuter()->GetOuter());
    }
    return GetOuter()->GetWorld();
}

void UFSMCreateActorHelper::CreateActor(UFlowStateContext* InStateContext)
{
    ensure(UniqueName != NAME_None);
    if (UniqueName == NAME_None)
    {
        return;
    }

    check(InStateContext);
    if (!InStateContext)
    {
        return;
    }

    TSharedPtr<FSMGC> GCManager = InStateContext->GetGCManager();
    if (!GCManager.IsValid())
    {
        return;
    }

    AActor* ResultActor = nullptr;
    // 先去内存中查找是否存在同名对象
    EFlowStateLifetime OldLifetime = GCManager->FindRefByCache(UniqueName, ResultActor);
    if (ResultActor == nullptr)
    {
        ResultActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(InStateContext, GetCreateClass(), FTransform(Rotator, Offset, Scale));
        InitializeActor(ResultActor);
        UGameplayStatics::FinishSpawningActor(ResultActor, FTransform(Rotator, Offset, Scale));
        OverrideProperty(ResultActor);

        ResultActor->Tags.AddUnique(UniqueName);
        InStateContext->AddToCache(ResultActor, Lifetime);
    }
    else
    {
        if (Lifetime != OldLifetime)
        {
            // 当前的生命周期与新的生命周期值不一致，则更新改对象的生命周期为最新值
            GCManager->SwitchCache(ResultActor, OldLifetime, Lifetime);
        }
        OverrideProperty(ResultActor);
        UpdateActorTransform(ResultActor);
    }
}

void UFSMCreateActorHelper::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
    UClass* CreateClass = GetCreateClass();
    if (CreateClass == nullptr)
    {
        return;
    }
    const UObject* DefaultObject = CreateClass->GetDefaultObject();
    if (DefaultObject->Implements<UFlowStateCollectInterface>())
    {
        IFlowStateCollectInterface::Execute_GetStatePinInfos(DefaultObject, PinInfos);
    }
}

TSubclassOf<AActor> UFSMCreateActorHelper::GetCreateClass() const
{
    UClass* CreateClass = NativeGetCreateClass();
    return CreateClass ? TSubclassOf<AActor>(CreateClass) : GetDefaultCreateClass();
}

TSubclassOf<AActor> UFSMCreateActorHelper::GetDefaultCreateClass() const
{
    return AActor::StaticClass();
}

void UFSMCreateActorHelper::OverrideProperty(AActor* ResultActor)
{
    ResultActor->SetActorHiddenInGame(false);
    NativeOverrideProperty(ResultActor);
}

void UFSMCreateActorHelper::InitializeActor(AActor* Target)
{
    NativeInitializeActor(Target);
}

bool UFSMCreateActorHelper::IsValid() const
{
    return UniqueName != NAME_None && Lifetime != EFlowStateLifetime::None;
}

void UFSMCreateActorHelper::UpdateActorTransform(AActor* ResultActor)
{
    switch (TransformMode)
    {
    case ECreateActorActionMode::World:
        ResultActor->SetActorLocation(Offset);
        ResultActor->SetActorRotation(Rotator);
        ResultActor->SetActorScale3D(Scale);
        break;
    case ECreateActorActionMode::Relative:
        // TODO::这里直接使用 SetActorRelativeXXX 函数可能不太符合预期
        ResultActor->SetActorRelativeLocation(Offset);
        ResultActor->SetActorRelativeRotation(Rotator);
        ResultActor->SetActorRelativeScale3D(Scale);
        break;
    }
}

void UCreateSkeletalActorHelper::InitializeActor(AActor* Target)
{
    Super::InitializeActor(Target);
    ASkeletalMeshActor* MeshActor = Cast<ASkeletalMeshActor>(Target);
    if (MeshActor != nullptr)
    {
        MeshActor->GetSkeletalMeshComponent()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
        MeshActor->GetSkeletalMeshComponent()->SetPosition(InitAnimPos, true);
    }
}

TSubclassOf<AActor> UCreateSkeletalActorHelper::GetDefaultCreateClass() const
{
    return ASkeletalMeshActor::StaticClass();
}

void UCreateSkeletalActorHelper::OverrideProperty(AActor* ResultActor)
{
    // 同步资产加载，可以使用LoadAsset行为优化资产加载产生的延迟
    ASkeletalMeshActor* MeshActor = Cast<ASkeletalMeshActor>(ResultActor);
    if (MeshActor != nullptr)
    {
        USkeletalMesh* LoadedMesh = Mesh.LoadSynchronous();
        MeshActor->GetSkeletalMeshComponent()->SetSkeletalMesh(LoadedMesh);
        UAnimationAsset* LoadedAnim = AnimationAsset.LoadSynchronous();
        MeshActor->GetSkeletalMeshComponent()->SetAnimation(LoadedAnim);
        MeshActor->GetSkeletalMeshComponent()->SetPosition(InitAnimPos);
        if (CollisionProfileName != NAME_None)
        {
            MeshActor->GetSkeletalMeshComponent()->SetCollisionProfileName(CollisionProfileName);
        }
        if (bIsAutoPlay && AnimationAsset.IsValid())
        {
            MeshActor->GetSkeletalMeshComponent()->Play(bIsLoop);
        }
    }
    Super::OverrideProperty(ResultActor);
}

void UCreateStaticActorHelper::InitializeActor(AActor* Target)
{
    AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(Target);
    if (MeshActor != nullptr)
    {
        // 静态模型要动态修改, 所以不能设置 Mobility 为 Static，否则会导致后续模型无法动态替换。
        MeshActor->GetStaticMeshComponent()->Mobility = EComponentMobility::Movable;
    }
    Super::InitializeActor(Target);
}

TSubclassOf<AActor> UCreateStaticActorHelper::GetDefaultCreateClass() const
{
    return AStaticMeshActor::StaticClass();
}

void UCreateStaticActorHelper::OverrideProperty(AActor* ResultActor)
{
    AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(ResultActor);
    if (MeshActor != nullptr)
    {
        // 同步资产加载，可以使用LoadAsset行为优化资产加载产生的延迟
        UStaticMesh* LoadedMesh = Mesh.LoadSynchronous();
        MeshActor->GetStaticMeshComponent()->SetStaticMesh(LoadedMesh);
        if (CollisionProfileName != NAME_None)
        {
            MeshActor->GetStaticMeshComponent()->SetCollisionProfileName(CollisionProfileName);
        }
    }
    Super::OverrideProperty(ResultActor);
}
