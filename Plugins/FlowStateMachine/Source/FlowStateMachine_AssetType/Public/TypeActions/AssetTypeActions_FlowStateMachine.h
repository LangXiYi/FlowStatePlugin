#pragma once
#include "AssetTypeActions_Base.h"
#include "FSMAssetType_Utility.h"
#include "SM/FlowStateMachine.h"

class FAssetTypeActions_FlowStateMachine: public FAssetTypeActions_Base
{
public:
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_FlowStateMachine", "FlowStateMachine"); }
	virtual FColor GetTypeColor() const override { return FFSMAssetTypeHelper::AssetColor; }
	virtual uint32 GetCategories() override { return FFSMAssetTypeHelper::AssetCategory; }
	virtual UClass* GetSupportedClass() const override { return UFlowStateMachine::StaticClass(); }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor) override;
};
