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

UENUM(BlueprintType)
enum class EFlowStateLifetime : uint8
{
	// 长期存在
	None = 0,
	// 当前状态结束后死亡
	Kill,
	// 当前状态结束后隐藏
	Hien,
};
