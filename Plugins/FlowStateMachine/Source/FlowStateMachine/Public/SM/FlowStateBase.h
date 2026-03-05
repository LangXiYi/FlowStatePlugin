// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NodeInstance/FSMNodeInstance.h"
#include "FlowStateBase.generated.h"

class UWidget;
class UFSMMetaDataAsset;
class UFlowStateDataFragment;
class UFlowStateLayoutWidget;

/*
 * 状态机可以切换状态至另一个状态机
 * 状态机会根据链式结构遍历执行条件
 * 
 */

class UFlowStateContext;
class UFlowStateLayoutWidget;


/**
 * 可以由蓝图继承并实现的状态基类
 */
UCLASS(Blueprintable, BlueprintType)
class FLOWSTATEMACHINE_API UFlowStateBase : public UFSMNodeInstance
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnInitialize() override;

	/** 每帧执行事件 */
	virtual void Tick(float DeltaTime) override;
	/** 每帧执行事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName="Tick")
	void OnTick(float DeltaTime);

	/** 初始化当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnIntialize)
	void NativeOnInitialize(UFlowStateContext* InContext);
	/** 进入当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnEnter)
	void NativeOnEnter();
	/** 退出当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnExit)
	void NativeOnExit();
		
	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
	UFUNCTION(BlueprintPure, Category="Flow State")
	FORCEINLINE float GetDeltaTime() const { return Private_DeltaTime; }

private:
	float Private_DeltaTime;
};