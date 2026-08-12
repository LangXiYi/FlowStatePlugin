// Fill out your copyright notice in the Description page of Project Settings.


#include "Utility/FSMUtility.h"


BEGIN_NAMESPACE_FSM

UWorld* GetWorldFromContextObject(UObject* WorldContextObject)
{
	if (WorldContextObject)
	{
		return GEngine != nullptr
			? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull)
			: nullptr;
	}
	return nullptr;
}

END_NAMESPACE_FSM
