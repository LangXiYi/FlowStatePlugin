// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/Node/FSMGraphNode.h"

#include "ToolMenu.h"
#include "Graph/FSMGraph.h"
#include "SM/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FSMGraphNode"

void UFSMGraphNode::PostPasteNode()
{
	Super::PostPasteNode();

	// NodeInstance can be already spawned by paste operation, don't override it

	UClass* NodeClass = ClassData.GetClass();
	if (NodeClass && (RuntimeNode == nullptr))
	{
		UEdGraph* MyGraph = GetGraph();
		// Graph 的 Outer 为 FlowStateMachine
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
		if (GraphOwner)
		{
			// 该 RuntimeNode 会在保存图表时赋予实际意义
			RuntimeNode = NewObject<UFSMRuntimeNode>(GraphOwner, NodeClass);
			// “transactional”这个词确实与编辑器的撤销/重做系统有关。
			RuntimeNode->SetFlags(RF_Transactional);
			InitializeInstance();
		}
	}
}


void UFSMGraphNode::GetNodeContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const
{
	FToolMenuSection& Section = Menu->FindOrAddSection("FlowStateMachineGraphNode");

	Section.AddSubMenu(
		"AddDecorator",
		LOCTEXT("Label", "Add Decorator...") ,
		LOCTEXT("ToolTip", "Adds new decorator as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddConditionSubMenu, (UEdGraph*)Context->Graph));
	
	Section.AddSubMenu(
		"AddAction",
		LOCTEXT("Label", "Add Action...") ,
		LOCTEXT("ToolTip", "Adds new action as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddActionSubMenu, (UEdGraph*)Context->Graph));
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
	UFlowStateMachine* FSMAsset = RuntimeNode ? Cast<UFlowStateMachine>(RuntimeNode->GetOuter()) : nullptr;
	if (RuntimeNode && FSMAsset)
	{
		RuntimeNode->InitializeFromAsset(*FSMAsset);
		// 初始化节点信息，如父级节点、节点深度、执行优先级等等，此时无实际意义。
		RuntimeNode->InitializeNode(NULL, MAX_uint16, 0, 0);
		RuntimeNode->OnNodeCreated();
	}
}

UFSMGraph* UFSMGraphNode::GetFSMGraph() const
{
	return CastChecked<UFSMGraph>(GetGraph());
}

void UFSMGraphNode::AddSubNode(UFSMGraphNode* SubNode, UEdGraph* ParentGraph)
{
	// const FScopedTransaction Transaction(LOCTEXT("AddNode", "Add Node"));
	ParentGraph->Modify();
	Modify();

	SubNode->SetFlags(RF_Transactional);

	// set outer to be the graph so it doesn't go away
	SubNode->Rename(nullptr, ParentGraph, REN_NonTransactional);
	SubNode->ParentNode = this;

	SubNode->CreateNewGuid();
	SubNode->PostPlacedNewNode();
	SubNode->AllocateDefaultPins();
	SubNode->AutowireNewNode(nullptr);

	SubNode->NodePosX = 0;
	SubNode->NodePosY = 0;

	SubNodes.Add(SubNode);
	OnSubNodeAdded(SubNode);

	ParentGraph->NotifyGraphChanged();
	GetFSMGraph()->UpdateAsset();
}

void UFSMGraphNode::RemoveSubNode(UFSMGraphNode* SubNode)
{
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
	/*
	TSharedRef<SGraphEditorActionMenuAI> Widget =
		SNew(SGraphEditorActionMenuAI)
		.GraphObj( Graph )
		.GraphNode((UBehaviorTreeGraphNode*)this)
		.SubNodeFlags(ESubNode::Decorator)
		.AutoExpandActionMenu(true);

	FToolMenuSection& Section = Menu->FindOrAddSection("Section");
	Section.AddEntry(FToolMenuEntry::InitWidget("DecoratorWidget", Widget, FText(), true));
	*/
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
