#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FFlowStateMachineEditor;

class FFlowStateMachineDetailSummoner: public FWorkflowTabFactory
{
public:
	FFlowStateMachineDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
