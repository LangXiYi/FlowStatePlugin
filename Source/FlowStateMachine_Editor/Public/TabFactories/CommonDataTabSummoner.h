#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"


class FFSMGraphEditor;


/** 共用数据的编辑面板 */
class FCommonDataEditorSummoner : public FWorkflowTabFactory
{
public:
	FCommonDataEditorSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
};

/** 共用数据的细节面板 */
class FCommonDataDetailSummoner : public FWorkflowTabFactory
{
public:
	FCommonDataDetailSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
};


