#include "Graph/FlowStateGraphSchema.h"

#include "Utility/FlowStateEditorType.h"
#include "FlowStateEditorModule.h"
#include "GraphEditorActions.h"
#include "ToolMenu.h"
#include "Graph/FlowStateGraph.h"
#include "AIGraph/Classes/AIGraphTypes.h"
#include "Node/Composites/FSGraph_CompositeNode.h"
#include "Node/FSGraphNode.h"
#include "Node/FSGraph_RootNode.h"
#include "Node/FSGraph_StateNode.h"
#include "Node/FSGraphSubNode.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "Node/Composites/Composite_JumpNode.h"
#include "SM/Composites/FlowStateComposite.h"
#include "SM/Actions/FlowStateAction.h"
#include "SM/FlowStateBase.h"
#include "SM/Conditions/FlowStateCondition.h"
#include "SM/Services/FlowStateService.h"
#include "SM/Composites/Composite_Jump.h"

USING_FLOWSTATE_EDITORTYPE

UEdGraphNode* FFSMSchemaAction_NewNode::PerformAction(UEdGraph* ParentGraph, UEdGraphPin* FromPin,
                                                      const FVector2D Location, bool bSelectNewNode)
{
    UFSGraphNodeBase* ResultNode = nullptr;
    // 创建图表节点
    if (NodeTemplateClass != nullptr)
    {
        ParentGraph->Modify();
        if (FromPin)
        {
            FromPin->Modify();
        }

        ResultNode = NewObject<UFSGraphNodeBase>(ParentGraph, NodeTemplateClass);
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

void FFSMSchemaAction_NewNode::InitializeGraphNode(UFSGraphNodeBase* GraphNode)
{
    GraphNode->ClassData = ClassData;
}

void FFSMSchemaAction_NewJumpNode::InitializeGraphNode(UFSGraphNodeBase* GraphNode)
{
    FFSMSchemaAction_NewNode::InitializeGraphNode(GraphNode);

    if (UGraphCNode_JumpTo* JumpToNode = Cast<UGraphCNode_JumpTo>(GraphNode))
    {
        JumpToNode->JumpStartId = JumpStartID;
    }
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin,
                                                         const FVector2D Location, bool bSelectNewNode)
{
    // TODO::子节点需要放置在父节点上才能正确添加，获取当前鼠标悬浮的节点设置为 ParentGraphNode
    if (ParentGraphNode != nullptr)
    {
        UFSGraphSubNode* ResultNode = NewObject<UFSGraphSubNode>(ParentGraph, NodeTemplateClass);
        ResultNode->ClassData = ClassData;
        ParentGraphNode->AddSubNode(ResultNode, ParentGraph);
    }
    return nullptr;
}

UEdGraphNode* FFSMSchemaAction_NewSubNode::PerformAction(class UEdGraph* ParentGraph, TArray<UEdGraphPin*>& FromPins,
                                                         const FVector2D Location, bool bSelectNewNode)
{
    return PerformAction(ParentGraph, nullptr, Location, bSelectNewNode);
}

void FFSMSchemaAction_NewSubNode::AddReferencedObjects(FReferenceCollector& Collector)
{
    FEdGraphSchemaAction::AddReferencedObjects(Collector);

    // These don't get saved to disk, but we want to make sure the objects don't get GC'd while the action array is around
    Collector.AddReferencedObject(ParentGraphNode);
}

void UFlowStateGraphSchema::CreateDefaultNodesForGraph(UEdGraph& Graph) const
{
    Super::CreateDefaultNodesForGraph(Graph);
    FGraphNodeCreator<UFSGraph_RootNode> NodeCreator(Graph);
    UFSGraph_RootNode* RootNode = NodeCreator.CreateNode();
    NodeCreator.Finalize();
    SetNodeMetaData(RootNode, FNodeMetadata::DefaultGraphNode);
}

void UFlowStateGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
    // 搜集所有的 FlowState 类型并添加该节点行为

    FFlowStateEditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        "FlowStateEditor");
    TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();

    bool bIsAllowCreateState = true;
    bool bIsAllowCreateComposites = true;

    // 收集所有状态节点
    if (bIsAllowCreateState)
    {
        FCategorizedGraphActionListBuilder TasksBuilder(TEXT("FlowState"));

        CollectNewNodeAction(
            TasksBuilder,
            UFlowStateBase::StaticClass(),
            UFSGraph_StateNode::StaticClass(),
            ContextMenuBuilder.CurrentGraph);
        ContextMenuBuilder.Append(TasksBuilder);
    }

    if (bIsAllowCreateComposites)
    {
        // Composites Nodes
        FCategorizedGraphActionListBuilder TasksBuilder(TEXT("Composites"));
        TArray<FGraphNodeClassData> CompositesNodeClasses;
        ClassCache->GatherClasses(UFlowStateComposite::StaticClass(), CompositesNodeClasses);
        for (FGraphNodeClassData& NodeClass : CompositesNodeClasses)
        {
            UClass* CompositesGraphNodeClass = GetCompositesGraphNodeClass(NodeClass.GetClass());
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

void UFlowStateGraphSchema::GetContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const
{
    // TODO::添加刷新节点操作

    // TODO::添加 Debug 功能

    Super::GetContextMenuActions(Menu, Context);
}

FLinearColor UFlowStateGraphSchema::GetPinTypeColor(const FEdGraphPinType& PinType) const
{
    return FLinearColor::Blue;
    // return Super::GetPinTypeColor(PinType);
}

FConnectionDrawingPolicy* UFlowStateGraphSchema::CreateConnectionDrawingPolicy(
    int32 InBackLayerID, int32 InFrontLayerID,
    float InZoomFactor, const FSlateRect& InClippingRect, FSlateWindowElementList& InDrawElements,
    UEdGraph* InGraphObj) const
{
    return Super::CreateConnectionDrawingPolicy(InBackLayerID, InFrontLayerID, InZoomFactor, InClippingRect,
                                                InDrawElements, InGraphObj);
}

bool UFlowStateGraphSchema::IsCacheVisualizationOutOfDate(int32 InVisualizationCacheID) const
{
    return Super::IsCacheVisualizationOutOfDate(InVisualizationCacheID);
}

int32 UFlowStateGraphSchema::GetCurrentVisualizationCacheID() const
{
    return Super::GetCurrentVisualizationCacheID();
}

void UFlowStateGraphSchema::ForceVisualizationCacheClear() const
{
    Super::ForceVisualizationCacheClear();
}

void UFlowStateGraphSchema::GetGraphNodeContextActions(FGraphContextMenuBuilder& ContextMenuBuilder,
                                                       ESubNodeType SubNodeFlags) const
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

            TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = AddNewSubNodeAction(
                ContextMenuBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
            // 记录操作的父级节点为当前图表选中的首个节点
            AddOpAction->ParentGraphNode = Cast<UFSGraphNode>(ContextMenuBuilder.SelectedObjects[0]);
            AddOpAction->NodeTemplateClass = GraphNodeClass;
            AddOpAction->ClassData = NodeClassData;
        }
    }
}

void UFlowStateGraphSchema::GetSubNodeClasses(ESubNodeType SubNodeFlags, TArray<FGraphNodeClassData>& ClassData,
                                              UClass*& GraphNodeClass) const
{
    FFlowStateEditorModule& EditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        TEXT("FlowStateEditor"));
    FGraphNodeClassHelper* ClassCache = EditorModule.GetClassCache().Get();
    switch (SubNodeFlags)
    {
    case ESubNodeType::None:
        checkNoEntry()
        break;
    case ESubNodeType::Condition:
        ClassCache->GatherClasses(UFlowStateCondition::StaticClass(), ClassData);
        GraphNodeClass = UFSMGraphSubNode_Condition::StaticClass();
        break;
    case ESubNodeType::Action:
        ClassCache->GatherClasses(UFlowStateAction::StaticClass(), ClassData);
        GraphNodeClass = UFSMGraphSubNode_Action::StaticClass();
        break;
    case ESubNodeType::Service:
        ClassCache->GatherClasses(UFlowStateService::StaticClass(), ClassData);
        GraphNodeClass = UFSMGraphSubNode_Service::StaticClass();
        break;
    }
}

