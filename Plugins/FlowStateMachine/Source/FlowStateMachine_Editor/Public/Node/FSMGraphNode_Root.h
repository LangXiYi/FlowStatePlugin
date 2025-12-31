// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node/FSMGraphNode.h"
#include "UObject/Object.h"
#include "FSMGraphNode_Root.generated.h"

/**
 * 默认的图表根节点
 */
UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraphNode_Root : public UFSMGraphNode
{
	GENERATED_BODY()

public:
	virtual void AllocateDefaultPins() override;
	virtual bool CanDuplicateNode() const override { return false; }
	virtual bool CanUserDeleteNode() const override{ return false; }
	virtual bool IsSelectedInEditor() const override { return false; }
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override { return FText::FromString(TEXT("Root Node")); }

	// TODO::监听 CommonData 改变事件
public:
	UPROPERTY(EditAnywhere)
	UFSMCommonData* CommonData;
};

