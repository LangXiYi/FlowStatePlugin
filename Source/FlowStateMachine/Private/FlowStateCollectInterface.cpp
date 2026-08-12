// Fill out your copyright notice in the Description page of Project Settings.


#include "FlowStateCollectInterface.h"

#include "Library/FSMFunctionLibrary.h"


void IFlowStateCollectInterface::Execute_GetStatePinInfos(const UObject* Target, TArray<FStatePinInfo>& PinInfos)
{
	if (Target && Target->Implements<UFlowStateCollectInterface>())
	{
		TArray<FName> Array = {};
		Execute_NativeGetStatePinInfos(Target, Array);
		for (FName Name : Array)
		{
			PinInfos.Add(FStatePinInfo("ThenPins", Name));
		}
	}
}

void IFlowStateCollectInterface::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
	// Execute_GetStatePinInfos(this, Array)
	checkf(false, TEXT("继承接口后，必须调用 Execute_GetStatePinInfos 函数"))
}
