#include "Slate/SGraphNode_FSM.h"
#include "Graph/Node/FSMGraphNode.h"

void SGraphNode_FSM::Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode)
{
	GraphNode = InGraphNode;
}
