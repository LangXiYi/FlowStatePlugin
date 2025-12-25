// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode.generated.h"

class UFlowStateMachine;

/**
 * 状态机运行时节点，保存图表中编辑的各个节点的关系。
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode : public UObject
{
	GENERATED_BODY()

public:
	void InitializeFromAsset(UFlowStateMachine& Asset);
	void InitializeNode(UFSMRuntimeNode* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth);

#if WITH_EDITOR
	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated() {}

	/** 【Only Editor】 只在编辑阶段可以调用添加子节点 */
	void AddChildNode(UFSMRuntimeNode* ChildNode)
	{
		if (ChildNode == nullptr)
		{
			return;
		}
		ChildrenNodes.Add(ChildNode);
	}

	/** 【Only Editor】 只在编辑阶段可以清除子节点 */
	void ClearChildren()
	{
		ChildrenNodes.Empty();
	}
#endif

	FString GetNodeName() const;

protected:
	// TODO::当属性 NodeName 发生改变时，同步修改节点的标题
	UPROPERTY(EditAnywhere)
	FString NodeName;

private:
	// Asset Ptr
	UPROPERTY()
	UFlowStateMachine* FSMAsset;

	/** 父级节点 */
	UPROPERTY()
	UFSMRuntimeNode* ParentNode;

	/** 子级节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNode*> ChildrenNodes;

	/** depth first index (execution order) */
	uint16 ExecutionIndex;

	/** instance memory offset */
	uint16 MemoryOffset;

	/** depth in tree */
	uint8 TreeDepth;
};

UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_State : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:


protected:
	/** 尝试切换至其他状态 */
};

/**
 * 运行时子节点
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeSubNode : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:

};

/**
 * 运行时节点---------行为
 * 作为 State 节点的子节点
 * 会在每次进入 State 之前执行一次，单个 State 节点可以添加多个 Action，但每个 Action 只能添加一个。
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Action : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	
};

/**
 * 运行时节点---------装饰器
 * 作为 State 节点的子节点
 * 表示从当前状态切换至该状态所需要的前置条件
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Condition : public UFSMRuntimeSubNode
{
	GENERATED_BODY()

public:
	
};