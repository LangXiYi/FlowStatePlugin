// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeNode/FSMRuntimeNode_State.h"
#include "UObject/Object.h"
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
UCLASS(Blueprintable, BlueprintType, Abstract)
class FLOWSTATEMACHINE_API UFlowStateBase : public UFSMRuntimeNode_State
{
	GENERATED_BODY()

	friend class UFlowStateContext;

public:
	UFlowStateBase() {}
	// UFlowStateBase(UFlowStateContext* InContext);

public:
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) override;
	virtual void OnInitialize(UFlowStateContext* InContext) override;

	/** 每帧执行事件 */
	virtual void Tick(float DeltaTime);
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

	/** 初始化控件事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnInitWidget)
	void NativeOnInitWidget(UFlowStateLayoutWidget* Layout);
		
	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	UFUNCTION(BlueprintPure, Category="Flow State")
	FORCEINLINE float GetDeltaTime() const { return Private_DeltaTime; }

private:
	float Private_DeltaTime;
};