// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FSMCommonDataFunctionLibrary.generated.h"

class UFlowStateContext;
class UFSMCommonDataManager;
class UFSMNodeInstanceBase;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMCommonDataFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

/*UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UFSMCommonDataManager* GetStateCommonData(UFSMNodeInstanceBase* NodeOwner);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UFlowStateContext* GetStateContext(const UFSMNodeInstanceBase* NodeOwner);*/
	
	/*
	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UObject* GetStateValueAsObject(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static AActor* GetStateValueAsActor(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static UClass* GetStateValueAsClass(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static uint8 GetStateValueAsEnum(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static int32 GetStateValueAsInt(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static float GetStateValueAsFloat(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static bool GetStateValueAsBool(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FString GetStateValueAsString(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FName GetStateValueAsName(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FVector GetStateValueAsVector(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintPure, Category ="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static FRotator GetStateValueAsRotator(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsObject(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, UObject* Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsClass(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, UClass* Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsEnum(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, uint8 Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsInt(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, int32 Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsFloat(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, float Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsBool(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, bool Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsString(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, FString Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsName(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, FName Value);

	UFUNCTION(BlueprintCallable, Category="FlowStateMachine", Meta=(HidePin="NodeOwner", DefaultToSelf="NodeOwner"))
	static void SetStateValueAsVector(UFSMNodeInstanceBase* NodeOwner, const FBlackboardKeySelector& Key, FVector Value);
	*/

};
