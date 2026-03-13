// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSGraphNode.h"
#include "UObject/Object.h"
#include "FSGraph_StateNode.generated.h"

/**
 * 状态节点
 * 至少有一个输入以及零个或多个输出
 */
UCLASS()
class FLOWSTATEEDITOR_API UFSGraph_StateNode : public UFSGraphNode
{
    GENERATED_BODY()

public:
    virtual void AllocateDefaultPins() override;

    /** 获得节点的标题 */
    virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

    virtual void GetNodeContextMenuActions(UToolMenu* Menu, UGraphNodeContextMenuContext* Context) const override;

    virtual FEdGraphNodeDeprecationResponse
    GetDeprecationResponse(EEdGraphNodeDeprecationType DeprecationType) const override;

    virtual TSharedPtr<SGraphNode> CreateVisualWidget() override;
};
