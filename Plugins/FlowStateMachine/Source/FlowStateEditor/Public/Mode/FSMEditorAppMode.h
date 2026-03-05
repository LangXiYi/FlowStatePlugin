#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFSMGraphEditor;

class FFSMEditorAppMode : public FApplicationMode
{
public:
	FFSMEditorAppMode(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet FlowStateMachineTabFactories;
};
