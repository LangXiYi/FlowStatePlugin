#include "Graph/FlowStateGraph.h"

// #include "NodeInstance/FSMNodeInstance_State.h"
#include "Utility/FlowStateEditorType.h"
#include "GraphEditAction.h"
#include "Node/FSGraphNode.h"
#include "Node/FSGraph_RootNode.h"
#include "Node/FSGraphSubNode.h"
#include "Node/Composites/Composite_JumpNode.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "NodeInstance/FSMSubNodeInstance.h"
#include "SM/Composites/Composite_Jump.h"
#include "SM/FlowStateMachine.h"
#include "Utility/FSMUtility.h"

void UFlowStateGraph::Initialize()
{
}

void UFlowStateGraph::OnCreateGraph()
{
    SpawnMissingNodes();
}

void UFlowStateGraph::OnLoadedGraph()
{
    RefreshAllNodes();
}

void UFlowStateGraph::RefreshAllNodes()
{
    for (UEdGraphNode* GraphNode : Nodes)
    {
        UFSGraphNodeBase* FSMNodeBase = Cast<UFSGraphNodeBase>(GraphNode);
        if (FSMNodeBase)
        {
            FSMNodeBase->ReconstructNode();
        }
    }
}

void UFlowStateGraph::OnSave()
{
    UpdateAsset();
}

void UFlowStateGraph::UpdateAsset(FString UpdateReason)
{
    if (!UpdateReason.IsEmpty())
    {
        FSMLOG("Update Asset %s -- UPDATE REASON: %s", *GetFSMAsset()->GetName(), *UpdateReason)
    }

    UFSGraph_RootNode* RootNode = nullptr;

    ScatteredNodes.Empty();
    for (int Index = 0; Index < Nodes.Num(); ++Index)
    {
        UFSGraphNode* NodeBase = Cast<UFSGraphNode>(Nodes[Index]);
        if (NodeBase == nullptr)
        {
            continue;
        }
        // 当根节点为空时，尝试更新根节点
        if (RootNode == nullptr)
        {
            RootNode = Cast<UFSGraph_RootNode>(NodeBase);
        }

        // 重置节点实例
        UFSMNodeInstance* NodeInstance = Cast<UFSMNodeInstance>(NodeBase->NodeInstance);
        if (NodeInstance != nullptr)
        {
            // 先将所有节点标记为未连接状态，之后从根节点出发的路径会用有效的值对其进行替换。
            NodeInstance->InitializeNode(nullptr);
            NodeInstance->ClearSubNodes();
            // 遍历次要节点，更新其父级节点，这里针对的是所有的节点进行的操作
            for (UFSGraphNodeBase* SubNode : NodeBase->SubNodes)
            {
                if (SubNode != nullptr)
                {
                    SubNode->ParentNode = NodeBase;
                    if (UFSMSubNodeInstance* SubNodeInstance = Cast<UFSMSubNodeInstance>(SubNode->NodeInstance))
                    {
                        NodeInstance->AddSubNode(SubNodeInstance);
                    }
                }
            }
        }

        // 记录所有零碎节点: 跳跃节点、...
        UGraphCNode_JumpStart* JumpStartNode = Cast<UGraphCNode_JumpStart>(Nodes[Index]);
        if (JumpStartNode)
        {
            ScatteredNodes.Add(JumpStartNode);
        }
    }

    // 必须确保图表中存在 RootNode
    check(RootNode);

    // 在撤销操作完成后，我们无法查看引脚，必须先修复引脚引用问题
    UEdGraphPin::ResolveAllPinReferences();
    if (RootNode && RootNode->Pins.Num() > 0 && RootNode->Pins[0]->LinkedTo.Num() > 0)
    {
        // 使用图表根节点的下一级节点作为运行时根节点
        UFSGraphNode* Node = Cast<UFSGraphNode>(RootNode->Pins[0]->LinkedTo[0]->GetOwningNode());
        if (Node)
        {
            CreateFSMFromGraph(Node);
        }
    }

    // TODO::UpdateBlackboardChange();
}

void UFlowStateGraph::OnNodesPasted(const FString& String)
{
}

