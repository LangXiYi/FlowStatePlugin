// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"

#include "SM/FlowStateContext.h"

void UFSMRuntimeNode_JumpStart::OnEnter()
{
	Super::OnEnter();

	TrySwitchTo(0);
}

FString UFSMRuntimeNode_JumpStart::GetNodeName() const
{
	return NodeName.Len() ? NodeName : "Default";
}

void UFSMRuntimeNode_JumpTo::OnEnter()
{
	Super::OnEnter();
	check(StateContext)
	check(JumpStartId.IsValid())
	StateContext->GotoScatteredNode(JumpStartId);
}

FString UFSMRuntimeNode_JumpTo::GetNodeName() const
{
	return NodeName.Len() ? NodeName : FSMAsset->GetScatteredNodeName(JumpStartId);
}
