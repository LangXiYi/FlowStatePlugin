// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNode.h"
#include "UObject/Object.h"
#include "FlowStateMachine.generated.h"

class UFSMMetaDataAsset;
class UFlowStateBase;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateMachine : public UObject
{
	GENERATED_BODY()

public:
	FORCEINLINE const FPrimaryAssetId& GetMetaDataID() const { return MetaDataID; }

public:
	/** 状态机的根节点 (是实际进入的第一个节点而不是图表根节点) */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNode* RootRuntimeNode;

	/** 状态机根节点的装饰器子节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNode_Decorator*> RootDecorators;

	/** 状态机根节点的行为子节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNode_Action*> RootActions;

#if WITH_EDITORONLY_DATA
	/** Graph For State Machine */
	UPROPERTY()
	class UEdGraph*	FSMGraph;

#endif
	UPROPERTY()
	class UFSMCommonData* CommonData = nullptr;
	
protected:
	UPROPERTY(EditAnywhere)
	FPrimaryAssetId MetaDataID;

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
