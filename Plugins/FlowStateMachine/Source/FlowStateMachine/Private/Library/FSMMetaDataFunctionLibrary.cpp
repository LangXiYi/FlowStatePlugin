// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FSMMetaDataFunctionLibrary.h"

#include "Data/FSMMetaDataAsset.h"
#include "Data/DataFragments/FSMMetaDataFragment_Assets.h"
#include "Library/FSMFunctionLibrary.h"
#include "SM/FlowStateContext.h"

UFSMMetaDataAsset* UFSMMetaDataFunctionLibrary::FindMetaDataAsset(UObject* WorldContextObject)
{
	UFlowStateContext* FlowStateContext = UFSMFunctionLibrary::GetFlowStateContext(WorldContextObject);
	return FlowStateContext ? FlowStateContext->GetMetaData() : nullptr;
}

UFSMMetaDataFragment* UFSMMetaDataFunctionLibrary::FindMetaDataFragment(UObject* WorldContextObject,
	TSubclassOf<UFSMMetaDataFragment> DataType)
{
	UFSMMetaDataAsset* MetaDataAsset = FindMetaDataAsset(WorldContextObject);
	return MetaDataAsset ? MetaDataAsset->FindDataFragment(DataType) : nullptr;
}

UObject* UFSMMetaDataFunctionLibrary::FindAssetFromMetaData(UObject* WorldContextObject, FName Name,
	TSubclassOf<UObject> AssetType)
{
	UFSMMetaDataFragment_Assets* DataFragment = FindMetaDataFragment<UFSMMetaDataFragment_Assets>(WorldContextObject);
	return DataFragment ? DataFragment->FindAsset(Name, AssetType) : nullptr;
}
