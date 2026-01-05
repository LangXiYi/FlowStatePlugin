// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMRuntimeNodeBase.generated.h"

class UFlowStateContext;
class UFlowStateMachine;
/**
 * 
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNodeBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void InitializeFromAsset(UFlowStateMachine* Asset);

	// 定义访问公共数据的方法
	// float GetCommonDataAsFloat(FString PropName);
	// ...

	virtual class UWorld* GetWorld() const override;

	FString GetNodeName() const;

#if WITH_EDITOR

	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated() {}
	
#endif

	template<class T = UFSMRuntimeNodeBase>
	T* GetParentNode() const
	{
		return static_cast<T*>(ParentNode);
	}

public:
	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNodeBase* ParentNode;
	
	/** 子级节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNodeBase*> ChildrenNodes;

	// 是否为根节点
	UPROPERTY(VisibleAnywhere)
	bool bIsRootNode = false;

protected:
	UPROPERTY(EditAnywhere)
	FString NodeName;

private:
	// 静态资产实例，可以通过他访问到我们的黑板资产
	UPROPERTY(VisibleAnywhere)
	UFlowStateMachine* FSMAsset;
};
