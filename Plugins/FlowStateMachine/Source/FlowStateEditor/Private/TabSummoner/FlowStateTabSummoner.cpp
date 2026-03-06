#include "TabSummoner/FlowStateTabSummoner.h"
#include "Utility/FlowStateEditorHelper.h"
#include "FlowStateMachineEditor.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineDetailSummoner"

FFSMGraphDetailSummoner::FFSMGraphDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor)
	:FWorkflowTabFactory(FTabSummonerHelper::GraphDetailsID, InEditor) , FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("DetailSummonerLabel", "GraphDetailView");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

FText FFSMGraphDetailSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("FlowStateMachineDetailTooltip", "The details tab is for editing FlowState entries.");
}

TSharedRef<SWidget> FFSMGraphDetailSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	return StateMachineEditor->CreateFlowStateMachineDetailView(Info);
}

#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "FSMGraphEditorSummoner"

FFSMGraphEditorSummoner::FFSMGraphEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FDocumentTabFactoryForObjects(FTabSummonerHelper::GraphEditorID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "GraphEditor");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

TAttribute<FText> FFSMGraphEditorSummoner::ConstructTabNameForObject(UFlowStateGraph* DocumentID) const
{
	return TAttribute<FText>( FText::FromString( DocumentID->GetName() ) );
}

TSharedRef<SWidget> FFSMGraphEditorSummoner::CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph) const
{
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
	check(InGraph != NULL);
	return StateMachineEditor->CreateFlowStateMachineGraphEditor(Info, InGraph);
}

const FSlateBrush* FFSMGraphEditorSummoner::GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph) const
{
	return FEditorStyle::GetBrush("NoBrush");
}

void FFSMGraphEditorSummoner::SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const
{
	FDocumentTabFactoryForObjects<UFlowStateGraph>::SaveState(Tab, Payload);
}

void FFSMGraphEditorSummoner::OnTabActivated(TSharedPtr<SDockTab> Tab) const
{
	check(FlowStateMachineEditor.IsValid());
	TSharedRef<SGraphEditor> GraphEditor = StaticCastSharedRef<SGraphEditor>(Tab->GetContent());
	FlowStateMachineEditor.Pin()->OnGraphEditorFocused(GraphEditor);
}

void FFSMGraphEditorSummoner::OnTabRefreshed(TSharedPtr<SDockTab> Tab) const
{
	FDocumentTabFactoryForObjects<UFlowStateGraph>::OnTabRefreshed(Tab);
}

/*TSharedRef<SWidget> FFSMGraphEditorSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFSMGraphEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	check(StateMachineEditor);

	SGraphEditor::FGraphEditorEvents InEvents;
	// InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FBehaviorTreeEditor::OnSelectedNodesChanged);
	// InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FBehaviorTreeEditor::OnNodeDoubleClicked);
	// InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FBehaviorTreeEditor::OnNodeTitleCommitted);


	UEdGraph* EditGraph = StateMachineEditor->GetEditGraph();
	TSharedPtr<SGraphEditor> GraphEditor = SNew(SGraphEditor)
		.IsEditable(true)
		.GraphToEdit(EditGraph);
	
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			GraphEditor.ToSharedRef()
		];
}*/


#undef LOCTEXT_NAMESPACE


#define LOCTEXT_NAMESPACE "FSMGraphNodeListSummoner"

FFSMGraphNodeListSummoner::FFSMGraphNodeListSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FWorkflowTabFactory(FTabSummonerHelper::GraphNodeListID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "GraphEditorSummoner");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

TSharedRef<SWidget> FFSMGraphNodeListSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	return StateMachineEditor->CreateFlowStateMachineListView(Info);
}

FText FFSMGraphNodeListSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("ToolTip", "GraphNodeListSummoner");
}

#undef LOCTEXT_NAMESPACE
