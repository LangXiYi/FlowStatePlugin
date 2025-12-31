#include "Slate/SFSMGraphNodeBase.h"

#include "Node/FSMGraphNodeBase.h"

void SFSMGraphNodeBase::Construct(const FArguments& InArgs, UFSMGraphNodeBase* InGraphNode)
{
	GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}