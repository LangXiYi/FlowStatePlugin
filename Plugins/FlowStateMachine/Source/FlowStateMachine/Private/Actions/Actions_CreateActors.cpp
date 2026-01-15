// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_CreateActors.h"

#include "Animation/SkeletalMeshActor.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "Library/FSMFunctionLibrary.h"
#include "SM/FlowStateContext.h"

void UCreateActorHelper::InitializeCreateActor(UFlowStateContext* InStateContext)
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
		ResultActor = GetWorld()->SpawnActor<AActor>(GetCreateClass(), Transform);
		bIsSpawnNewActor = true;
	}

	OverrideActorProperty(ResultActor);

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
		AddActorToCache(InStateContext, ResultActor);
	}
}

void UCreateActorHelper::OverrideActorProperty_Implementation(AActor* ResultActor)
{
}

UClass* UCreateActorHelper::GetCreateClass_Implementation() const
{
	return AActor::StaticClass();
}

void UCreateActorHelper::AddActorToCache_Implementation(UFlowStateContext* InStateContext, AActor* ResultActor)
{
	check(UniqueName != NAME_None);
	if (UniqueName != NAME_None)
	{
		ResultActor->Tags.AddUnique(UniqueName);
	}
	InStateContext->AddToCache(ResultActor, Lifetime);
}

void UCreateActorHelper::SwitchActorCache_Implementation(UFlowStateContext* InStateContext, AActor* ResultActor,
	EFlowStateLifetime OldLifetime)
{
	InStateContext->SwitchCache(ResultActor, OldLifetime,Lifetime);
}

void UCreateActorHelper::UpdateActorTransform_Implementation(AActor* ResultActor)
{
	switch (ActionMode)
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

UClass* UCreateSkeletalActorHelper::GetCreateClass_Implementation() const
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
		MeshActor->SetActorHiddenInGame(false);
	}
}

UClass* UCreateStaticActorHelper::GetCreateClass_Implementation() const
{
	return Super::GetCreateClass();
}

void UCreateStaticActorHelper::OverrideActorProperty_Implementation(AActor* ResultActor)
{
	AStaticMeshActor* MeshActor = Cast<AStaticMeshActor>(ResultActor);
	if (MeshActor != nullptr)
	{
		// 同步资产加载，可以使用LoadAsset行为优化资产加载产生的延迟
		UStaticMesh* LoadedMesh = Mesh.LoadSynchronous();
		MeshActor->GetStaticMeshComponent()->SetStaticMesh(LoadedMesh);
		MeshActor->GetStaticMeshComponent()->Mobility = bMoveable ? EComponentMobility::Movable : EComponentMobility::Static;
		MeshActor->SetActorHiddenInGame(false);
	}
}

void UCreateStaticActorHelper::UpdateActorTransform_Implementation(AActor* ResultActor)
{
	if (bMoveable)
	{
		Super::UpdateActorTransform(ResultActor);
	}
}

void UActions_CreateActors::ExecuteAction(UFSMRuntimeNode* Instance)
{
	for (UCreateActorHelper* Helper : CreateActors)
	{
		Helper->InitializeCreateActor(StateContext);
	}
}
