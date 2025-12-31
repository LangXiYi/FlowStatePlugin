// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FSMRuntimeNode.h"

#include "SM/FSMRuntimeSubNode.h"

void UFSMRuntimeNode::InitializeNode(UFSMRuntimeNodeBase* InParentNode, uint16 InExecutionIndex, uint16 InMemoryOffset, uint8 InTreeDepth)
{
	ParentNode = InParentNode;
	ExecutionIndex = InExecutionIndex;
	MemoryOffset = InMemoryOffset;
	TreeDepth = InTreeDepth;
}

#if WITH_EDITOR



#endif

