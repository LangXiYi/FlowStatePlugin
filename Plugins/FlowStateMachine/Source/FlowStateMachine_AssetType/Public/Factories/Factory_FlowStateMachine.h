// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/FlowStateBase.h"
#include "Factories/Factory.h"
#include "Factory_FlowStateMachine.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_ASSETTYPE_API UFactory_FlowStateMachine : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	// UFactory interface
	virtual bool ShouldShowInNewMenu() const override { return true; }
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
};

