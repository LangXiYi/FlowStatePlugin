// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNodeBase.h"
#include "UObject/Object.h"
#include "Utility/FSMUtility.h"
#include "FSMRuntimeNode.generated.h"

class UFSMRuntimeNode;
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
	virtual void OnInitialize();

	/** 进入当前节点 */
	virtual void OnEnter();

	/** 退出当前节点 */
	virtual void OnExit();

	/** 检查当前节点的条件 */
	virtual bool CheckCondition();

	/** 尝试切换至其他节点 */
	virtual bool TrySwitchTo(int Index) override;

	/** 尝试切换至其他节点 */
	virtual bool SwitchToByName(FName Name) override;

	/** Tick 函数每帧执行 */
	virtual void Tick(float DeltaTime) {}

	/** 添加子节点 */
	virtual void AddSubNode(UFSMRuntimeNodeBase* InSubNode);

	/** 替换次要节点，使用新的次要节点替换原有的节点 */
	virtual void ReplaceSubNode(UFSMRuntimeNodeBase* NewSubNode, int Index);

	/** 清除子节点 */
	virtual void ClearSubNodes();

	template<class T = UFSMRuntimeNodeBase>
	T* FindSubNode() const
	{
		for (auto SubNode : SubNodes)
		{
			// 若该次要节点是一个目标类型的对象，则返回该对象
			if (SubNode->IsA(T::StaticClass()))
			{
				return static_cast<T*>(SubNode);
			}
		}
		return nullptr;
	}

	const TArray<UFSMRuntimeNodeBase*> GetAllSubNodes() const { return SubNodes; }

	virtual UWorld* GetWorld() const override;

	/** 是否将实例加入执行链 */
	virtual bool IsStackInstance() const { return false; }

public:
	FStateDelegate OnExitDelegate;

	//////////////////////////////////////////////////////////////////////////
	// Runtime Child State
	//////////////////////////////////////////////////////////////////////////

public:
#if WITH_EDITOR
	/** 【Only Editor】 增加子级状态节点 */
	void AddChildState(FName FromPinName, UFSMRuntimeNode* NodeInstance);
	/** 【Only Editor】 移除子级状态节点 */
	void RemoveChildState(int Index);
	/** 【Only Editor】 清空子级状态节点 */
	void ClearChildStates();
	/** 【Only Editor】 获取所有子级状态节点 */
#endif
	/** 替换子级节点为指定的新对象 */
	void ReplaceChildState(UFSMRuntimeNode* NewChildNode, int Index);
	/** 获取所有的子级节点 */
	const TArray<FStateChildNodeHelper>& GetStateChildren() const { return ChildStateHelpers; }

protected:
	// 【Only Runtime】该属性在运行时会被新的值替换
	UPROPERTY()
	TArray<FStateChildNodeHelper> ChildStateHelpers;

protected:
	/** 次要节点：行为列表 */
	UPROPERTY()
	TArray<class UFSMRuntimeSubNode_Action*> Actions;

	/** 次要节点：服务列表 */
	UPROPERTY()
	TArray<class UFSMRuntimeSubNode_Service*> Services;

	/** 次要节点：条件列表 */
	UPROPERTY()
	TArray<class UFSMRuntimeSubNode_Condition*> Conditions;
};
