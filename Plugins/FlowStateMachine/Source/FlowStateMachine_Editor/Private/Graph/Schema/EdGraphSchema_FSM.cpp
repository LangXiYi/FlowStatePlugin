#include "Graph/Schema/EdGraphSchema_FSM.h"

#include "Graph/Node/FSMGraphNode.h"
#include "Graph/Node/FSMGraphNode_State.h"
#include "Graph/Node/FSMGraphNode_StateMachine.h"
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

		ParentGraph->AddNode(NodeTemplate);

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
	// TODO:: Create Root Node

}

void UEdGraphSchema_FSM::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{

	// TODO::仅测试
	// GetGraphNodeContextActions(ContextMenuBuilder, EFSMNodeType::State);
	// GetGraphNodeContextActions(ContextMenuBuilder, EFSMNodeType::StateMachine);
	UEdGraph* Graph = (UEdGraph*)ContextMenuBuilder.CurrentGraph;
	UFSMGraphNode* OpNode = NewObject<UFSMGraphNode>(Graph, UFSMGraphNode_State::StaticClass());
	// OpNode->ClassData = NodeClass;
	 TSharedPtr<FFSMSchemaAction_NewNode>  NewAction = AddNewNodeAction(ContextMenuBuilder, FText::FromString("Default"), FText::FromString("AddNode"), FText::FromString("Tooltip"));	
	NewAction->NodeTemplate = OpNode;


	/*TSharedPtr<FFSMSchemaAction_NewState> NewStateAction = MakeShareable(new FFSMSchemaAction_NewState(
		// TODO::需要在后续修改该部分的类型
		UFSMGraphNode::StaticClass(),
		FText::FromString("Flow State"),
		FText::FromString("New state"),
		FText::FromString("Create a new state"),
		0
	));

	NewStateAction;
	
	ContextMenuBuilder.AddAction(NewStateAction);

	TSharedPtr<FFSMSchemaAction_NewMachine> NewStateMachineAction = MakeShareable(new FFSMSchemaAction_NewMachine(
			// TODO::需要在后续修改该部分的类型
			UEdGraphNode::StaticClass(),
			FText::FromString("Flow State Machine"),
			FText::FromString("New state machine"),
			FText::FromString("Create a new state machine"),
			0
		));
	ContextMenuBuilder.AddAction(NewStateMachineAction);*/

	

	// Add New State

	// Add New State Machine
	
	/*const FName PinCategory = ContextMenuBuilder.FromPin ?
		ContextMenuBuilder.FromPin->PinType.PinCategory : 
		UBehaviorTreeEditorTypes::PinCategory_MultipleNodes;

	const bool bNoParent = (ContextMenuBuilder.FromPin == NULL);
	const bool bOnlyTasks = (PinCategory == UBehaviorTreeEditorTypes::PinCategory_SingleTask);
	const bool bOnlyComposites = (PinCategory == UBehaviorTreeEditorTypes::PinCategory_SingleComposite);
	const bool bAllowComposites = bNoParent || !bOnlyTasks || bOnlyComposites;
	const bool bAllowTasks = bNoParent || !bOnlyComposites || bOnlyTasks;

	FBehaviorTreeEditorModule& EditorModule = FModuleManager::GetModuleChecked<FBehaviorTreeEditorModule>(TEXT("BehaviorTreeEditor"));
	FGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();

	if (bAllowComposites)
	{
		FCategorizedGraphActionListBuilder CompositesBuilder(TEXT("Composites"));

		TArray<FGraphNodeClassData> NodeClasses;
		ClassCache->GatherClasses(UBTCompositeNode::StaticClass(), NodeClasses);

		const FString ParallelClassName = UBTComposite_SimpleParallel::StaticClass()->GetName();
		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));

			TSharedPtr<FAISchemaAction_NewNode> AddOpAction = UAIGraphSchema::AddNewNodeAction(CompositesBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());

			UClass* GraphNodeClass = UBehaviorTreeGraphNode_Composite::StaticClass();
			if (NodeClass.GetClassName() == ParallelClassName)
			{
				GraphNodeClass = UBehaviorTreeGraphNode_SimpleParallel::StaticClass();
			}

			UBehaviorTreeGraphNode* OpNode = NewObject<UBehaviorTreeGraphNode>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
			OpNode->ClassData = NodeClass;
			AddOpAction->NodeTemplate = OpNode;
		}

		ContextMenuBuilder.Append(CompositesBuilder);
	}

	if (bAllowTasks)
	{
		FCategorizedGraphActionListBuilder TasksBuilder(TEXT("Tasks"));

		TArray<FGraphNodeClassData> NodeClasses;
		ClassCache->GatherClasses(UBTTaskNode::StaticClass(), NodeClasses);

		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));

			TSharedPtr<FAISchemaAction_NewNode> AddOpAction = UAIGraphSchema::AddNewNodeAction(TasksBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			
			UClass* GraphNodeClass = UBehaviorTreeGraphNode_Task::StaticClass();
			if (NodeClass.GetClassName() == UBTTask_RunBehavior::StaticClass()->GetName())
			{
				GraphNodeClass = UBehaviorTreeGraphNode_SubtreeTask::StaticClass();
			}

			UBehaviorTreeGraphNode* OpNode = NewObject<UBehaviorTreeGraphNode>(ContextMenuBuilder.OwnerOfTemporaries, GraphNodeClass);
			OpNode->ClassData = NodeClass;
			AddOpAction->NodeTemplate = OpNode;
		}

		ContextMenuBuilder.Append(TasksBuilder);
	}
	
	if (bNoParent)
	{
		TSharedPtr<FBehaviorTreeSchemaAction_AutoArrange> Action = TSharedPtr<FBehaviorTreeSchemaAction_AutoArrange>(
			new FBehaviorTreeSchemaAction_AutoArrange(FText::GetEmpty(), LOCTEXT("AutoArrange", "Auto Arrange"), FText::GetEmpty(), 0)
			);

		ContextMenuBuilder.AddAction(Action);
	}*/
	Super::GetGraphContextActions(ContextMenuBuilder);
}

