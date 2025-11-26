#pragma once
#include "CoreMinimal.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"


class FFlowStateMachineEditor;

class FFSMGraphNodeListSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphNodeListSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
