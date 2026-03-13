// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/Conditions/Conditions_AssetCheck.h"

#include "SM/Actions/Actions_LoadAsset.h"
#include "NodeInstance/FSMNodeInstance.h"

bool UConditions_AssetCheck::Condition(UFlowStateContext* Context) const
{
    UFSMNodeInstance* FSMParentNode = Cast<UFSMNodeInstance>(ParentNode);
    if (FSMParentNode)
    {
        UActions_LoadAsset* LoadAsset = FSMParentNode->FindSubNode<UActions_LoadAsset>();
        return LoadAsset && LoadAsset->HasLoadCompleted();
    }
    return false;
}
