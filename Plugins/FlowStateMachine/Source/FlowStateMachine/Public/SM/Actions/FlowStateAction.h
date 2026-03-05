// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NodeInstance/FSMSubNodeInstance.h"
#include "FlowStateAction.generated.h"

class UFlowStateBase;
/**
 * NOTE：：目前不支持异步Action阻塞状态机执行
 */
UCLASS(Abstract, Blueprintable)
class FLOWSTATEMACHINE_API UFlowStateAction : public UFSMSubNodeInstance
{
	GENERATED_BODY()

public:
	virtual void ExecuteAction(UFSMNodeInstance* Instance);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExecuteAction(UFSMNodeInstance* Instance);
};