void UFlowStateGraphSchema::CollectNewNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
                                                 UClass* NodeInstanceClass, UClass* GraphNodeClass,
                                                 const UEdGraph* InGraph)
{
    if (InGraph == nullptr)
    {
        return;
    }
    FFlowStateEditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        "FlowStateEditor");
    TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();

    TArray<FGraphNodeClassData> NodeClasses;
    ClassCache->GatherClasses(NodeInstanceClass, NodeClasses);

    for (auto& NodeClassData : NodeClasses)
    {
        if (NodeClassData.GetClass(true) == nullptr)
        {
            continue;
        }
        // Action Switcher 控制行为创建
        if (NodeClassData.GetClass() == UCNodeIns_JumpTo::StaticClass())
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
            TSharedPtr<FFSMSchemaAction_NewNode> AddOpAction = AddNewNodeAction(
                TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());

            // 创建一个图表节点的模板给操作类
            AddOpAction->NodeTemplateClass = GraphNodeClass;
            AddOpAction->ClassData = NodeClassData;
        }
    }
}

void UFlowStateGraphSchema::CollectNewSubNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
                                                    UClass* NodeInstanceClass, UClass* GraphNodeClass,
                                                    const UEdGraph* Owner)
{
    if (Owner == nullptr)
    {
        return;
    }
    FFlowStateEditorModule& FSMEditorModule = FModuleManager::GetModuleChecked<FFlowStateEditorModule>(
        "FlowStateEditor");
    TSharedPtr<FGraphNodeClassHelper> ClassCache = FSMEditorModule.GetClassCache();

    TArray<FGraphNodeClassData> NodeClasses;
    ClassCache->GatherClasses(NodeInstanceClass, NodeClasses);

    for (auto& NodeClassData : NodeClasses)
    {
        if (NodeClassData.GetClass(true) == nullptr)
        {
            continue;
        }
        const FText NodeTypeName = FText::FromString(FName::NameToDisplayString(NodeClassData.ToString(), false));

        TSharedPtr<FFSMSchemaAction_NewSubNode> AddOpAction = AddNewSubNodeAction(
            TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
        // 记录操作的父级节点为当前图表选中的首个节点
        AddOpAction->NodeTemplateClass = GraphNodeClass;
        AddOpAction->ClassData = NodeClassData;
    }
}

void UFlowStateGraphSchema::CollectJumpNodeAction(FCategorizedGraphActionListBuilder& TasksBuilder,
                                                  const FGraphNodeClassData& NodeClassData, UClass* GraphNodeClass,
                                                  const UEdGraph* InGraph)
{
    const auto& GetJumpToActionName = [](const UFSGraphNodeBase* InGraphNode) -> FText
    {
        if (InGraphNode && InGraphNode->NodeInstance)
        {
            return FText::FromString(TEXT("Jump To ---> ") + InGraphNode->NodeInstance->GetNodeName());
        }
        return FText::FromString(TEXT("Error None"));
    };

    if (const UFlowStateGraph* MyGraph = Cast<UFlowStateGraph>(InGraph))
    {
        // 查找图表中的所有零散节点
        for (const UFSGraphNode* ScatteredNode : MyGraph->GetScatteredNodes())
        {
            if (const UGraphCNode_JumpStart* JumpStartNode = Cast<UGraphCNode_JumpStart>(ScatteredNode))
            {
                const FText NodeTypeName = GetJumpToActionName(JumpStartNode);
                // 添加创建状态节点到图表右键菜单
                TSharedPtr<FFSMSchemaAction_NewJumpNode> AddOpAction = AddNewJumpNodeAction(
                    TasksBuilder, NodeClassData.GetCategory(), NodeTypeName, FText::GetEmpty());
                AddOpAction->NodeTemplateClass = GraphNodeClass;
                AddOpAction->ClassData = NodeClassData;
                AddOpAction->JumpStartID = JumpStartNode->JumpStartId;
            }
        }
    }
}

TSharedPtr<FFSMSchemaAction_NewNode> UFlowStateGraphSchema::AddNewNodeAction(
    FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
    TSharedPtr<FFSMSchemaAction_NewNode> NewAction = MakeShareable(
        new FFSMSchemaAction_NewNode(Category, MenuDesc, Tooltip, 0));
    ContextMenuBuilder.AddAction(NewAction);
    return NewAction;
}

TSharedPtr<FFSMSchemaAction_NewJumpNode> UFlowStateGraphSchema::AddNewJumpNodeAction(
    FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
    TSharedPtr<FFSMSchemaAction_NewJumpNode> NewAction = MakeShareable(
        new FFSMSchemaAction_NewJumpNode(Category, MenuDesc, Tooltip, 0));
    ContextMenuBuilder.AddAction(NewAction);
    return NewAction;
}

TSharedPtr<FFSMSchemaAction_NewSubNode> UFlowStateGraphSchema::AddNewSubNodeAction(
    FGraphActionListBuilderBase& ContextMenuBuilder, const FText& Category, const FText& MenuDesc, const FText& Tooltip)
{
    TSharedPtr<FFSMSchemaAction_NewSubNode> NewAction = MakeShareable(
        new FFSMSchemaAction_NewSubNode(Category, MenuDesc, Tooltip, 0));
    ContextMenuBuilder.AddAction(NewAction);
    return NewAction;
}

UClass* UFlowStateGraphSchema::GetCompositesGraphNodeClass(const UClass* NodeInstanceClass)
{
    if (NodeInstanceClass == (UGraphCNode_JumpStart::StaticClass()))
    {
        return UGraphCNode_JumpStart::StaticClass();
    }
    if (NodeInstanceClass == (UGraphCNode_JumpTo::StaticClass()))
    {
        return UGraphCNode_JumpTo::StaticClass();
    }
    // 返回默认的图表节点
    return UFSGraph_CompositeNode::StaticClass();
}

const FPinConnectionResponse UFlowStateGraphSchema::CanCreateConnection(
    const UEdGraphPin* PinA, const UEdGraphPin* PinB) const
{
    if (PinA == nullptr || PinB == nullptr)
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("Invalid Pin"));
    }

    const UFSGraphNodeBase* OwningNodeA = Cast<UFSGraphNodeBase>(PinA->GetOwningNodeUnchecked());
    const UFSGraphNodeBase* OwningNodeB = Cast<UFSGraphNodeBase>(PinB->GetOwningNodeUnchecked());

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
    return OwningNodeA->CheckPinConnection(OwningNodeB, PinA->Direction);
}

const FPinConnectionResponse UFlowStateGraphSchema::CanMergeNodes(const UEdGraphNode* A, const UEdGraphNode* B) const
{
    // TODO::合并子节点与父节点
    /*if (A == B)
    {
        return FPinConnectionResponse(ECanCreateConnectionResponse::CONNECT_RESPONSE_DISALLOW, TEXT("Both are the same node."));
    }

    const bool bNodeAIsCondition = A->IsA(UFSMGraphSubNode_Condition::StaticClass());
    const bool bNodeAIsAction = A->IsA(UFlowStateAction::StaticClass());

    const bool bNodeBIsState = B->IsA(UFSMGraphNode_State::StaticClass());
    const bool bNodeBIsCondition = B->IsA(UFSMGraphSubNode_Condition::StaticClass());
    const bool bNodeBIsAction = B->IsA(UFlowStateAction::StaticClass());

    if ((bNodeAIsCondition && (bNodeBIsState || bNodeBIsCondition))
        || (bNodeAIsAction && (bNodeBIsState || bNodeAIsAction)))
    {
        return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("Merge"));
    }*/

    return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT(""));
}
