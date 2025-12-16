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
class FLOWSTATEMACHINE_API UFSMRuntimeNode_State : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};

UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_StateMachine : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};


/**
 * 运行时节点---------行为
 * 作为 State 节点的子节点
 * 会在每次进入 State 之前执行一次，单个 State 节点可以添加多个 Action，但每个 Action 只能添加一个。
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Action : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};

/**
 * 运行时节点---------装饰器
 * 作为 State 节点的子节点
 * 会在每帧执行，与 BehaviorTree 执行流程相同，会中断当前 State 的执行或限制进入某 State。
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Decorator : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	
};