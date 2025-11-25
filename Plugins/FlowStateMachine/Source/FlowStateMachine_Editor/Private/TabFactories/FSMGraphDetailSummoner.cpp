#include "TabFactories/FSMGraphDetailSummoner.h"
#include "TabFactories/FSMEditorTabsHelper.h"
#include "FlowStateMachineEditor.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineDetailSummoner"

FFSMGraphDetailSummoner::FFSMGraphDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor)
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
	return SNew(STextBlock).Text(LOCTEXT("DetailSummonerText", "This is a DetailView"));
}

#undef LOCTEXT_NAMESPACE
