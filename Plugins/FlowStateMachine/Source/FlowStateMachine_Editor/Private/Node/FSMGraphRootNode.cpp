// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphRootNode.h"

#include "Graph/FSMGraph.h"
#include "SM/FlowStateMachine.h"
#include "Utility/FSMEditorCore.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/FlowStateWidgetLayerManager.h"

#define LOCTEXT_NAMESPACE "FSMGraphRootNode"

void UFSMGraphRootNode::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, FStateNodePinHelper::Output_PinCategory, FStateNodePinHelper::Output_DefaultPinName);
}

bool UFSMGraphRootNode::IsDeprecated() const
{
	return false;
}

FText UFSMGraphRootNode::GetTooltipText() const
{
	return LOCTEXT("RootNodeTooltip", "RootNode");
}

FPinConnectionResponse UFSMGraphRootNode::CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const
{
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, TEXT("Connect node"));
}

void UFSMGraphRootNode::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphRootNode, CommonData))
	{
		UFSMGraph* MyGraph = GetFSMGraph();
		if (MyGraph)
		{
			UFlowStateMachine* Asset = MyGraph->GetFSMAsset();
			if (Asset)
			{
				Asset->CommonData = CommonData;
			}
		}
	}
	if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphRootNode, WidgetLayerManagerClass))
	{
		UFSMGraph* MyGraph = GetFSMGraph();
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

void UFSMGraphRootNode::UpdateCommonData()
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
	if (FSMAsset && FSMAsset->CommonData != CommonData)
	{
		FSMAsset->CommonData = CommonData;
		// 通知图表公共数据已经改变
	}
}

void UFSMGraphRootNode::UpdateLayoutWidget()
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
	if (FSMAsset && FSMAsset->WidgetLayerManagerClass != WidgetLayerManagerClass)
	{
		FSMAsset->WidgetLayerManagerClass = WidgetLayerManagerClass;
	}
}

#undef LOCTEXT_NAMESPACE