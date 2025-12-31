// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeSubNode.h"
#include "UObject/Object.h"
#include "FSMRuntimeSubNode_Action.generated.h"

/**
 * 运行时节点---------行为
 * 作为 State 节点的子节点
 * 会在每次进入 State 之前执行一次，单个 State 节点可以添加多个 Action，但每个 Action 只能添加一个。
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode_Action : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 执行行为 */
	virtual void ExecuteAction() {}
};
