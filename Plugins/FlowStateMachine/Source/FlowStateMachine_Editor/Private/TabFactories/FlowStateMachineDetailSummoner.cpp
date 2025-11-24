#include "TabFactories/FlowStateMachineDetailSummoner.h"
#include "TabFactories/FlowStateMachineEditorTabs.h"
#include "FlowStateMachineEditor.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineDetailSummoner"

FFlowStateMachineDetailSummoner::FFlowStateMachineDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor)
	:FWorkflowTabFactory(FFlowStateMachineEditorTabs::GraphDetailsID, InEditor) ,FlowStateMachineEditor(InEditor)
{
	bIsSingleton = true;
}

FText FFlowStateMachineDetailSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("FlowStateMachineDetailTooltip", "The details tab is for editing FlowState entries.");
}

#undef LOCTEXT_NAMESPACE