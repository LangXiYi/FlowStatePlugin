// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/Actions/Actions_CreateWidgets.h"

#include "Utility/FSMCreateWidgetHelper.h"
#include "Utility/FSMUtility.h"

void UActions_CreateWidgets::ExecuteAction(UFSMNodeInstance* Instance)
{
	Super::ExecuteAction(Instance);
	for (UFSMCreateWidgetHelper* Helper : CreateWidgets)
	{
		if (Helper == nullptr || !Helper->IsValid()) {continue;}
		Helper->CreateWidget(StateContext);
	}
}

void UActions_CreateWidgets::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
	for (const UFSMCreateWidgetHelper* Helper : CreateWidgets)
	{
		if (Helper == nullptr || !Helper->IsValid() || !Helper->Implements<UFlowStateCollectInterface>()) {continue;}
		Helper->GetStatePinInfos(PinInfos);
	}
	Super::GetStatePinInfos(PinInfos);
}
