#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"


class FFlowStateMachineEditor;


/** 共用数据的编辑面板 */
class FCommonDataEditorSummoner : public FWorkflowTabFactory
{
public:
    FCommonDataEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

    virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
    virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
    TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};

/** 共用数据的细节面板 */
class FCommonDataDetailSummoner : public FWorkflowTabFactory
{
public:
    FCommonDataDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

    virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
    virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
    TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
