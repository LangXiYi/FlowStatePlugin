#pragma once
#include "AssetTypeActions_Base.h"
#include "Data/FlowStateDataAsset.h"

class FAssetTypeActions_FlowStateData : public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowStateData", "Flow State Dat"); }
	virtual FColor GetTypeColor() const override { return FColor(201, 29, 85); }
	virtual UClass* GetSupportedClass() const override { return UFlowStateDataAsset::StaticClass(); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Gameplay; }
};
