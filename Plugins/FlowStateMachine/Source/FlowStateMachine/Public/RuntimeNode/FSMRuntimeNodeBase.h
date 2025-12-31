// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMRuntimeNodeBase.generated.h"

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
	
	virtual void SetOwner(AActor* ActorOwner) {}

	virtual class UWorld* GetWorld() const override;

	FString GetNodeName() const;

#if WITH_EDITOR

	/** 【Only Editor】 在创建新的图表节点后调用 */
	virtual void OnNodeCreated() {}
	
#endif


public:
	/** 子级节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNodeBase*> ChildrenNodes;
	
protected:
	// Asset Ptr
	UPROPERTY(VisibleAnywhere)
	UFlowStateMachine* FSMAsset;
	
	// TODO::当属性 NodeName 发生改变时，同步修改节点的标题
	UPROPERTY(EditAnywhere)
	FString NodeName;

	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNodeBase* ParentNode;

};
