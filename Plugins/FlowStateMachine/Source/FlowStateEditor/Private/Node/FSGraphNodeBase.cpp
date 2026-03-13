// Fill out your copyright notice in the Description page of Project Settings.

#include "Node/FSGraphNodeBase.h"

#include "DiffResults.h"
#include "Graph/FlowStateGraph.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "SM/FlowStateMachine.h"
#include "Utility/FlowStateEditorHelper.h"

#define LOCTEXT_NAMESPACE "FSMGraphNodeBase"

USING_FLOWSTATE_EDITORHELPER

void UFSGraphNodeBase::PostPasteNode()
{
    Super::PostPasteNode();

    // NodeInstance can be already spawned by paste operation, don't override it

    UClass* NodeClass = ClassData.GetClass();
    if (NodeClass && (NodeInstance == nullptr))
    {
        UEdGraph* MyGraph = GetGraph();
        // Graph 的 Outer 为 FlowStateMachine
        UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
        if (GraphOwner)
        {
            // 该 NodeInstance 会在保存图表时赋予实际意义
            NodeInstance = NewObject<UFSMNodeInstanceBase>(GraphOwner, NodeClass);
            // “transactional”这个词确实与编辑器的撤销/重做系统有关。
            NodeInstance->SetFlags(RF_Transactional);
            InitializeInstance();
        }
    }
}

void UFSGraphNodeBase::PostPlacedNewNode()
{
    // NodeInstance can be already spawned by paste operation, don't override it

    UClass* NodeClass = ClassData.GetClass();
    if (NodeClass && (NodeInstance == nullptr))
    {
        UEdGraph* MyGraph = GetGraph();
        // Graph 的 Outer 为 FlowStateMachine
        UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
        if (GraphOwner)
        {
            // 该 NodeInstance 会在保存图表时赋予实际意义
            NodeInstance = NewObject<UFSMNodeInstanceBase>(GraphOwner, NodeClass);
            // “transactional”这个词确实与编辑器的撤销/重做系统有关。
            NodeInstance->SetFlags(RF_Transactional);
            InitializeInstance();
        }
    }
}

void UFSGraphNodeBase::FindDiffs(class UEdGraphNode* OtherNode, FDiffResults& Results)
{
    Super::FindDiffs(OtherNode, Results);

    if (UFSGraphNodeBase* OtherGraphNode = Cast<UFSGraphNodeBase>(OtherNode))
    {
        if (NodeInstance && OtherGraphNode->NodeInstance)
        {
            FDiffSingleResult Diff;
            Diff.Diff = EDiffType::NODE_PROPERTY;
            Diff.Node1 = this;
            Diff.Node2 = OtherNode;
            Diff.ToolTip = LOCTEXT("DIF_NodeInstancePropertyToolTip", "A property of the node instance has changed");
            Diff.DisplayColor = FLinearColor(0.25f, 0.71f, 0.85f);

            DiffProperties(NodeInstance->GetClass(), OtherGraphNode->NodeInstance->GetClass(), NodeInstance,
                           OtherGraphNode->NodeInstance, Results, Diff);
        }
    }
}

bool UFSGraphNodeBase::IsDeprecated() const
{
    return NodeInstance == nullptr || Super::IsDeprecated();
}

bool UFSGraphNodeBase::HasDeprecatedReference() const
{
    return false;
}

FEdGraphNodeDeprecationResponse UFSGraphNodeBase::GetDeprecationResponse(
    EEdGraphNodeDeprecationType DeprecationType) const
{
    FEdGraphNodeDeprecationResponse Response;

    if (DeprecationType == EEdGraphNodeDeprecationType::NodeTypeIsDeprecated)
    {
        Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
        Response.MessageText = LOCTEXT("NodeDeprecated_Warning",
                                       "Warning: @@ is deprecated; please replace or remove it.");
    }
    else if (DeprecationType == EEdGraphNodeDeprecationType::NodeHasDeprecatedReference)
    {
        Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
        Response.MessageText = LOCTEXT("NodeDeprecatedReference_Note",
                                       "Warning: @@ has a deprecated reference; please replace or remove it.");
    }

    return Response;
}

void UFSGraphNodeBase::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    RefreshStateNode(false);
}

void UFSGraphNodeBase::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
    Super::PostEditChangeChainProperty(PropertyChangedEvent);
    RefreshStateNode(false);
}

void UFSGraphNodeBase::PinConnectionListChanged(UEdGraphPin* Pin)
{
    if (Pin->bOrphanedPin && Pin->LinkedTo.Num() == 0)
    {
        RemovePin(Pin);
        MarkNodeRequiresSynchronization(false);
    }
    Super::PinConnectionListChanged(Pin);
}

