// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeSubNode.h"

#include "RuntimeNode/FSMRuntimeNode.h"


UWorld* UFSMRuntimeSubNode::GetWorld() const
{
	if (ParentNode)
	{
		return ParentNode->GetWorld();
	}
	return Super::GetWorld();
}

UFlowStateContext* UFSMRuntimeSubNode::GetContext() const
{
	if (ParentNode)
	{
		UFSMRuntimeNode* FSMParentNode = Cast<UFSMRuntimeNode>(ParentNode);
		if (FSMParentNode)
		{
			return FSMParentNode->GetContext();
		}
	}
	return nullptr;
}

void UFSMRuntimeSubNode::InitializeNode(UFSMRuntimeNodeBase* InParentNode)
{
	Super::InitializeNode(InParentNode);
	// 次要节点的 ParentNode 是固定，所以可以直接赋值
	ParentNode = InParentNode;
}
