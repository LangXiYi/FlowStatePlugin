// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "Factory_FlowState.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITORMODULE_API UFactory_FlowState : public UFactory
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
	UPROPERTY(EditAnywhere, Category=DataAsset)
	TSubclassOf<UObject> ParentClass;
};