void UFSGraphNodeBase::RefreshStateNode(bool bIsAutoRemoveOrphanedNode)
{
    if (NodeInstance == nullptr)
    {
        return;
    }

    bool bIsDirty = false;
    TArray<FStatePinInfo> StatePinInfos;
    TMap<FName, FStatePinInfo> ValidPinNames;

    // 获取所有状态引脚的信息
    NodeInstance->GetStatePinInfos(StatePinInfos);
    // 移除无效数据
    for (int i = StatePinInfos.Num() - 1; i >= 0; --i)
    {
        const FStatePinInfo& StatePinInfo = StatePinInfos[i];
        if (!StatePinInfo.IsValid())
        {
            StatePinInfos.RemoveAt(i);
            continue;
        }
        ValidPinNames.Add(StatePinInfo.PinName, StatePinInfo);

        // 添加引脚
        UEdGraphPin* FoundPins = FindPin(StatePinInfo.PinName);
        if (FoundPins == nullptr)
        {
            CreatePin(EGPD_Output, StatePinInfo.PinCategory, StatePinInfo.PinName);
            bIsDirty = true;
        }
    }

    for (int i = Pins.Num() - 1; i >= 0; --i)
    {
        UEdGraphPin* NodePin = Pins[i];
        if (NodePin->Direction == EGPD_Output && NodePin->PinName != FPinHelper::Output_DefaultPinName && !ValidPinNames
            .Contains(NodePin->PinName))
        {
            if (NodePin->bOrphanedPin && bIsAutoRemoveOrphanedNode)
            {
                // 已经标记为过期的引脚则直接移除
                RemovePin(NodePin);
                bIsDirty = true;
            }
            else
            {
                // 标记该引脚为过期的
                NodePin->bOrphanedPin = true;
            }
        }
        else
        {
            // 取消过期标记
            NodePin->bOrphanedPin = false;
        }
    }
    if (bIsDirty)
    {
        MarkNodeRequiresSynchronization(false);
    }
}

void UFSGraphNodeBase::ReconstructNode()
{
    RefreshStateNode(false);
}

void UFSGraphNodeBase::PrepareForCopying()
{
    if (NodeInstance)
    {
        // 暂时接管该节点实例的控制权，这样在进行剪切操作时该实例就不会被删除了
        NodeInstance->Rename(nullptr, this, REN_DontCreateRedirectors | REN_DoNotDirty);
    }
}

void UFSGraphNodeBase::AutowireNewNode(UEdGraphPin* FromPin)
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

void UFSGraphNodeBase::InitializeInstance()
{
    UFlowStateMachine* FSMAsset = NodeInstance ? Cast<UFlowStateMachine>(NodeInstance->GetOuter()) : nullptr;
    if (NodeInstance && FSMAsset)
    {
        NodeInstance->InitializeFromAsset(FSMAsset);
        // NodeInstance->OnNodeCreated();
    }
}

void UFSGraphNodeBase::PostCopyNode()
{
    ResetNodeOwner();
}

void UFSGraphNodeBase::NodeConnectionListChanged()
{
    Super::NodeConnectionListChanged();
    GetFSMGraph()->UpdateAsset();
}

FLinearColor UFSGraphNodeBase::GetNodeTitleColor() const
{
    if (HasDeprecatedReference())
    {
        return FLinearColor::Yellow;
    }
    return Super::GetNodeTitleColor();
}

FText UFSGraphNodeBase::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
    FText NodeTitle = NodeInstance ? FText::FromString(NodeInstance->GetNodeName()) : Super::GetNodeTitle(TitleType);
    FText NodeTitleSuffix = GetNodeTitleSuffix();
    if (NodeTitleSuffix.IsEmpty())
    {
        return FText::Format(FTextFormat::FromString(GetNodeTitleFormatString()), NodeTitle);
    }
    return FText::Format(FTextFormat::FromString(GetNodeTitleFormatString() + "{1}"), NodeTitle, NodeTitleSuffix);
}

FString UFSGraphNodeBase::GetNodeTitleFormatString() const
{
    return "{0}";
}

