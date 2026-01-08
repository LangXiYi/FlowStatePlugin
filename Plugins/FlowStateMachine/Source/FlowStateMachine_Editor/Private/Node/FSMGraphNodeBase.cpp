// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNodeBase.h"

#include "DiffResults.h"
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

void UFSMGraphNodeBase::FindDiffs(class UEdGraphNode* OtherNode, FDiffResults& Results)
{
	Super::FindDiffs(OtherNode, Results);

	if (UFSMGraphNodeBase* OtherGraphNode = Cast<UFSMGraphNodeBase>(OtherNode))
	{
		if (RuntimeNode && OtherGraphNode->RuntimeNode)
		{
			FDiffSingleResult Diff;
			Diff.Diff = EDiffType::NODE_PROPERTY;
			Diff.Node1 = this;
			Diff.Node2 = OtherNode;
			Diff.ToolTip = LOCTEXT("DIF_NodeInstancePropertyToolTip", "A property of the node instance has changed");
			Diff.DisplayColor = FLinearColor(0.25f, 0.71f, 0.85f);

			DiffProperties(RuntimeNode->GetClass(), OtherGraphNode->RuntimeNode->GetClass(), RuntimeNode, OtherGraphNode->RuntimeNode, Results, Diff);
		}
	}
}

void UFSMGraphNodeBase::PrepareForCopying()
{
	if (RuntimeNode)
	{
		// 暂时接管该节点实例的控制权，这样在进行剪切操作时该实例就不会被删除了
		RuntimeNode->Rename(nullptr, this, REN_DontCreateRedirectors | REN_DoNotDirty);
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

void UFSMGraphNodeBase::PostCopyNode()
{
	ResetNodeOwner();
}

void UFSMGraphNodeBase::NodeConnectionListChanged()
{
	Super::NodeConnectionListChanged();
	GetFSMGraph()->UpdateAsset();
}

FText UFSMGraphNodeBase::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return RuntimeNode ? FText::FromString(RuntimeNode->GetNodeName()) : Super::GetNodeTitle(TitleType);
}

void UFSMGraphNodeBase::ResetNodeOwner()
{
	if (RuntimeNode)
	{
		UEdGraph* MyGraph = GetGraph();
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;

		RuntimeNode->Rename(NULL, GraphOwner, REN_DontCreateRedirectors | REN_DoNotDirty);
		RuntimeNode->ClearFlags(RF_Transient);
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

bool UFSMGraphNodeBase::UserBlueprint() const
{
	return RuntimeNode && RuntimeNode->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint);
}

#if WITH_EDITOR

void UFSMGraphNodeBase::PostEditUndo()
{
	Super::PostEditUndo();

	ResetNodeOwner();
}

void UFSMGraphNodeBase::PostEditImport()
{
	Super::PostEditImport();

	ResetNodeOwner();
	if (RuntimeNode)
	{
		InitializeInstance();
	}
}

#endif

FPinConnectionResponse UFSMGraphNodeBase::CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const
{
	return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Connect node"));
}

bool UFSMGraphNodeBase::CheckNodeValidity()
{
	return ErrorMessage.Len() == 0 && RuntimeNode != nullptr;
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