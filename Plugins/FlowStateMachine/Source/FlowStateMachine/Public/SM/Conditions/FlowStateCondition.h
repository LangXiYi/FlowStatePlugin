// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NodeInstance/FSMSubNodeInstance.h"
#include "FlowStateCondition.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateCondition : public UFSMSubNodeInstance
{
	GENERATED_BODY()

public:
	virtual bool Condition(UFlowStateContext* Context) const;

	UFUNCTION(BlueprintImplementableEvent, DisplayName = "Condition")
	bool BP_Condition(UFlowStateContext* Context) const;
};
