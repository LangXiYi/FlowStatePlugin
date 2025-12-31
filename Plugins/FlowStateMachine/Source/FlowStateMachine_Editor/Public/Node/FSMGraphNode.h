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
	/** 初始化运行时节点实例时调用  */
	virtual void InitializeInstance() override;

	virtual void OnSubNodeAdded(UFSMGraphNodeBase* SubNode) override;

	/** 是否可以删除该节点 */
	virtual bool CanUserDeleteNode() const override;

public:
	/** 次要节点：条件列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphSubNode*> Conditions;

	/** 次要节点：行为列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphSubNode*> Actions;

	/** 次要节点：服务列表 */
	UPROPERTY(VisibleAnywhere)
	TArray<UFSMGraphSubNode*> Services;

public:
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



