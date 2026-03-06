// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlowStateMachine.generated.h"

class UFlowStateWidgetLayerManager;
class UFSMNodeInstance;

/**
 *
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateMachine : public UObject
{
    GENERATED_BODY()

public:
    /** 状态机的运行时根节点 */
    UPROPERTY(VisibleAnywhere)
    UFSMNodeInstance* RootNodeInstance;

    /** 状态机的所有零散节点（无法被RootNode追溯到节点） */
    UPROPERTY(VisibleAnywhere)
    TArray<UFSMNodeInstance*> ScatteredNodes;

    /** 状态机根节点的装饰器子节点 */
    UPROPERTY(VisibleAnywhere)
    TArray<class UFlowStateCondition*> RootDecorators;

    /** 状态机根节点的服务子节点 */
    UPROPERTY(VisibleAnywhere)
    TArray<class UFlowStateService*> RootServices;

    /** 状态机根节点的行为子节点 */
    UPROPERTY(VisibleAnywhere)
    TArray<class UFlowStateAction*> RootActions;

#if WITH_EDITORONLY_DATA
    /** Graph For State Machine */
    UPROPERTY()
    class UEdGraph* FSMGraph;

#endif

    FString GetScatteredNodeName(FGuid InScatteredNodeID) const;

    /** 黑板 */
    UPROPERTY(VisibleAnywhere)
    class UFSMCommonData* CommonData = nullptr;

    /** 状态机的布局管理器 */
    UPROPERTY(VisibleAnywhere)
    TSubclassOf<UFlowStateWidgetLayerManager> WidgetLayerManagerClass;
};
