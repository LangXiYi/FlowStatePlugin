#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFlowStateMachineEditor;

class FFSMCommonDataEditorApplicationMode : public FApplicationMode
{
public:
	FFSMCommonDataEditorApplicationMode(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet CommonDataTabFactories;
};
