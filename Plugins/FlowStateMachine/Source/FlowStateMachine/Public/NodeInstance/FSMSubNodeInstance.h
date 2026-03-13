// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMNodeInstanceBase.h"
#include "FSMSubNodeInstance.generated.h"


class UFSMNodeInstance;

/**
 * 运行时子节点
 */
UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMSubNodeInstance : public UFSMNodeInstanceBase
{
    GENERATED_BODY()

public:
    virtual UWorld* GetWorld() const override;

    virtual void InitializeNode(UFSMNodeInstanceBase* InParentNode, UFlowStateContext* Context) override;

    virtual bool TrySwitchTo(int Index) override;

    virtual bool SwitchToByName(FName Name) override;

    template <class T = UFSMNodeInstanceBase>
    T* GetParentNode() const
    {
        return static_cast<T*>(ParentNode);
    }

    /** 调用的父级节点 */
    UPROPERTY()
    UFSMNodeInstanceBase* ParentNode;
};
