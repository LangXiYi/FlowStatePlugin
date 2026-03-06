// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/Blueprint.h"
#include "FlowStateBlueprint.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateBlueprint : public UBlueprint
{
	GENERATED_BODY()

public:
	virtual bool SupportedByDefaultBlueprintFactory() const override
	{
		return false;
	}	
};
