// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
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
