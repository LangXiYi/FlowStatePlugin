// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowStateCollectInterface.h"
#include "UObject/Object.h"
#include "FSMNodeInstanceBase.generated.h"

class FSMGC;
class UFlowStateContext;
class UFlowStateMachine;

/**
 * 
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMNodeInstanceBase : public UObject, public IFlowStateCollectInterface
{
	GENERATED_BODY()

public:
	virtual void InitializeFromAsset(UFlowStateMachine* Asset);

	/** 预处理运行时实例 */
	virtual void OnPreprocessing();

	virtual void InitializeNode(UFSMNodeInstanceBase* InParentNode, UFlowStateContext* Context = nullptr);

	// 定义访问公共数据的方法
	// float GetCommonDataAsFloat(FString PropName);
	// ...

	/** 尝试切换至其他节点 */
	UFUNCTION(BlueprintCallable, Category = "FlowStateMachine")
	virtual bool TrySwitchTo(int Index);

	/** 尝试切换至其他节点 */
	UFUNCTION(BlueprintCallable, Category = "FlowStateMachine")
	virtual bool SwitchToByName(FName Name);

	virtual class UWorld* GetWorld() const override;

	virtual FString GetNodeName() const;

	UFlowStateMachine* GetStateMachine() const { return FSMAsset; }

	UFUNCTION(BlueprintPure)
	UFlowStateContext* GetStateContext() const { return StateContext; }

	TSharedPtr<FSMGC> GetGCManager() const;

	// Begin IFlowStateCollectInterface
	virtual void GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const override;
	// End of IFlowStateCollectInterface

#if WITH_EDITOR

public:
	// virtual void OnNode
	
	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated(UFSMNodeInstanceBase* InParentNode)
	{
		// TODO::区分编辑环境与运行环境下的函数调用
		if (InParentNode)
		{
			AllParentNodes.AddUnique(InParentNode);
		}
		// GraphNode = InGraphNode;
	}

	/** 【Only Editor】 在图表节点更新后调用 */
	virtual void OnNodeUpdate() {}

#endif

public:
	/** 次要节点 */
	UPROPERTY()
	TArray<UFSMNodeInstanceBase*> SubNodes;

	// 是否为根节点
	UPROPERTY()
	bool bIsRootNode = false;

	/** 该实例是否是模板实例(不会参与实际运行，仅作为运行的参考) */
	bool bIsTemplateInstance = true;

protected:
	/** 运行时创建的状态管理实例 */
	UPROPERTY(Transient)
	UFlowStateContext* StateContext;
	
	UPROPERTY(EditAnywhere)
	FString NodeName;

	/** 所有父级节点 */
	UPROPERTY()
	TArray<UFSMNodeInstanceBase*> AllParentNodes;

	// 静态资产实例，可以通过他访问到我们的黑板资产
	UPROPERTY()
	UFlowStateMachine* FSMAsset;

};