void UFlowStateGraph::NotifyGraphChanged()
{
    Super::NotifyGraphChanged();
}

void UFlowStateGraph::CreateFSMFromGraph(UFSGraphNode* RootEdNode)
{
    UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());
    FSMAsset->RootNodeInstance = nullptr; // 解除旧资产保存的数据引用

    UFSMNodeInstance* RootStateNode = Cast<UFSMNodeInstance>(RootEdNode->NodeInstance);
    if (RootStateNode == nullptr)
    {
        return;
    }
    // 更新资产的根节点
    FSMAsset->RootNodeInstance = RootStateNode;
    // 赋予节点实际意义
    RootStateNode->InitializeNode(nullptr);

    FSMAsset->RootDecorators.Empty();
    FSMAsset->RootActions.Empty();

    // 创建所有子节点
    TArray<UObject*> Stack;
    CreateChildrenNodes(FSMAsset, FSMAsset->RootNodeInstance, RootEdNode, Stack);

    // 创建所有零碎节点
    CreateScatteredNodes(FSMAsset, ScatteredNodes);

    // 对根节点进行标记
    ClearRootNodeFlags();
    RootEdNode->bIsRootNode = true;
    RootStateNode->bIsRootNode = true;
}

void UFlowStateGraph::UpdateClassData()
{
    for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
    {
        UFSGraphNode* Node = Cast<UFSGraphNode>(Nodes[Idx]);
        if (Node)
        {
            Node->UpdateNodeClassData();

            for (int32 SubIdx = 0; SubIdx < Node->SubNodes.Num(); SubIdx++)
            {
                if (Node->SubNodes[SubIdx])
                {
                    Node->SubNodes[SubIdx]->UpdateNodeClassData();
                }
            }
        }
    }
}

bool UFlowStateGraph::IsLocked() const
{
    return bLockUpdates;
}

void UFlowStateGraph::LockUpdates()
{
    bLockUpdates = true;
}

void UFlowStateGraph::UnlockUpdates()
{
    bLockUpdates = false;
    UpdateAsset();
}

void UFlowStateGraph::Serialize(FArchive& Ar)
{
    UObject::Serialize(Ar);
    if (Ar.IsSaving() || Ar.IsCooking())
    {
        // 检查所有节点的有效性
        UpdateAllNodesValidity();
    }
}

#if WITH_EDITOR
void UFlowStateGraph::PostEditUndo()
{
    Super::PostEditUndo();
    // make sure that all execution indices are up to date
    UpdateAsset();
    Modify();
}
#endif

UFlowStateMachine* UFlowStateGraph::GetFSMAsset() const
{
    return Cast<UFlowStateMachine>(GetOuter());
}

