#include "Mode/FSMEditorApplicationMode.h"

#include "FlowStateMachineEditor.h"
#include "TabFactories/FSMGraphDetailSummoner.h"
#include "TabFactories/FSMEditorTabsHelper.h"
#include "TabFactories/FSMGraphEditorSummoner.h"
#include "TabFactories/FSMSearchSummoner.h"

FFSMEditorApplicationMode::FFSMEditorApplicationMode(
	TSharedPtr<FFlowStateMachineEditor> InEditor)
		:FApplicationMode(FFlowStateMachineEditor::FlowStateMachineMode)
{
	FlowStateMachineEditor = InEditor;

	// Register Tabs
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphEditorSummoner(InEditor)));
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphDetailSummoner(InEditor)));
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FSMSearchSummoner(InEditor)));
	// TODO::Add More Tab Factories..

	TabLayout = FTabManager::FLayout::NullLayout;
	/*TabLayout = FTabManager::NewLayout("Standalone_FlowStateMachine_Layout_v1")
	->AddArea
	(
		FTabManager::NewPrimaryArea() ->SetOrientation(Orient_Vertical)
#if ENGINE_MAJOR_VERSION < 5
		/*->Split
		(
		// DEPRECATED:: UE5 Deprecated the toolbar tab
			FTabManager::NewStack()
			->SetSizeCoefficient(0.1f)
			->AddTab(InEditor->GetToolbarTabId(), ETabState::OpenedTab) 
			->SetHideTabWell(true) 
		)#1#
#endif
		->Split
		(
			FTabManager::NewSplitter() ->SetOrientation(Orient_Horizontal)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.7f)
				->AddTab(FFSMEditorTabsHelper::GraphEditorID, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation(Orient_Vertical)
				->SetSizeCoefficient(0.3f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.6f)
					->AddTab(FFSMEditorTabsHelper::GraphDetailsID, ETabState::OpenedTab)
					->AddTab(FFSMEditorTabsHelper::SearchID, ETabState::ClosedTab)
				)
			)
		)
	);*/

	// InEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
	// InEditor->GetToolbarBuilder()->AddDebuggerToolbar(ToolbarExtender);
	// InEditor->GetToolbarBuilder()->AddBehaviorTreeToolbar(ToolbarExtender);
}

void FFSMEditorApplicationMode::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	// Push our tabs
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	FlowStateMachineEditorPtr->PushTabFactories(FlowStateMachineTabFactories);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FFSMEditorApplicationMode::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();

	FlowStateMachineEditorPtr->SaveEditedObjectState();
}
