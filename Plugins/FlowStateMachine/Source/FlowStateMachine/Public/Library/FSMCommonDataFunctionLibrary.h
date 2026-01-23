// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSMCommonDataFunctionLibrary.generated.h"

class UFlowStateContext;
class UFSMCommonDataManager;
class UFSMRuntimeNodeBase;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/*UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UFSMCommonDataManager* GetStateCommonData(UFSMRuntimeNodeBase* NodeOwner);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UFlowStateContext* GetStateContext(const UFSMRuntimeNodeBase* NodeOwner);*/
	
	/*
	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UObject* GetStateValueAsObject(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static AActor* GetStateValueAsActor(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UClass* GetStateValueAsClass(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static uint8 GetStateValueAsEnum(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static int32 GetStateValueAsInt(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static float GetStateValueAsFloat(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static bool GetStateValueAsBool(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FString GetStateValueAsString(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FName GetStateValueAsName(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FVector GetStateValueAsVector(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category ="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FRotator GetStateValueAsRotator(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsObject(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, UObject* Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsClass(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, UClass* Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsEnum(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, uint8 Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsInt(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsFloat(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, float Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsBool(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, bool Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsString(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, FString Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsName(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, FName Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsVector(UFSMRuntimeNodeBase* NodeOwner, const FBlackboardKeySelector& Key, FVector Value);
	*/

};
