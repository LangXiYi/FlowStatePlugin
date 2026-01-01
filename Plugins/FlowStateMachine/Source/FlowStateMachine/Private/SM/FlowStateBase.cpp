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

void UFlowStateBase::OnInitWidget(UFlowStateLayoutWidget* Layout)
{
	Super::OnInitWidget(Layout);
	NativeOnInitWidget(Layout);
}

void UFlowStateBase::OnInitialize(UFlowStateContext* InContext)
{
	Super::OnInitialize(InContext);
	NativeOnInitialize(InContext);
}

void UFlowStateBase::OnExit()
{
	Super::OnExit();
	NativeOnExit();
}