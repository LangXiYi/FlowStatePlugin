// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_CreateActors.h"

#include "Utility/FSMCreateActorHelper.h"


void UActions_CreateActors::ExecuteAction(UFSMRuntimeNode* Instance)
{
	for (UFSMCreateActorHelper* Helper : CreateActors)
	{
		if (Helper == nullptr || !Helper->IsValid()) continue;
		Helper->CreateActor(StateContext);
	}
}

void UActions_CreateActors::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
	for (const UFSMCreateActorHelper* Helper : CreateActors)
	{
		if (Helper == nullptr || !Helper->IsValid() || !Helper->Implements<UFlowStateCollectInterface>()) continue;
		Helper->GetStatePinInfos(PinInfos);
	}
	Super::GetStatePinInfos(PinInfos);
}
