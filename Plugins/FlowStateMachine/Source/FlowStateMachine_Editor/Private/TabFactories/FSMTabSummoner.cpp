#include "TabFactories/FSMTabSummoner.h"
#include "TabFactories/FSMEditorTabsHelper.h"
#include "FSMEditor.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineDetailSummoner"

FFSMGraphDetailSummoner::FFSMGraphDetailSummoner(TSharedPtr<FFSMEditor> InEditor)
	:FWorkflowTabFactory(FFSMEditorTabsHelper::GraphDetailsID, InEditor) , FlowStateMachineEditor(InEditor)
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
	TSharedPtr<FFSMEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);
	
	TSharedRef<IDetailsView> AssetDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);
	TSharedRef<IDetailsView> NodeDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);

	AssetDetailsView->SetObject(StateMachineEditor->GetFlowStateMachine());
	// TODO::需要修改为选择的节点
	NodeDetailsView->SetObject(nullptr);
	
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			AssetDetailsView
		]
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			NodeDetailsView
		];
}

#undef LOCTEXT_NAMESPACE



#define LOCTEXT_NAMESPACE "FSMGraphEditorSummoner"

FFSMGraphEditorSummoner::FFSMGraphEditorSummoner(TSharedPtr<FFSMEditor> InEditor):
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
	TSharedPtr<FFSMEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
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
	TSharedPtr<FFSMEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
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

FFSMGraphNodeListSummoner::FFSMGraphNodeListSummoner(TSharedPtr<FFSMEditor> InEditor):
	FWorkflowTabFactory(FFSMEditorTabsHelper::GraphNodeListID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "GraphEditorSummoner");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

TSharedRef<SWidget> FFSMGraphNodeListSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(STextBlock).Text(LOCTEXT("GraphSummoner_Title", "GraphNodeListSummoner"));
}

FText FFSMGraphNodeListSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("ToolTip", "GraphNodeListSummoner");
}

#undef LOCTEXT_NAMESPACE
