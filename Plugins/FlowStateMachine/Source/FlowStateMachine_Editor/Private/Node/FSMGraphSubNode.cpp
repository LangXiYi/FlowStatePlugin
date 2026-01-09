// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphSubNode.h"

#include "Graph/FSMGraph.h"
#include "Node/FSMGraphNode.h"

#define LOCTEXT_NAMESPACE "FSMGraphSubNode"




void UFSMGraphSubNode::DestroyNode()
{
	Super::DestroyNode();
	if (UFSMGraphNode* FSMParentNode = Cast<UFSMGraphNode>(ParentNode))
	{
		FSMParentNode->RemoveSubNode(this);
	}
}

FLinearColor UFSMGraphSubNode::GetNodeTitleColor() const
{
	if (HasDeprecatedReference())
	{
		return FLinearColor::Yellow;
	}
	return FLinearColor::Green;
}

bool UFSMGraphSubNode::HasDeprecatedReference() const
{
	return ParentNode == nullptr || Super::HasDeprecatedReference();
}

FEdGraphNodeDeprecationResponse UFSMGraphSubNode::GetDeprecationResponse(
	EEdGraphNodeDeprecationType DeprecationType) const
{
	FEdGraphNodeDeprecationResponse Response = Super::GetDeprecationResponse(DeprecationType);
	if (DeprecationType == EEdGraphNodeDeprecationType::NodeTypeIsDeprecated)
	{
		FText NodeTitle = ParentNode->GetNodeTitle(ENodeTitleType::FullTitle);
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = FText::Format(FTextFormat::FromString("Warning: The subnode '@@' is deprecated from {0}; please replace or remove it."), NodeTitle);
	}
	else if (DeprecationType == EEdGraphNodeDeprecationType::NodeHasDeprecatedReference)
	{
		FText NodeTitle = GetNodeTitle(ENodeTitleType::FullTitle);
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
		Response.MessageText = FText::Format(FTextFormat::FromString("Warning: The subnode '{0}' has a deprecated parent; please replace or remove it."), NodeTitle);
	}
	return Response;
}

#if WITH_EDITOR

void UFSMGraphSubNode::PostEditUndo()
{
	Super::PostEditUndo();

	if (UFSMGraphNode* FSMParentNode = Cast<UFSMGraphNode>(ParentNode))
	{
		FSMParentNode->SubNodes.AddUnique(this);

		if (UFSMGraphSubNode_Condition* ConditionNode = Cast<UFSMGraphSubNode_Condition>(this))
		{
			FSMParentNode->Conditions.AddUnique(ConditionNode);
		}
		else if (UFSMGraphSubNode_Service* ServiceNode = Cast<UFSMGraphSubNode_Service>(this))
		{
			FSMParentNode->Services.AddUnique(ServiceNode);
		}
		else if (UFSMGraphSubNode_Action* ActionNode = Cast<UFSMGraphSubNode_Action>(this))
		{
			FSMParentNode->Actions.AddUnique(ActionNode);
		}
	}
}

#endif


#undef LOCTEXT_NAMESPACE
