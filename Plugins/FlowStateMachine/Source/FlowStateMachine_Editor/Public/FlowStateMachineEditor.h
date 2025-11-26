#pragma once
#include "IFlowStateMachineEditor.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"


class UFlowStateMachine;




class FFlowStateMachineEditor: public IFlowStateMachineEditor
{
public:
	FFlowStateMachineEditor();
	
	void InitFlowStateMachineEditor(EToolkitMode::Type Mode,
		const TSharedPtr<class IToolkitHost>& InitToolkitHost, UObject* InObject);
	
	// IAssetEditorInstance Begin
	virtual FLinearColor GetWorldCentricTabColorScale() const override { return FLinearColor::Blue;}
	virtual FName GetToolkitFName() const override { return FName("FlowStateMachineEditor"); }
	virtual FText GetBaseToolkitName() const override { return FText::FromString("FlowStateMachineEditor"); }
	virtual FString GetWorldCentricTabPrefix() const override { return "FlowStateMachineEditor"; }
	// IAssetEditorInstance End

	void SaveEditedObjectState();

	//////////////////////////////////////////////////////////////
	/// Get Or Set
	//////////////////////////////////////////////////////////////
public:
	FORCEINLINE UFlowStateMachine* GetEditAsset() const { return FlowStateMachine; }
	FORCEINLINE UEdGraph* GetEditGraph() const { return FlowStateMachineGraph; }

public:
	static FName const FlowStateMachineMode; 

private:
	UFlowStateMachine* FlowStateMachine = nullptr;
	UEdGraph* FlowStateMachineGraph = nullptr;

	// 管理不同编辑器图表
	TSharedPtr<FDocumentTracker> DocumentManager;
};