FText UFSGraphNodeBase::GetTooltipText() const
{
    if (IsDeprecated())
    {
        FEdGraphNodeDeprecationResponse DeprecationMessage = GetDeprecationResponse(
            EEdGraphNodeDeprecationType::NodeTypeIsDeprecated);
        if (DeprecationMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
        {
            return DeprecationMessage.MessageText;
        }
    }

    if (HasDeprecatedReference())
    {
        FEdGraphNodeDeprecationResponse DeprecatedReferenceMessage = GetDeprecationResponse(
            EEdGraphNodeDeprecationType::NodeHasDeprecatedReference);
        if (DeprecatedReferenceMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
        {
            return DeprecatedReferenceMessage.MessageText;
        }
    }

    FText TooltipDesc;
    if (NodeInstance->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
    {
        FAssetData AssetData(NodeInstance->GetClass()->ClassGeneratedBy);
        FString Description = AssetData.GetTagValueRef<FString>(
            GET_MEMBER_NAME_CHECKED(UBlueprint, BlueprintDescription));
        if (!Description.IsEmpty())
        {
            Description.ReplaceInline(TEXT("\\n"), TEXT("\n"));
            TooltipDesc = FText::FromString(MoveTemp(Description));
        }
    }
    else
    {
        TooltipDesc = NodeInstance->GetClass()->GetToolTipText();
    }
    return TooltipDesc;
}

void UFSGraphNodeBase::GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const
{
    Super::GetPinHoverText(Pin, HoverTextOut);
}

void UFSGraphNodeBase::ResetNodeOwner()
{
    if (NodeInstance)
    {
        UEdGraph* MyGraph = GetGraph();
        UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;

        NodeInstance->Rename(nullptr, GraphOwner, REN_DontCreateRedirectors | REN_DoNotDirty);
        NodeInstance->ClearFlags(RF_Transient);
    }
}

void UFSGraphNodeBase::UpdateNodeClassData()
{
    if (NodeInstance)
    {
        UpdateNodeClassDataFrom(NodeInstance->GetClass(), ClassData);
        ErrorMessage = ClassData.GetDeprecatedMessage();
    }
}

void UFSGraphNodeBase::UpdateNodeClassDataFrom(UClass* InstanceClass, FGraphNodeClassData& UpdatedData)
{
    if (InstanceClass)
    {
        UBlueprint* BPOwner = Cast<UBlueprint>(InstanceClass->ClassGeneratedBy);
        if (BPOwner)
        {
            UpdatedData = FGraphNodeClassData(BPOwner->GetName(), BPOwner->GetOutermost()->GetName(),
                                              InstanceClass->GetName(), InstanceClass);
        }
        else
        {
            UpdatedData = FGraphNodeClassData(InstanceClass,
                                              FGraphNodeClassHelper::GetDeprecationMessage(InstanceClass));
        }
    }
}

UFlowStateGraph* UFSGraphNodeBase::GetFSMGraph() const
{
    return CastChecked<UFlowStateGraph>(GetGraph());
}

bool UFSGraphNodeBase::UserBlueprint() const
{
    return NodeInstance && NodeInstance->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint);
}

void UFSGraphNodeBase::MarkNodeRequiresSynchronization(bool bIsUpdateAsset, const FString& Reason)
{
    if (bIsUpdateAsset)
    {
        GetFSMGraph()->UpdateAsset(Reason);
    }
    GetGraph()->NotifyGraphChanged();
}

#if WITH_EDITOR

void UFSGraphNodeBase::PostEditUndo()
{
    Super::PostEditUndo();

    ResetNodeOwner();
}

void UFSGraphNodeBase::PostEditImport()
{
    Super::PostEditImport();

    ResetNodeOwner();
    if (NodeInstance)
    {
        InitializeInstance();
    }
}

#endif

FPinConnectionResponse UFSGraphNodeBase::CheckPinConnection(const UFSGraphNodeBase* OtherNode,
                                                            EEdGraphPinDirection FromDirection) const
{
    if (FromDirection == EGPD_Output)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, TEXT("Connect node Break A"));
    }
    return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, TEXT("Connect node Break B"));
}

UEdGraphPin* UFSGraphNodeBase::GetInputPin() const
{
    TArray<UEdGraphPin*> OutPins;
    for (UEdGraphPin* Pin : Pins)
    {
        if (Pin && Pin->Direction == EGPD_Input)
        {
            return Pin;
        }
    }
    return nullptr;
}

TArray<UEdGraphPin*> UFSGraphNodeBase::GetOutputPins() const
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

FText UFSGraphNodeBase::GetNodeTitleSuffix() const
{
    FText Suffix = LOCTEXT("NodeTitleSuffix", "");
    if (IsDeprecated())
    {
        Suffix = LOCTEXT("DeprecatedSuffix", "(Deprecated)");
    }
    if (HasDeprecatedReference())
    {
        Suffix = LOCTEXT("UnknownReference", "(Unknown Reference)");
    }
    return Suffix;
}

#undef LOCTEXT_NAMESPACE
