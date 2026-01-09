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

bool UFSMGraphNodeBase::IsDeprecated() const
{
	return RuntimeNode == nullptr || Super::IsDeprecated();
}

bool UFSMGraphNodeBase::HasDeprecatedReference() const
{
	return false;
}

FEdGraphNodeDeprecationResponse UFSMGraphNodeBase::GetDeprecationResponse(
	EEdGraphNodeDeprecationType DeprecationType) const
{
	FEdGraphNodeDeprecationResponse Response;

	if (DeprecationType == EEdGraphNodeDeprecationType::NodeTypeIsDeprecated)
	{
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = LOCTEXT("NodeDeprecated_Warning", "Warning: @@ is deprecated; please replace or remove it.");
	}
	else if (DeprecationType == EEdGraphNodeDeprecationType::NodeHasDeprecatedReference)
	{
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = LOCTEXT("NodeDeprecatedReference_Note", "Warning: @@ has a deprecated reference; please replace or remove it.");
	}

	return Response;
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

FLinearColor UFSMGraphNodeBase::GetNodeTitleColor() const
{
	if (HasDeprecatedReference())
	{
		return FLinearColor::Yellow;
	}
	return Super::GetNodeTitleColor();
}

FText UFSMGraphNodeBase::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	FText NodeTitle = RuntimeNode ? FText::FromString(RuntimeNode->GetNodeName()) : Super::GetNodeTitle(TitleType);
	FText NodeTitleSuffix = GetNodeTitleSuffix();
	if (NodeTitleSuffix.IsEmpty())
	{
		return NodeTitle;
	}
	return FText::Format(FTextFormat::FromString("{0} {1}"), NodeTitle, NodeTitleSuffix);
}

FText UFSMGraphNodeBase::GetTooltipText() const
{
	if (IsDeprecated())
	{
		FEdGraphNodeDeprecationResponse DeprecationMessage = GetDeprecationResponse(EEdGraphNodeDeprecationType::NodeTypeIsDeprecated);
		if (DeprecationMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
		{
			return DeprecationMessage.MessageText;
		}
	}

	if (HasDeprecatedReference())
	{
		FEdGraphNodeDeprecationResponse DeprecatedReferenceMessage = GetDeprecationResponse(EEdGraphNodeDeprecationType::NodeHasDeprecatedReference);
		if (DeprecatedReferenceMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
		{
			return DeprecatedReferenceMessage.MessageText;
		}
	}

	FText TooltipDesc;
	if (RuntimeNode->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
	{
		FAssetData AssetData(RuntimeNode->GetClass()->ClassGeneratedBy);
		FString Description = AssetData.GetTagValueRef<FString>(GET_MEMBER_NAME_CHECKED(UBlueprint, BlueprintDescription));
		if (!Description.IsEmpty())
		{
			Description.ReplaceInline(TEXT("\\n"), TEXT("\n"));
			TooltipDesc = FText::FromString(MoveTemp(Description));
		}
	}
	else
	{
		TooltipDesc = RuntimeNode->GetClass()->GetToolTipText();
	}
	return TooltipDesc;
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

FText UFSMGraphNodeBase::GetNodeTitleSuffix() const
{
	FText Suffix = LOCTEXT("NodeTitleSuffix", "");
	if (IsDeprecated())
	{
		Suffix = LOCTEXT("DeprecatedSuffix","(Deprecated)");
	}
	if (HasDeprecatedReference())
	{
		Suffix = LOCTEXT("UnknownReference","(Unknown Reference)");
	}
	return Suffix;
}

#undef LOCTEXT_NAMESPACE
