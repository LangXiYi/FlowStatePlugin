// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNode.generated.h"

class UFSMCommonData;
class UFSMGraph;
class UFSMRuntimeNode;

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

	/** 是否可以删除该节点 */
	virtual bool CanUserDeleteNode() const override { return true; }

	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;
	
	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance();

	UFSMGraph* GetFSMGraph() const;

	void AddSubNode(UFSMGraphNode* SubNode, class UEdGraph* ParentGraph);
	void RemoveSubNode(UFSMGraphNode* SubNode);
	virtual void OnSubNodeAdded(UFSMGraphNode* SubNode) {}

protected:
	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

public:
	/** 类型数据，目前使用的是 AIGraphType 中定义的类型，后续可以考虑使用自定义的类型 */
	FGraphNodeClassData ClassData;

	/**	运行时会随图表节点一起创建。 */
	UPROPERTY(VisibleAnywhere)
	UFSMRuntimeNode* RuntimeNode;

	/** ParentNode 是指 SubNode 的父级，SubNode 一般指 Action、Condition 等类型 */
	UPROPERTY(VisibleAnywhere)
	UFSMGraphNode* ParentNode;

	// DEPRECATED
	TArray<UFSMGraphNode*> SubNodes;
	
	bool bIsRootNode = false;

protected:
	/** 创建添加条件子菜单 */
	void CreateAddConditionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;

	/** 创建添加行为子菜单 */
	void CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;
};

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Root : public UFSMGraphNode
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual bool CanDuplicateNode() const override { return false; }
	virtual bool CanUserDeleteNode() const override{ return false; }
	virtual bool IsSelectedInEditor() const override { return false; }
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override { return FText::FromString(TEXT("Root Node")); }

	// TODO::监听 CommonData 改变事件
public:
	UPROPERTY(EditAnywhere)
	UFSMCommonData* CommonData;
};

/**
 * 状态节点
 * 至少有一个输入以及零个或多个输出
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_State : public UFSMGraphNode
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	/** 获得节点的标题 */
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

	void CreateCustomPin(EEdGraphPinDirection Direction, const FString& PinName);

private:
	// 仅存储装饰器
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphNode*> Condition;

	// 仅存储行为
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphNode*> Actions;
};

// 更改 Decorator 名称为 Condition
// 用于标识由当前状态切换至下一状态的条件
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Condition : public UFSMGraphNode
{
	GENERATED_BODY()

public:
};

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Action : public UFSMGraphNode
{
	GENERATED_BODY()

public:
};