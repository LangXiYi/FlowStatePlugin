// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNode_Root.h"

#include "Graph/FSMGraph.h"
#include "SM/FlowStateMachine.h"
#include "Widgets/FlowStateLayoutWidget.h"


void UFSMGraphNode_Root::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Execute");
}

void UFSMGraphNode_Root::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphNode_Root, CommonData))
	{
		
	}
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UFSMGraphNode_Root, LayoutWidget))
	{
		
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
	if (FSMAsset && FSMAsset->LayoutWidget != LayoutWidget)
	{
		FSMAsset->LayoutWidget = LayoutWidget;
	}
}
