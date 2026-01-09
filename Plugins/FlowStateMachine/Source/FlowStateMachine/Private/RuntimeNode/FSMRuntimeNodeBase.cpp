// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNodeBase.h"

void UFSMRuntimeNodeBase::InitializeFromAsset(UFlowStateMachine* Asset)
{
	FSMAsset = Asset;
}

void UFSMRuntimeNodeBase::InitializeNode(UFSMRuntimeNodeBase* InParentNode)
{
	if (InParentNode)
	{
		AllParentNodes.AddUnique(InParentNode);
	}
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
	return GetOuter()->GetWorld();
}

FString UFSMRuntimeNodeBase::GetNodeName() const
{
	const auto& GetShortTypeName = [](const UObject* Obj)
	{
		if (Obj->GetClass()->HasAnyClassFlags(CLASS_CompiledFromBlueprint))
		{
			return Obj->GetClass()->GetName().LeftChop(2);
		}

		FString TypeDesc = Obj->GetClass()->GetName();
		const int32 ShortNameIdx = TypeDesc.Find(TEXT("_"), ESearchCase::CaseSensitive);
		if (ShortNameIdx != INDEX_NONE)
		{
			TypeDesc.MidInline(ShortNameIdx + 1, MAX_int32, false);
		}
		return TypeDesc;
	};
	return NodeName.Len() ? NodeName : GetShortTypeName(this);
}