void UEdGraphSchema_FSM::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
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
	int32 SubNodeFlags) const
{
	UEdGraph* Graph = (UEdGraph*)ContextMenuBuilder.CurrentGraph;
	UClass* GraphNodeClass = nullptr;
	TArray<FFSMGraphNodeClassData> NodeClasses;
	GetSubNodeClasses(SubNodeFlags, NodeClasses, GraphNodeClass);

	if (GraphNodeClass)
	{
		for (const auto& NodeClass : NodeClasses)
		{
			const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClass.ToString(), false));

			UFSMGraphNode* OpNode = NewObject<UFSMGraphNode>(Graph, GraphNodeClass);
			OpNode->ClassData = NodeClass;

			TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = UEdGraphSchema_FSM::AddNewSubNodeAction(ContextMenuBuilder, NodeClass.GetCategory(), NodeTypeName, FText::GetEmpty());
			// AddOpAction->ParentGraphNode = Cast<UFSMGraphNode>(ContextMenuBuilder.SelectedObjects[0]);
			AddOpAction->NodeTemplate = OpNode;
		}
	}
}

void UEdGraphSchema_FSM::GetSubNodeClasses(int32 SubNodeFlags, TArray<FFSMGraphNodeClassData>& ClassData,
                                           UClass*& GraphNodeClass) const
{
	if (SubNodeFlags == EFSMNodeType::State)
	{
		FFSMGraphNodeClassData Data(UFSMRuntimeNode_State::StaticClass(), "");
		ClassData = {Data};
		GraphNodeClass = UFSMGraphNode_State::StaticClass();
	}
	else if (SubNodeFlags == EFSMNodeType::StateMachine)
	{
		FFSMGraphNodeClassData Data(UFSMRuntimeNode_StateMachine::StaticClass(), "");
		ClassData = {Data};
		GraphNodeClass = UFSMGraphNode_StateMachine::StaticClass();
	}
	/*FBehaviorTreeEditorModule& EditorModule = FModuleManager::GetModuleChecked<FBehaviorTreeEditorModule>(TEXT("BehaviorTreeEditor"));
	FGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();

	if (SubNodeFlags == ESubNode::Decorator)
	{
		ClassCache->GatherClasses(UBTDecorator::StaticClass(), ClassData);
		GraphNodeClass = UBehaviorTreeGraphNode_Decorator::StaticClass();
	}
	else
	{
		ClassCache->GatherClasses(UBTService::StaticClass(), ClassData);
		GraphNodeClass = UBehaviorTreeGraphNode_Service::StaticClass();
	}*/
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
	return Super::CanMergeNodes(A, B);
}
