// Fill out your copyright notice in the Description page of Project Settings.


#include "Graph/Node/FSMGraphNodeBase.h"

#include "Graph/FSMGraph.h"
#include "SM/FSMRuntimeNode.h"
#include "SM/FlowStateMachine.h"

#define LOCTEXT_NAMESPACE "FSMGraphNodeBase"

void UFSMGraphNodeBase::PostPasteNode()
{
	Super::PostPasteNode();

	// NodeInstance can be already spawned by paste operation, don't override it

	UClass* NodeClass = ClassData.GetClass();
	if (NodeClass && (RuntimeNode == nullptr))
	{
		UEdGraph* MyGraph = GetGraph();
		// Graph 的 Outer 为 FlowStateMachine
		UObject* GraphOwner = MyGraph ? MyGraph->GetOuter() : nullptr;
		if (GraphOwner)
		{
			// 该 RuntimeNode 会在保存图表时赋予实际意义
			RuntimeNode = NewObject<UFSMRuntimeNode>(GraphOwner, NodeClass);
			// “transactional”这个词确实与编辑器的撤销/重做系统有关。
			RuntimeNode->SetFlags(RF_Transactional);
			InitializeInstance();
		}
	}
}

void UFSMGraphNodeBase::InitializeInstance()
{
	UFlowStateMachine* FSMAsset = RuntimeNode ? Cast<UFlowStateMachine>(RuntimeNode->GetOuter()) : nullptr;
	if (RuntimeNode && FSMAsset)
	{
		RuntimeNode->InitializeFromAsset(*FSMAsset);
		// 初始化节点信息，如父级节点、节点深度、执行优先级等等，此时无实际意义。
		RuntimeNode->InitializeNode(NULL, MAX_uint16, 0, 0);
		RuntimeNode->OnNodeCreated();
	}
}

UFSMGraph* UFSMGraphNodeBase::GetFSMGraph() const
{
	return CastChecked<UFSMGraph>(GetGraph());
}

#undef LOCTEXT_NAMESPACE