// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSGraph_CompositeNode.h"
#include "Composite_JumpNode.generated.h"

/**
 * JumpStart节点不能连接未被使用的节点？
 */
UCLASS()
class FLOWSTATEEDITOR_API UGraphCNode_JumpStart : public UFSGraph_CompositeNode
{
    GENERATED_BODY()

public:
    UGraphCNode_JumpStart(const FObjectInitializer& ObjectInitializer);
    virtual void                   PostPasteNode() override;
    virtual void                   PostPlacedNewNode() override;
    virtual void                   DestroyNode() override;
    virtual void                   AllocateDefaultPins() override;
    virtual FString                GetNodeTitleFormatString() const override;
    virtual FPinConnectionResponse CheckPinConnection(const UFSGraphNodeBase* OtherNode, EEdGraphPinDirection FromDirection) const override;

    UPROPERTY()
    FGuid JumpStartId;
};

/**
 *
 */
UCLASS()
class FLOWSTATEEDITOR_API UGraphCNode_JumpTo : public UFSGraph_CompositeNode
{
    GENERATED_BODY()

public:
    virtual void    AllocateDefaultPins() override;
    virtual void    PostPlacedNewNode() override;
    virtual FString GetNodeTitleFormatString() const override;

    virtual bool IsDeprecated() const override;
    virtual bool HasDeprecatedReference() const override;

    virtual FEdGraphNodeDeprecationResponse GetDeprecationResponse(EEdGraphNodeDeprecationType DeprecationType) const override;

protected:
    bool IsValidJumpNode() const;

public:
    // 点击时，创建一个查找窗口，返回所有的跳跃节点列表，点击后将值赋予该节点
    UPROPERTY()
    FGuid JumpStartId;
};
