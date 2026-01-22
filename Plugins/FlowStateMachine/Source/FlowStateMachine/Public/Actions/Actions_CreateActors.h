// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "Actions_CreateActors.generated.h"

class UFSMCreateActorHelper;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UActions_CreateActors : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category = "CreateActors")
	TArray<UFSMCreateActorHelper*> CreateActors;

	virtual void ExecuteAction(UFSMRuntimeNode* Instance) override;

	/** 返回该子节点需要创建的引脚信息 */
	virtual void GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const override;
};