void UFlowStateGraph::UpdateNodeErrorMessage(UFSGraphNodeBase& FSMNode)
{
    FSMNode.ErrorMessage.Empty();
    if (FSMNode.IsDeprecated())
    {
        FEdGraphNodeDeprecationResponse DeprecationMessage = FSMNode.GetDeprecationResponse(
            EEdGraphNodeDeprecationType::NodeTypeIsDeprecated);
        if (DeprecationMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
        {
            FSMNode.ErrorMessage = DeprecationMessage.MessageText.ToString();
        }
    }

    if (FSMNode.HasDeprecatedReference())
    {
        FEdGraphNodeDeprecationResponse DeprecatedReferenceMessage = FSMNode.GetDeprecationResponse(
            EEdGraphNodeDeprecationType::NodeHasDeprecatedReference);
        if (DeprecatedReferenceMessage.MessageType != EEdGraphNodeDeprecationMessageType::None)
        {
            FSMNode.ErrorMessage = DeprecatedReferenceMessage.MessageText.ToString();
        }
    }
    if (!FSMNode.ErrorMessage.IsEmpty())
    {
        FSMLOGE("%s", *FSMNode.ErrorMessage);
    }
}

void UFlowStateGraph::UpdateAllNodesValidity()
{
    for (int i = 0; i < Nodes.Num(); ++i)
    {
        UFSGraphNodeBase* FSMNode = Cast<UFSGraphNodeBase>(Nodes[i]);
        if (FSMNode == nullptr)
        {
            continue;
        }
        UpdateNodeErrorMessage(*FSMNode);
        for (UFSGraphNodeBase* SubNode : FSMNode->SubNodes)
        {
            if (SubNode == nullptr)
            {
                continue;
            }
            UpdateNodeErrorMessage(*SubNode);
        }
    }
}

void UFlowStateGraph::SpawnMissingNodes()
{
    UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());
    if (FSMAsset)
    {
        UFSGraphNode* RootGraphNode = nullptr;
        for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
        {
            RootGraphNode = Cast<UFSGraph_RootNode>(Nodes[Idx]);
            if (RootGraphNode)
            {
                break;
            }
        }

        // 找到根节点后，建立 NodeInstance 与 GraphNode 的对应关系
    }
    /*UBehaviorTree* BTAsset = Cast<UBehaviorTree>(GetOuter());
    if (BTAsset)
    {
        UBehaviorTreeGraphNode* RootNode = nullptr;
        for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
        {
            RootNode = Cast<UBehaviorTreeGraphNode_Root>(Nodes[Idx]);
            if (RootNode)
            {
                break;
            }
        }

        UBehaviorTreeGraphNode* SpawnedRootNode = BTGraphHelpers::SpawnMissingGraphNodes(BTAsset, RootNode, this);
        if (RootNode && SpawnedRootNode)
        {
            UEdGraphPin* RootOutPin = FindGraphNodePin(RootNode, EGPD_Output);
            UEdGraphPin* SpawnedInPin = FindGraphNodePin(SpawnedRootNode, EGPD_Input);

            RootOutPin->MakeLinkTo(SpawnedInPin);
        }
    }*/
}

void UFlowStateGraph::ClearRootNodeFlags()
{
    // TO
    for (UEdGraphNode* Node : Nodes)
    {
    }
    for (int i = 0; i < Nodes.Num(); ++i)
    {
        UFSGraphNode* GraphNode = Cast<UFSGraphNode>(Nodes[i]);
        if (GraphNode)
        {
            GraphNode->bIsRootNode = false;
            if (GraphNode->NodeInstance)
            {
                GraphNode->NodeInstance->bIsRootNode = false;
            }
            // TODO::同时对子节点进行清除
        }
    }
}

void UFlowStateGraph::RemoveOrphanedNodes()
{
    TSet<UObject*> NodeInstances;
    CollectAllNodeInstances(NodeInstances);

    NodeInstances.Remove(nullptr);

    // Obtain a list of all nodes actually in the asset and discard unused nodes
    TArray<UObject*> AllInners;
    constexpr bool bIncludeNestedObjects = false;
    GetObjectsWithOuter(GetOuter(), AllInners, bIncludeNestedObjects);
    for (auto InnerIt = AllInners.CreateConstIterator(); InnerIt; ++InnerIt)
    {
        UObject* TestObject = *InnerIt;
        if (!NodeInstances.Contains(TestObject) && CanRemoveNestedObject(TestObject))
        {
            OnNodeInstanceRemoved(TestObject);

            TestObject->SetFlags(RF_Transient);
            TestObject->Rename(nullptr, GetTransientPackage(),
                               REN_DontCreateRedirectors | REN_NonTransactional | REN_ForceNoResetLoaders);
        }
    }
}

void UFlowStateGraph::CollectAllNodeInstances(TSet<UObject*>& NodeInstances)
{
    for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
    {
        UFSGraphNode* MyNode = Cast<UFSGraphNode>(Nodes[Idx]);
        if (MyNode)
        {
            NodeInstances.Add(MyNode->NodeInstance);

            for (int32 SubIdx = 0; SubIdx < MyNode->SubNodes.Num(); SubIdx++)
            {
                if (MyNode->SubNodes[SubIdx])
                {
                    NodeInstances.Add(MyNode->SubNodes[SubIdx]->NodeInstance);
                }
            }
        }
    }
}

