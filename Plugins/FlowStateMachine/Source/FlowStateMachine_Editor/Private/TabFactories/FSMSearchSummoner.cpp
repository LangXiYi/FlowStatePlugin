#include "TabFactories/FSMSearchSummoner.h"
#include "FlowStateMachineEditor.h"
#include "TabFactories/FSMEditorTabsHelper.h"

#define LOCTEXT_NAMESPACE "FSMSearchSummoner"

FFSMSearchSummoner::FFSMSearchSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor):
	FWorkflowTabFactory(FFSMEditorTabsHelper::SearchID, InEditor),
	FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("TabLabel", "SearchView");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open Search View");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "Search View");
	bIsSingleton = true;
}

FText FFSMSearchSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("TabToolTipText", "The tab is for search FlowState.");
}

TSharedRef<SWidget> FFSMSearchSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return SNew(STextBlock).Text(LOCTEXT("DetailSummonerText", "This is a Search View"));
}

#undef LOCTEXT_NAMESPACE