#include "Slate/SFSMGraphSubNode.h"

#include "SGraphPanel.h"
#include "Node/FSMGraphSubNode.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"

void SFSMGraphSubNode::Construct(const FArguments& InArgs, UFSMGraphSubNode* InGraphNode)
{
	this->GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}

FString SFSMGraphSubNode::GetNodeComment() const
{
	const UFSMGraphSubNode_Condition* MyGraphNode = Cast<UFSMGraphSubNode_Condition>(GetNodeObj());
	const UFSMRuntimeSubNode_Condition* MyRuntimeNode = MyGraphNode ? Cast<UFSMRuntimeSubNode_Condition>(MyGraphNode->RuntimeNode) : NULL;

	if (MyRuntimeNode)
	{
		return MyRuntimeNode->GetNodeName();
	}

	return SGraphNode::GetNodeComment();
}

FReply SFSMGraphSubNode::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
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
