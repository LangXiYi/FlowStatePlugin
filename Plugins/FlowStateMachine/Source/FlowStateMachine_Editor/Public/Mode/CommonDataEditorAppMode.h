#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFSMEditor;

class FCommonDataEditorAppMode : public FApplicationMode
{
public:
	FCommonDataEditorAppMode(TSharedPtr<FFSMEditor> InEditor);

	virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
	virtual void PostActivateMode() override;

protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;

	FWorkflowAllowedTabSet CommonDataTabFactories;
};
