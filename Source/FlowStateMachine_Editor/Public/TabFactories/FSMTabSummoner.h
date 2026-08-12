#pragma once
#include "CoreMinimal.h"
#include "Graph/FSMGraph.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"
#include "WorkflowOrientedApp/WorkflowUObjectDocuments.h"

class FFSMGraphEditor;

/** 状态机图表的细节面板 */
class FFSMGraphDetailSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphDetailSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

	// Begin FWorkflowTabFactory
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
};

/** 状态机图表的编辑面板 */
class FFSMGraphEditorSummoner: public FDocumentTabFactoryForObjects<UFSMGraph>
{
public:
	FFSMGraphEditorSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual void OnTabActivated(TSharedPtr<SDockTab> Tab) const override;
	virtual void OnTabRefreshed(TSharedPtr<SDockTab> Tab) const override;

protected:
	virtual TAttribute<FText> ConstructTabNameForObject(UFSMGraph* DocumentID) const override;
	virtual TSharedRef<SWidget> CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual const FSlateBrush* GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual void SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const override;

	
protected:

	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
};

/** 状态机图表的节点列表 */
class FFSMGraphNodeListSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphNodeListSummoner(TSharedPtr<FFSMGraphEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMGraphEditor> FlowStateMachineEditor;
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
