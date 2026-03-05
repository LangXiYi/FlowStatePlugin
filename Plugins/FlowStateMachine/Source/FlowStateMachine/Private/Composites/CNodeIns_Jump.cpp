// Fill out your copyright notice in the Description page of Project Settings.


#include "Composites/CNodeIns_Jump.h"

#include "SM/FlowStateContext.h"

void UCNodeIns_JumpStart::OnEnter()
{
	Super::OnEnter();

	TrySwitchTo(0);
}

FString UCNodeIns_JumpStart::GetNodeName() const
{
	return NodeName.Len() ? NodeName : "Default";
}

void UCNodeIns_JumpTo::OnEnter()
{
	Super::OnEnter();
	check(StateContext)
	check(JumpStartId.IsValid())
	StateContext->GotoScatteredNode(JumpStartId);
}

FString UCNodeIns_JumpTo::GetNodeName() const
{
	return NodeName.Len() ? NodeName : FSMAsset->GetScatteredNodeName(JumpStartId);
}
