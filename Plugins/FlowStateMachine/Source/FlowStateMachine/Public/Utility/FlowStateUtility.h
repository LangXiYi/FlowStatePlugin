// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FlowStateUtility.generated.h"

DECLARE_LOG_CATEGORY_CLASS(LogFlowState, Log, All);

// #define BEGIN_NAMESPACE_FSM namespace FlowStateMachine {
// #define END_NAMESPACE_FSM } 

#define BEGIN_NAMESPACE_FSM 
#define END_NAMESPACE_FSM 

BEGIN_NAMESPACE_FSM

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

UENUM(BlueprintType)
enum class ECameraRotationMode : uint8
{
	// 不支持旋转
	None = 0,
	Origin,
	Origin_OnlyPitch,
	Origin_OnlyYaw,
	Self,
};

END_NAMESPACE_FSM
