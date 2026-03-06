// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSGraphNodeBase.h"
#include "EdGraph/EdGraphNode.h"
#include "FSGraphSubNode.generated.h"

class UFSMCommonData;
class UFlowStateGraph;

class UFSMNodeInstance;

/**
 * 图表子节点
 * 不能单独创建，必须在某个主节点下才能创建，创建后会自动附加到主节点上
 *     ParentNode
 *     |___ SubNode_A
 *     |___ SubNode_B
 */
UCLASS()
class FLOWSTATEEDITOR_API UFSGraphSubNode : public UFSGraphNodeBase
{
    GENERATED_BODY()

public:
    virtual void DestroyNode() override;
    virtual TSharedPtr<SGraphNode> CreateVisualWidget() override;

    virtual FLinearColor GetNodeTitleColor() const override;

    virtual bool HasDeprecatedReference() const override;

    virtual FEdGraphNodeDeprecationResponse
    GetDeprecationResponse(EEdGraphNodeDeprecationType DeprecationType) const override;

#if WITH_EDITOR

    virtual void PostEditUndo() override;

#endif
};

// 更改 Decorator 名称为 Condition
// 用于标识由当前状态切换至下一状态的条件
UCLASS()
class FLOWSTATEEDITOR_API UFSMGraphSubNode_Condition : public UFSGraphSubNode
{
    GENERATED_BODY()
};

UCLASS()
class FLOWSTATEEDITOR_API UFSMGraphSubNode_Action : public UFSGraphSubNode
{
    GENERATED_BODY()
};

UCLASS()
class FLOWSTATEEDITOR_API UFSMGraphSubNode_Service : public UFSGraphSubNode
{
    GENERATED_BODY()
};
