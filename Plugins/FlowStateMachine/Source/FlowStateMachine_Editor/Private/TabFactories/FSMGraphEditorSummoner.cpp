#include "TabFactories/FSMGraphEditorSummoner.h"
#include "FlowStateMachineEditor.h"
#include "TabFactories/FSMEditorTabsHelper.h"

#define LOCTEXT_NAMESPACE "FSMGraphEditorSummoner"

FFSMGraphEditorSummoner::FFSMGraphEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FDocumentTabFactoryForObjects(FFSMEditorTabsHelper::GraphEditorID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "GraphEditor");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

TAttribute<FText> FFSMGraphEditorSummoner::ConstructTabNameForObject(UFSMGraph* DocumentID) const
{
	return TAttribute<FText>( FText::FromString( DocumentID->GetName() ) );
}

TSharedRef<SWidget> FFSMGraphEditorSummoner::CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const
{
#if 0
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
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
#else

	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
	check(InGraph != NULL);
	
	/*if (!GraphEditorCommands.IsValid())
	{
		CreateCommandList();

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().RemoveExecutionPin,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnRemoveInputPin ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanRemoveInputPin )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().AddExecutionPin,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnAddInputPin ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanAddInputPin )
			);

		// Debug actions
		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().AddBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnAddBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanAddBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanAddBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().RemoveBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnRemoveBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanRemoveBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanRemoveBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().EnableBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnEnableBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanEnableBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanEnableBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().DisableBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnDisableBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanDisableBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanDisableBreakpoint )
			);

		GraphEditorCommands->MapAction( FGraphEditorCommands::Get().ToggleBreakpoint,
			FExecuteAction::CreateSP( this, &FBehaviorTreeEditor::OnToggleBreakpoint ),
			FCanExecuteAction::CreateSP( this, &FBehaviorTreeEditor::CanToggleBreakpoint ),
			FIsActionChecked(),
			FIsActionButtonVisible::CreateSP( this, &FBehaviorTreeEditor::CanToggleBreakpoint )
			);
	}*/

	SGraphEditor::FGraphEditorEvents InEvents;
	// InEvents.OnSelectionChanged = SGraphEditor::FOnSelectionChanged::CreateSP(this, &FBehaviorTreeEditor::OnSelectedNodesChanged);
	// InEvents.OnNodeDoubleClicked = FSingleNodeEvent::CreateSP(this, &FBehaviorTreeEditor::OnNodeDoubleClicked);
	// InEvents.OnTextCommitted = FOnNodeTextCommitted::CreateSP(this, &FBehaviorTreeEditor::OnNodeTitleCommitted);
	
	// Make full graph editor
	const bool bGraphIsEditable = InGraph->bEditable;
	return SNew(SGraphEditor)
		// .AdditionalCommands(GraphEditorCommands)
		.IsEditable(this, &FFSMGraphEditorSummoner::InEditingMode, bGraphIsEditable)
		.Appearance(this, &FFSMGraphEditorSummoner::GetGraphAppearance)
		.GraphToEdit(InGraph)
		.GraphEvents(InEvents);
#endif
}

const FSlateBrush* FFSMGraphEditorSummoner::GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const
{
	return FEditorStyle::GetBrush("NoBrush");
}

void FFSMGraphEditorSummoner::SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const
{
	FDocumentTabFactoryForObjects<UFSMGraph>::SaveState(Tab, Payload);
}

bool FFSMGraphEditorSummoner::InEditingMode(bool bGraphIsEditable) const
{
	return bGraphIsEditable;
}

FGraphAppearanceInfo FFSMGraphEditorSummoner::GetGraphAppearance() const
{
	FGraphAppearanceInfo AppearanceInfo;
	AppearanceInfo.CornerText = LOCTEXT("AppearanceCornerText", "FLOW STATE MACHINE");

	// const int32 StepIdx = Debugger.IsValid() ? Debugger->GetShownStateIndex() : 0;
	// if (Debugger.IsValid() && !Debugger->IsDebuggerRunning())
	// {
	// 	AppearanceInfo.PIENotifyText = LOCTEXT("InactiveLabel", "INACTIVE");
	// }
	// else if (StepIdx)
	// {
	// 	AppearanceInfo.PIENotifyText = FText::Format(LOCTEXT("StepsBackLabelFmt", "STEPS BACK: {0}"), FText::AsNumber(StepIdx));
	// }
	// else if (FBehaviorTreeDebugger::IsPlaySessionPaused())
	// {
	// 	AppearanceInfo.PIENotifyText = LOCTEXT("PausedLabel", "PAUSED");
	// }
	
	return AppearanceInfo;
}

/*TSharedRef<SWidget> FFSMGraphEditorSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
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
