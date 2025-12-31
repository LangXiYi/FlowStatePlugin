// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FSMRuntimeNodeBase.h"

void UFSMRuntimeNodeBase::InitializeFromAsset(UFlowStateMachine& Asset)
{
	FSMAsset = &Asset;
}



FString UFSMRuntimeNodeBase::GetNodeName() const
{
	// TODO::后续可以改为其他名称，而不是对象的名称
	return NodeName.Len() ? NodeName : GetName();
}
