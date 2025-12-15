// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNode.generated.h"

class UFSMGraph;
class UFSMRuntimeNode;

USTRUCT()
struct FFSMGraphNodeClassData
{
	GENERATED_BODY()

public:
	FFSMGraphNodeClassData() {}
	FFSMGraphNodeClassData(UClass* InClass, const FString& InDeprecatedMessage);
	FFSMGraphNodeClassData(const FString& InAssetName, const FString& InGeneratedClassPackage, const FString& InClassName, UClass* InClass);

	UClass* GetClass() const;
	const FString& ToString() const;

private:
	TWeakObjectPtr<UClass> RuntimeNodeClass;
};

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode : public UEdGraphNode
{
	GENERATED_BODY()

public:
	// 当节点被放置后调用，创建 RuntimeNode 实例
	virtual void PostPasteNode() override;

	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance();

	UFSMGraph* GetFSMGraph() const;

	void AddSubNode(UFSMGraphNode* SubNode, class UEdGraph* ParentGraph);
	void RemoveSubNode(UFSMGraphNode* SubNode);
	virtual void OnSubNodeAdded(UFSMGraphNode* SubNode) {}
	
public:
	FFSMGraphNodeClassData ClassData;
	
	UPROPERTY()
	UFSMRuntimeNode* NodeInstance;

	UPROPERTY()
	UFSMGraphNode* ParentNode;

	TArray<UFSMGraphNode*> SubNodes;
};
