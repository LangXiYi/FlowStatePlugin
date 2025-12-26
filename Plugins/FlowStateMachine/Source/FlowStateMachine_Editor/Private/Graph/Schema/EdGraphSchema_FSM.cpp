#include "Graph/Schema/EdGraphSchema_FSM.h"

#include "FlowStateMachineEditorTypes.h"
#include "FlowStateMachine_Editor.h"
#include "GraphEditorActions.h"
#include "ToolMenu.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "Graph/Node/FSMGraphNode.h"
#include "Graph/Node/FSMGraphSubNode.h"
#include "SM/FSMRuntimeNode.h"

UEdGraphNode* FFSMSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
	const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode* ResultNode = nullptr;
	// 创建图表节点
	if (NodeTemplate != nullptr)
	{
		ParentGraph->Modify();
		if (FromPin)
		{
			FromPin->Modify();
		}

		// 通过 Rename 函数重设节点模板的 Outer，之前的 Outer 为临时图表
		NodeTemplate->Rename(NULL, ParentGraph, REN_NonTransactional);
		ParentGraph->AddNode(NodeTemplate, true);

		NodeTemplate->CreateNewGuid();
		NodeTemplate->PostPasteNode();

		NodeTemplate->NodePosX = Location.X;
		NodeTemplate->NodePosY = Location.Y;
		
		NodeTemplate->AllocateDefaultPins();
		NodeTemplate->AutowireNewNode(FromPin);

		ResultNode = NodeTemplate;

	}
	return ResultNode;
}

UEdGraphNode* FFSMSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins,
	const FVector2D Location, bool bSelectNewNode)
{
	// TODO::
	return FEdGraphSchemaAction::PerformAction(ParentGraph, FromPins, Location, bSelectNewNode);
}

void FFSMSchemaAction_NewNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	ParentGraphNode->AddSubNode(NodeTemplate, ParentGraph);
	return NULL;
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins, const FVector2D Location, bool bSelectNewNode)
{
	return PerformAction(ParentGraph, NULL, Location, bSelectNewNode);
}

void FFSMSchemaAction_NewSubNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);

	// These don't get saved to disk, but we want to make sure the objects don't get GC'd while the action array is around
	Collector.AddReferencedObject(NodeTemplate);
	Collector.AddReferencedObject(ParentGraphNode);
}

void UEdGraphSchema_FSM::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	Super::CreateDefaultNodesForGraph(Graph);
	FGraphNodeCreator<UFSMGraphNode_Root> NodeCreator(Graph);
	UFSMGraphNode_Root* RootNode = NodeCreator.CreateNode();
	NodeCreator.Finalize();
	SetNodeMetaData(RootNode, FNodeMetadata::DefaultGraphNode);
}

void UEdGraphSchema_FSM::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	// 搜集所有的 FlowState 类型并添加该节点行为

	FFlowStateMachine_EditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>("FlowStateMachine_Editor");
	TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();

	bool bIsAllowCreateState = true;

	// 收集所有状态节点
	if (bIsAllowCreateState)
	{
		FCategorizedGraphActionListBuilder TasksBuilder(TEXT("FlowState"));

		TArray<FGraphNodeClassData> NodeClasses;
		ClassCache->GatherClasses(UFSMRuntimeNode_State::StaticClass(), NodeClasses);

		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));
			// 添加操作行为到图表右键菜单
			TSharedPtr<FFSMSchemaAction_NewNode> AddOpAction = AddNewNodeAction(TasksBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());

			// 创建一个图表节点的模板给操作类
			UFSMGraphNode* OpNode = NewObject<UFSMGraphNode>(ContextMenuBuilder.OwnerOfTemporaries, UFSMGraphNode_State::StaticClass());
			OpNode->ClassData = NodeClass;
			AddOpAction->NodeTemplate = OpNode;
		}

		ContextMenuBuilder.Append(TasksBuilder);
	}
	
	Super::GetGraphContextActions(ContextMenuBuilder);
}

void UEdGraphSchema_FSM::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
	// TODO::添加刷新节点操作

	// TODO::添加 Debug 功能
	
	Super::GetContextMenuActions(Menu, Context);
}

FLinearColor UEdGraphSchema_FSM::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
	return FLinearColor::Blue;
	// return Super::GetPinTypeColor(PinType);
}

FConnectionDrawingPolicy* UEdGraphSchema_FSM::CreateConnectionDrawingPolicy(int32 InBackLayerID, int32 InFrontLayerID,
	float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements,
	UEdGraph* InGraphObj) const
{
	return Super::CreateConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect,
	                                            InDrawElements, InGraphObj);
}

