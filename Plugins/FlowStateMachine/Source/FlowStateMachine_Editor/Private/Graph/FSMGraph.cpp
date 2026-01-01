#include "Graph/FSMGraph.h"

// #include "RuntimeNode/FSMRuntimeNode_State.h"
#include "Node/FSMGraphNode.h"
#include "Node/FSMGraphNode_Root.h"
#include "Node/FSMGraphSubNode.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

void UFSMGraph::Initialize()
{
}

void UFSMGraph::OnCreateGraph()
{
	SpawnMissingNodes();
}

void UFSMGraph::OnLoadedGraph()
{
}

void UFSMGraph::OnSave()
{
	UpdateAsset();


}

void UFSMGraph::UpdateAsset(int32 UpdateFlags)
{
	UFSMGraphNode_Root* RootNode = nullptr;

	for (int Index = 0; Index < Nodes.Num(); ++Index)
	{
		UFSMGraphNodeBase* NodeBase = Cast<UFSMGraphNodeBase>(Nodes[Index]);
		if (NodeBase == nullptr) continue;
		// 当根节点为空时，尝试更新根节点
		if (RootNode == nullptr)
		{
			RootNode = Cast<UFSMGraphNode_Root>(NodeBase);
		}

		// 遍历次要节点，更新其父级节点
		for (UFSMGraphNodeBase* SubNode : NodeBase->SubNodes)
		{
			if (SubNode)
			{
				SubNode->ParentNode = NodeBase;
			}
		}

		// 重置节点实例
		UFSMRuntimeNode* RuntimeNode = Cast<UFSMRuntimeNode>(NodeBase->RuntimeNode);
		if (RuntimeNode != nullptr)
		{
			// 先将所有节点标记为未连接状态，之后从根节点出发的路径会用有效的值对其进行替换。
			RuntimeNode->InitializeNode(nullptr, MAX_uint16, 0, 0);
		}
	}

	if (RootNode == nullptr)
	{
		checkNoEntry();
	}

	// 确保根节点连接了至少一个其他节点
	if (RootNode && RootNode->Pins.Num() > 0 && RootNode->Pins[0]->LinkedTo.Num() > 0)
	{
		// 使用图表根节点的下一级节点作为运行时根节点
		UFSMGraphNode* Node = Cast<UFSMGraphNode>(RootNode->Pins[0]->LinkedTo[0]->GetOwningNode());
		if (Node)
		{
			CreateFSMFromGraph(Node);
		}
	}

	// TODO::UpdateBlackboardChange();
}

void UFSMGraph::OnNodesPasted(const FString& String)
{
}

void UFSMGraph::CreateFSMFromGraph(UFSMGraphNode* RootEdNode)
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());
	FSMAsset->RootRuntimeNode = nullptr; // 解除旧资产保存的数据引用

	// 根据图表中创建新数据
	uint16 ExecutionIndex = 0;
	uint8 TreeDepth = 0;

	auto RootStateNode = Cast<UFSMRuntimeNode>(RootEdNode->RuntimeNode);
	if (RootStateNode == nullptr)
	{
		return;
	}
	FSMAsset->RootRuntimeNode = RootStateNode;
	// 赋予节点实际意义
	RootStateNode->InitializeNode(nullptr, ExecutionIndex++, 0, TreeDepth);

	// TODO::初始化 RuntimeDecorators/RuntimeActions
	uint16 DummyIndex = MAX_uint16; // 暂时未知实际意义
	FSMAsset->RootDecorators.Empty();
	FSMAsset->RootActions.Empty();

	// 创建所有子节点
	CreateChildrenNodes(FSMAsset, FSMAsset->RootRuntimeNode, RootEdNode, ExecutionIndex, TreeDepth + 1);

	// 对根节点进行标记
	ClearRootNodeFlags();
	RootEdNode->bIsRootNode = true;
	/*RootEdNode->Condition;
	for (int i = 0; i < RootEdNode->Decorators.Num(); ++i)
	{
		UFSMGraphNode* Node = RootEdNode->Decorators[i];
		if (Node)
		{
			Node->bIsRootNode = true;
		}
	}
	if (FSMAsset->RootRuntimeNode)
	{
		// FSMAsset->RootRuntimeNode->InitializeComposite(ExecutionIndex - 1);
	}*/
	// 移除孤儿节点
	// RemoveOrphanedNodes();
}

