// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node/FSMGraphNode_Composites.h"
#include "FSMGraphNode_Jump.generated.h"

/**
 * JumpStart节点不能连接未被使用的节点？
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_JumpStart : public UFSMGraphNode_Composites
{
	GENERATED_BODY()

public:
	UFSMGraphNode_JumpStart(const FObjectInitializer& ObjectInitializer);
	virtual void PostPlacedNewNode() override;
	virtual void AllocateDefaultPins() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual FPinConnectionResponse CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const override;

	// DEBUG：：不要修改此属性值
	UPROPERTY()
	FGuid JumpStartId;
};

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_JumpTo : public UFSMGraphNode_Composites
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual void PostPlacedNewNode() override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual bool CheckNodeValidity() override;

	// 点击时，创建一个查找窗口，返回所有的跳跃节点列表，点击后将值赋予该节点
	UPROPERTY()
	FGuid JumpStartId;
};
