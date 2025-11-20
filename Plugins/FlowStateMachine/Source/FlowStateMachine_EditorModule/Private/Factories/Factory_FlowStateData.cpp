// Fill out your copyright notice in the Description page of Project Settings.


#include "Factories/Factory_FlowStateData.h"

#include "Data/FlowStateDataAsset.h"

#define LOCTEXT_NAMESPACE "Factory_FlowStateData"

UFactory_FlowStateData::UFactory_FlowStateData(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	SupportedClass = UFlowStateDataAsset::StaticClass();
	bCreateNew = true;
	bEditAfterNew = true;
}

UObject* UFactory_FlowStateData::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags,
	UObject* Context, FFeedbackContext* Warn)
{
	check(Class->IsChildOf(UFlowStateDataAsset::StaticClass()));
	return NewObject<UFlowStateDataAsset>(InParent, Class, Name, Flags);
}

#undef LOCTEXT_NAMESPACE