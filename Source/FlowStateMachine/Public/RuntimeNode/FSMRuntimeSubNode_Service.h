// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeSubNode.h"
#include "UObject/Object.h"
#include "FSMRuntimeSubNode_Service.generated.h"

/**
 * 运行时节点---------服务
 * 作为 State 节点的子节点
 * 会按照固定间隔执行一次
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode_Service : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	/** 执行服务 */
	virtual void ExecuteService() {}

	/** 中止服务服务 */
	virtual void SuspendService() {}

protected:
	/** 服务间隔时间 */
	UPROPERTY(EditAnywhere)
	float IntervalTime = 0.5f;

	/** 随机偏差 */
	UPROPERTY(EditAnywhere)
	float RandomDeviation = 0.1f;
};


UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode_Service_Test : public UFSMRuntimeSubNode_Service
{
	GENERATED_BODY()


};
