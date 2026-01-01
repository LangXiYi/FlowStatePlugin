// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateCondition.h"

#include "RuntimeNode/FSMRuntimeNode.h"

bool UFlowStateCondition::Condition() const
{
	return Super::Condition() && BP_Condition((UFSMRuntimeNode*)ParentNode);
}
