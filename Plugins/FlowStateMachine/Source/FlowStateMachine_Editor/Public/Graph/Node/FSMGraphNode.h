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
	FString ToString() const;
	FText GetCategory() const { return FText::FromString("Default"); }

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
	/** 当节点被放置后调用，创建 RuntimeNode 实例 */
	virtual void PostPasteNode() override;

	/** 获得当前操作节点的上下文菜单行为，当右键节点时触发该函数 */
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;

	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance();

	UFSMGraph* GetFSMGraph() const;

	void AddSubNode(UFSMGraphNode* SubNode, class UEdGraph* ParentGraph);
	void RemoveSubNode(UFSMGraphNode* SubNode);
	virtual void OnSubNodeAdded(UFSMGraphNode* SubNode) {}

	
public:
	FFSMGraphNodeClassData ClassData;

	/**	RuntimeNode 一般会随图表节点的创建一起创建。 */
	UPROPERTY()
	UFSMRuntimeNode* RuntimeNode;

	UPROPERTY()
	UFSMGraphNode* ParentNode;

	// DEPRECATED
	TArray<UFSMGraphNode*> SubNodes;

	// 仅存储装饰器
	UPROPERTY()
	TArray<UFSMGraphNode*> Decorators;

	// 仅存储行为
	UPROPERTY()
	TArray<UFSMGraphNode*> Actions;
	
	bool bIsRootNode = false;

protected:
	/** creates add decorator... submenu */
	void CreateAddDecoratorSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;

	/** creates add service... submenu */
	void CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;
};

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Decorator : public UEdGraphNode
{
	GENERATED_BODY()

public:
};

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Action : public UEdGraphNode
{
	GENERATED_BODY()

public:
};