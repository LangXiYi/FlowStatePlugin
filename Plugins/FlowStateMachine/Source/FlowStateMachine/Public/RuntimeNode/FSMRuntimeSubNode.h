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
};





