// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNodeBase.h"
#include "UObject/Object.h"
#include "FSMRuntimeSubNode.generated.h"


class UFSMRuntimeNode;

/**
 * 运行时子节点
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode : public UFSMRuntimeNodeBase
{
	GENERATED_BODY()

public:

};

/**
 * 运行时节点---------行为
 * 作为 State 节点的子节点
 * 会在每次进入 State 之前执行一次，单个 State 节点可以添加多个 Action，但每个 Action 只能添加一个。
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Action : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 执行行为 */
	virtual void ExecuteAction() {}
	/** 执行行为 */
	UFUNCTION(BlueprintImplementableEvent)
	virtual void OnExecuteAction();
};

/**
 * 运行时节点---------服务
 * 作为 State 节点的子节点
 * 会按照固定间隔执行一次
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Service : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 执行服务 */
	virtual void ExecuteService() {}
	/** 执行服务 */
	UFUNCTION(BlueprintImplementableEvent)
	virtual void OnExecuteService();

	/** 中止服务服务 */
	virtual void SuspendService() {}
	/** 中止服务服务 */
	UFUNCTION(BlueprintImplementableEvent)
	virtual void OnSuspendService();

protected:
	/** 服务间隔时间 */
	UPROPERTY(EditAnywhere)
	float IntervalTime = 0.5f;

	/** 随机偏差 */
	UPROPERTY(EditAnywhere)
	float RandomDeviation = 0.1f;
};

UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Service_Test : public UFSMRuntimeSubNode
{
	GENERATED_BODY()


};


/**
 * 运行时节点---------条件
 * 作为 State 节点的子节点
 * 表示从当前状态切换至该状态所需要的前置条件
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Condition : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 过度条件 */
	virtual bool Condition() const { return true; }
};

UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Condition_Test : public UFSMRuntimeNode_Condition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	FString TestCondition;
};