// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNode_State.h"

#include "SM/FlowStateContext.h"
#include "Utility/FSMUtility.h"

void UFSMRuntimeNode_State::EndState(int Index)
{
	if (!ChildrenNodes.IsValidIndex(Index))
	{
		FSMLOGW("UFSMRuntimeNode_State::EndState: Invalid Index %d", Index);
		return;
	}

	if (Context)
	{
		Context->SwitchTo((UFlowStateBase*)ChildrenNodes[Index]);
	}
}