bool UEdGraphSchema_FSM::IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const
{
	return Super::IsCacheVisualizationOutOfDate(InVisualizationCacheID);
}

int32 UEdGraphSchema_FSM::GetCurrentVisualizationCacheID() const
{
	return Super::GetCurrentVisualizationCacheID();
}

void UEdGraphSchema_FSM::ForceVisualizationCacheClear() const
{
	Super::ForceVisualizationCacheClear();
}

void UEdGraphSchema_FSM::GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder,
	EFSMSubNodeType SubNodeFlags) const
{
	/*
	 * 收集所有的子节点加入到节点右键菜单中
	 */
	UClass* GraphNodeClass = nullptr;
	TArray<FGraphNodeClassData> NodeClasses;
	GetSubNodeClasses(SubNodeFlags, NodeClasses, GraphNodeClass);

	if (GraphNodeClass)
	{
		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));

			// 创建一个子节点模板
			UFSMGraphSubNode* OpNode = NewObject<UFSMGraphSubNode>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
			OpNode->ClassData = NodeClass;

			TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = UEdGraphSchema_FSM::AddNewSubNodeAction(ContextMenuBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			// 记录操作的父级节点为当前图表选中的首个节点
			AddOpAction->ParentGraphNode = Cast<UFSMGraphNode>(ContextMenuBuilder.SelectedObjects[0]);
			AddOpAction->NodeTemplate = OpNode;
		}
	}
}

void UEdGraphSchema_FSM::GetSubNodeClasses(EFSMSubNodeType SubNodeFlags, TArray<FGraphNodeClassData>& ClassData,
                                           UClass*& GraphNodeClass) const
{
	FFlowStateMachine_EditorModule& EditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>(TEXT("FlowStateMachine_Editor"));
	FGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();
	switch (SubNodeFlags)
	{
	case EFSMSubNodeType::None:
		checkNoEntry()
		break;
	case EFSMSubNodeType::Condition:
		ClassCache->GatherClasses(UFSMRuntimeNode_Condition::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphNode_Condition::StaticClass();
		break;
	case EFSMSubNodeType::Action:
		ClassCache->GatherClasses(UFSMRuntimeNode_Action::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphNode_Action::StaticClass();
		break;
	case EFSMSubNodeType::Service:
		ClassCache->GatherClasses(UFSMRuntimeNode_Service::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphNode_Service::StaticClass();
		break;
	}
}

TSharedPtr<FFSMSchemaAction_NewNode> UEdGraphSchema_FSM::AddNewNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FFSMSchemaAction_NewNode> NewAction = MakeShareable(new FFSMSchemaAction_NewNode(Category, MenuDesc, Tooltip, 0));
	ContextMenuBuilder.AddAction(NewAction);
	return NewAction;
}

TSharedPtr<FFSMSchemaAction_NewSubNode> UEdGraphSchema_FSM::AddNewSubNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FFSMSchemaAction_NewSubNode> NewAction = MakeShareable(new FFSMSchemaAction_NewSubNode(Category, MenuDesc, Tooltip, 0));
	ContextMenuBuilder.AddAction(NewAction);
	return NewAction;
}

const FPinConnectionResponse UEdGraphSchema_FSM::CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const
{
	FPinConnectionResponse Response;

	// TODO::控制两个引脚之间是否可以连接
	// A->Direction != B->Direction;
	if (A == nullptr || B == nullptr)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("A || B is nullptr."));
	}
	if (A->Direction == B->Direction)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("A Direction == B Direction."));
	}

	
	
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_AB, "");
}

const FPinConnectionResponse UEdGraphSchema_FSM::CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const
{
	// TODO::合并子节点与父节点
	if (A == B)
	{
		return FPinConnectionResponse(ECanCreateConnectionResponse::CONNECT_RESPONSE_DISALLOW, TEXT("Both are the same node."));
	}

	const bool bNodeAIsCondition = A->IsA(UFSMGraphNode_Condition::StaticClass());
	const bool bNodeAIsAction = A->IsA(UFSMRuntimeNode_Action::StaticClass());

	const bool bNodeBIsState = B->IsA(UFSMGraphNode_State::StaticClass());
	const bool bNodeBIsCondition = B->IsA(UFSMGraphNode_Condition::StaticClass());
	const bool bNodeBIsAction = B->IsA(UFSMRuntimeNode_Action::StaticClass());

	if ((bNodeAIsCondition && (bNodeBIsState || bNodeBIsCondition))
		|| (bNodeAIsAction && (bNodeBIsState || bNodeAIsAction)))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Merge"));
	}

	return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT(""));
}
