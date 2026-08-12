// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateCondition.h"

#include "RuntimeNode/FSMRuntimeNode.h"

bool UFlowStateCondition::Condition(UFlowStateContext* Context) const
{
	return Super::Condition(Context) && BP_Condition(Context);
}
