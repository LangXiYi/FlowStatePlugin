// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FSMRuntimeNode.h"

void UFSMRuntimeNode::InitializeFromAsset(UFlowStateMachine& Asset)
{
	FSMAsset = &Asset;
}

void UFSMRuntimeNode::InitializeNode(UFSMRuntimeNode* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth)
{
	ParentNode = InParentNode;
	ExecutionIndex = InExecutionIndex;
	MemoryOffset = InMemoryOffset;
	TreeDepth = InTreeDepth;
}

FString UFSMRuntimeNode::GetNodeName() const
{
	// TODO::后续可以改为其他名称，而不是对象的名称
	return NodeName.Len() ? NodeName : GetName();
}

