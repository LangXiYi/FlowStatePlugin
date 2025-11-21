// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SM/FlowState.h"
#include "SM/FlowStateContext.h"
#include "Utility/FSMUtility.h"
#include "FSMFunctionLibrary.generated.h"


class UFlowStateLayoutWidget;
class UFlowState;
class UFlowStateContext;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	//////////////////////////////////////////////////////////////////
	// Flow State Machine Meta Data
	//////////////////////////////////////////////////////////////////
public:
	UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
	static UFlowStateContext* GetFlowStateContext(UObject* WorldContextObject);

	template<class T>
	static T* GetFlowStateContext(UObject* WorldContextObject)
	{
		return static_cast<T*>(GetFlowStateContext(WorldContextObject));
	}

	UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
	static UFlowState* GetCurFlowState(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Type"))
	static UFlowState* GetCurFlowStateAs(UObject* WorldContextObject, TSubclassOf<UFlowState> Type);

	template<class T>
	static T* GetCurFlowStateAs(UObject* WorldContextObject)
	{
		return static_cast<T*>(GetCurFlowState(WorldContextObject));
	}

	/////////////////////////////////////////////////////////////////////
	/// Blueprint Internal Use Only Function
	/////////////////////////////////////////////////////////////////////
public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "FSMFunctionLibrary", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Class", BlueprintInternalUseOnly = "true"))
	static UUserWidget* CreateAndBindWidget(UObject* WorldContextObject, UFlowStateLayoutWidget* WidgetLayout, TSubclassOf<UUserWidget> WidgetType, FGameplayTag WidgetSlotTag, EFlowStateLifetime Lifetime = EFlowStateLifetime::Kill);

	UFUNCTION(BlueprintCallable, Category = "FSMFunctionLibrary", meta = (BlueprintInternalUseOnly = "true"))
	static AActor* InitActorLifetimeState(AActor* Target, EFlowStateLifetime Lifetime, FName ActorTag);

	UFUNCTION(BlueprintCallable, Category = "FSMFunctionLibrary", meta = (WorldContext = "WorldContextObject", BlueprintInternalUseOnly = "True"))
	static bool FindActorFromCache(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FName ActorTag, AActor*& FindActor);
};
