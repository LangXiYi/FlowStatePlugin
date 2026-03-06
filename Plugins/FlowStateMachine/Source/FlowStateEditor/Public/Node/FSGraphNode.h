// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSGraphNodeBase.h"
#include "EdGraph/EdGraphNode.h"
#include "FSGraphNode.generated.h"

class UFSMCommonData;
class UFlowStateGraph;

class UFSMNodeInstance;
class UFSGraphSubNode;

/**
 *
 */
UCLASS()
class FLOWSTATEEDITOR_API UFSGraphNode : public UFSGraphNodeBase
{
    GENERATED_BODY()

public:
    /** 初始化运行时节点实例时调用  */
    virtual void InitializeInstance() override;

    /** 为节点添加一个次要节点 */
    void AddSubNode(UFSGraphNodeBase* SubNode, class UEdGraph* ParentGraph);
    /** 为节点添加一个次要节点 */
    virtual void OnSubNodeAdded(UFSGraphNodeBase* SubNode);

    /** 将一个次要节点从当前节点中移除 */
    void RemoveSubNode(UFSGraphNodeBase* SubNode);
    /** 将一个次要节点从当前节点中移除 */
    virtual void OnSubNodeRemoved(UFSGraphNodeBase* SubNode);

    /** 移除节点中的所有次级节点 */
    virtual void RemoveAllSubNode();

    /** 是否可以删除该节点 */
    virtual bool CanUserDeleteNode() const override;

    virtual void ResetNodeOwner() override;

    virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;

    /** 次要节点：条件列表 */
    UPROPERTY()
    TArray<UFSGraphSubNode*> Conditions;

    /** 次要节点：行为列表 */
    UPROPERTY()
    TArray<UFSGraphSubNode*> Actions;

    /** 次要节点：服务列表 */
    UPROPERTY()
    TArray<UFSGraphSubNode*> Services;

    void AddConditionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const;
    void AddServiceSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const;
    void AddActionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const;

protected:
    /** 创建添加条件子菜单 */
    void CreateAddConditionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;

    /** 创建添加行为子菜单 */
    void CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;

    /** 创建添加服务子菜单 */
    void CreateAddServiceSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const;
};

