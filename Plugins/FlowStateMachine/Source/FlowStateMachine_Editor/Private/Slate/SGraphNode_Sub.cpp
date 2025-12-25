#include "Slate/SGraphNode_Sub.h"
#include "Graph/Node/FSMGraphSubNode.h"
#include "SM/FSMRuntimeNode.h"

void SGraphNode_Sub::Construct(const FArguments& InArgs, UFSMGraphSubNode* InGraphNode)
{
	GraphNode = InGraphNode;
}

FString SGraphNode_Sub::GetNodeComment() const
{
	const UFSMGraphNode_Condition* MyGraphNode = Cast<UFSMGraphNode_Condition>(GetNodeObj());
	const UFSMRuntimeNode_Condition* MyRuntimeNode = MyGraphNode ? Cast<UFSMRuntimeNode_Condition>(MyGraphNode->RuntimeNode) : NULL;

	if (MyRuntimeNode)
	{
		return MyRuntimeNode->GetNodeName();
	}

	return SGraphNode::GetNodeComment();
}
