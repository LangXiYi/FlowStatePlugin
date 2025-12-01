#pragma once
#include "CoreMinimal.h"
#include "Graph/FSMGraph.h"
#include "WorkflowOrientedApp/WorkflowTabFactory.h"
#include "WorkflowOrientedApp/WorkflowUObjectDocuments.h"

class FFSMEditor;

/** 状态机图表的细节面板 */
class FFSMGraphDetailSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphDetailSummoner(TSharedPtr<FFSMEditor> InEditor);

	// Begin FWorkflowTabFactory
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};

/** 状态机图表的编辑面板 */
class FFSMGraphEditorSummoner: public FDocumentTabFactoryForObjects<UFSMGraph>
{
public:
	FFSMGraphEditorSummoner(TSharedPtr<FFSMEditor> InEditor);

protected:
	virtual TAttribute<FText> ConstructTabNameForObject(UFSMGraph* DocumentID) const override;
	virtual TSharedRef<SWidget> CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual const FSlateBrush* GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual void SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const override;

private:
	bool InEditingMode(bool bGraphIsEditable) const;
	FGraphAppearanceInfo GetGraphAppearance() const;

protected:

	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};

/** 状态机图表的节点列表 */
class FFSMGraphNodeListSummoner: public FWorkflowTabFactory
{
public:
	FFSMGraphNodeListSummoner(TSharedPtr<FFSMEditor> InEditor);

	virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;

protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};

/** 状态机图表的搜索界面 */
/*
class FFSMSearchSummoner : public FWorkflowTabFactory
{
public:
	FFSMSearchSummoner(TSharedPtr<FFSMEditor> InEditor);

protected:
	// Begin FWorkflowTabFactory
	// virtual FText GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const override;
	// virtual TSharedRef<SWidget> CreateTabBody(const FWorkflowTabSpawnInfo& Info) const override;
	
protected:
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};
*/
