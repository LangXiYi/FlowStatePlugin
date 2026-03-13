// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/Actions/FlowStateAction.h"
#include "Actions_CreateWidgets.generated.h"

class UFSMCreateWidgetHelper;
/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UActions_CreateWidgets : public UFlowStateAction
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, Instanced, Category = "CreateWidgets")
    TArray<UFSMCreateWidgetHelper*> CreateWidgets;

    virtual void ExecuteAction(UFSMNodeInstance* Instance) override;

    /** 返回该子节点需要创建的引脚信息 */
    virtual void GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const override;
};
