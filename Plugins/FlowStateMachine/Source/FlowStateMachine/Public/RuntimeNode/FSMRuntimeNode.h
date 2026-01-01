// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNodeBase.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode.generated.h"

class UFlowStateContext;
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
	/** 初始化当前节点 */
	virtual void OnInitialize(UFlowStateContext* InContext);

	/** 进入当前节点 */
	virtual void OnEnter();

	/** 退出当前节点 */
	virtual void OnExit();

	/** 检查当前节点的条件 */
	virtual bool CheckCondition();

	/** 尝试切换至其他节点 */
	UFUNCTION(BlueprintCallable, Category = "FlowStateMachine")
	virtual bool TrySwitchTo(int Index);

	/** Tick 函数每帧执行 */
	virtual void Tick(float DeltaTime) {}

#if WITH_EDITOR
	/** 初始化节点，该函数注意在编辑器构建阶段调用 */
	virtual void InitializeNode(UFSMRuntimeNode* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth);

	/** 【Only Editor】 只在编辑阶段可以调用添加子节点 */
	virtual void AddSubNode(UFSMRuntimeNodeBase* InSubNode);

	/** 【Only Editor】 只在编辑阶段可以清除子节点 */
	virtual void ClearSubNodes()
	{
		Actions.Empty();
		Services.Empty();
		Conditions.Empty();
	}
#endif

	UFUNCTION(BlueprintPure, Category = "FlowStateMachine")
	UFlowStateContext* GetContext() const { return Context; }

	virtual UWorld* GetWorld() const override;

protected:
	/** 次要节点：行为列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Action*> Actions;

	/** 次要节点：服务列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Service*> Services;

	/** 次要节点：条件列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Condition*> Conditions;

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

	UPROPERTY(VisibleAnywhere)
	class UFlowStateContext* Context;
};
