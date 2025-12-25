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

void UFSMGraphNode::GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const
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

	// TODO::Add Server SubMenu
}

bool UFSMGraphNode::CanUserDeleteNode() const
{
	return Super::CanUserDeleteNode();
}

void UFSMGraphNode::AutowireNewNode(UEdGraphPin* FromPin)
{
	Super::AutowireNewNode(FromPin);

	if (FromPin != nullptr)
	{
		// UEdGraphPin* OutputPin = GetOutputPins(EGPD_Output);
		
		if (GetSchema()->TryCreateConnection(FromPin, GetInputPin()))
		{
			FromPin->GetOwningNode()->NodeConnectionListChanged();
		}
		// else if (OutputPin != nullptr && GetSchema()->TryCreateConnection(OutputPin, FromPin))
		// {
			// NodeConnectionListChanged();
		// }
	}
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

UEdGraphPin* UFSMGraphNode::GetInputPin() const
{
	TArray<UEdGraphPin*> OutPins;
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin && Pin->Direction == EGPD_Input)
		{
			return Pin;
		}
	}
	checkNoEntry();
	return nullptr;;
}

TArray<UEdGraphPin*> UFSMGraphNode::GetOutputPins() const
{
	TArray<UEdGraphPin*> OutPins;
	for (UEdGraphPin* Pin : Pins)
	{
		if (Pin && Pin->Direction == EGPD_Output)
		{
			OutPins.Add(Pin);
		}
	}
	return OutPins;
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
	Section.AddEntry(FToolMenuEntry::InitWidget("DecoratorWidget", Widget, FText(), true));

	// TODO::创建并添加节点行为列表
}

void UFSMGraphNode::CreateAddActionSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
{
	// TODO::创建并添加节点行为列表
}

#undef LOCTEXT_NAMESPACE


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
