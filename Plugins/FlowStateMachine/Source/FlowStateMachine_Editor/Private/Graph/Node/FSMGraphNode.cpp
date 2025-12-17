// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/Node/FSMGraphNode.h"

#include "ToolMenu.h"
#include "Graph/FSMGraph.h"
#include "SM/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

FFSMGraphNodeClassData::FFSMGraphNodeClassData(UClass* InClass, const FString& InDeprecatedMessage):
	RuntimeNodeClass(InClass)
{
}

FFSMGraphNodeClassData::FFSMGraphNodeClassData(const FString& InAssetName, const FString& InGeneratedClassPackage,
	const FString& InClassName, UClass* InClass)
{
}

UClass* FFSMGraphNodeClassData::GetClass() const
{
	return RuntimeNodeClass.Get();
}

FString FFSMGraphNodeClassData::ToString() const
{
	if (RuntimeNodeClass.IsValid())
	{
		return RuntimeNodeClass->GetName();
	}
	return "None";
}
#define LOCTEXT_NAMESPACE "FSMGraphNode"

void UFSMGraphNode::PostPasteNode()
{
	Super::PostPasteNode();

	// NodeInstance can be already spawned by paste operation, don't override it

	UClass* NodeClass = ClassData.GetClass();
	if (NodeClass && (RuntimeNode == nullptr))
	{
		UEdGraph* MyGraph = GetGraph();
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
		if (GraphOwner)
		{
			// 该 RuntimeNode 会在其他阶段赋予实际意义
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
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddDecoratorSubMenu, (UEdGraph*)Context->Graph));
	
	Section.AddSubMenu(
		"AddAction",
		LOCTEXT("Label", "Add Action...") ,
		LOCTEXT("ToolTip", "Adds new action as a subnode"),
		FNewToolMenuDelegate::CreateUObject(this, &UFSMGraphNode::CreateAddActionSubMenu, (UEdGraph*)Context->Graph));
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

void UFSMGraphNode::CreateAddDecoratorSubMenu(class UToolMenu* Menu, UEdGraph* Graph) const
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
