#include "Utility/FSMCreateActorHelper.h"

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
	
	AActor* ResultActor = nullptr;
	bool bIsSpawnNewActor = false;
	// 先去内存中查找是否存在同名对象
	EFlowStateLifetime CurLifetime = InStateContext->FindByCache(UniqueName, ResultActor);
	if (ResultActor == nullptr)
	{
		// 内存中不存在同名的对象，直接创建一个新的对象
		ResultActor = UGameplayStatics::BeginDeferredActorSpawnFromClass(InStateContext, GetCreateClass(), Transform);
		// ResultActor = GetWorld()->SpawnActor<AActor>(GetCreateClass(), Transform);
		bIsSpawnNewActor = true;
	}

	if (bIsSpawnNewActor == false)
	{
		UpdateActorTransform(ResultActor);
		if (Lifetime != CurLifetime)
		{
			// 当前的生命周期与新的生命周期值不一致，则更新改对象的生命周期为最新值
			SwitchActorCache(InStateContext, ResultActor, CurLifetime);
		}
	}
	else
	{
		InitializeActor(ResultActor);
		AddActorToCache(InStateContext, ResultActor);
		UGameplayStatics::FinishSpawningActor(ResultActor, Transform);
	}

	ResultActor->SetActorHiddenInGame(false);
	OverrideActorProperty(ResultActor);
}

void UFSMCreateActorHelper::OverrideActorProperty_Implementation(AActor* ResultActor)
{
	/** Override actor property... */
}

TSubclassOf<AActor> UFSMCreateActorHelper::GetCreateClass_Implementation() const
{
	return AActor::StaticClass();
}

void UFSMCreateActorHelper::InitializeActor_Implementation(AActor* Target)
{
	/** Override initialize actor... */
}

bool UFSMCreateActorHelper::IsValid() const
{
	return UniqueName != NAME_None && Lifetime != EFlowStateLifetime::None;
}

void UFSMCreateActorHelper::AddActorToCache(UFlowStateContext* InStateContext, AActor* ResultActor)
{
	check(UniqueName != NAME_None);
	if (UniqueName != NAME_None)
	{
		ResultActor->Tags.AddUnique(UniqueName);
	}
	InStateContext->AddToCache(ResultActor, Lifetime);
}

void UFSMCreateActorHelper::SwitchActorCache(UFlowStateContext* InStateContext, AActor* ResultActor,
	EFlowStateLifetime OldLifetime)
{
	InStateContext->SwitchCache(ResultActor, OldLifetime,Lifetime);
}

void UFSMCreateActorHelper::UpdateActorTransform_Implementation(AActor* ResultActor)
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

void UCreateSkeletalActorHelper::InitializeActor_Implementation(AActor* Target)
{
	ASkeletalMeshActor* MeshActor = Cast<ASkeletalMeshActor>(Target);
	if (MeshActor != nullptr)
	{
		MeshActor->GetSkeletalMeshComponent()->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	}
}

TSubclassOf<AActor> UCreateSkeletalActorHelper::GetCreateClass_Implementation() const
{
	return ASkeletalMeshActor::StaticClass();
}

void UCreateSkeletalActorHelper::OverrideActorProperty_Implementation(AActor* ResultActor)
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
}

void UCreateStaticActorHelper::InitializeActor_Implementation(AActor* Target)
{
	AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(Target);
	if (MeshActor != nullptr)
	{
		MeshActor->GetStaticMeshComponent()->Mobility = bMoveable ? EComponentMobility::Movable : EComponentMobility::Static;
	}
}

TSubclassOf<AActor> UCreateStaticActorHelper::GetCreateClass_Implementation() const
{
	return AStaticMeshActor::StaticClass();
}

void UCreateStaticActorHelper::OverrideActorProperty_Implementation(AActor* ResultActor)
{
	AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(ResultActor);
	if (MeshActor != nullptr)
	{
		// 同步资产加载，可以使用LoadAsset行为优化资产加载产生的延迟
		UStaticMesh* LoadedMesh = Mesh.LoadSynchronous();
		MeshActor->GetStaticMeshComponent()->SetStaticMesh(LoadedMesh);
	}
}

void UCreateStaticActorHelper::UpdateActorTransform_Implementation(AActor* ResultActor)
{
	if (bMoveable)
	{
		Super::UpdateActorTransform(ResultActor);
	}
}