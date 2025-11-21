#pragma once
#include "AssetTypeActions_Base.h"
#include "FSMAssetType_Utility.h"
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "SM/FlowState.h"

class FAssetTypeActions_FlowState : public FAssetTypeActions_Blueprint
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowState", "Flow State"); }
	virtual UClass* GetSupportedClass() const override { return UFlowState::StaticClass(); }

	virtual FColor GetTypeColor() const override { return FFSMAssetTypeHelper::AssetColor; }
	virtual uint32 GetCategories() override { return FFSMAssetTypeHelper::AssetCategory; }
};
