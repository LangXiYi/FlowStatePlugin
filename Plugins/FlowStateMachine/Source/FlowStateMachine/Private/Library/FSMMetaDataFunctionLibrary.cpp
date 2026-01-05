// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FSMMetaDataFunctionLibrary.h"

#include "Data/FSMMetaDataAsset.h"
#include "Data/DataFragments/FSMMetaDataFragment_Assets.h"
#include "Engine/AssetManager.h"
#include "Library/FSMFunctionLibrary.h"
#include "SM/FlowStateContext.h"

UFSMMetaDataAsset* UFSMMetaDataFunctionLibrary::FindMetaDataAsset(UObject* WorldContextObject,
	FPrimaryAssetId MetaDataID)
{
	// 直接根据资产ID在内存中查找
	UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(MetaDataID);
	if (UFSMMetaDataAsset* MetaData = Cast<UFSMMetaDataAsset>(AssetObject))
	{
		return MetaData;
	}
	return nullptr;
}

UFSMMetaDataFragment* UFSMMetaDataFunctionLibrary::FindMetaDataFragment(UObject* WorldContextObject,
	FPrimaryAssetId MetaDataID, TSubclassOf<UFSMMetaDataFragment> DataType)
{
	if (UFSMMetaDataAsset* MetaData = FindMetaDataAsset(WorldContextObject, MetaDataID))
	{
		return MetaData->FindDataFragment(DataType);
	}
	return nullptr;
}
