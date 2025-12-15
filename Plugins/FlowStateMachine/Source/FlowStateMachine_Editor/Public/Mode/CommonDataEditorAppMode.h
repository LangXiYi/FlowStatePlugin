#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFSMGraphEditor;

class FCommonDataEditorAppMode : public FApplicationMode
{
public:
	FCommonDataEditorAppMode(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet CommonDataTabFactories;
};
