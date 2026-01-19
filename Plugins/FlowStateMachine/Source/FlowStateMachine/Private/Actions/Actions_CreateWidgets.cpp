// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_CreateWidgets.h"

#include "Utility/FSMCreateWidgetHelper.h"
#include "Utility/FSMUtility.h"

void UActions_CreateWidgets::ExecuteAction(UFSMRuntimeNode* Instance)
{
	Super::ExecuteAction(Instance);
	for (UFSMCreateWidgetHelper* Helper : CreateWidgets)
	{
		if (Helper == nullptr)
		{
			continue;
		}
		if (!Helper->IsValid())
		{
			FSMLOGW("Create Actor (%s) Failed, UniqueName or Lifetime is none.", *Helper->GetName());
			continue;
		}
		Helper->CreateWidget(StateContext);
	}
}
