#include "Graph/FSMGraph.h"

// #include "RuntimeNode/FSMRuntimeNode_State.h"
#include "FSMEditorTypes.h"
#include "Node/FSMGraphNode.h"
#include "Node/FSMGraphNode_Root.h"
#include "Node/FSMGraphSubNode.h"
#include "Node/Composites/FSMGraphNode_Jump.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"
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
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());

	JumpStartNodes.Empty();
	for (int Index = 0; Index < Nodes.Num(); ++Index)
	{
		UFSMGraphNode* NodeBase = Cast<UFSMGraphNode>(Nodes[Index]);
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
			RuntimeNode->ParentNode;
			RuntimeNode->InitializeNode(nullptr, 0);
		}

		// TODO::记录所有 JumpStart 节点
		
	}

	// 必须确保图表中存在 RootNode
	check(RootNode);

	// 在撤销操作完成后，我们无法查看引脚，必须先修复引脚引用问题
	UEdGraphPin::ResolveAllPinReferences();
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

	UFSMRuntimeNode* RootStateNode = Cast<UFSMRuntimeNode>(RootEdNode->RuntimeNode);
	if (RootStateNode == nullptr)
	{
		return;
	}
	FSMAsset->RootRuntimeNode = RootStateNode;
	// 赋予节点实际意义
	RootStateNode->InitializeNode(nullptr);

	// TODO::初始化 RuntimeDecorators/RuntimeActions
	uint16 DummyIndex = MAX_uint16; // 暂时未知实际意义
	FSMAsset->RootDecorators.Empty();
	FSMAsset->RootActions.Empty();

	// 创建所有子节点
	TArray<UObject*> Stack;
	CreateChildrenNodes(FSMAsset, FSMAsset->RootRuntimeNode, RootEdNode, Stack);

	// 对根节点进行标记
	ClearRootNodeFlags();
	RootEdNode->bIsRootNode = true;
	RootStateNode->bIsRootNode = true;
}

void UFSMGraph::UpdateClassData()
{
	for (int32 Idx = 0; Idx < Nodes.Num(); Idx++)
	{
		UFSMGraphNode* Node = Cast<UFSMGraphNode>(Nodes[Idx]);
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


#if WITH_EDITOR

void UFSMGraph::PostEditUndo()
{
	Super::PostEditUndo();
	// make sure that all execution indices are up to date
	UpdateAsset();
	Modify();
}

UFlowStateMachine* UFSMGraph::GetFSMAsset() const
{
	return Cast<UFlowStateMachine>(GetOuter());
}

#endif

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
			if (GraphNode->RuntimeNode)
			{
				GraphNode->RuntimeNode->bIsRootNode = false;
			}
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
	UFSMGraphNode* GraphRootNode, TArray<UObject*>& Stack)
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

		// sort connections so that they're organized the same as user can see in the editor
		Pin->LinkedTo.Sort(FCompareNodeYLocation());
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
			// RuntimeNode->InitializeNode(RuntimeRootNode);

			// 递归添加子节点
			CreateChildrenNodes(FSMAsset, RuntimeNode, GraphNode, Stack);

		}
	}
	
	// 创建完成所有子节点后，将当前节点从栈中弹出
	Stack.Pop();
}

bool UFSMGraph::CheckRing(UFSMGraphNodeBase* StartNode, UFSMGraphNodeBase* BreakNode)
{
	/*
	 * 递归检查 StartNode 的所有子引脚，并与 BreakNode 进行比较，确保不是环形
	 * 递归结束条件：
	 *     1、传入的起始节点为空
	 *     2、起始节点与标记点一致
	 *     3、无任何输出引脚
	 */
	if (StartNode == nullptr)
	{
		return false;
	}
	if (StartNode == BreakNode)
	{
		return false;
	}
	for (UEdGraphPin* Pin : StartNode->Pins)
	{
		if (Pin->Direction != EGPD_Output)
		{
			continue;
		}
		UFSMGraphNodeBase* FSMNode = Cast<UFSMGraphNodeBase>(Pin->GetOwningNode());
		if (FSMNode)
		{
			CheckRing(FSMNode, BreakNode);
		}
	}
	return false;
}

namespace FSMGraphHelper
{
	// TODO::收集装饰及以及行为子节点
	// void CollectDecorators();
	// void CollectActions();
}
