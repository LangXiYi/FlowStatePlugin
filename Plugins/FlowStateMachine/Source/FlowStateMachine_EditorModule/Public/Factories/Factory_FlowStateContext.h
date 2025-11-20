// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/FlowState.h"
#include "Factories/Factory.h"
#include "Factory_FlowStateContext.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITORMODULE_API UFactory_FlowStateContext : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	// UFactory interface
	virtual bool ShouldShowInNewMenu() const override { return true; }
	virtual bool ConfigureProperties() override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface

protected:
	UPROPERTY(EditAnywhere, Category = "Factory_FlowStateContext")
	TSubclassOf<UObject> ParentClass;
};