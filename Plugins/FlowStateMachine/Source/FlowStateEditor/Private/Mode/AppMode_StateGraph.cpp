#include "Mode/AppMode_StateGraph.h"

#include "FlowStateEditorToolbar.h"
#include "FlowStateMachineEditor.h"
#include "Utility/FlowStateEditorHelper.h"
#include "TabSummoner/FlowStateTabSummoner.h"

USING_FLOWSTATE_EDITORHELPER

FAppMode_StateGraph::FAppMode_StateGraph(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FApplicationMode(FEditorHelper::FlowStateMachineMode),
	FlowStateMachineEditor(InEditor)
{
	// FlowStateMachineEditor = InEditor;

	// Register Tabs
	FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphDetailSummoner(InEditor)));
	FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMGraphNodeListSummoner(InEditor)));
	// FlowStateMachineTabFactories.RegisterFactory(MakeShareable(new FFSMSearchSummoner(InEditor)));
	// TODO::Add More Tab Factories..

	// TabLayout = FTabManager::FLayout::NullLayout;
	TabLayout = FTabManager::NewLayout("Standalone_FlowStateMachine_Layout_v2.1")
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
				->SetSizeCoefficient(0.2f)
				->AddTab(FTabSummonerHelper::GraphNodeListID, ETabState::OpenedTab)
			)
			->Split
			(
				FTabManager::NewStack()
				->SetSizeCoefficient(0.55f)
				->AddTab(FTabSummonerHelper::GraphEditorID, ETabState::ClosedTab)
			)
			->Split
			(
				FTabManager::NewSplitter() ->SetOrientation(Orient_Vertical)
				->SetSizeCoefficient(0.25f)
				->Split
				(
					FTabManager::NewStack()
					->SetSizeCoefficient(0.6f)
					->AddTab(FTabSummonerHelper::GraphDetailsID, ETabState::OpenedTab)
					// ->AddTab(FFSMEditorTabsHelper::SearchID, ETabState::ClosedTab)
				)
			)
		)
	);

	InEditor->GetToolbarBuilder()->AddModesToolbar(ToolbarExtender);
	InEditor->GetToolbarBuilder()->AddDebuggerToolbar(ToolbarExtender);
	InEditor->GetToolbarBuilder()->AddBehaviorTreeToolbar(ToolbarExtender);
}

void FAppMode_StateGraph::RegisterTabFactories(TSharedPtr<FTabManager> InTabManager)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	// Create Editor Toolbar Tab
	FlowStateMachineEditorPtr->RegisterToolbarTab(InTabManager.ToSharedRef());
	// Push our tabs
	FlowStateMachineEditorPtr->PushTabFactories(FlowStateMachineTabFactories);
	FApplicationMode::RegisterTabFactories(InTabManager);
}

void FAppMode_StateGraph::PreDeactivateMode()
{
	FApplicationMode::PreDeactivateMode();
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();

	FlowStateMachineEditorPtr->SaveEditedObjectState();
}

void FAppMode_StateGraph::PostActivateMode()
{
	// Reopen any documents that were open when the blueprint was last saved
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFlowStateMachineEditor> FlowStateMachineEditorPtr = FlowStateMachineEditor.Pin();
	FlowStateMachineEditorPtr->RestoreFlowStateMachine();

	FApplicationMode::PostActivateMode();
}
