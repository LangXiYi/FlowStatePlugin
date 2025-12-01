#pragma once
#include "WorkflowOrientedApp/WorkflowTabFactory.h"


class FFSMEditor;


/** 共用数据的编辑面板 */
class FCommonDataEditorSummoner : public FWorkflowTabFactory
{
public:
	FCommonDataEditorSummoner(TSharedPtr<FFSMEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};

/** 共用数据的细节面板 */
class FCommonDataDetailSummoner : public FWorkflowTabFactory
{
public:
	FCommonDataDetailSummoner(TSharedPtr<FFSMEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};


