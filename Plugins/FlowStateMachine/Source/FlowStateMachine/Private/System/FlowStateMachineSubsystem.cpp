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
    RunningStateContext = NewObject<UFlowStateContext>(this);
    if (RunningStateContext == nullptr)
    {
        UE_LOG(LogFlowStateMachine, Error, TEXT("Create 'StateContext' failed, It's a nullptr."))
        return false;
    }
    // 将 StateMachine 注册至 FlowStateContext
    RunningStateContext->RegisterFlowStateMachine(*StateMachine);
    return true;
}

void UFlowStateMachineSubsystem::StopFlowStateMachine()
{
    if (RunningStateContext)
    {
        RunningStateContext->ConditionalBeginDestroy();
        RunningStateContext = nullptr;
    }
}
