// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMRuntimeNodeBase.generated.h"

class UFlowStateMachine;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMRuntimeNodeBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void InitializeFromAsset(UFlowStateMachine& Asset);

	virtual void SetOwner(UFSMRuntimeNodeBase* InParent)
	{
		ParentNode = InParent;
	}

	FString GetNodeName() const;

public:
#if WITH_EDITOR
	/** 子级节点 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMRuntimeNodeBase*> ChildrenNodes;
#endif
	
protected:
	// TODO::当属性 NodeName 发生改变时，同步修改节点的标题
	UPROPERTY(EditAnywhere)
	FString NodeName;

	// Asset Ptr
	UPROPERTY(VisibleAnywhere)
	UFlowStateMachine* FSMAsset;

	/** 父级节点 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNodeBase* ParentNode;
};
