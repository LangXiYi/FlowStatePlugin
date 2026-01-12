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

void UFSMRuntimeSubNode::InitializeNode(UFSMRuntimeNodeBase* InParentNode, UFlowStateContext* Context)
{
	Super::InitializeNode(InParentNode, Context);
	// 次要节点的 ParentNode 是固定，所以可以直接赋值
	ParentNode = InParentNode;
}
