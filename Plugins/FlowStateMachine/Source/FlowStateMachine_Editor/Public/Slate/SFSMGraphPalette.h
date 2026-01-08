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

private:
	UFlowStateMachine* FSMAsset = nullptr;
};
