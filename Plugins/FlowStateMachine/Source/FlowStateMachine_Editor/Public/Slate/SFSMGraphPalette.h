#pragma once
#include "SGraphPalette.h"
#include "Graph/FSMGraph.h"

class SFSMGraphPalette : public SGraphPalette
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphPalette) {};
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFlowStateMachine* InAsset);

	virtual void RefreshActionsList(bool bPreserveExpansion) override;

protected:
	virtual void CollectAllActions(FGraphActionListBuilderBase& OutAllActions) override;

	void AddAssetFromAssetRegistry(const FAssetData& AssetData);
	void RemoveAssetFromRegistry(const FAssetData& AssetData);
	void RenameAssetFromRegistry(const FAssetData& AssetData, const FString& String);

	void RefreshAssetInRegistry(const FAssetData& InAddedAssetData);

private:
	UFlowStateMachine* FSMAsset = nullptr;

	TArray<FDelegateHandle> DelegateHandles;
};
