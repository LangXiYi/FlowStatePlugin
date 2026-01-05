// Fill out your copyright notice in the Description page of Project Settings.


#include "Conditions/Conditions_AssetCheck.h"

#include "Actions/Actions_LoadAsset.h"
#include "RuntimeNode/FSMRuntimeNode.h"

bool UConditions_AssetCheck::Condition(UFlowStateContext* Context) const
{
	UFSMRuntimeNode* FSMParentNode = Cast<UFSMRuntimeNode>(ParentNode);
	if (FSMParentNode)
	{
		UActions_LoadAsset* LoadAsset = FSMParentNode->FindSubNode<UActions_LoadAsset>();
		return LoadAsset && LoadAsset->HasLoadCompleted();
	}
	return false;
}
