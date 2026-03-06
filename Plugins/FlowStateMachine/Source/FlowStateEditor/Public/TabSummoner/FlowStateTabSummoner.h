#pragma once
#include "CoreMinimal.h"
#include "Graph/FlowStateGraph.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"
#include "WorkflowOrientedApp/WorkflowUObjectDocuments.h"

class FFlowStateMachineEditor;

/** 状态机图表的细节面板 */
class FFSMGraphDetailSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	// Begin FWorkflowTabFactory
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};

/** 状态机图表的编辑面板 */
class FFSMGraphEditorSummoner: public FDocumentTabFactoryForObjects<UFlowStateGraph>
{
public:
	FFSMGraphEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual void OnTabActivated(TSharedPtr<SDockTab> Tab) const override;
	virtual void OnTabRefreshed(TSharedPtr<SDockTab> Tab) const override;

protected:
	virtual TAttribute<FText> ConstructTabNameForObject(UFlowStateGraph* DocumentID) const override;
	virtual TSharedRef<SWidget> CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph) const override;
	virtual const FSlateBrush* GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFlowStateGraph* InGraph) const override;
	virtual void SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const override;

	
TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};

/** 状态机图表的节点列表 */
class FFSMGraphNodeListSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphNodeListSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};

/** 状态机图表的搜索界面 */
/*
class FFSMSearchSummoner : public FWorkflowTabFactory
{
public:
	FFSMSearchSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

protected:
	// Begin FWorkflowTabFactory
	// virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	// virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
};
*/
