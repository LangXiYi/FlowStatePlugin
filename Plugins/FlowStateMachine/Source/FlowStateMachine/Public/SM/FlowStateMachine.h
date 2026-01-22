// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"
#include "UObject/Object.h"
#include "FlowStateMachine.generated.h"

class UFlowStateWidgetLayerManager;
class UFSMRuntimeNode;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateMachine : public UObject
{
	GENERATED_BODY()

public:
	/** 状态机的运行时根节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNode* RootRuntimeNode;

	/** 状态机的所有零散节点（无法被RootNode追溯到节点） */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNode*> ScatteredNodes;

	/** 状态机根节点的装饰器子节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Condition*> RootDecorators;

	/** 状态机根节点的服务子节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Service*> RootServices;

	/** 状态机根节点的行为子节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<class UFSMRuntimeSubNode_Action*> RootActions;

#if WITH_EDITORONLY_DATA
	/** Graph For State Machine */
	UPROPERTY()
	class UEdGraph*	FSMGraph;

#endif

	FString GetScatteredNodeName(FGuid InScatteredNodeID) const;

	/** 黑板 */
	UPROPERTY(VisibleAnywhere)
	class UFSMCommonData* CommonData = nullptr;

	/** 状态机的布局管理器 */
	UPROPERTY(VisibleAnywhere)
	TSubclassOf<UFlowStateWidgetLayerManager> WidgetLayerManagerClass;

	// 状态机的切换映射
	/**
	 * TODO::后续可以通过图表编辑
	 *               State_B
	 *             /          \
	 * root ----->             State_C ------> State_D          State_G
	 *			   \          /                       \       /
	 *			    State_A                            State_E
	 *			                                              \
	 *			                                                State_F
	 *  Start节点
	 *  Cur节点
	 *     - NextNodes[]
	 *  BroadcastSwitchToByIndex(int Index) --> check(GetThenCount() > Index)
	 *  数据结构大致如下
	 * 		节点结构
	 * 			NodeID
	 * 			NextNodes[节点结构]
	 * 			Node_DisplayName
	 * 			Node_StateClass
	 */
};
