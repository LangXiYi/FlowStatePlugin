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

void UFlowState::Enter(UFlowStateContext* Context)
{
	StateContext = Context;
	OnEnter();
}

void UFlowState::InitWidget(UFlowStateLayoutWidget* Layout)
{
	OnInitWidget(Layout);
}

void UFlowState::Exit()
{
	OnExit();
}

void UFlowState::PreIniProperties(UFlowState* LastState)
{
	OnPreInitProperties(LastState);
}
