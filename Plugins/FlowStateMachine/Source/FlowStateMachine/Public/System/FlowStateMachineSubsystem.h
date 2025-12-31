// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
	UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
	bool RunFlowStateMachine(UFlowStateMachine* StateMachine);

	UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
	void StopFlowStateMachine(UFlowStateMachine* StateMachine);

	UFlowStateContext* GetRunningStateContext() const { return RunningStateContext; }

private:
	UPROPERTY()
	UFlowStateContext* RunningStateContext;
};
