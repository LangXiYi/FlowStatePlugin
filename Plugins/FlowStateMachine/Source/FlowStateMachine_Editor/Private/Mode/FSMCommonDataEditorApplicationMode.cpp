#include "Mode/FSMCommonDataEditorApplicationMode.h"

#include "FlowStateMachineEditor.h"
#include "FSMEditorToolbar.h"
#include "TabFactories/FSMEditorTabsHelper.h"

FFSMCommonDataEditorApplicationMode::FFSMCommonDataEditorApplicationMode(TSharedPtr<FFlowStateMachineEditor> InEditor) :
	FApplicationMode(FFlowStateMachineEditor::CommonDataMode),
	FlowStateMachineEditor(InEditor)
{
	// FlowStateMachineEditor = InEditor;
	// Register Tabs
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphDetailSummoner(InEditor)));
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphNodeListSummoner(InEditor)));
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FSMSearchSummoner(InEditor)));
	// TODO::Add More Tab Factories..

	// TabLayout = FTabManager::FLayout::NullLayout;
	TabLayout = FTabManager::NewLayout("Standalone_FSMCommonData_Layout_v2")
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
				->AddTab(FFSMEditorTabsHelper::CommonDataEditorID, ETabState::ClosedTab)
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

void FFSMCommonDataEditorApplicationMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// Create Editor Toolbar Tab
	FlowStateMachineEditorPtr->RegisterToolbarTab(InTabManager.ToSharedRef());
	// Push our tabs
	FlowStateMachineEditorPtr->PushTabFactories(CommonDataTabFactories);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FFSMCommonDataEditorApplicationMode::PostActivateMode()
{
	// Reopen any documents that were open when the blueprint was last saved
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// FlowStateMachineEditorPtr->RestoreFlowStateMachine();

	FApplicationMode::PostActivateMode();
}
