// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Composites/FSMGraphNode_Jump.h"

void UFSMGraphNode_JumpStart::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Execute");
}

FText UFSMGraphNode_JumpStart::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("Jump Start 'NodeName'"));
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
		return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_A, TEXT("connect node"));
	}
	return FPinConnectionResponse(CONNECT_RESPONSE_BREAK_OTHERS_B, TEXT("connect node"));
}

void UFSMGraphNode_JumpTo::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();

	CreatePin(EGPD_Input, "DefaultInput", "Then");
}

FText UFSMGraphNode_JumpTo::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("Jump To 'NodeName'"));
}
