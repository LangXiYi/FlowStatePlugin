#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFlowStateMachineEditor;

class FFlowStateMachineEditorApplicationMode : public FApplicationMode
{
public:
	FFlowStateMachineEditorApplicationMode(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;

protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet FlowStateMachineTabFactories;
};
