// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateAction.h"

void UFlowStateAction::ExecuteAction(UFSMRuntimeNode* Instance)
{
	Super::ExecuteAction(Instance);
	OnExecuteAction(Instance);
}
