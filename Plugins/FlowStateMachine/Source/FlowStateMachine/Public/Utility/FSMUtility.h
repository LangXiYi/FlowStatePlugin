// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMUtility.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogFlowStateMachine, Log, All);

#define FSMLOG(msg, ...) UE_LOG(LogFlowStateMachine, Log, TEXT(msg), __VA_ARGS__)
#define FSMLOGW(msg, ...) UE_LOG(LogFlowStateMachine, Warning, TEXT(msg), __VA_ARGS__)
#define FSMLOGE(msg, ...) UE_LOG(LogFlowStateMachine, Error, TEXT(msg), __VA_ARGS__)

#define BEGIN_NAMESPACE_FSM namespace FlowStateMachine {
#define END_NAMESPACE_FSM }

BEGIN_NAMESPACE_FSM
    UWorld* GetWorldFromContextObject(UObject* WorldContextObject);

END_NAMESPACE_FSM

// Delegates --------------------------
DECLARE_MULTICAST_DELEGATE(FStateDelegate);
DECLARE_DYNAMIC_DELEGATE(FStateExecuteDelegate);

UENUM(BlueprintType)
enum class EFlowStateLifetime : uint8
{
    None = 0,
    // 长期存在
    Static,
    // 当前状态结束后死亡
    Kill,
    // 当前状态结束后隐藏
    Hidden,
};


namespace FCommonData
{
    // const FName KeySelf = TEXT("SelfActor");

    using FKey = uint8;

    constexpr FKey InvalidKey = static_cast<FKey>(-1);
}

class UFSMNodeInstance;

USTRUCT(BlueprintType)
struct FStatePinInfo
{
    GENERATED_BODY()
    FStatePinInfo()
    {
    }

    FStatePinInfo(FName InPinCategory, FName InPinName) :
        PinCategory(InPinCategory), PinName(InPinName)
    {
    }

    bool IsValid() const
    {
        return PinCategory != NAME_None && PinName != NAME_None;
    }

    UPROPERTY(BlueprintReadWrite, Category = "FlowStateCollectData")
    FName PinCategory;

    UPROPERTY(BlueprintReadWrite, Category = "FlowStateCollectData")
    FName PinName;
};


USTRUCT()
struct FStateChildNodeHelper
{
    GENERATED_BODY()

    FStateChildNodeHelper()
    {
    }

    FStateChildNodeHelper(FName InPinName, UFSMNodeInstance* InChildNodeInstance) :
        PinName(InPinName), ChildNodeInstance(InChildNodeInstance)
    {
    }

    UPROPERTY()
    FName PinName;

    UPROPERTY()
    UFSMNodeInstance* ChildNodeInstance;
};
