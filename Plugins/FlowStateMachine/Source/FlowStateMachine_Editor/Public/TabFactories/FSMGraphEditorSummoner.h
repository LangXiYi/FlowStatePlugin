#pragma once
#include "CoreMinimal.h"
#include "Graph/FSMGraph.h"
#include "WorkflowOrientedApp/WorkflowUObjectDocuments.h"


class FFlowStateMachineEditor;

class FFSMGraphEditorSummoner: public FDocumentTabFactoryForObjects<UFSMGraph>
{
public:
	FFSMGraphEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor);

protected:
	virtual TAttribute<FText> ConstructTabNameForObject(UFSMGraph* DocumentID) const override;
	virtual TSharedRef<SWidget> CreateTabBodyForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual const FSlateBrush* GetTabIconForObject(const FWorkflowTabSpawnInfo& Info, UFSMGraph* InGraph) const override;
	virtual void SaveState(TSharedPtr<SDockTab> Tab, TSharedPtr<FTabPayload> Payload) const override;

private:
	bool InEditingMode(bool bGraphIsEditable) const;
	FGraphAppearanceInfo GetGraphAppearance() const;

protected:

	TWeakPtr<FFlowStateMachineEditor> FlowStateMachineEditor;
};
