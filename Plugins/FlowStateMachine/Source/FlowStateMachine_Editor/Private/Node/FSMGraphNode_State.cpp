// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNode_State.h"

#include "RuntimeNode/FSMRuntimeNodeBase.h"
#include "ToolMenu.h"
#include "ToolMenuDelegates.h"
#include "Node/FSMGraphSubNode.h"


#define LOCTEXT_NAMESPACE "FSMGraphNode_State"

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

	AddConditionSubMenu(Menu, Context);
	AddServiceSubMenu(Menu, Context);
	AddActionSubMenu(Menu, Context);

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

#undef LOCTEXT_NAMESPACE
