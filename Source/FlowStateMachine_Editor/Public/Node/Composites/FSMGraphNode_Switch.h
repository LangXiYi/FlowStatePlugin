// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node/FSMGraphNode_Composites.h"
#include "FSMGraphNode_Switch.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Switch : public UFSMGraphNode_Composites
{
	GENERATED_BODY()

public:
	/** 生成一个默认的输入和输出引脚 */
	virtual void AllocateDefaultPins() override;

	/** Switch 节点会生成多个引脚，每个引脚只能有一个输出 */
	virtual FPinConnectionResponse CheckPinConnection(const UFSMGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const override;

protected:
	// 读取CommonData数据，并查找？？？？
};
