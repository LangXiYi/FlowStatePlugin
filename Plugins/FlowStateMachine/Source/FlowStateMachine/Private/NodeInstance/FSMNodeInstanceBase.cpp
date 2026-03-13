// Fill out your copyright notice in the Description page of Project Settings.


#include "NodeInstance/FSMNodeInstanceBase.h"

#include "SM/FlowStateContext.h"

void UFSMNodeInstanceBase::InitializeFromAsset(UFlowStateMachine* Asset)
{
    FSMAsset = Asset;
}

void UFSMNodeInstanceBase::OnPreprocessing()
{
    // bIsTemplateInstance = false;
}

void UFSMNodeInstanceBase::InitializeNode(UFSMNodeInstanceBase* InParentNode, UFlowStateContext* Context)
{
    if (InParentNode)
    {
        AllParentNodes.AddUnique(InParentNode);
    }
    StateContext = Context;
    OnPreprocessing();
}

bool UFSMNodeInstanceBase::TrySwitchTo(int Index)
{
    checkNoEntry()
    return false;
}

bool UFSMNodeInstanceBase::SwitchToByName(FName Name)
{
    checkNoEntry()
    return false;
}

class UWorld* UFSMNodeInstanceBase::GetWorld() const
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

FString UFSMNodeInstanceBase::GetNodeName() const
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

TSharedPtr<FSMGC> UFSMNodeInstanceBase::GetGCManager() const
{
    return StateContext ? StateContext->GetGCManager() : nullptr;
}

void UFSMNodeInstanceBase::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
    Execute_GetStatePinInfos(this, PinInfos);
    for (UFSMNodeInstanceBase* SubNode : SubNodes)
    {
        if (SubNode == nullptr) { continue; }
        SubNode->GetStatePinInfos(PinInfos);
    }
}
