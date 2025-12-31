// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "FlowStateAction.generated.h"

/**
 * 
 */
UCLASS(Abstract, BlueprintType, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateAction : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()
};
