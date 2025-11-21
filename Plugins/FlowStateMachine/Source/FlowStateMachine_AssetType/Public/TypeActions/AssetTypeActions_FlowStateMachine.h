#pragma once
#include "FSMAssetType_Utility.h"
#include "SM/FlowStateContext.h"

class FAssetTypeActions_FlowStateMachine: public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowStateMachine", "Flow State Machine"); }
	virtual FColor GetTypeColor() const override { return FFSMAssetTypeHelper::AssetColor; }
	virtual uint32 GetCategories() override { return FFSMAssetTypeHelper::AssetCategory; }

	virtual UClass* GetSupportedClass() const override { return UFlowStateContext::StaticClass(); }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};
