// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/IFlowStateInterface.h"
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
class FLOWSTATEMACHINE_API UFlowState : public UObject, public IFlowStateInterface
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
	/// IFlowStateInterface Event
	////////////////////////////////////////////////////////////////////////
public:
	virtual void OnEnter() override;
	virtual void OnExit() override;
	virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) override;
	virtual void OnInitialize(UFlowStateContext* Context) override;
	virtual void OnPreInitialize(UFlowState* LastState) override {}
	virtual void OnPostInitialize() override {}

	/** 每帧执行事件 */
	virtual void Tick(float DeltaTime);
	/** 每帧执行事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName="Tick")
	void OnTick(float DeltaTime);

	/** 初始化当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnIntialize)
	void NativeOnInitialize();
	/** 进入当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnEnter)
	void NativeOnEnter();
	/** 退出当前状态事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnExit)
	void NativeOnExit();

	/** 初始化控件事件 */
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName = OnInitWidget)
	void NativeOnInitWidget(UFlowStateLayoutWidget* Layout);
	
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
