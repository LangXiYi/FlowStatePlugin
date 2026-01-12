// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FSMCommonDataFunctionLibrary.h"

#include "RuntimeNode/FSMRuntimeNodeBase.h"
#include "SM/FlowStateContext.h"

UFSMCommonDataManager* UFSMCommonDataFunctionLibrary::GetStateCommonData(UFSMRuntimeNodeBase* NodeOwner)
{
	UFlowStateContext* StateContext = GetStateContext(NodeOwner);
	if (StateContext)
	{
		return StateContext->GetCommonDataManager();
	}
	return nullptr;
}

UFlowStateContext* UFSMCommonDataFunctionLibrary::GetStateContext(const UFSMRuntimeNodeBase* NodeOwner)
{
	return NodeOwner->GetStateContext();
}
