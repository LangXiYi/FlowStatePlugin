#include "FlowStateMachineEditorApplicationMode.h"

#include "FlowStateMachineEditor.h"
#include "TabFactories/FlowStateMachineDetailSummoner.h"
#include "TabFactories/FlowStateMachineEditorTabs.h"

FFlowStateMachineEditorApplicationMode::FFlowStateMachineEditorApplicationMode(
	TSharedPtr<FFlowStateMachineEditor> InEditor)
		:FApplicationMode(FFlowStateMachineEditor::FlowStateMachineMode)
{
	FlowStateMachineEditor = InEditor;

	// Register Tabs
	FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFlowStateMachineDetailSummoner(InEditor)));

	TabLayout = FTabManager::NewLayout("Standalone_FlowStateMachine_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
		->Split
		(
		// DEPRECATED:: UE5 Deprecated the toolbar tab
#if ENGINE_MAJOR_VERSION < 5
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->AddTab(InEditor->GetToolbarTabId(), ETabState::OpenedTab) 
			->SetHideTabWell(true) 
#endif
		)
		->Split
		(
			FTabManager::NewSplitter() ->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.7f)
				->AddTab(FFlowStateMachineEditorTabs::GraphEditorID, ETabState::ClosedTab)
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation(Orient_Vertical)
				->SetSizeCoefficient(0.3f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.6f)
					->AddTab(FFlowStateMachineEditorTabs::GraphDetailsID, ETabState::OpenedTab)
					->AddTab(FFlowStateMachineEditorTabs::SearchID, ETabState::ClosedTab)
				)
			)
		)
	);

	// InEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
	// InEditor->GetToolbarBuilder()->AddDebuggerToolbar(ToolbarExtender);
	// InEditor->GetToolbarBuilder()->AddBehaviorTreeToolbar(ToolbarExtender);
}

void FFlowStateMachineEditorApplicationMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();

	FlowStateMachineEditorPtr->RegisterTabSpawners(InTabManager.ToSharedRef());
	FlowStateMachineEditorPtr->PushTabFactories(FlowStateMachineTabFactories);
	
	
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FFlowStateMachineEditorApplicationMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();

	FlowStateMachineEditorPtr->SaveEditedObjectState();
}
