// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphSubNode.h"

#include "Graph/FSMGraph.h"
#include "Node/FSMGraphNode.h"

#define LOCTEXT_NAMESPACE "FSMGraphSubNode"



#undef LOCTEXT_NAMESPACE

void UFSMGraphSubNode::DestroyNode()
{
	Super::DestroyNode();
	if (UFSMGraphNode* FSMParentNode = Cast<UFSMGraphNode>(ParentNode))
	{
		FSMParentNode->RemoveSubNode(this);
	}
}

#if WITH_EDITOR

void UFSMGraphSubNode::PostEditUndo()
{
	Super::PostEditUndo();

	if (UFSMGraphNode* FSMParentNode = Cast<UFSMGraphNode>(ParentNode))
	{
		FSMParentNode->SubNodes.AddUnique(this);

		if (UFSMGraphSubNode_Condition* ConditionNode = Cast<UFSMGraphSubNode_Condition>(this))
		{
			FSMParentNode->Conditions.AddUnique(ConditionNode);
		}
		else if (UFSMGraphSubNode_Service* ServiceNode = Cast<UFSMGraphSubNode_Service>(this))
		{
			FSMParentNode->Services.AddUnique(ServiceNode);
		}
		else if (UFSMGraphSubNode_Action* ActionNode = Cast<UFSMGraphSubNode_Action>(this))
		{
			FSMParentNode->Actions.AddUnique(ActionNode);
		}
	}
}

#endif