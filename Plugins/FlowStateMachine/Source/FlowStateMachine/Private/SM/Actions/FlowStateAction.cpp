// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/Actions/FlowStateAction.h"

void UFlowStateAction::ExecuteAction(UFSMNodeInstance* Instance)
{
    OnExecuteAction(Instance);
}
