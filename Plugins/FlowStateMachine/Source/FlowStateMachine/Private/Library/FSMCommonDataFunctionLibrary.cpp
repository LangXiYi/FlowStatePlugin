// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FSMCommonDataFunctionLibrary.h"

#include "NodeInstance/FSMNodeInstanceBase.h"
#include "SM/FlowStateContext.h"

/*
UFSMCommonDataManager* UFSMCommonDataFunctionLibrary::GetStateCommonData(UFSMNodeInstanceBase* NodeOwner)
{
	UFlowStateContext* StateContext = GetStateContext(NodeOwner);
	if (StateContext)
	{
		return StateContext->GetCommonDataManager();
	}
	return nullptr;
}

UFlowStateContext* UFSMCommonDataFunctionLibrary::GetStateContext(const UFSMNodeInstanceBase* NodeOwner)
{
	return NodeOwner->GetStateContext();
}
*/
