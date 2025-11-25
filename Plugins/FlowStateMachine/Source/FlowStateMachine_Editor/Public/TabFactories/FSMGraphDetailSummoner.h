#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"

class FFlowStateMachineEditor;

class FFSMGraphDetailSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	// Begin FWorkflowTabFactory
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
