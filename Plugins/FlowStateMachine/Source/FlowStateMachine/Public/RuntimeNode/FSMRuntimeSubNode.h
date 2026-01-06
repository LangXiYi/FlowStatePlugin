// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNodeBase.h"
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
	virtual UWorld* GetWorld() const override;

	UFlowStateContext* GetContext() const;

	// 若要所有属性都同步，那么就必须要在这里将属性复制出来，因为没有UPROPERTY修饰的对不会被拷贝
	virtual void InitializeSubNode(const UFSMRuntimeSubNode* TemplateNodeInstance, UFSMRuntimeNodeBase* InParentNode);
};





