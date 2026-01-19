// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "Actions_CreateWidgets.generated.h"

class UFSMCreateWidgetHelper;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UActions_CreateWidgets : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category = "CreateActors")
	TArray<UFSMCreateWidgetHelper*> CreateWidgets;

	virtual void ExecuteAction(UFSMRuntimeNode* Instance) override;
};
