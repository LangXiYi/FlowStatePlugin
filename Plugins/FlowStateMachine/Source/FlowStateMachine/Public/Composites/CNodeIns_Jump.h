// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NodeInstance/FSMCompositeNodeInstance.h"
#include "FSMNodeInstance_Jump.generated.h"

/**
 * 创建一个选择器，支持从图表中查找目标节点并跳跃至该节点
 */
UCLASS()
class FLOWSTATEMACHINE_API UCNodeIns_JumpStart : public UFSMCompositeNodeInstance
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual FString GetNodeName() const override;

	UPROPERTY()
	FGuid JumpStartId;
};

/**
 * 创建一个选择器，支持从图表中查找目标节点并跳跃至该节点
 */
UCLASS()
class FLOWSTATEMACHINE_API UCNodeIns_JumpTo : public UFSMCompositeNodeInstance
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual FString GetNodeName() const override;

	UPROPERTY()
	FGuid JumpStartId;
};