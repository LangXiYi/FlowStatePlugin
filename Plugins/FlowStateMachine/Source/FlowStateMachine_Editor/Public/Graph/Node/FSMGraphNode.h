// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMGraphNodeBase.h"
#include "EdGraph/EdGraphNode.h"
#include "FSMGraphNode.generated.h"

class UFSMCommonData;
class UFSMGraph;

class UFSMRuntimeNode;
class UFSMGraphSubNode;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode : public UFSMGraphNodeBase
{
	GENERATED_BODY()

public:
	/** 获得当前操作节点的上下文菜单行为，当右键节点时触发该函数 */
	virtual void GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;

	/** 是否可以删除该节点 */
	virtual bool CanUserDeleteNode() const override;

	/** 自动连接创建的新节点 */
	virtual void AutowireNewNode(UEdGraphPin* FromPin) override;
	
	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance() override;

	/** 为节点添加一个子节点 */
	void AddSubNode( UFSMGraphSubNode* SubNode, class UEdGraph* ParentGraph);
	virtual void OnSubNodeAdded( UFSMGraphSubNode* SubNode) {}

	/** 将一个子节点从当前节点中移除 */
	void RemoveSubNode(UFSMGraphSubNode* SubNode);
	virtual void OnSubNodeRemoved(UFSMGraphSubNode* SubNode) {}

protected:
	UEdGraphPin* GetInputPin() const;
	TArray<UEdGraphPin*> GetOutputPins() const;

public:
	/** 所有子节点 */
	TArray<UFSMGraphSubNode*> SubNodes;

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
	TArray<UFSMGraphSubNode*> Condition;

	// 仅存储行为
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphSubNode*> Actions;
};