// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "FlowStateService.generated.h"

/**
 * 
 */
UCLASS(Abstract, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateService : public UFSMRuntimeSubNode_Service
{
	GENERATED_BODY()

	// 按设定的间隔时间执行
};
