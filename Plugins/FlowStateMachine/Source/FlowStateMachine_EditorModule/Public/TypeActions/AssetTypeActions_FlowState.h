#pragma once
#include "AssetTypeActions_Base.h"
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "SM/FlowState.h"

class FAssetTypeActions_FlowState : public FAssetTypeActions_Blueprint
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowState", "Flow State"); }
	virtual FColor GetTypeColor() const override { return FColor(0, 55, 100); }
	virtual UClass* GetSupportedClass() const override { return UFlowState::StaticClass(); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Gameplay; }
};
