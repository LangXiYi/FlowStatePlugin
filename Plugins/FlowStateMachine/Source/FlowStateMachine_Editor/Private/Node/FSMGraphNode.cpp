// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNode.h"

#include "FSMEditorTypes.h"
#include "ToolMenu.h"
#include "Graph/FSMGraph.h"
#include "Node/FSMGraphSubNode.h"
#include "Slate/SGraphEditorActionMenu_FSM.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FSMGraphNode"

bool UFSMGraphNode::CanUserDeleteNode() const
{
	return Super::CanUserDeleteNode();
}

void UFSMGraphNode::RemoveAllSubNode()
{
	Super::RemoveAllSubNode();

	Actions.Reset();
	Services.Reset();
	Conditions.Reset();
}


void UFSMGraphNode::InitializeInstance()
{
	Super::InitializeInstance();
	if (UFSMRuntimeNode* Node = Cast<UFSMRuntimeNode>(RuntimeNode))
	{
		// 初始化节点信息，如父级节点、节点深度、执行优先级等等，此时无实际意义。
		Node->InitializeNode(NULL, MAX_uint16, 0, 0);
	}
}

void UFSMGraphNode::OnSubNodeAdded(UFSMGraphNodeBase* SubNode)
{
	if (UFSMGraphSubNode_Condition* ConditionNode = Cast<UFSMGraphSubNode_Condition>(SubNode))
	{
		Conditions.Add(ConditionNode);
	}
	else if (UFSMGraphSubNode_Service* ServiceNode = Cast<UFSMGraphSubNode_Service>(SubNode))
	{
		Services.Add(ServiceNode);
	}
	else if (UFSMGraphSubNode_Action* ActionNode = Cast<UFSMGraphSubNode_Action>(SubNode))
	{
		Actions.Add(ActionNode);
	}
}

void UFSMGraphNode::AddConditionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
	Section.AddSubMenu(
		"AddCondition",
		LOCTEXT("ConditionLabel", "Add Condition...") ,
		LOCTEXT("ConditionToolTip", "Adds new decorator as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddConditionSubMenu, (UEdGraph*)Context->Graph));
}

void UFSMGraphNode::AddServiceSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
	Section.AddSubMenu(
		"AddAction",
		LOCTEXT("ActionLabel", "Add Action...") ,
		LOCTEXT("ActionToolTip", "Adds new action as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddActionSubMenu, (UEdGraph*)Context->Graph));
}

void UFSMGraphNode::AddActionSubMenu(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
	Section.AddSubMenu(
			"AddService",
			LOCTEXT("ServiceLabel", "Add Service...") ,
			LOCTEXT("ServiceToolTip", "Adds new service as a subnode"),
			FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddServiceSubMenu, (UEdGraph*)Context->Graph));
}

void UFSMGraphNode::CreateAddConditionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
	TSharedRef<SGraphEditorActionMenu_FSM> Widget =
		SNew(SGraphEditorActionMenu_FSM)
		.GraphObj( Graph )
		.GraphNode(const_cast<UFSMGraphNode*>(this))
		.SubNodeFlags(EFSMSubNodeType::Condition)
		.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("ConditionWidget", Widget, FText(), true));
}

void UFSMGraphNode::CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
	TSharedRef<SGraphEditorActionMenu_FSM> Widget =
		SNew(SGraphEditorActionMenu_FSM)
		.GraphObj( Graph )
		.GraphNode(const_cast<UFSMGraphNode*>(this))
		.SubNodeFlags(EFSMSubNodeType::Action)
		.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("ActionWidget", Widget, FText(), true));
}

void UFSMGraphNode::CreateAddServiceSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
	TSharedRef<SGraphEditorActionMenu_FSM> Widget =
	SNew(SGraphEditorActionMenu_FSM)
	.GraphObj( Graph )
	.GraphNode(const_cast<UFSMGraphNode*>(this))
	.SubNodeFlags(EFSMSubNodeType::Service)
	.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("ServiceWidget", Widget, FText(), true));
}

#undef LOCTEXT_NAMESPACE

