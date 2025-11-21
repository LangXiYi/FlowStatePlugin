// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutomationBlueprintFunctionLibrary.h"
#include "FSMMetaDataFunctionLibrary.generated.h"

class UFSMMetaDataAsset;
class UFSMMetaDataFragment;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMMetaDataFunctionLibrary : public UAutomationBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	//////////////////////////////////////////////////////////////////
	// Flow State Machine Meta Data
	//////////////////////////////////////////////////////////////////
	
	UFUNCTION(BlueprintPure, Category = "FSMMetaDataFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
	static UFSMMetaDataAsset* FindMetaDataAsset(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "FSMMetaDataFunctionLibrary", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "DataType"))
	static UFSMMetaDataFragment* FindMetaDataFragment(UObject* WorldContextObject, TSubclassOf<UFSMMetaDataFragment> DataType);

	template<class T>
	static T* FindMetaDataFragment(UObject* WorldContextObject)
	{
		return (T*)FindMetaDataFragment(WorldContextObject, T::StaticClass());
	}

	//////////////////////////////////////////////////////////////////
	// Flow State Machine Meta Data Fragments
	//////////////////////////////////////////////////////////////////

	UFUNCTION(BlueprintPure, Category = "FSMMetaDataFunctionLibrary", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "AssetType"))
	static UObject* FindAssetFromMetaData(UObject* WorldContextObject, FName Name, TSubclassOf<UObject> AssetType);
};
