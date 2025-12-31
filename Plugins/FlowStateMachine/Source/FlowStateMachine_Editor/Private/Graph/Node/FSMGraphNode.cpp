// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/Node/FSMGraphNode.h"

#include "FlowStateMachineEditorTypes.h"
#include "ToolMenu.h"
#include "Graph/FSMGraph.h"
#include "Graph/Node/FSMGraphSubNode.h"
#include "Slate/SGraphEditorActionMenu_FSM.h"
#include "SM/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FSMGraphNode"

bool UFSMGraphNode::CanUserDeleteNode() const
{
	return Super::CanUserDeleteNode();
}



void UFSMGraphNode::InitializeInstance()
{
	Super::InitializeInstance();
}

void UFSMGraphNode::AddSubNode( UFSMGraphSubNode* SubNode, UEdGraph* ParentGraph)
{
	// const FScopedTransaction Transaction(LOCTEXT("AddNode", "Add Node"));
	ParentGraph->Modify();
	Modify();

	UFSMGraphSubNode* GraphSubNode = Cast<UFSMGraphSubNode>(SubNode);
	if (GraphSubNode == nullptr)
	{
		return;
	}

	GraphSubNode->SetFlags(RF_Transactional);

	// 设置节点 Outer 为 Graph 确保其不会被回收
	GraphSubNode->Rename(nullptr, ParentGraph, REN_NonTransactional);
	GraphSubNode->ParentNode = this;

	GraphSubNode->CreateNewGuid();
	GraphSubNode->PostPlacedNewNode();
	GraphSubNode->AllocateDefaultPins();
	GraphSubNode->AutowireNewNode(nullptr);

	GraphSubNode->NodePosX = 0;
	GraphSubNode->NodePosY = 0;

	SubNodes.Add(GraphSubNode);
	OnSubNodeAdded(GraphSubNode);

	ParentGraph->NotifyGraphChanged();
	GetFSMGraph()->UpdateAsset();
}

void UFSMGraphNode::RemoveSubNode(UFSMGraphSubNode* SubNode)
{
	SubNodes.RemoveSingle(SubNode);
	Modify();

	OnSubNodeRemoved(SubNode);
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


#define LOCTEXT_NAMESPACE "FSMGraphNode_State"

void UFSMGraphNode_Root::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Root");
}

void UFSMGraphNode_State::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, "DefaultInput", TEXT("In"));
	CreatePin(EGPD_Output, "DefaultOutput", TEXT("Out"));
}

FText UFSMGraphNode_State::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (RuntimeNode != NULL)
	{
		return FText::FromString(RuntimeNode->GetNodeName());
	}
	else if (!ClassData.GetClassName().IsEmpty())
	{
		FString StoredClassName = ClassData.GetClassName();
		StoredClassName.RemoveFromEnd(TEXT("_C"));

		return FText::Format(NSLOCTEXT("FSMGraph", "NodeClassError", "Class {0} not found, make sure it's saved!"), FText::FromString(StoredClassName));
	}

	return Super::GetNodeTitle(TitleType);
}

void UFSMGraphNode_State::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection("FSMGraphNode");
	// 添加子菜单
	Section.AddSubMenu(
		"AddCondition",
		LOCTEXT("ConditionLabel", "Add Condition...") ,
		LOCTEXT("ConditionToolTip", "Adds new decorator as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddConditionSubMenu, (UEdGraph*)Context->Graph));
	
	Section.AddSubMenu(
		"AddAction",
		LOCTEXT("ActionLabel", "Add Action...") ,
		LOCTEXT("ActionToolTip", "Adds new action as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddActionSubMenu, (UEdGraph*)Context->Graph));

	Section.AddSubMenu(
			"AddService",
			LOCTEXT("ServiceLabel", "Add Service...") ,
			LOCTEXT("ServiceToolTip", "Adds new service as a subnode"),
			FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddServiceSubMenu, (UEdGraph*)Context->Graph));


	Super::GetNodeContextMenuActions(Menu, Context);
	FToolMenuSection& section = Menu->AddSection(TEXT("SectionName"), FText::FromString(TEXT("Custom Node Actions")));
	UFSMGraphNode_State* node = (UFSMGraphNode_State*)this;
	section.AddMenuEntry(
		TEXT("AddPinEntry"),
		FText::FromString(TEXT("Add Pin")),
		FText::FromString(TEXT("Creates a new pin")),
		FSlateIcon(TEXT("FlowStateMachineStyleSet"), TEXT("FlowStateMachineEditor.NodeAddPinIcon")),
		FUIAction(FExecuteAction::CreateLambda(
			[node] () {
				node->CreatePin(EGPD_Output, TEXT("FlowStatePins"), TEXT("OutputPin"));
				// node->CreateCustomPin(EEdGraphPinDirection::EGPD_Output, TEXT("AnotherOutput"));
				node->GetGraph()->NotifyGraphChanged();
				node->GetGraph()->Modify();
			}
		))
	);

	section.AddMenuEntry(
		TEXT("DeletePinEntry"),
		FText::FromString(TEXT("Delete Pin")),
		FText::FromString(TEXT("Deletes the last pin")),
		FSlateIcon(TEXT("FlowStateMachineStyleSet"), TEXT("FlowStateMachineEditor.NodeDeletePinIcon")),
		FUIAction(FExecuteAction::CreateLambda(
			[node] () {
				UEdGraphPin* pin = node->GetPinAt(node->Pins.Num() - 1);
				if (pin->Direction != EEdGraphPinDirection::EGPD_Input) {
					node->RemovePin(pin);

					node->GetGraph()->NotifyGraphChanged();
					node->GetGraph()->Modify();
				}
			}
		))
	);

	section.AddMenuEntry(
		TEXT("DeleteEntry"),
		FText::FromString(TEXT("Delete Node")),
		FText::FromString(TEXT("Deletes the node")),
		FSlateIcon(TEXT("FlowStateMachineStyleSet"), TEXT("FlowStateMachineEditor.NodeDeleteNodeIcon")),
		FUIAction(FExecuteAction::CreateLambda(
			[node] () {
				node->GetGraph()->RemoveNode(node);
			}
		))
	);
}

void UFSMGraphNode_State::CreateCustomPin(EEdGraphPinDirection Direction, const FString& PinName)
{
}

void UFSMGraphNode_State::AddSubNode(UFSMGraphSubNode* SubNode, class UEdGraph* ParentGraph)
{
	Super::AddSubNode(SubNode, ParentGraph);
	
	if (UFSMGraphNode_Condition* ConditionNode = Cast<UFSMGraphNode_Condition>(SubNode))
	{
		Conditions.Add(ConditionNode);
	}
	else if (UFSMGraphNode_Service* ServiceNode = Cast<UFSMGraphNode_Service>(SubNode))
	{
		Services.Add(ServiceNode);
	}
	else if (UFSMGraphNode_Action* ActionNode = Cast<UFSMGraphNode_Action>(SubNode))
	{
		Actions.Add(ActionNode);
	}
}
#undef LOCTEXT_NAMESPACE
