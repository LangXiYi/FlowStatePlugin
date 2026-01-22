#include "Utility/FSMCreateActorHelper.h"

#include "FlowStateCollectInterface.h"
#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"

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
		ResultActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(InStateContext, GetCreateClass(), Transform);
		OverrideProperty(ResultActor);
		UGameplayStatics::FinishSpawningActor(ResultActor, Transform);

		ResultActor->Tags.AddUnique(UniqueName);
		InStateContext->AddToCache(ResultActor, Lifetime);
		InitializeActor(ResultActor);
	}
	else
	{
		if (Lifetime != OldLifetime)
		{
			// 当前的生命周期与新的生命周期值不一致，则更新改对象的生命周期为最新值
			GCManager->SwitchCache(ResultActor, OldLifetime,Lifetime);
		}
		OverrideProperty(ResultActor);
		UpdateActorTransform(ResultActor);
	}
	ResultActor->SetActorHiddenInGame(false);
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
	return CreateClass ? CreateClass : GetDefaultCreateClass();
}

TSubclassOf<AActor> UFSMCreateActorHelper::GetDefaultCreateClass() const
{
	return AActor::StaticClass();
}

void UFSMCreateActorHelper::OverrideProperty(AActor* ResultActor)
{
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
	case ECreateActorActionMode::None:
		break;
	case ECreateActorActionMode::Override_World:
		ResultActor->SetActorTransform(Transform);
		break;
	case ECreateActorActionMode::Override_Local:
		ResultActor->SetActorRelativeTransform(Transform);
		break;
	case ECreateActorActionMode::Additive_World:
		ResultActor->AddActorWorldTransform(Transform);
		break;
	case ECreateActorActionMode::Additive_Local:
		ResultActor->AddActorLocalTransform(Transform);
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
		if (bIsAutoPlay)
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
		MeshActor->GetStaticMeshComponent()->Mobility = bMoveable ? EComponentMobility::Movable : EComponentMobility::Static;
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
	}
	Super::OverrideProperty(ResultActor);
}

void UCreateStaticActorHelper::UpdateActorTransform(AActor* ResultActor)
{
	if (bMoveable)
	{
		Super::UpdateActorTransform(ResultActor);
	}
}