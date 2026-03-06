#include "Node/Slates/SFSGraphNodeBase.h"

#include "Node/FSGraphNodeBase.h"

void SFSGraphNodeBase::Construct(const FArguments& InArgs, UFSGraphNodeBase* InGraphNode)
{
    GraphNode = InGraphNode;

    this->SetCursor(EMouseCursor::CardinalCross);

    this->UpdateGraphNode();
}

FText SFSGraphNodeBase::GetNodeName() const
{
    const UFSGraphNodeBase* MyGraphNode = Cast<UFSGraphNodeBase>(GetNodeObj());
    if (MyGraphNode)
    {
        return MyGraphNode->GetNodeTitle(ENodeTitleType::MenuTitle);
    }
    return FText::FromString("None");
}
