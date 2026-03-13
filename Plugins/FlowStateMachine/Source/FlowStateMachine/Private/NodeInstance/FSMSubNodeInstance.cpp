// Fill out your copyright notice in the Description page of Project Settings.


#include "NodeInstance/FSMSubNodeInstance.h"

#include "NodeInstance/FSMNodeInstance.h"


UWorld* UFSMSubNodeInstance::GetWorld() const
{
    if (ParentNode)
    {
        return ParentNode->GetWorld();
    }
    return Super::GetWorld();
}

void UFSMSubNodeInstance::InitializeNode(UFSMNodeInstanceBase* InParentNode, UFlowStateContext* Context)
{
    // 次要节点的 ParentNode 是固定，所以可以直接赋值
    ParentNode = InParentNode;
    Super::InitializeNode(InParentNode, Context);
}

bool UFSMSubNodeInstance::TrySwitchTo(int Index)
{
    return ParentNode ? ParentNode->TrySwitchTo(Index) : Super::TrySwitchTo(Index);
}

bool UFSMSubNodeInstance::SwitchToByName(FName Name)
{
    return ParentNode ? ParentNode->SwitchToByName(Name) : Super::SwitchToByName(Name);
}
