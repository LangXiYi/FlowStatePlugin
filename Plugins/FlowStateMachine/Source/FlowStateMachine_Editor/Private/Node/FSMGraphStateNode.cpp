// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphStateNode.h"

#include "NodeInstance/FSMNodeInstanceBase.h"
#include "ToolMenu.h"
#include "ToolMenuDelegates.h"
#include "Node/FSMGraphSubNode.h"
#include "Slate/SFSMGraphStateNode.h"
#include "Utility/FSMEditorCore.h"


#define LOCTEXT_NAMESPACE "FSMGraphStateNode"

void UFSMGraphStateNode::AllocateDefaultPins()
{
	CreatePin(EGPD_Input, FStateNodePinHelper::Input_PinCategory, FStateNodePinHelper::InPut_DefaultPinName);
	// CreatePin(EGPD_Output, FStateNodePinHelper::Output_PinCategory, FStateNodePinHelper::Output_DefaultPinName);
}

FText UFSMGraphStateNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	if (NodeInstance != NULL)
	{
		return FText::FromString(NodeInstance->GetNodeName());
	}
	else if (!ClassData.GetClassName().IsEmpty())
	{
		FString StoredClassName = ClassData.GetClassName();
		StoredClassName.RemoveFromEnd(TEXT("_C"));

		return FText::Format(NSLOCTEXT("FSMGraph", "NodeClassError", "Class {0} not found, make sure it's saved!"), FText::FromString(StoredClassName));
	}

	return Super::GetNodeTitle(TitleType);
}

void UFSMGraphStateNode::GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	Super::GetNodeContextMenuActions(Menu, Context);

	AddConditionSubMenu(Menu, Context);
	AddServiceSubMenu(Menu, Context);
	AddActionSubMenu(Menu, Context);

	/*FToolMenuSection& section = Menu->AddSection(TEXT("SectionName"), FText::FromString(TEXT("Custom Node Actions")));
	UFSMGraphStateNode* node = (UFSMGraphStateNode*)this;
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
				if (node->Pins.Num() <= 1)
				{
					return;
				}
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
	);*/
}

FEdGraphNodeDeprecationResponse UFSMGraphStateNode::GetDeprecationResponse(
	EEdGraphNodeDeprecationType DeprecationType) const
{
	FEdGraphNodeDeprecationResponse Response = Super::GetDeprecationResponse(DeprecationType);
	if (DeprecationType == EEdGraphNodeDeprecationType::NodeTypeIsDeprecated)
	{
		// 得到当前节点的名称
		FText NodeTitle = GetNodeTitle(ENodeTitleType::FullTitle);
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = FText::Format(FTextFormat::FromString("Warning: The state node '@@' is deprecated from {0}; please replace or remove it."), NodeTitle);
	}
	else if (DeprecationType == EEdGraphNodeDeprecationType::NodeHasDeprecatedReference)
	{
		// 得到当前节点的名称
		FText NodeTitle = GetNodeTitle(ENodeTitleType::FullTitle);
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = FText::Format(FTextFormat::FromString("Warning: The state node '@@' has a deprecated reference from {0}; please replace or remove it."), NodeTitle);
	}
	return Response;
}

TSharedPtr<SGraphNode> UFSMGraphStateNode::CreateVisualWidget()
{
	return SNew(SFSMGraphStateNode, this);
}

#undef LOCTEXT_NAMESPACE
