#include "Graph/FSMGraph.h"

#include "Graph/Node/FSMGraphNode.h"
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
		UFSMGraphNode* Node = Cast<UFSMGraphNode>(Nodes[Index]);
		if (Node == nullptr) continue;
		// 当根节点为空时，尝试更新根节点
		if (RootNode == nullptr)
		{
			RootNode = Cast<UFSMGraphNode_Root>(Node);
		}
		// TODO::这里可以对其他节点执行其他操作，如为节点的 Decorators/Actions 设置它们的父级
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
	// CreateFSMFromGraph()

	/*if (bLockUpdates)
	{
		return;
	}

	// initial cleanup & root node search
	UBehaviorTreeGraphNode_Root* RootNode = NULL;
	for (int32 Index = 0; Index < Nodes.Num(); ++Index)
	{
		UBehaviorTreeGraphNode* Node = Cast<UBehaviorTreeGraphNode>(Nodes[Index]);

		if (Node == nullptr)
		{
			// ignore non-BT nodes.
			continue;
		}

		// debugger flags
		if (UpdateFlags & ClearDebuggerFlags)
		{
			Node->ClearDebuggerState();

			for (int32 iAux = 0; iAux < Node->Services.Num(); iAux++)
			{
				Node->Services[iAux]->ClearDebuggerState();
			}

			for (int32 iAux = 0; iAux < Node->Decorators.Num(); iAux++)
			{
				Node->Decorators[iAux]->ClearDebuggerState();
			}
		}

		// parent chain
		Node->ParentNode = NULL;
		for (int32 iAux = 0; iAux < Node->Services.Num(); iAux++)
		{
			Node->Services[iAux]->ParentNode = Node;
		}

		for (int32 iAux = 0; iAux < Node->Decorators.Num(); iAux++)
		{
			Node->Decorators[iAux]->ParentNode = Node;
		}

		// prepare node instance
		UBTNode* NodeInstance = Cast<UBTNode>(Node->NodeInstance);
		if (NodeInstance)
		{
			// mark all nodes as disconnected first, path from root will replace it with valid values later
			NodeInstance->InitializeNode(NULL, MAX_uint16, 0, 0);
		}

		// cache root
		if (RootNode == NULL)
		{
			RootNode = Cast<UBehaviorTreeGraphNode_Root>(Nodes[Index]);
		}

		UBehaviorTreeGraphNode_CompositeDecorator* CompositeDecorator = Cast<UBehaviorTreeGraphNode_CompositeDecorator>(Nodes[Index]);
		if (CompositeDecorator)
		{
			CompositeDecorator->ResetExecutionRange();
		}
	}

	// we can't look at pins until pin references have been fixed up post undo:
	UEdGraphPin::ResolveAllPinReferences();
	if (RootNode && RootNode->Pins.Num() > 0 && RootNode->Pins[0]->LinkedTo.Num() > 0)
	{
		UBehaviorTreeGraphNode* Node = Cast<UBehaviorTreeGraphNode>(RootNode->Pins[0]->LinkedTo[0]->GetOwningNode());
		if (Node)
		{
			CreateBTFromGraph(Node);

			if ((UpdateFlags & KeepRebuildCounter) == 0)
			{
				ModCounter++;
			}
		}
	}

	UpdateBlackboardChange();*/
}

void UFSMGraph::CreateFSMFromGraph(UFSMGraphNode* RootEdNode)
{
	UFlowStateMachine* FSMAsset = Cast<UFlowStateMachine>(GetOuter());
	FSMAsset->RootRuntimeNode = nullptr; // 解除旧资产保存的数据引用

	// 根据图表中创建新数据
	uint16 ExecutionIndex = 0;
	uint8 TreeDepth = 0;

	FSMAsset->RootRuntimeNode = RootEdNode->RuntimeNode;
	if (FSMAsset->RootRuntimeNode)
	{
		// 赋予节点实际意义
		FSMAsset->RootRuntimeNode->InitializeNode(nullptr, ExecutionIndex++, 0, TreeDepth);
	}

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
	if (RuntimeRootNode == nullptr || GraphRootNode == nullptr)
	{
		return;
	}

	// 清理上次添加的对象
	RuntimeRootNode->ClearChildren();

	// 递归结束条件2：GraphRootNode 的输出引脚数量为 0 或 引脚未连接其他节点
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
			RuntimeRootNode->AddChildNode(RuntimeNode);
			
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
