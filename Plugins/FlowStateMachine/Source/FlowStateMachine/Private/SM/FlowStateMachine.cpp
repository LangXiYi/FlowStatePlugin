// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateMachine.h"

#include "SM/Composites/Composite_Jump.h"

FString UFlowStateMachine::GetScatteredNodeName(FGuid InScatteredNodeID) const
{
    for (UFSMNodeInstance* ScatteredNode : ScatteredNodes)
    {
        if (auto JumpStartNode = Cast<UCNodeIns_JumpStart>(ScatteredNode))
        {
            if (JumpStartNode->JumpStartId == InScatteredNodeID)
            {
                return JumpStartNode->GetNodeName();
            }
        }
    }
    return "Default";
}
