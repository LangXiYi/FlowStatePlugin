// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNodeBase.h"

#include "Graph/FSMGraph.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FSMGraphNodeBase"

void UFSMGraphNodeBase::PostPasteNode()
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
			RuntimeNode = NewObject<UFSMRuntimeNodeBase>(GraphOwner, NodeClass);
			// “transactional”这个词确实与编辑器的撤销/重做系统有关。
			RuntimeNode->SetFlags(RF_Transactional);
			InitializeInstance();
		}
	}
}

void UFSMGraphNodeBase::PostPlacedNewNode()
{
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
			RuntimeNode = NewObject<UFSMRuntimeNodeBase>(GraphOwner, NodeClass);
			// “transactional”这个词确实与编辑器的撤销/重做系统有关。
			RuntimeNode->SetFlags(RF_Transactional);
			InitializeInstance();
		}
	}
}

void UFSMGraphNodeBase::AutowireNewNode(UEdGraphPin* FromPin)
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

void UFSMGraphNodeBase::InitializeInstance()
{
	UFlowStateMachine* FSMAsset = RuntimeNode ? Cast<UFlowStateMachine>(RuntimeNode->GetOuter()) : nullptr;
	if (RuntimeNode && FSMAsset)
	{
		RuntimeNode->InitializeFromAsset(FSMAsset);
		RuntimeNode->OnNodeCreated();
	}
}

void UFSMGraphNodeBase::AddSubNode(UFSMGraphNodeBase* SubNode, class UEdGraph* ParentGraph)
{
	if (SubNode ==nullptr)
	{
		checkNoEntry()
		return;
	}
	
	// const FScopedTransaction Transaction(LOCTEXT("AddNode", "Add Node"));
	ParentGraph->Modify();
	Modify();

	SubNode->SetFlags(RF_Transactional);

	// 设置节点 Outer 为 Graph 确保其不会被回收
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

void UFSMGraphNodeBase::RemoveSubNode(UFSMGraphNodeBase* SubNode)
{
	SubNodes.RemoveSingle(SubNode);
	Modify();

	OnSubNodeRemoved(SubNode);
}

void UFSMGraphNodeBase::RemoveAllSubNode()
{
	SubNodes.Empty();
}

void UFSMGraphNodeBase::PostCopyNode()
{
	ResetNodeOwner();
}

void UFSMGraphNodeBase::ResetNodeOwner()
{
	if (RuntimeNode)
	{
		UEdGraph* MyGraph = GetGraph();
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;

		RuntimeNode->Rename(NULL, GraphOwner, REN_DontCreateRedirectors | REN_DoNotDirty);
		RuntimeNode->ClearFlags(RF_Transient);

		for (auto& SubNode : SubNodes)
		{
			SubNode->ResetNodeOwner();
		}
	}
}

void UFSMGraphNodeBase::UpdateNodeClassData()
{
	if (RuntimeNode)
	{
		UpdateNodeClassDataFrom(RuntimeNode->GetClass(), ClassData);
		ErrorMessage = ClassData.GetDeprecatedMessage();
	}
}

void UFSMGraphNodeBase::UpdateNodeClassDataFrom(UClass* InstanceClass, FGraphNodeClassData& UpdatedData)
{
	if (InstanceClass)
	{
		UBlueprint* BPOwner = Cast<UBlueprint>(InstanceClass->ClassGeneratedBy);
		if (BPOwner)
		{
			UpdatedData = FGraphNodeClassData(BPOwner->GetName(), BPOwner->GetOutermost()->GetName(), InstanceClass->GetName(), InstanceClass);
		}
		else
		{
			UpdatedData = FGraphNodeClassData(InstanceClass, FGraphNodeClassHelper::GetDeprecationMessage(InstanceClass));
		}
	}
}

UFSMGraph* UFSMGraphNodeBase::GetFSMGraph() const
{
	return CastChecked<UFSMGraph>(GetGraph());
}


UEdGraphPin* UFSMGraphNodeBase::GetInputPin() const
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

TArray<UEdGraphPin*> UFSMGraphNodeBase::GetOutputPins() const
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

#undef LOCTEXT_NAMESPACE