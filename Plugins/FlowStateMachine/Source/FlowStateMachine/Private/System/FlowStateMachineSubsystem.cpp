// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FlowStateMachineSubsystem.h"
#include "Utility/FSMUtility.h"
#include "SM/FlowStateContext.h"


bool UFlowStateMachineSubsystem::RunFlowStateMachine(UFlowStateMachine* StateMachine)
{
	if (StateMachine == nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("StateMachine is nullptr."))
		return false;
	}
	if (RunningStateContext != nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("The 'FlowStateMachine' is running."))
		return false;
	}
	UFlowStateContext* StateContext = NewObject<UFlowStateContext>(this);
	if (StateContext == nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("Create 'StateContext' failed, It's a nullptr."))
		return false;
	}
	RunningStateContext = StateContext;
	// 将 StateMachine 注册至 FlowStateContext
	StateContext->RegisterFlowStateMachine(StateMachine);
	return true;
}

void UFlowStateMachineSubsystem::StopFlowStateMachine()
{
	if (RunningStateContext)
	{
		// TODO::停止运行状态机
		RunningStateContext = nullptr;
	}
}

void UFlowStateMachineSubsystem::Tick(float DeltaTime)
{
	if (RunningStateContext)
	{
		RunningStateContext->Tick(DeltaTime);
	}
}

TStatId UFlowStateMachineSubsystem::GetStatId() const
{
	return Super::GetStatID();
}

