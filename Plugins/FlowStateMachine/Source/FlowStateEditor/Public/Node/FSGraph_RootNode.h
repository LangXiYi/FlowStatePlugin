// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Node/FSGraphNode.h"
#include "UObject/Object.h"
#include "FSGraph_RootNode.generated.h"

class UFlowStateWidgetLayerManager;
/**
 * 默认的图表根节点
 */
UCLASS()
class FLOWSTATEEDITOR_API UFSGraph_RootNode : public UFSGraphNode
{
    GENERATED_BODY()

public:
    virtual void                   AllocateDefaultPins() override;
    virtual bool                   CanDuplicateNode() const override { return false; }
    virtual bool                   CanUserDeleteNode() const override { return false; }
    virtual bool                   IsSelectedInEditor() const override { return false; }
    virtual bool                   IsDeprecated() const override;
    virtual FText                  GetTooltipText() const override;
    virtual FText                  GetNodeTitle(ENodeTitleType::Type TitleType) const override { return FText::FromString(TEXT("Root Node")); }
    virtual FPinConnectionResponse CheckPinConnection(const UFSGraphNodeBase* OtherNode, EEdGraphPinDirection Direction) const override;
    // TODO::监听 CommonData 改变事件
    virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

protected:
    void UpdateCommonData();

    void UpdateLayoutWidget();

public:
    UPROPERTY(EditAnywhere)
    UFSMCommonData* CommonData;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UFlowStateWidgetLayerManager> WidgetLayerManagerClass;
};

