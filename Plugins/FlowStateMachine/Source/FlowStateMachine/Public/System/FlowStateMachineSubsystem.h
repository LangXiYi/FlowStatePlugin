// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Utility/FSMUtility.h"
#include "Subsystems/WorldSubsystem.h"
#include "FlowStateMachineSubsystem.generated.h"

class UFlowStateContext;
class UFlowStateMachine;


/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateMachineSubsystem : public UWorldSubsystem
{
    GENERATED_BODY()

public:
    /**
     * 只执行一次，执行完成后结束？
     * 什么时候结束，在执行到无法继续向下执行时，自动结束
     * @param StateMachine
     * @param ExecuteMode 状态机的运行模式 
     * @return 
     */
    UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
    bool RunFlowStateMachine(UFlowStateMachine* StateMachine);

    UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
    void StopFlowStateMachine();

    UFlowStateContext* GetRunningStateContext() const { return RunningStateContext; }

private:
    UPROPERTY()
    UFlowStateContext* RunningStateContext;
};
