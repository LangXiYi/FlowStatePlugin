#include "Graph/Schema/EdGraphSchema_FSM.h"

UEdGraphNode* FFSMSchemaAction_NewMachine::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
	const FVector2D Location, bool bSelectNewNode)
{
	UEdGraphNode* Node = NewObject<UEdGraphNode>(ParentGraph, NodeParentClass);
	Node->CreateNewGuid();
	Node->NodePosX = Location.X;
	Node->NodePosY = Location.Y;

	// TODO::创建输入输出引脚
	UEdGraphPin* Input = Node->CreatePin(EGPD_Input, "InputPin", "From");
	Node->CreatePin(EGPD_Output, "OutputPin", "Output_1");
	Node->CreatePin(EGPD_Output, "OutputPin", "Output_2");
	Node->CreatePin(EGPD_Output, "OutputPin", "Output_3");

	// From引脚有效时会尝试将引脚连接至新建的节点
	if (FromPin)
	{
		Node->GetSchema()->TryCreateConnection(FromPin, Input);
	}
	ParentGraph->Modify();
	ParentGraph->AddNode(Node);
	return Node;
}

void UEdGraphSchema_FSM::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
	Super::CreateDefaultNodesForGraph(Graph);
	// TODO:: Create Root Node

}

void UEdGraphSchema_FSM::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	TSharedPtr<FFSMSchemaAction_NewMachine> NewMachineAction = MakeShareable(new FFSMSchemaAction_NewMachine(
		// TODO::需要在后续修改该部分的类型
		UEdGraphNode::StaticClass(),
		FText::FromString("Flow State Machine"),
		FText::FromString("New state machine"),
		FText::FromString("Create a new state machine"),
		0
	));
	ContextMenuBuilder.AddAction(NewMachineAction);
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
