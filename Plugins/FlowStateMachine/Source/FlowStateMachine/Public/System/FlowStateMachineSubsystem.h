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
class FLOWSTATEMACHINE_API UFlowStateMachineSubsystem : public UWorldSubsystem, public FTickableGameObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
	bool RunFlowStateMachine(UFlowStateMachine* StateMachine);

	UFUNCTION(BlueprintCallable, Category = "FlowStateMachineSubsystem")
	void StopFlowStateMachine();

	UFlowStateContext* GetRunningStateContext() const { return RunningStateContext; }

	virtual void Tick(float DeltaTime) override;

	virtual TStatId GetStatId() const override;

private:
	UPROPERTY()
	UFlowStateContext* RunningStateContext;
};
