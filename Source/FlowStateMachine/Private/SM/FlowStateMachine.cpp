// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateMachine.h"

FString UFlowStateMachine::GetScatteredNodeName(FGuid InScatteredNodeID) const
{
	for (UFSMRuntimeNode* ScatteredNode : ScatteredNodes)
	{
		if (auto JumpStartNode = Cast<UFSMRuntimeNode_JumpStart>(ScatteredNode))
		{
			if (JumpStartNode->JumpStartId == InScatteredNodeID)
			{
				return JumpStartNode->GetNodeName();
			}
		}
	}
	return "Default";
}
