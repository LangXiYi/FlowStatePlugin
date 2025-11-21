// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FSMWorldSettings.h"

#include "SM/FlowStateContext.h"
#include "SM/FlowStateMachine.h"


AFSMWorldSettings::AFSMWorldSettings()
{
	PrimaryActorTick.bCanEverTick = true;
}

AFSMWorldSettings* AFSMWorldSettings::Get(UObject* WorldContextObject)
{
	UWorld* World = FlowStateMachine::GetWorldFromContextObject(WorldContextObject);
	if (World)
	{
		return (AFSMWorldSettings*)World->GetWorldSettings();
	}
	return nullptr;
}

void AFSMWorldSettings::BeginPlay()
{
	Super::BeginPlay();
	if (bIsFlowStateLevel)
	{
		if (FlowStateMachine == nullptr)
		{
			check(FlowStateMachine);
			UE_LOG(LogFlowStateMachine, Error, TEXT("FlowStateMachine is nullptr."))
			return;
		}
		InitFlowStateContext();
	}
}

void AFSMWorldSettings::InitFlowStateContext()
{
	FlowStateContext = NewObject<UFlowStateContext>(this);
	FlowStateContext->Initialize();

	// 将 FlowStateMachine 注册至 FlowStateContext
	FlowStateContext->RegisterFlowStateMachine(FlowStateMachine);
}

void AFSMWorldSettings::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bIsFlowStateLevel && FlowStateContext)
	{
		FlowStateContext->Tick(DeltaSeconds);
	}
}
