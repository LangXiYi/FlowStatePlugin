// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlowState.generated.h"

class UFSMMetaDataAsset;
class UFlowStateDataFragment;
class UWidget;
class UFlowStateLayoutWidget;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FLOWSTATEMACHINE_API UFlowState : public UObject
{
	GENERATED_BODY()

	friend class UFlowStateContext;

	////////////////////////////////////////////////////////////////////////
	/// Get or Set
	////////////////////////////////////////////////////////////////////////
public:
	virtual UWorld* GetWorld() const override;
	virtual ULevel* GetLevel() const;

	UFUNCTION(BlueprintPure, Category="Flow State")
	FORCEINLINE float GetDeltaTime() const { return Private_DeltaTime; }

	////////////////////////////////////////////////////////////////////////
	/// Custom Process Event
	////////////////////////////////////////////////////////////////////////
public:
	/** 每帧执行事件 */
	virtual void Tick(float DeltaTime);
	/** 每帧执行事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName="Tick")
	void OnTick(float DeltaTime);

	/** 进入当前状态事件 */
	virtual void Enter(UFlowStateContext* Context);
	/** 进入当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState")
	void OnEnter();

	/** 初始化控件事件 */
	virtual void InitWidget(UFlowStateLayoutWidget* Layout);
	/** 初始化控件事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState")
	void OnInitWidget(UFlowStateLayoutWidget* Layout);

	/** 退出当前状态事件 */
	virtual void Exit();
	/** 退出当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState")
	void OnExit();
	
protected:
	// 预初始化属性，可以在这里继承上一状态的属性
	virtual void PreIniProperties(UFlowState* LastState);
	UFUNCTION(BlueprintImplementableEvent, Category = "FlowState")
	void OnPreInitProperties(UFlowState* LastState);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "FlowState", meta = (AllowPrivateAccess = true))
	UFlowStateContext* StateContext;

private:
	float Private_DeltaTime;
};
