// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/Composites/FSMGraphNode_Jump.h"

#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"

UFSMGraphNode_JumpStart::UFSMGraphNode_JumpStart(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	// if (!JumpStartId.IsValid())
	// {
	// 	JumpStartId = FGuid::NewGuid();
	// }
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
	}
	check(JumpStartId.IsValid());
}

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

FText UFSMGraphNode_JumpTo::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("Jump To 'NodeName'"));
}

bool UFSMGraphNode_JumpTo::CheckNodeValidity()
{
	// TODO::检查
	return Super::CheckNodeValidity();
}
