#include "Graph/FSMGraph.h"

#include "Graph/Node/FSMGraphNode.h"
#include "Graph/Node/FSMGraphNode_Root.h"
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
		if (Node == nullptr)
		{
			continue;
		}



		// 当根节点为空时，尝试更新根节点
		if (RootNode == nullptr)
		{
			RootNode = Cast<UFSMGraphNode_Root>(Node);
		}
	}

	// 确保根节点连接了至少一个其他节点
	if (RootNode && RootNode->Pins.Num() > 0 && RootNode->Pins[0]->LinkedTo.Num() > 0)
	{
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
	FSMAsset->RootRuntimeNode = nullptr; // 丢弃旧数据

	// 根据图表中创建新数据
	uint16 ExecutionIndex = 0;
	uint8 TreeDepth = 0;

	FSMAsset->RootRuntimeNode = RootEdNode->NodeInstance;
	
	/*UBehaviorTree* BTAsset = Cast<UBehaviorTree>(GetOuter());
	BTAsset->RootNode = NULL; //discard old tree

	// let's create new tree from graph
	uint16 ExecutionIndex = 0;
	uint8 TreeDepth = 0;

	BTAsset->RootNode = Cast<UBTCompositeNode>(RootEdNode->NodeInstance);
	if (BTAsset->RootNode)
	{
		BTAsset->RootNode->InitializeNode(NULL, ExecutionIndex, 0, TreeDepth);
		ExecutionIndex++;
	}

	// collect root level decorators
	uint16 DummyIndex = MAX_uint16;
	BTAsset->RootDecorators.Empty();
	BTAsset->RootDecoratorOps.Empty();
	BTGraphHelpers::CollectDecorators(BTAsset, RootEdNode, BTAsset->RootDecorators, BTAsset->RootDecoratorOps, false, NULL, &DummyIndex, 0, 0);

	// connect tree nodes
	BTGraphHelpers::CreateChildren(BTAsset, BTAsset->RootNode, RootEdNode, &ExecutionIndex, TreeDepth + 1); //-V595

	// mark root level nodes
	BTGraphHelpers::ClearRootLevelFlags(this);

	RootEdNode->bRootLevel = true;
	for (int32 Index = 0; Index < RootEdNode->Decorators.Num(); Index++)
	{
		UBehaviorTreeGraphNode* Node = RootEdNode->Decorators[Index];
		if (Node)
		{
			Node->bRootLevel = true;
		}
	}

	if (BTAsset->RootNode)
	{
		BTAsset->RootNode->InitializeComposite(ExecutionIndex - 1);
	}

	// Now remove any orphaned nodes left behind after regeneration
	RemoveOrphanedNodes();*/
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
