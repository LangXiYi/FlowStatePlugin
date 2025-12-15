// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode.generated.h"

class UFlowStateMachine;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode : public UObject
{
	GENERATED_BODY()

public:
	void InitializeFromAsset(UFlowStateMachine& Asset);
	void InitializeNode(UFSMRuntimeNode* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth);

#if WITH_EDITOR
	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated() {}
#endif

private:
	// Asset Ptr
	UPROPERTY()
	UFlowStateMachine* FSMAsset;
	
	UPROPERTY()
	UFSMRuntimeNode* ParentNode;

	/** depth first index (execution order) */
	uint16 ExecutionIndex;

	/** instance memory offset */
	uint16 MemoryOffset;

	/** depth in tree */
	uint8 TreeDepth;
};

UCLASS()
class UFSMRuntimeNode_State : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};

UCLASS()
class UFSMRuntimeNode_StateMachine : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};