#pragma once
#include "IFlowStateMachineEditor.h"

class UFlowStateMachine;




class FFlowStateMachineEditor: public IFlowStateMachineEditor
{
public:
	FFlowStateMachineEditor():
		FlowStateMachine(nullptr)
	{
		
	}
	
	void InitFlowStateMachineEditor(EToolkitMode::Type Mode,
		const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);
	
	// IAssetEditorInstance Begin
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor::Blue;}
	virtual FName GetToolkitFName() const override { return FName("FlowStateMachineEditor"); }
	virtual FText GetBaseToolkitName() const override { return FText::FromString("FlowStateMachineEditor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return "FlowStateMachineEditor"; }
	// IAssetEditorInstance End

	void SaveEditedObjectState();
	

	static FName const FlowStateMachineMode; 
	
private:
	UFlowStateMachine* FlowStateMachine;
};
