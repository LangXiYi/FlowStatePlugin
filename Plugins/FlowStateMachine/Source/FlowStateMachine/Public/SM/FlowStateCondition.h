// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "FlowStateCondition.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateCondition : public UFSMRuntimeSubNode_Condition
{
	GENERATED_BODY()

public:
	virtual bool Condition() const override;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Condition")
	bool BP_Condition(UFSMRuntimeNode* Parent) const;
};
