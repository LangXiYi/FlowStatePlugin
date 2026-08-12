// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "Conditions_AssetCheck.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UConditions_AssetCheck : public UFSMRuntimeSubNode_Condition
{
	GENERATED_BODY()

	virtual bool Condition(UFlowStateContext* Context) const override;
};
