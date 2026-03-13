#pragma once

#include "FlowStateBlueprint.h"
#include "AssetTypeActions/AssetTypeActions_Blueprint.h"

class FAssetTypeActions_FlowState : public FAssetTypeActions_Blueprint
{
public:
    // IAssetTypeActions Implementation
    virtual FText GetName() const override
    {
        return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowState", "FlowState");
    }

    virtual UClass* GetSupportedClass() const override { return UFlowStateBlueprint::StaticClass(); }
    virtual FColor GetTypeColor() const override { return FColor(0, 55, 100); }
    virtual uint32 GetCategories() override { return EAssetTypeCategories::Gameplay; }
};
