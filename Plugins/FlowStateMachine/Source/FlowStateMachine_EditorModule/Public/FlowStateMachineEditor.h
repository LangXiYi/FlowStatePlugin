#pragma once

#include "BlueprintEditor.h"

class FFlowStateMachineEditor : public FBlueprintEditor
{
public:
	// todo::Create my editor

	virtual FName GetToolkitFName() const override { return FName("FlowStateMachineEditor"); }
	virtual FText GetToolkitName() const override { return FText::FromString("FlowStateMachineEditor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return FString("FlowStateMachineEditor"); }
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor::Yellow; }
};
