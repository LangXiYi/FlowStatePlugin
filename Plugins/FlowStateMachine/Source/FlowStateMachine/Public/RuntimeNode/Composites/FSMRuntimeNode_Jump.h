// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "FSMRuntimeNode_Jump.generated.h"

/**
 * 创建一个选择器，支持从图表中查找目标节点并跳跃至该节点
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_JumpStart : public UFSMRuntimeNode_Composites
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;

	UPROPERTY()
	FGuid JumpStartId;
};

/**
 * 创建一个选择器，支持从图表中查找目标节点并跳跃至该节点
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_JumpTo : public UFSMRuntimeNode_Composites
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;

	UPROPERTY()
	FGuid JumpStartId;
};