bool UFlowStateGraph::CanRemoveNestedObject(UObject* TestObject) const
{
    return !TestObject->IsA(UEdGraphNode::StaticClass()) && !TestObject->IsA(UEdGraph::StaticClass()) && !TestObject->
        IsA(UEdGraphSchema::StaticClass());
}

void UFlowStateGraph::CreateChildrenNodes(class UFlowStateMachine* FSMAsset, UFSMNodeInstance* RuntimeRootNode,
                                          const UFSGraphNode* GraphRootNode, TArray<UObject*>& Stack)
{
    // 递归结束条件1：确保传入的运行时节点以及图表节点为空
    // 递归结束条件2：GraphRootNode 的输出引脚数量为 0 或 引脚未连接其他节点
    // 递归结束条件3：出现环形

    if (RuntimeRootNode == nullptr || GraphRootNode == nullptr)
    {
        return;
    }

    // 该节点已经在栈中存在，表明当前执行流出现环形，需要中止执行。
    if (Stack.Contains(RuntimeRootNode))
    {
        return;
    }
    // 将当前节点压入栈中
    Stack.Push(RuntimeRootNode);

    // 清理并初始化次要节点
    RuntimeRootNode->ClearSubNodes();
    for (UFSGraphNodeBase* SubNode : GraphRootNode->SubNodes)
    {
        if (SubNode && SubNode->NodeInstance)
        {
            SubNode->NodeInstance->InitializeNode(RuntimeRootNode);
            RuntimeRootNode->AddSubNode(SubNode->NodeInstance);
        }
    }

    // 清理子对象
    RuntimeRootNode->ClearChildStates();
    // 收集子节点
    for (int32 Idx = 0; Idx < GraphRootNode->Pins.Num(); ++Idx)
    {
        UEdGraphPin* Pin = GraphRootNode->Pins[Idx];
        // 过滤非输出引脚以及错误引脚
        if (Pin->Direction != EGPD_Output || Pin->bOrphanedPin || Pin->bIsDiffing)
        {
            continue;
        }

        // sort connections so that they're organized the same as user can see in the editor
        // Pin->LinkedTo.Sort(FCompareNodeYLocation());
        // 遍历节点引脚获得当前节点下的所有子节点
        for (int i = 0; i < Pin->LinkedTo.Num(); ++i)
        {
            UFSGraphNode* GraphNode = Cast<UFSGraphNode>(Pin->LinkedTo[i]->GetOwningNode());
            if (GraphNode == nullptr)
            {
                continue;
            }
            UFSMNodeInstance* NodeInstance = Cast<UFSMNodeInstance>(GraphNode->NodeInstance);
            if (NodeInstance == nullptr)
            {
                continue;
            }
            // 重命名运行时节点，确保节点的 Outer 为资产对象而非其他。
            NodeInstance->Rename(nullptr, FSMAsset);
            // 初始化节点
            NodeInstance->InitializeNode(RuntimeRootNode);

            RuntimeRootNode->AddChildState(Pin->PinName, NodeInstance);
            // 递归添加子节点
            CreateChildrenNodes(FSMAsset, NodeInstance, GraphNode, Stack);
        }
    }
    // 创建完成所有子节点后，将当前节点从栈中弹出
    Stack.Pop();
}

void UFlowStateGraph::CreateScatteredNodes(UFlowStateMachine* FSMAsset,
                                           const TArray<const UFSGraphNode*>& ScatteredNodes)
{
    TArray<UObject*> Stack;
    FSMAsset->ScatteredNodes.Empty();
    for (const UFSGraphNode* ScatteredGraphNode : ScatteredNodes)
    {
        UFSMNodeInstance* ScatteredNodeInstance = Cast<UFSMNodeInstance>(ScatteredGraphNode->NodeInstance);
        if (ScatteredNodeInstance == nullptr)
        {
            continue;
        }
        Stack.Empty();
        CreateChildrenNodes(FSMAsset, ScatteredNodeInstance, ScatteredGraphNode, Stack);
        FSMAsset->ScatteredNodes.Add(ScatteredNodeInstance);
    }
}

namespace FSMGraphHelper
{
    // TODO::收集装饰及以及行为子节点
    // void CollectDecorators();
    // void CollectActions();
}
