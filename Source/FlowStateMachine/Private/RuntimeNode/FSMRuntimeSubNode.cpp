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
	// 次要节点的 ParentNode 是固定，所以可以直接赋值
	ParentNode = InParentNode;
	Super::InitializeNode(InParentNode, Context);
}

bool UFSMRuntimeSubNode::TrySwitchTo(int Index)
{
	return ParentNode ? ParentNode->TrySwitchTo(Index) : Super::TrySwitchTo(Index);
}

bool UFSMRuntimeSubNode::SwitchToByName(FName Name)
{
	return ParentNode ? ParentNode->SwitchToByName(Name) : Super::SwitchToByName(Name);
}
