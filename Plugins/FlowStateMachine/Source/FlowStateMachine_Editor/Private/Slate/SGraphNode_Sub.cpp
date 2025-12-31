#include "Slate/SGraphNode_Sub.h"

#include "SGraphPanel.h"
#include "Graph/Node/FSMGraphSubNode.h"
#include "SM/FSMRuntimeNode.h"

void SGraphNode_Sub::Construct(const FArguments& InArgs, UFSMGraphSubNode* InGraphNode)
{
	this->GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
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

FReply SGraphNode_Sub::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	UFSMGraphSubNode* SubNode = Cast<UFSMGraphSubNode>(GraphNode);
	if (SubNode != nullptr)
	{
		// OwnerGraphPanel is nullptr
		GetOwnerPanel()->SelectionManager.ClickedOnNode(GraphNode, MouseEvent);
		return FReply::Handled();
	}
	return FReply::Unhandled();
}
