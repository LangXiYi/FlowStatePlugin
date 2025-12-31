// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNode.h"

#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"

void UFSMRuntimeNode::InitializeNode(UFSMRuntimeNode* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth)
{
	ParentNode = InParentNode;
	ExecutionIndex = InExecutionIndex;
	MemoryOffset = InMemoryOffset;
	TreeDepth = InTreeDepth;
}

#if WITH_EDITOR

void UFSMRuntimeNode::AddSubNode(UFSMRuntimeNodeBase* InSubNode)
{
	if (UFSMRuntimeSubNode_Action* ActionNode = Cast<UFSMRuntimeSubNode_Action>(InSubNode))
	{
		Actions.Add(ActionNode);
	}
	else if (UFSMRuntimeSubNode_Service* ServiceNode = Cast<UFSMRuntimeSubNode_Service>(InSubNode))
	{
		Services.Add(ServiceNode);
	}
	else if (UFSMRuntimeSubNode_Condition* ConditionNode = Cast<UFSMRuntimeSubNode_Condition>(InSubNode))
	{
		Conditions.Add(ConditionNode);
	}
	else
	{
		checkNoEntry();
	}
}

#endif

