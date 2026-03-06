#include "Mode/AppMode_CommonData.h"

#include "FlowStateMachineEditor.h"
#include "FlowStateEditorToolbar.h"
#include "TabSummoner/CommonDataTabSummoner.h"
#include "Utility/FlowStateEditorHelper.h"

USING_FLOWSTATE_EDITORHELPER

FAppMode_CommonData::FAppMode_CommonData(TSharedPtr<FFlowStateMachineEditor> InEditor) :
	FApplicationMode(FEditorHelper::CommonDataMode),
	FlowStateMachineEditor(InEditor)
{
	CommonDataTabFactories.RegisterFactory(MakeShareable(new FCommonDataEditorSummoner(InEditor)));
	CommonDataTabFactories.RegisterFactory(MakeShareable(new FCommonDataDetailSummoner(InEditor)));

	TabLayout = FTabManager::NewLayout("Standalone_FSMCommonData_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
		->Split
		(
			// DEPRECATED:: UE5 Deprecated the toolbar tab
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->AddTab(InEditor->GetToolbarTabId(), ETabState::OpenedTab) 
			->SetHideTabWell(true) 
		)
		->Split
		(
			FTabManager::NewSplitter() ->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.6f)
				->AddTab(FTabSummonerHelper::CommonDataEditorID, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.4f)
				->AddTab(FTabSummonerHelper::CommonDataDetailsID, ETabState::OpenedTab)
			)
		)
	);

	InEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
}

void FAppMode_CommonData::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// Create Editor Toolbar Tab
	FlowStateMachineEditorPtr->RegisterToolbarTab(InTabManager.ToSharedRef());
	// Push our tabs
	FlowStateMachineEditorPtr->PushTabFactories(CommonDataTabFactories);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FAppMode_CommonData::PostActivateMode()
{
	// Reopen any documents that were open when the blueprint was last saved
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// FlowStateMachineEditorPtr->RestoreFlowStateMachine();

	FApplicationMode::PostActivateMode();
}
