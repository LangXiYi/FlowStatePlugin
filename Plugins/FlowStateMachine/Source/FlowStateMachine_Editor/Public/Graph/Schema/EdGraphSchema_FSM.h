#pragma once
#include "CoreMinimal.h"
#include "FlowStateMachineEditorTypes.h"
#include "Graph/Node/FSMGraphNode.h"
#include "UObject/Object.h"
#include "EdGraphSchema_FSM.generated.h"

/** Action to add a subnode to the selected node */
USTRUCT()
struct FLOWSTATEMACHINE_EDITOR_API FFSMSchemaAction_NewNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	/** Template of node we want to create */
	UPROPERTY()
	class UFSMGraphNode* NodeTemplate;

	/** parent node */
	UPROPERTY()
	class UFSMGraphNode* ParentGraphNode;

	FFSMSchemaAction_NewNode()
		: FEdGraphSchemaAction()
		, NodeTemplate(nullptr)
		, ParentGraphNode(nullptr)
	{}

	FFSMSchemaAction_NewNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping)
		, NodeTemplate(nullptr)
		, ParentGraphNode(nullptr)
	{}

	//~ Begin FEdGraphSchemaAction Interface
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins, const FVector2D Location, bool bSelectNewNode = true) override;
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	//~ End FEdGraphSchemaAction Interface
};


/** Action to add a subnode to the selected node */
USTRUCT()
struct FLOWSTATEMACHINE_EDITOR_API FFSMSchemaAction_NewSubNode : public FEdGraphSchemaAction
{
	GENERATED_USTRUCT_BODY();

	/** Template of node we want to create */
	UPROPERTY()
	class UFSMGraphSubNode* NodeTemplate;

	/** parent node */
	UPROPERTY()
	class UFSMGraphNode* ParentGraphNode;

	FFSMSchemaAction_NewSubNode()
		: FEdGraphSchemaAction()
		, NodeTemplate(nullptr)
		, ParentGraphNode(nullptr)
	{}

	FFSMSchemaAction_NewSubNode(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping)
		: FEdGraphSchemaAction(MoveTemp(InNodeCategory), MoveTemp(InMenuDesc), MoveTemp(InToolTip), InGrouping)
		, NodeTemplate(nullptr)
		, ParentGraphNode(nullptr)
	{}

	//~ Begin FEdGraphSchemaAction Interface
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode = true) override;
	virtual UEdGraphNode* PerformAction(class UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins, const FVector2D Location, bool bSelectNewNode = true) override;
	virtual void AddReferencedObjects(FReferenceCollector& Collector) override;
	//~ End FEdGraphSchemaAction Interface
};


UCLASS()
class UEdGraphSchema_FSM : public UEdGraphSchema
{
	GENERATED_BODY()

public:
	//~ Begin EdGraphSchema Interface
	/** 为图表创建默认根节点 */
	virtual void CreateDefaultNodesForGraph(UEdGraph& Graph) const override;
	/** 收集所有的状态类（UFSMRuntimeNode_State）构建图表行为，右键图表空白区域 */
	virtual void GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const override;
	/** 构建当前图表下所有节点的右键菜单 */
	virtual void GetContextMenuActions(class UToolMenu* Menu, class UGraphNodeContextMenuContext* Context) const override;
	/** 两节点间连接的条件 */
	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override;
	/** 两节点是否可以合并（未完成） */
	virtual const FPinConnectionResponse CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const override;
	/** 设置当前图表模式下所有引脚及连线的颜色 */
	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override;
	// TODO::完善后续函数注释
	virtual class FConnectionDrawingPolicy* CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID, float InZoomFactor, const FSlateRect& InClippingRect, class FSlateWindowElementList& InDrawElements, class UEdGraph* InGraphObj) const override;
	virtual bool IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const override;
	virtual int32 GetCurrentVisualizationCacheID() const override;
	virtual void ForceVisualizationCacheClear() const override;
	//~ End EdGraphSchema Interface

	/* 扩展节点右键菜单，如为节点添加装饰器、添加行为等等 */
	virtual void GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder, EFSMSubNodeType SubNodeFlags) const;
	virtual void GetSubNodeClasses(EFSMSubNodeType SubNodeFlags, TArray<FGraphNodeClassData>& ClassData, UClass*& GraphNodeClass) const;

protected:
	static TSharedPtr<FFSMSchemaAction_NewNode> AddNewNodeAction(FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip);
	static TSharedPtr<FFSMSchemaAction_NewSubNode> AddNewSubNodeAction(FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip);
};
