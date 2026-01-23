// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateBase.h"

void UFlowStateBase::Tick(float DeltaTime)
{
	Private_DeltaTime = DeltaTime;
	OnTick(DeltaTime); 
}

void UFlowStateBase::OnEnter()
{
	Super::OnEnter();
	NativeOnEnter();
}

void UFlowStateBase::OnInitialize()
{
	Super::OnInitialize();
	NativeOnInitialize(StateContext);
}

void UFlowStateBase::OnExit()
{
	NativeOnExit();
	Super::OnExit();
}