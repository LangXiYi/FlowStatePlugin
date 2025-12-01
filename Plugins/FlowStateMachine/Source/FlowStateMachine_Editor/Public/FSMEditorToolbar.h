#pragma once
#include "FSMEditor.h"

struct FFSMEditorToolbar : public TSharedFromThis<FFSMEditorToolbar>
{
public:
	FFSMEditorToolbar(TSharedPtr<FFSMEditor> InEditor)
		: FlowStateMachineEditor(InEditor) {}

	void AddModesToolbar(TSharedPtr<FExtender> Extender);
	void AddDebuggerToolbar(TSharedPtr<FExtender> Extender);
	void AddBehaviorTreeToolbar(TSharedPtr<FExtender> Extender);

private:
	void FillModesToolbar(FToolBarBuilder& ToolbarBuilder);
	void FillDebuggerToolbar(FToolBarBuilder& ToolbarBuilder);
	void FillBehaviorTreeToolbar(FToolBarBuilder& ToolbarBuilder);

protected:
	/** Pointer back to the blueprint editor tool that owns us */
	TWeakPtr<FFSMEditor> FlowStateMachineEditor;
};
