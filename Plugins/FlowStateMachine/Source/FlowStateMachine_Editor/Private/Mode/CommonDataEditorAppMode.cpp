#include "Mode/CommonDataEditorAppMode.h"

#include "FSMEditor.h"
#include "FSMEditorToolbar.h"
#include "TabFactories/CommonDataTabSummoner.h"
#include "TabFactories/FSMEditorTabsHelper.h"

FCommonDataEditorAppMode::FCommonDataEditorAppMode(TSharedPtr<FFSMEditor> InEditor) :
	FApplicationMode(FFSMEditor::CommonDataMode),
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
				->AddTab(FFSMEditorTabsHelper::CommonDataEditorID, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.4f)
				->AddTab(FFSMEditorTabsHelper::CommonDataDetailsID, ETabState::OpenedTab)
			)
		)
	);

	InEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
}

void FCommonDataEditorAppMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFSMEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// Create Editor Toolbar Tab
	FlowStateMachineEditorPtr->RegisterToolbarTab(InTabManager.ToSharedRef());
	// Push our tabs
	FlowStateMachineEditorPtr->PushTabFactories(CommonDataTabFactories);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FCommonDataEditorAppMode::PostActivateMode()
{
	// Reopen any documents that were open when the blueprint was last saved
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFSMEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// FlowStateMachineEditorPtr->RestoreFlowStateMachine();

	FApplicationMode::PostActivateMode();
}
