// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeSubNode.h"
#include "UObject/Object.h"
#include "FSMRuntimeSubNode_Condition.generated.h"

/**
 * 运行时节点---------条件
 * 作为 State 节点的子节点
 * 表示从当前状态切换至该状态所需要的前置条件
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode_Condition : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 过度条件 */
	virtual bool Condition(UFlowStateContext* Context) const { return true; }
};