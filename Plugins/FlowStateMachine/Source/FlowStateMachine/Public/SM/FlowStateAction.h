// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "FlowStateAction.generated.h"

/**
 * NOTE：：目前不支持异步Action阻塞状态机执行
 */
UCLASS(Abstract, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateAction : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()

public:
	virtual void ExecuteAction() override;

	UFUNCTION(BlueprintImplementableEvent)
	void OnExecuteAction();
};
