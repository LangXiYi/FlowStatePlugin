// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/Node/FSMGraphNode.h"

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

const FString& FFSMGraphNodeClassData::ToString() const
{
	if (RuntimeNodeClass.IsValid())
	{
		return RuntimeNodeClass->GetName();
	}
	return "None";
}

void UFSMGraphNode::PostPasteNode()
{
	Super::PostPasteNode();

	// NodeInstance can be already spawned by paste operation, don't override it

	UClass* NodeClass = ClassData.GetClass();
	if (NodeClass && (NodeInstance == nullptr))
	{
		UEdGraph* MyGraph = GetGraph();
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
		if (GraphOwner)
		{
			NodeInstance = NewObject<UFSMRuntimeNode>(GraphOwner, NodeClass);
			NodeInstance->SetFlags(RF_Transactional);
			InitializeInstance();
		}
	}
}

void UFSMGraphNode::InitializeInstance()
{
	UFlowStateMachine* FSMAsset = NodeInstance ? Cast<UFlowStateMachine>(NodeInstance->GetOuter()) : nullptr;
	if (NodeInstance && FSMAsset)
	{
		NodeInstance->InitializeFromAsset(*FSMAsset);
		NodeInstance->InitializeNode(NULL, MAX_uint16, 0, 0);
		NodeInstance->OnNodeCreated();
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
