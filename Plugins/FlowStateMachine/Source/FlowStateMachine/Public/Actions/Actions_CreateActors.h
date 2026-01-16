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
};
