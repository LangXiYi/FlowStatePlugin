// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/Conditions/FlowStateCondition.h"

#include "NodeInstance/FSMNodeInstance.h"

bool UFlowStateCondition::Condition(UFlowStateContext* Context) const
{
	return BP_Condition(Context);
}
