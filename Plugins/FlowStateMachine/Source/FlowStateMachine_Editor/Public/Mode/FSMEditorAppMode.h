#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFSMEditor;

class FFSMEditorAppMode : public FApplicationMode
{
public:
	FFSMEditorAppMode(TSharedPtr<FFSMEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PreDeactivateMode() override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet FlowStateMachineTabFactories;
};
