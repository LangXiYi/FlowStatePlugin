// Fill out your copyright notice in the Description page of Project Settings.
#include "Data/FSMMetaDataAsset.h"

#include "Data/DataFragments/FSMMetaDataFragment.h"

void UFSMMetaDataAsset::PostLoad()
{
	Super::PostLoad();
	for (UFSMMetaDataFragment* Fragment : DataFragments)
	{
		check(Fragment);
		// TODO::Fragment->PostLoad();
	}
}

UFSMMetaDataFragment* UFSMMetaDataAsset::FindDataFragment(TSubclassOf<UFSMMetaDataFragment> Type)
{
	for (UFSMMetaDataFragment* Fragment : DataFragments) 
	{
		if (Fragment->IsA(Type))
		{
			return Fragment;
		}
	}
	return nullptr;
}
