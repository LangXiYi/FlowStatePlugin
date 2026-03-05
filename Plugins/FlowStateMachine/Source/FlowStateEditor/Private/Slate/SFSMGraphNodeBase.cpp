#include "Slate/SFSMGraphNodeBase.h"

#include "Node/FSGraphNodeBase.h"

void SFSMGraphNodeBase::Construct(const FArguments& InArgs, UFSGraphNodeBase* InGraphNode)
{
    GraphNode = InGraphNode;

    this->SetCursor(EMouseCursor::CardinalCross);

    this->UpdateGraphNode();
}

FText SFSMGraphNodeBase::GetNodeName() const
{
    const UFSGraphNodeBase* MyGraphNode = Cast<UFSGraphNodeBase>(GetNodeObj());
    if (MyGraphNode)
    {
        return MyGraphNode->GetNodeTitle(ENodeTitleType::MenuTitle);
    }
    return FText::FromString("None");
}
