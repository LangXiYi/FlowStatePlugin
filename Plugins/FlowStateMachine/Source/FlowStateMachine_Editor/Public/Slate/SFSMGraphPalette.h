#pragma once
#include "SGraphPalette.h"
#include "Graph/FSMGraph.h"

class SFSMGraphPalette : public SGraphPalette
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphPalette) {};
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UEdGraph* InGraph);

protected:
	virtual void CollectAllActions(FGraphActionListBuilderBase& OutAllActions) override;

private:
	UEdGraph* FSMGraph = nullptr;
};