void UFSMGraph::UpdateClassData()
{
	for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
	{
		UFSMGraphNodeBase* Node = Cast<UFSMGraphNodeBase>(Nodes[Idx]);
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

bool UFSMGraph::IsLocked() const
{
	return bLockUpdates;
}

void UFSMGraph::LockUpdates()
{
	bLockUpdates = true;
}

void UFSMGraph::UnlockUpdates()
{
	bLockUpdates = false;
	UpdateAsset();
}

void UFSMGraph::SpawnMissingNodes()
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());
	if (FSMAsset)
	{
		UFSMGraphNode* RootGraphNode = nullptr;
		for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
		{
			RootGraphNode = Cast<UFSMGraphNode_Root>(Nodes[Idx]);
			if (RootGraphNode)
			{
				break;
			}
		}

		// 找到根节点后，建立 RuntimeNode 与 GraphNode 的对应关系
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

void UFSMGraph::ClearRootNodeFlags()
{
	// TO
	for (UEdGraphNode* Node : Nodes)
	{
	}
	for (int i = 0; i < Nodes.Num(); ++i)
	{
		UFSMGraphNode* GraphNode = Cast<UFSMGraphNode>(Nodes[i]);
		if (GraphNode)
		{
			GraphNode->bIsRootNode = false;
			// TODO::同时对子节点进行清除
		}
	}
}

void UFSMGraph::RemoveOrphanedNodes()
{
	TSet<UObject*> NodeInstances;
	CollectAllNodeInstances(NodeInstances);

	NodeInstances.Remove(nullptr);

	// Obtain a list of all nodes actually in the asset and discard unused nodes
	TArray<UObject*> AllInners;
	const bool bIncludeNestedObjects = false;
	GetObjectsWithOuter(GetOuter(), AllInners, bIncludeNestedObjects);
	for (auto InnerIt = AllInners.CreateConstIterator(); InnerIt; ++InnerIt)
	{
		UObject* TestObject = *InnerIt;
		if (!NodeInstances.Contains(TestObject) && CanRemoveNestedObject(TestObject))
		{
			OnNodeInstanceRemoved(TestObject);

			TestObject->SetFlags(RF_Transient);
			TestObject->Rename(NULL, GetTransientPackage(), REN_DontCreateRedirectors | REN_NonTransactional | REN_ForceNoResetLoaders);
		}
	}
}

void UFSMGraph::CollectAllNodeInstances(TSet<UObject*>& NodeInstances)
{
	for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
	{
		UFSMGraphNode* MyNode = Cast<UFSMGraphNode>(Nodes[Idx]);
		if (MyNode)
		{
			NodeInstances.Add(MyNode->RuntimeNode);

			for (int32 SubIdx = 0; SubIdx < MyNode->SubNodes.Num(); SubIdx++)
			{
				if (MyNode->SubNodes[SubIdx])
				{
					NodeInstances.Add(MyNode->SubNodes[SubIdx]->RuntimeNode);
				}
			}
		}
	}
}

bool UFSMGraph::CanRemoveNestedObject(UObject* TestObject) const
{
	return !TestObject->IsA(UEdGraphNode::StaticClass()) &&
	!TestObject->IsA(UEdGraph::StaticClass()) &&
	!TestObject->IsA(UEdGraphSchema::StaticClass());
}

void UFSMGraph::CreateChildrenNodes(class UFlowStateMachine* FSMAsset, UFSMRuntimeNode* RuntimeRootNode,
	UFSMGraphNode* GraphRootNode, uint16& ExecuteIndex, uint8 TreeDepth)
{
	// 递归结束条件1：确保传入的运行时节点以及图表节点为空
	// 递归结束条件2：GraphRootNode 的输出引脚数量为 0 或 引脚未连接其他节点

	if (RuntimeRootNode == nullptr || GraphRootNode == nullptr)
	{
		return;
	}

	// 清理父级节点
	GraphRootNode->ParentNode = nullptr;

	// 清理次要对象
	RuntimeRootNode->ClearSubNodes();
	// 收集 Condition、Service、Action 等次要节点
	for (UFSMGraphNodeBase* SubNode : GraphRootNode->SubNodes)
	{
		if (SubNode && SubNode->RuntimeNode)
		{
			RuntimeRootNode->AddSubNode(SubNode->RuntimeNode);
		}
	}

	// 清理子对象
	RuntimeRootNode->ChildrenNodes.Empty();
	// 收集子节点
	for (int32 Idx = 0; Idx < GraphRootNode->Pins.Num(); ++Idx)
	{
		UEdGraphPin* Pin = GraphRootNode->Pins[Idx];
		// 过滤非输出引脚
		if (Pin->Direction != EGPD_Output)
		{
			continue;
		}

		// 遍历节点引脚获得当前节点下的所有子节点
		for (int i = 0; i < Pin->LinkedTo.Num(); ++i)
		{
			UFSMGraphNode* GraphNode = Cast<UFSMGraphNode>(Pin->LinkedTo[i]->GetOwningNode());
			if (GraphNode == nullptr)
			{
				continue;
			}
			UFSMRuntimeNode* RuntimeNode = Cast<UFSMRuntimeNode>(GraphNode->RuntimeNode);
			if (RuntimeNode == nullptr)
			{
				continue;
			}
			// 重命名运行时节点，确保节点的 Outer 为资产对象而非其他。
			RuntimeNode->Rename(nullptr, FSMAsset);
			RuntimeRootNode->ChildrenNodes.Add(RuntimeNode);
			
			// 更新执行顺序
			RuntimeNode->InitializeNode(RuntimeRootNode, ExecuteIndex++, 0, TreeDepth);

			// 递归添加子节点
			CreateChildrenNodes(FSMAsset, RuntimeNode, GraphNode, ExecuteIndex, TreeDepth + 1);
		}
	}
}

namespace FSMGraphHelper
{
	// TODO::收集装饰及以及行为子节点
	// void CollectDecorators();
	// void CollectActions();
}
