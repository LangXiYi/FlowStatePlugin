#include "Graph/Schema/EdGraphSchema_FSM.h"

#include "FSMEditorTypes.h"
#include "FlowStateMachine_EditorModule.h"
#include "GraphEditorActions.h"
#include "ToolMenu.h"
#include "Graph/FSMGraph.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "Node/FSMGraphNode.h"
#include "Node/FSMGraphNode_Composites.h"
#include "Node/FSMGraphSubNode.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "RuntimeNode/FSMRuntimeNode_State.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "Node/FSMGraphNode_Root.h"
#include "Node/FSMGraphNode_State.h"
#include "Node/Composites/FSMGraphNode_Jump.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"

UEdGraphNode* FFSMSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
                                                      const FVector2D Location, bool bSelectNewNode)
{
	UFSMGraphNodeBase* ResultNode = nullptr;
	// 创建图表节点
	if (NodeTemplateClass != nullptr)
	{
		ParentGraph->Modify();
		if (FromPin)
		{
			FromPin->Modify();
		}

		ResultNode = NewObject<UFSMGraphNodeBase>(ParentGraph, NodeTemplateClass);
		InitializeGraphNode(ResultNode);

		ResultNode->CreateNewGuid();
		ResultNode->PostPlacedNewNode();

		ResultNode->NodePosX = Location.X;
		ResultNode->NodePosY = Location.Y;
		
		ResultNode->AllocateDefaultPins();
		ResultNode->AutowireNewNode(FromPin);

		ParentGraph->AddNode(ResultNode, true);
	}
	return ResultNode;
}

UEdGraphNode* FFSMSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins,
	const FVector2D Location, bool bSelectNewNode)
{
	return FEdGraphSchemaAction::PerformAction(ParentGraph, FromPins, Location, bSelectNewNode);
}

void FFSMSchemaAction_NewNode::InitializeGraphNode(UFSMGraphNodeBase* GraphNode)
{
	GraphNode->ClassData = ClassData;
}

void FFSMSchemaAction_NewJumpNode::InitializeGraphNode(UFSMGraphNodeBase* GraphNode)
{
	FFSMSchemaAction_NewNode::InitializeGraphNode(GraphNode);

	if (UFSMGraphNode_JumpTo* JumpToNode = Cast<UFSMGraphNode_JumpTo>(GraphNode))
	{
		JumpToNode->JumpStartId = JumpStartID;
	}
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode)
{
	// TODO::子节点需要放置在父节点上才能正确添加，获取当前鼠标悬浮的节点设置为 ParentGraphNode
	if (ParentGraphNode != nullptr)
	{
		UFSMGraphSubNode* ResultNode = NewObject<UFSMGraphSubNode>(ParentGraph, NodeTemplateClass);
		ResultNode->ClassData = ClassData;
		ParentGraphNode->AddSubNode(ResultNode, ParentGraph);
	}
	return nullptr;
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins, const FVector2D Location, bool bSelectNewNode)
{
	return PerformAction(ParentGraph, NULL, Location, bSelectNewNode);
}

