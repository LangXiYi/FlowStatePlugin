// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/FlowStateDataAsset.h"

UObject* UDataFragment_Assets::FindData(TSubclassOf<UObject> Type, FName Name)
{
	if (Type == UStaticMesh::StaticClass())
	{
		if (SM_Meshes.Contains(Name))
		{
			return SM_Meshes.FindRef(Name);
		}
		return nullptr;
	}
	if (Type == USkeletalMesh::StaticClass())
	{
		if (SK_Meshes.Contains(Name))
		{
			return SK_Meshes.FindRef(Name);
		}
		return nullptr;
	}
	if (Type == UAnimSequence::StaticClass())
	{
		if (Animations.Contains(Name))
		{
			return Animations.FindRef(Name);
		}
		return nullptr;
	}
	return nullptr;
}

void UFlowStateDataAsset::PostLoad()
{
	Super::PostLoad();
	for (UFlowStateDataFragment* GuideData : DataArray)
	{
		GuideData->PostLoad();
	}
}

UFlowStateDataFragment* UFlowStateDataAsset::FindDataFragment(TSubclassOf<UFlowStateDataFragment> Type)
{
	for (UFlowStateDataFragment* DataFragment : DataArray) 
	{
		if (DataFragment->IsA(Type))
		{
			return DataFragment;
		}
	}
	return nullptr;
}
