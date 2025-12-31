// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNodeBase.h"

void UFSMRuntimeNodeBase::InitializeFromAsset(UFlowStateMachine* Asset)
{
	FSMAsset = Asset;
}

class UWorld* UFSMRuntimeNodeBase::GetWorld() const
{
	if (GetOuter() == nullptr)
	{
		return nullptr;
	}

	// Special case for behavior tree nodes in the editor
	if (Cast<UPackage>(GetOuter()) != nullptr)
	{
		// GetOuter should return a UPackage and its Outer is a UWorld
		return Cast<UWorld>(GetOuter()->GetOuter());
	}

	// In all other cases...
	return GetOuter()->GetWorld();
}

FString UFSMRuntimeNodeBase::GetNodeName() const
{
	// TODO::后续可以改为其他名称，而不是对象的名称
	return NodeName.Len() ? NodeName : GetName();
}
