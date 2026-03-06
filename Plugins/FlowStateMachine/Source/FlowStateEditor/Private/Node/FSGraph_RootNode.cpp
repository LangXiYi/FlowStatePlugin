// Fill out your copyright notice in the Description page of Project Settings.

#include "Node/FSGraph_RootNode.h"

#include "Graph/FlowStateGraph.h"
#include "SM/FlowStateMachine.h"
#include "Node/Slates/SFSGraph_RootNode.h"
#include "Utility/FlowStateEditorHelper.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/FlowStateWidgetLayerManager.h"

#define LOCTEXT_NAMESPACE "FSMGraphRootNode"

USING_FLOWSTATE_EDITORHELPER

void UFSGraph_RootNode::AllocateDefaultPins()
{
    Super::AllocateDefaultPins();
    CreatePin(EGPD_Output, FPinHelper::Output_PinCategory, FPinHelper::Output_DefaultPinName);
}

bool UFSGraph_RootNode::IsDeprecated() const
{
    return false;
}

FText UFSGraph_RootNode::GetTooltipText() const
{
    return LOCTEXT("RootNodeTooltip", "RootNode");
}
TSharedPtr<SGraphNode> UFSGraph_RootNode::CreateVisualWidget()
{
    return SNew(SFSGraph_RootNode, this);;
}

FPinConnectionResponse UFSGraph_RootNode::CheckPinConnection(const UFSGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const
{
    return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, TEXT("Connect node"));
}

void UFSGraph_RootNode::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);
    if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSGraph_RootNode, CommonData))
    {
        UFlowStateGraph* MyGraph = GetFSMGraph();
        if (MyGraph)
        {
            UFlowStateMachine* Asset = MyGraph->GetFSMAsset();
            if (Asset)
            {
                Asset->CommonData = CommonData;
            }
        }
    }
    if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSGraph_RootNode, WidgetLayerManagerClass))
    {
        UFlowStateGraph* MyGraph = GetFSMGraph();
        if (MyGraph)
        {
            UFlowStateMachine* Asset = MyGraph->GetFSMAsset();
            if (Asset)
            {
                Asset->WidgetLayerManagerClass = WidgetLayerManagerClass;
            }
        }
    }
}

void UFSGraph_RootNode::UpdateCommonData()
{
    UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
    if (FSMAsset && FSMAsset->CommonData != CommonData)
    {
        FSMAsset->CommonData = CommonData;
        // 通知图表公共数据已经改变
    }
}

void UFSGraph_RootNode::UpdateLayoutWidget()
{
    UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
    if (FSMAsset && FSMAsset->WidgetLayerManagerClass != WidgetLayerManagerClass)
    {
        FSMAsset->WidgetLayerManagerClass = WidgetLayerManagerClass;
    }
}

#undef LOCTEXT_NAMESPACE