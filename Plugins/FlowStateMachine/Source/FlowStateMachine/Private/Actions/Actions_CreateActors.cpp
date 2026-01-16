// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_CreateActors.h"

#include "Utility/FSMCreateActorHelper.h"


void UActions_CreateActors::ExecuteAction(UFSMRuntimeNode* Instance)
{
	for (UFSMCreateActorHelper* Helper : CreateActors)
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
		Helper->CreateActor(StateContext);
	}
}
