#pragma once
#include "WorkflowOrientedApp/ApplicationMode.h"
#include "WorkflowOrientedApp/WorkflowTabManager.h"

class FFlowStateMachineEditor;

class FAppMode_StateGraph : public FApplicationMode
{
public:
    FAppMode_StateGraph(TSharedPtr<FFlowStateMachineEditor> InEditor);

    virtual void RegisterTabFactories(TSharedPtr<FTabManager> InTabManager) override;
    virtual void PreDeactivateMode() override;
    virtual void PostActivateMode() override;

protected:
    TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;

    FWorkflowAllowedTabSet FlowStateMachineTabFactories;
};
