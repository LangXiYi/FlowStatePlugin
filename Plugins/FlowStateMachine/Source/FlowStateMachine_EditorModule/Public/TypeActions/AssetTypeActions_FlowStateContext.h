#pragma once
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"
#include "SM/FlowStateContext.h"

class FAssetTypeActions_FlowStateContext : public FAssetTypeActions_Blueprint
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowStateContext", "Flow State Context"); }
	virtual FColor GetTypeColor() const override { return FColor(0, 55, 100); }
	virtual UClass* GetSupportedClass() const override { return UFlowStateContext::StaticClass(); }
	virtual uint32 GetCategories() override { return EAssetTypeCategories::Gameplay; }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};
