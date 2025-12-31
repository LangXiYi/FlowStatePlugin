// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNodeBase.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode.generated.h"

class UFSMRuntimeSubNode;
class UFlowStateMachine;

/**
 * 状态机运行时节点，保存图表中编辑的各个节点的关系。
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode : public UFSMRuntimeNodeBase
{
	GENERATED_BODY()

public:
	void InitializeNode(UFSMRuntimeNodeBase* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth);

#if WITH_EDITOR
	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated() {}

	/** 【Only Editor】 只在编辑阶段可以调用添加子节点 */
	virtual void AddChildNode(UFSMRuntimeNode* ChildNode)
	{
		if (ChildNode == nullptr)
		{
			return;
		}
		ChildrenNodes.Add(ChildNode);
	}

	/** 【Only Editor】 只在编辑阶段可以清除子节点 */
	virtual void ClearChildren()
	{
		ChildrenNodes.Empty();
	}
#endif

private:
	/** depth first index (execution order) */
	UPROPERTY(VisibleAnywhere)
	uint16 ExecutionIndex;

	/** instance memory offset */
	UPROPERTY(VisibleAnywhere)
	uint16 MemoryOffset;

	/** depth in tree */
	UPROPERTY(VisibleAnywhere)
	uint8 TreeDepth;
};

UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_Composites : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:


protected:
	/** 尝试切换至其他状态 */


	/** 行为列表 */
	TArray<UFSMRuntimeSubNode*> Actions;
	/** 服务列表 */
	TArray<UFSMRuntimeSubNode*> Services;
	/** 条件列表 */
	TArray<UFSMRuntimeSubNode*> Conditions;
};

UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_State : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:


protected:
	/** 尝试切换至其他状态 */


	/** 行为列表 */
	TArray<UFSMRuntimeSubNode*> Actions;
	/** 服务列表 */
	TArray<UFSMRuntimeSubNode*> Services;
	/** 条件列表 */
	TArray<UFSMRuntimeSubNode*> Conditions;
};
