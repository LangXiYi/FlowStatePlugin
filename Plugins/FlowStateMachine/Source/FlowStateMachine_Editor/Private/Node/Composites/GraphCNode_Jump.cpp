// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Composites/GraphCNode_Jump.h"

#include "Graph/FSMGraph.h"
#include "Composites/CNodeIns_Jump.h"
#include "Utility/FSMEditorCore.h"

#define LOCTEXT_NAMESPACE "FSMGraphNodeJump"

UGraphCNode_JumpStart::UGraphCNode_JumpStart(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// if (!JumpStartId.IsValid())
	// {
	// 	JumpStartId = FGuid::NewGuid();
	// }
}

void UGraphCNode_JumpStart::PostPasteNode()
{
	Super::PostPasteNode();
	GetFSMGraph()->AddScatteredNode(this);
}

void UGraphCNode_JumpStart::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	if (UCNodeIns_JumpStart* JumpStartNodeInstance = Cast<UCNodeIns_JumpStart>(NodeInstance))
	{
		if (!JumpStartId.IsValid())
		{
			JumpStartId = FGuid::NewGuid();
			JumpStartNodeInstance->JumpStartId = JumpStartId;
		}
		GetFSMGraph()->AddScatteredNode(this);
	}
	check(JumpStartId.IsValid());
}

void UGraphCNode_JumpStart::DestroyNode()
{
	GetFSMGraph()->RemoveScatteredNode(this);
	Super::DestroyNode();
}

void UGraphCNode_JumpStart::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, FStateNodePinHelper::Output_PinCategory, FStateNodePinHelper::Output_DefaultPinName);
}

FString UGraphCNode_JumpStart::GetNodeTitleFormatString() const
{
	return "Jump Start {0}";
}

FPinConnectionResponse UGraphCNode_JumpStart::CheckPinConnection(const UFSMGraphNodeBase* OtherNode,
                                                                   EEdGraphPinDirection FromDirection) const
{
	// 检查 OtherNode 是否被根节点引用
	if (OtherNode == nullptr || OtherNode->NodeInstance == nullptr)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_DISALLOW, TEXT("node is nullptr"));
	}
	
	if (FromDirection == EGPD_Input)
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, TEXT("connect node and break b"));
	}
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, TEXT("connect node and break a"));
}

void UGraphCNode_JumpTo::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	CreatePin(EGPD_Input, FStateNodePinHelper::Input_PinCategory, FStateNodePinHelper::InPut_DefaultPinName);
}

void UGraphCNode_JumpTo::PostPlacedNewNode()
{
	Super::PostPlacedNewNode();
	UCNodeIns_JumpTo* JumpStartNodeInstance = Cast<UCNodeIns_JumpTo>(NodeInstance);
	check(JumpStartNodeInstance);
	JumpStartNodeInstance->JumpStartId = JumpStartId;
}

FString UGraphCNode_JumpTo::GetNodeTitleFormatString() const
{
	return "Jump To {0}";
}

bool UGraphCNode_JumpTo::IsDeprecated() const
{
	return Super::IsDeprecated();
}

bool UGraphCNode_JumpTo::HasDeprecatedReference() const
{
	return Super::HasDeprecatedReference() || !IsValidJumpNode();
}

FEdGraphNodeDeprecationResponse UGraphCNode_JumpTo::GetDeprecationResponse(
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

bool UGraphCNode_JumpTo::IsValidJumpNode() const
{
	UFSMGraph* MyGraph = GetFSMGraph();
	if (MyGraph == nullptr) return false;
	for (const UFSMGraphNode* ScatteredNode : MyGraph->GetScatteredNodes())
	{
		const UGraphCNode_JumpStart* JumpStartNode = Cast<UGraphCNode_JumpStart>(ScatteredNode);
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