void FFSMSchemaAction_NewSubNode::AddReferencedObjects(FReferenceCollector& Collector)
{
	FEdGraphSchemaAction::AddReferencedObjects(Collector);

	// These don't get saved to disk, but we want to make sure the objects don't get GC'd while the action array is around
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
	bool bIsAllowCreateComposites = true;

	// 收集所有状态节点
	if (bIsAllowCreateState)
	{
		FCategorizedGraphActionListBuilder TasksBuilder(TEXT("FlowState"));

		CollectNewNodeAction(
			TasksBuilder,
			UFSMRuntimeNode_State::StaticClass(),
			UFSMGraphNode_State::StaticClass(),
			ContextMenuBuilder.CurrentGraph);
		ContextMenuBuilder.Append(TasksBuilder);
	}

	if (bIsAllowCreateComposites)
	{
		// Composites Nodes
		FCategorizedGraphActionListBuilder TasksBuilder(TEXT("Composites"));
		TArray<FGraphNodeClassData> CompositesNodeClasses;
		ClassCache->GatherClasses(UFSMRuntimeNode_Composites::StaticClass(), CompositesNodeClasses);
		for (FGraphNodeClassData& NodeClass : CompositesNodeClasses)
		{
			UClass* CompositesGraphNodeClass = UEdGraphSchema_FSM::GetCompositesGraphNodeClass(NodeClass.GetClass());
			CollectNewNodeAction(
				TasksBuilder,
				NodeClass.GetClass(),
				CompositesGraphNodeClass,
				ContextMenuBuilder.CurrentGraph);
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
		for (const auto& NodeClassData : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClassData.ToString(), false));

			TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = UEdGraphSchema_FSM::AddNewSubNodeAction(ContextMenuBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
			// 记录操作的父级节点为当前图表选中的首个节点
			AddOpAction->ParentGraphNode = Cast<UFSMGraphNode>(ContextMenuBuilder.SelectedObjects[0]);
			AddOpAction->NodeTemplateClass = GraphNodeClass;
			AddOpAction->ClassData = NodeClassData;
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
		ClassCache->GatherClasses(UFSMRuntimeSubNode_Condition::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphSubNode_Condition::StaticClass();
		break;
	case EFSMSubNodeType::Action:
		ClassCache->GatherClasses(UFSMRuntimeSubNode_Action::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphSubNode_Action::StaticClass();
		break;
	case EFSMSubNodeType::Service:
		ClassCache->GatherClasses(UFSMRuntimeSubNode_Service::StaticClass(), ClassData);
		GraphNodeClass = UFSMGraphSubNode_Service::StaticClass();
		break;
	}
}

void UEdGraphSchema_FSM::CollectNewNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
	UClass* RuntimeNodeClass, UClass* GraphNodeClass, const UEdGraph* InGraph)
{
	if (InGraph == nullptr)
	{
		return;
	}
	FFlowStateMachine_EditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>("FlowStateMachine_Editor");
	TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();
	
	TArray<FGraphNodeClassData> NodeClasses;
	ClassCache->GatherClasses(RuntimeNodeClass, NodeClasses);

	for (auto& NodeClassData : NodeClasses)
	{
		if (NodeClassData.GetClass(true) == nullptr)
		{
			continue;
		}
		// Action Switcher 控制行为创建
		if (NodeClassData.GetClass() == UFSMRuntimeNode_JumpTo::StaticClass())
		{
			CollectJumpNodeAction(TasksBuilder, NodeClassData, GraphNodeClass, InGraph);
		}
		else
		{
			//////////////////////////////////
			// Default Action
			//////////////////////////////////
			
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClassData.ToString(), false));
			// 添加创建状态节点到图表右键菜单
			TSharedPtr<FFSMSchemaAction_NewNode> AddOpAction = AddNewNodeAction(TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());

			// 创建一个图表节点的模板给操作类
			AddOpAction->NodeTemplateClass = GraphNodeClass;
			AddOpAction->ClassData = NodeClassData;
		}
	}
}

void UEdGraphSchema_FSM::CollectNewSubNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
                                                 UClass* RuntimeNodeClass, UClass* GraphNodeClass, const UEdGraph* Owner)
{
	if (Owner == nullptr)
	{
		return;
	}
	FFlowStateMachine_EditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateMachine_EditorModule>("FlowStateMachine_Editor");
	TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();
	
	TArray<FGraphNodeClassData> NodeClasses;
	ClassCache->GatherClasses(RuntimeNodeClass, NodeClasses);

	for (auto& NodeClassData : NodeClasses)
	{
		if (NodeClassData.GetClass(true) == nullptr)
		{
			continue;
		}
		const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClassData.ToString(), false));

		TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = UEdGraphSchema_FSM::AddNewSubNodeAction(TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
		// 记录操作的父级节点为当前图表选中的首个节点
		AddOpAction->NodeTemplateClass = GraphNodeClass;
		AddOpAction->ClassData = NodeClassData;
	}
}

