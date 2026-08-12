#pragma once

#include "WorkflowOrientedApp/WorkflowCentricApplication.h"

class IFlowStateMachineEditor : public FWorkflowCentricApplication, public FEditorUndoClient
{
public:
	IFlowStateMachineEditor();
	virtual ~IFlowStateMachineEditor();
	
	// TODO::添加子类必须重载的函数
	void CreateCommandList();

	//~ Begin FEditorUndoClient Interface
	virtual void PostUndo(bool bSuccess) override;
	virtual void PostRedo(bool bSuccess) override;
	// End of FEditorUndoClient

protected:
	void SelectAllNodes();
	bool CanSelectAllNodes() const;
	void DeleteSelectedNodes();
	bool CanDeleteNodes() const;
	void DeleteSelectedDuplicatableNodes();
	void CutSelectedNodes();
	bool CanCutNodes() const;
	
	/**
	 * bug::在复制完成后会为子节点添加一个气泡消息，这不是程序所期望的。禁止
	 */
	void CopySelectedNodes();
	bool CanCopyNodes() const;
	void PasteNodes();
	void PasteNodesHere(const FVector2D& Location);
	bool CanPasteNodes() const;
	void DuplicateNodes();
	bool CanDuplicateNodes() const;

	bool CanCreateComment() const;
	void OnCreateComment();

	virtual void FixupPastedNodes(const TSet<UEdGraphNode*>& NewPastedGraphNodes, const TMap<FGuid/*New*/, FGuid/*Old*/>& NewToOldNodeMapping);

protected:
	/** Currently focused graph */
	TWeakPtr<SGraphEditor> UpdateGraphEdPtr;
	
	/** The command list for this editor */
	TSharedPtr<FUICommandList> GraphEditorCommands;
};
