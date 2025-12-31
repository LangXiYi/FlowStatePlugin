// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateBase.h"

#include "Components/SlateWrapperTypes.h"
#include "Components/Widget.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"

// UFlowStateBase::UFlowStateBase(UFlowStateContext* InContext):
// 	IFlowStateInterface(InContext)
// {
// }

UWorld* UFlowStateBase::GetWorld() const
{
	return Super::GetWorld();
	/*if (!HasAnyFlags(RF_ClassDefaultObject) && ensureMsgf(GetOuter(),
		TEXT("Actor: %s has a null OuterPrivate in AActor::GetWorld()"), *GetFullName())
		&& !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
	{
		if (ULevel* Level = GetLevel())
		{
			return Level->OwningWorld;
		}
	}
	return nullptr;*/
}

ULevel* UFlowStateBase::GetLevel() const
{
	return GetTypedOuter<ULevel>();
}

void UFlowStateBase::SetOwner(AActor* InActorOwner)
{
	Super::SetOwner(InActorOwner);
	ActorOwner = InActorOwner;
}

void UFlowStateBase::Tick(float DeltaTime)
{
	Private_DeltaTime = DeltaTime;
	OnTick(DeltaTime); 
}

void UFlowStateBase::OnEnter()
{
	NativeOnEnter();
}

void UFlowStateBase::OnInitWidget(UFlowStateLayoutWidget* Layout)
{
	NativeOnInitWidget(Layout);
}

/*
void UFlowStateBase::OnInitialize()
{
	// ParentContext = Context;
	// 预初始化状态
	// OnPreInitialize(Context->CurState);
	// TODO::获取当前新节点的Action并执行它们！！！

	// for (Action* Action : Actions)

	// 进入状态
	OnEnter();
}
*/

void UFlowStateBase::OnExit()
{
	NativeOnExit();
}

void UFlowStateBase::PreIniProperties(UFlowStateBase* LastState)
{
	OnPreInitProperties(LastState);
}
