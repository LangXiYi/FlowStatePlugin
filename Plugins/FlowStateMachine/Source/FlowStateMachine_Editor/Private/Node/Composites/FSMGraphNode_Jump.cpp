// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Composites/FSMGraphNode_Jump.h"

#include "Graph/FSMGraph.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"

#define LOCTEXT_NAMESPACE "FSMGraphNodeJump"

UFSMGraphNode_JumpStart::UFSMGraphNode_JumpStart(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// if (!JumpStartId.IsValid())
	// {
	// 	JumpStartId = FGuid::NewGuid();
	// }
}

void UFSMGraphNode_JumpStart::PostPasteNode()
{
	Super::PostPasteNode();
	GetFSMGraph()->AddScatteredNode(this);
}

void UFSMGraphNode_JumpStart::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (UFSMRuntimeNode_JumpStart* JumpStartRuntimeNode = Cast<UFSMRuntimeNode_JumpStart>(RuntimeNode))
	{
		if (!JumpStartId.IsValid())
		{
			JumpStartId = FGuid::NewGuid();
			JumpStartRuntimeNode->JumpStartId = JumpStartId;
		}
		GetFSMGraph()->AddScatteredNode(this);
	}
	check(JumpStartId.IsValid());
}

void UFSMGraphNode_JumpStart::DestroyNode()
{
	GetFSMGraph()->RemoveScatteredNode(this);
	Super::DestroyNode();
}

void UFSMGraphNode_JumpStart::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Execute");
}

FString UFSMGraphNode_JumpStart::GetNodeTitleFormatString() const
{
	return "Jump Start {0}";
}

FPinConnectionResponse UFSMGraphNode_JumpStart::CheckPinConnection(const UFSMGraphNodeBase* OtherNode,
                                                                   EEdGraphPinDirection FromDirection) const
{
	// 检查 OtherNode 是否被根节点引用
	if (OtherNode == nullptr || OtherNode->RuntimeNode == nullptr)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("node is nullptr"));
	}
	
	if (FromDirection == EGPD_Input)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, TEXT("connect node and break b"));
	}
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, TEXT("connect node and break a"));
}

void UFSMGraphNode_JumpTo::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	CreatePin(EGPD_Input, "DefaultInput", "Then");
}

void UFSMGraphNode_JumpTo::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	UFSMRuntimeNode_JumpTo* JumpStartRuntimeNode = Cast<UFSMRuntimeNode_JumpTo>(RuntimeNode);
	check(JumpStartRuntimeNode);
	JumpStartRuntimeNode->JumpStartId = JumpStartId;
}

FString UFSMGraphNode_JumpTo::GetNodeTitleFormatString() const
{
	return "Jump To {0}";
}

bool UFSMGraphNode_JumpTo::IsDeprecated() const
{
	return Super::IsDeprecated();
}

bool UFSMGraphNode_JumpTo::HasDeprecatedReference() const
{
	return Super::HasDeprecatedReference() || !IsValidJumpNode();
}

FEdGraphNodeDeprecationResponse UFSMGraphNode_JumpTo::GetDeprecationResponse(
	EEdGraphNodeDeprecationType DeprecationType) const
{
	FEdGraphNodeDeprecationResponse Response = Super::GetDeprecationResponse(DeprecationType);
	if (DeprecationType == EEdGraphNodeDeprecationType::NodeHasDeprecatedReference)
	{
		Response.MessageText = LOCTEXT("NodeDeprecationResponse", "Warning: JumpTo 节点中引用了错误的 JumpStartId ");
		Response.MessageType = EEdGraphNodeDeprecationMessageType::Warning;
	}
	return Response;
}

bool UFSMGraphNode_JumpTo::IsValidJumpNode() const
{
	UFSMGraph* MyGraph = GetFSMGraph();
	if (MyGraph == nullptr) return false;
	for (const UFSMGraphNode* ScatteredNode : MyGraph->GetScatteredNodes())
	{
		const UFSMGraphNode_JumpStart* JumpStartNode = Cast<UFSMGraphNode_JumpStart>(ScatteredNode);
		if (JumpStartNode == nullptr) continue;
		// 判断 Id 是否匹配
		if (JumpStartNode->JumpStartId == JumpStartId)
		{
			return true;
		}
	}
	return false;
}


#undef LOCTEXT_NAMESPACE
