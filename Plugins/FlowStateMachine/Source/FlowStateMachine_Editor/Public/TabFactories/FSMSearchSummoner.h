#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"


class FFlowStateMachineEditor;

class FFSMSearchSummoner : public FWorkflowTabFactory
{
public:
	FFSMSearchSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

protected:
	// Begin FWorkflowTabFactory
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