void UEdGraphSchema_FSM::CollectJumpNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
	const FGraphNodeClassData& NodeClassData, UClass* GraphNodeClass, const UEdGraph* InGraph)
{
	 const auto& GetJumpToActionName = [](const UFSMGraphNodeBase* InGraphNode)->FText
	 {
		 if (InGraphNode && InGraphNode->RuntimeNode)
		 {
		 	return FText::FromString(TEXT("Jump To ---> ") + InGraphNode->RuntimeNode->GetNodeName());
		 }
		 return FText::FromString(TEXT("Error None"));
	 };
	
	if (const UFSMGraph* MyGraph = Cast<UFSMGraph>(InGraph))
	{
		// 查找图表中的所有零散节点
		for (const UFSMGraphNode* ScatteredNode : MyGraph->GetScatteredNodes())
		{
			if (const UFSMGraphNode_JumpStart* JumpStartNode = Cast<UFSMGraphNode_JumpStart>(ScatteredNode))
			{
				const FText NodeTypeName = GetJumpToActionName(JumpStartNode);
				// 添加创建状态节点到图表右键菜单
				TSharedPtr<FFSMSchemaAction_NewJumpNode> AddOpAction = AddNewJumpNodeAction(TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
				AddOpAction->NodeTemplateClass = GraphNodeClass;
				AddOpAction->ClassData = NodeClassData;
				AddOpAction->JumpStartID = JumpStartNode->JumpStartId;
			}
		}
	}
}

TSharedPtr<FFSMSchemaAction_NewNode> UEdGraphSchema_FSM::AddNewNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FFSMSchemaAction_NewNode> NewAction = MakeShareable(new FFSMSchemaAction_NewNode(Category, MenuDesc, Tooltip, 0));
	ContextMenuBuilder.AddAction(NewAction);
	return NewAction;
}

TSharedPtr<FFSMSchemaAction_NewJumpNode> UEdGraphSchema_FSM::AddNewJumpNodeAction(
	FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
	TSharedPtr<FFSMSchemaAction_NewJumpNode> NewAction = MakeShareable(new FFSMSchemaAction_NewJumpNode(Category, MenuDesc, Tooltip, 0));
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

UClass* UEdGraphSchema_FSM::GetCompositesGraphNodeClass(const UClass* RuntimeNodeClass)
{
	if (RuntimeNodeClass == (UFSMRuntimeNode_JumpStart::StaticClass()))
	{
		return UFSMGraphNode_JumpStart::StaticClass();
	}
	if (RuntimeNodeClass == (UFSMRuntimeNode_JumpTo::StaticClass()))
	{
		return UFSMGraphNode_JumpTo::StaticClass();
	}
	// 返回默认的图表节点
	return UFSMGraphNode_Composites::StaticClass();
}

const FPinConnectionResponse UEdGraphSchema_FSM::CanCreateConnection(const UEdGraphPin* PinA, const UEdGraphPin* PinB) const
{
	if (PinA == nullptr || PinB == nullptr)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Invalid Pin"));
	}

	const UFSMGraphNodeBase* OwningNodeA = Cast<UFSMGraphNodeBase>(PinA->GetOwningNodeUnchecked());
	const UFSMGraphNodeBase* OwningNodeB = Cast<UFSMGraphNodeBase>(PinB->GetOwningNodeUnchecked());

	if (!OwningNodeA || !OwningNodeB)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Invalid nodes"));
	}

	// Make sure the pins are not on the same node
	if (OwningNodeA == OwningNodeB)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Both are on the same node"));
	}
	
	if (PinA->Direction == PinB->Direction)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("PinA Direction == PinB Direction."));
	}

	// 从输入节点向输出节点连接
	if (PinA->Direction == EGPD_Input)
	{
		return OwningNodeB->CheckPinConnection(OwningNodeA, PinA->Direction);
	}
	else
	{
		return OwningNodeA->CheckPinConnection(OwningNodeB, PinA->Direction);
	}
}

const FPinConnectionResponse UEdGraphSchema_FSM::CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const
{
	// TODO::合并子节点与父节点
	/*if (A == B)
	{
		return FPinConnectionResponse(ECanCreateConnectionResponse::CONNECT_RESPONSE_DISALLOW, TEXT("Both are the same node."));
	}

	const bool bNodeAIsCondition = A->IsA(UFSMGraphSubNode_Condition::StaticClass());
	const bool bNodeAIsAction = A->IsA(UFSMRuntimeSubNode_Action::StaticClass());

	const bool bNodeBIsState = B->IsA(UFSMGraphNode_State::StaticClass());
	const bool bNodeBIsCondition = B->IsA(UFSMGraphSubNode_Condition::StaticClass());
	const bool bNodeBIsAction = B->IsA(UFSMRuntimeSubNode_Action::StaticClass());

	if ((bNodeAIsCondition && (bNodeBIsState || bNodeBIsCondition))
		|| (bNodeAIsAction && (bNodeBIsState || bNodeAIsAction)))
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Merge"));
	}*/

	return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT(""));
}

