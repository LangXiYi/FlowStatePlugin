#include "Slate/SFSMGraphNodeBase.h"

#include "Node/FSMGraphNodeBase.h"

void SFSMGraphNodeBase::Construct(const FArguments& InArgs, UFSMGraphNodeBase* InGraphNode)
{
	GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}

FText SFSMGraphNodeBase::GetNodeName() const
{
	const UFSMGraphNodeBase* MyGraphNode = Cast<UFSMGraphNodeBase>(GetNodeObj());
	if (MyGraphNode)
	{
		return MyGraphNode->GetNodeTitle(ENodeTitleType::MenuTitle);
	}
	return FText::FromString("None");
}
