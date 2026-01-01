// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeSubNode.h"


UWorld* UFSMRuntimeSubNode::GetWorld() const
{
	if (ParentNode)
	{
		return ParentNode->GetWorld();
	}
	return Super::GetWorld();
}
