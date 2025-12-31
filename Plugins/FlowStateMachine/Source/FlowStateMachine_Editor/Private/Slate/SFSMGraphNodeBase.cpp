#include "Slate/SGraphNode_Root.h"
#include "Graph/Node/FSMGraphNode.h"
#include "SM/FSMRuntimeNode.h"

void SGraphNode_Root::Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode)
{
	GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}