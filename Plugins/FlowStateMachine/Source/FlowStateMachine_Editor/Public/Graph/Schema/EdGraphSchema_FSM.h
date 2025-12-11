#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EdGraphSchema_FSM.generated.h"

/** Action to auto arrange the graph */
USTRUCT()
struct FFSMSchemaAction_NewState : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	FFSMSchemaAction_NewState() 
		: FEdGraphSchemaAction() {}

	FFSMSchemaAction_NewState(UClass* InNodeParentClass, FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping):
		FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping),
		NodeParentClass(InNodeParentClass)
	{
	}

	//~ Begin FEdGraphSchemaAction Interface
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	//~ End FEdGraphSchemaAction Interface
private:
	UClass* NodeParentClass = nullptr;
};

USTRUCT()
struct FFSMSchemaAction_NewMachine : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	FFSMSchemaAction_NewMachine() 
		: FEdGraphSchemaAction() {}

	FFSMSchemaAction_NewMachine(UClass* InNodeParentClass, FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping):
		FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping),
		NodeParentClass(InNodeParentClass)
	{
	}

	//~ Begin FEdGraphSchemaAction Interface
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	//~ End FEdGraphSchemaAction Interface
private:
	UClass* NodeParentClass = nullptr;
};

UCLASS()
class UEdGraphSchema_FSM : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	//~ Begin EdGraphSchema Interface
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	virtual void GetContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	virtual const FPinConnectionResponse CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const override;
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;
	virtual bool IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const override;
	virtual int32 GetCurrentVisualizationCacheID() const override;
	virtual void ForceVisualizationCacheClear() const override;
	//~ End EdGraphSchema Interface

protected:
	// static TSharedPtr<FAISchemaAction_NewNode> AddNewNodeAction(FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip);
	// static TSharedPtr<FAISchemaAction_NewSubNode> AddNewSubNodeAction(FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip);
};
