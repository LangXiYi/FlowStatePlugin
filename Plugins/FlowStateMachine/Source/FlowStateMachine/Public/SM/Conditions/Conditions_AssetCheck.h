// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/Conditions/FlowStateCondition.h"
#include "Conditions_AssetCheck.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UConditions_AssetCheck : public UFlowStateCondition
{
    GENERATED_BODY()

    virtual bool Condition(UFlowStateContext* Context) const override;
};
