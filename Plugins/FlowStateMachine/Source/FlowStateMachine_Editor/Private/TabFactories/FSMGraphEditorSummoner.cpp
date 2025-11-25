#include "TabFactories/FSMGraphEditorSummoner.h"
#include "FlowStateMachineEditor.h"
#include "TabFactories/FSMEditorTabsHelper.h"

#define LOCTEXT_NAMESPACE "FSMGraphEditorSummoner"

FFSMGraphEditorSummoner::FFSMGraphEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FWorkflowTabFactory(FFSMEditorTabsHelper::GraphEditorID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "GraphEditorSummoner");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

TSharedRef<SWidget> FFSMGraphEditorSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(STextBlock).Text(LOCTEXT("GraphSummoner_Title", "GraphEditorSummoner"));
}

FText FFSMGraphEditorSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("ToolTip", "GraphEditorSummoner");
}

#undef LOCTEXT_NAMESPACE
