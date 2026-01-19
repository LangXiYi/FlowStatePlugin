// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNode_Root.h"

#include "Graph/FSMGraph.h"
#include "SM/FlowStateMachine.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/FlowStateWidgetLayerManager.h"

#define LOCTEXT_NAMESPACE "FSMGraphNode_Root"

void UFSMGraphNode_Root::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Execute");
}

bool UFSMGraphNode_Root::IsDeprecated() const
{
	return false;
}

FText UFSMGraphNode_Root::GetTooltipText() const
{
	return LOCTEXT("RootNodeTooltip", "RootNode");
}

FPinConnectionResponse UFSMGraphNode_Root::CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const
{
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, TEXT("Connect node"));
}

void UFSMGraphNode_Root::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphNode_Root, CommonData))
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
	if (PropertyChangedEvent.MemberProperty && PropertyChangedEvent.MemberProperty->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphNode_Root, WidgetLayerManagerClass))
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

void UFSMGraphNode_Root::UpdateCommonData()
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
	if (FSMAsset && FSMAsset->CommonData != CommonData)
	{
		FSMAsset->CommonData = CommonData;
		// 通知图表公共数据已经改变
	}
}

void UFSMGraphNode_Root::UpdateLayoutWidget()
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetFSMGraph()->GetOuter());
	if (FSMAsset && FSMAsset->WidgetLayerManagerClass != WidgetLayerManagerClass)
	{
		FSMAsset->WidgetLayerManagerClass = WidgetLayerManagerClass;
	}
}

#undef LOCTEXT_NAMESPACE