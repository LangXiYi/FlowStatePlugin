// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"

#include "SM/FlowStateContext.h"

void UFSMRuntimeNode_JumpStart::OnEnter()
{
	Super::OnEnter();

	TrySwitchTo(0);
}

void UFSMRuntimeNode_JumpTo::OnEnter()
{
	Super::OnEnter();


	check(StateContext)
	StateContext->GotoScatteredNode(JumpStartId);
}
