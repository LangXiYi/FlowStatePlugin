// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowState.h"

#include "Components/SlateWrapperTypes.h"
#include "Components/Widget.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"

UWorld* UFlowState::GetWorld() const
{
	if (!HasAnyFlags(RF_ClassDefaultObject) && ensureMsgf(GetOuter(),
		TEXT("Actor: %s has a null OuterPrivate in AActor::GetWorld()"), *GetFullName())
		&& !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
	{
		if (ULevel* Level = GetLevel())
		{
			return Level->OwningWorld;
		}
	}
	return nullptr;
}

ULevel* UFlowState::GetLevel() const
{
	return GetTypedOuter<ULevel>();
}

void UFlowState::Tick(float DeltaTime)
{
	Private_DeltaTime = DeltaTime;
	OnTick(DeltaTime); 
}

void UFlowState::OnEnter()
{
	NativeOnEnter();
}

void UFlowState::OnInitWidget(UFlowStateLayoutWidget* Layout)
{
	NativeOnInitWidget(Layout);
}

void UFlowState::OnInitialize(UFlowStateContext* Context)
{
	StateContext = Context;
	// 预初始化状态
	OnPreInitialize(Context->CurState);
	// TODO::获取当前新节点的Action并执行它们！！！

	// for (Action* Action : Actions)

	// 进入状态
	OnEnter();
}

void UFlowState::OnExit()
{
	NativeOnExit();
}

void UFlowState::PreIniProperties(UFlowState* LastState)
{
	OnPreInitProperties(LastState);
}
