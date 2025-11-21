#include "Data/DataFragments/FSMMetaDataFragment_Assets.h"

#include "Utility/FSMUtility.h"


UObject* UFSMMetaDataFragment_Assets::FindAsset(const FName Name, TSubclassOf<UObject> AssetType) const
{
	if (AssetType->IsA<UStaticMesh>())
	{
		return FindAssetByStaticMesh(Name);
	}
	if (AssetType->IsA<USkeletalMesh>())
	{
		return FindAssetBySkeletalMesh(Name);
	}
	if (AssetType->IsA<UAnimSequence>())
	{
		return FindAssetByAnimSequence(Name);
	}
	UE_LOG(LogFlowStateMachine, Warning, TEXT("%hs Not found asset by %s"), __FUNCTION__, *Name.ToString())
	return nullptr;
}

UObject* UFSMMetaDataFragment_Assets::FindAssetByStaticMesh(const FName Name) const
{
	if (SM_Meshes.Contains(Name))
	{
		return SM_Meshes.FindRef(Name);
	}
	return nullptr;
}

UObject* UFSMMetaDataFragment_Assets::FindAssetBySkeletalMesh(const FName Name) const
{
	if (SK_Meshes.Contains(Name))
	{
		return SK_Meshes.FindRef(Name);
	}
	return nullptr;
}

UObject* UFSMMetaDataFragment_Assets::FindAssetByAnimSequence(const FName Name) const
{
	if (Animations.Contains(Name))
	{
		return Animations.FindRef(Name);
	}
	return nullptr;
}
