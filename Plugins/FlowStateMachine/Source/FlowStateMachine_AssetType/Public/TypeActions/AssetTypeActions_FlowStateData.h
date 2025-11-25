#pragma once
#include "AssetTypeActions_Base.h"
#include "FSMAssetType_Utility.h"
#include "Data/FSMMetaDataAsset.h"

class FAssetTypeActions_FlowStateData : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowStateData", "FlowStateDat"); }
	virtual UClass* GetSupportedClass() const override { return UFSMMetaDataAsset::StaticClass(); }
	virtual FColor GetTypeColor() const override { return FFSMAssetTypeHelper::AssetColor; }
	virtual uint32 GetCategories() override { return FFSMAssetTypeHelper::AssetCategory; }
};
