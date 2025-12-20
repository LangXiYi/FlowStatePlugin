// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNode.h"
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


class IFlowStateInterface
{
public:
	IFlowStateInterface() {}//: Context(InContext) {}
	virtual ~IFlowStateInterface() = default;
	
	/** 当初始化状态时触发该函数 */
	virtual void OnInitialize(UFlowStateContext* Context) = 0;
	/** 在初始化状态前调用该函数 */
	virtual void OnPreInitialize(IFlowStateInterface* LastState) = 0;
	/** 当初始化状态后触发该函数 */
	virtual void OnPostInitialize() = 0;
	/** 当进入状态时触发该函数 */
	virtual void OnEnter() = 0;
	/** 当退出状态时触发该函数 */
	virtual void OnExit() = 0;
	/** 初始化状态控件 */
	virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) = 0;
	/** 检查过度条件 */
	virtual bool CheckCondition() = 0;

protected:
	// UFlowStateContext* Context;	
};

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Abstract)
class FLOWSTATEMACHINE_API UFlowStateBase : public UFSMRuntimeNode_State, public IFlowStateInterface
{
	GENERATED_BODY()

	friend class UFlowStateContext;

public:
	UFlowStateBase() {}
	// UFlowStateBase(UFlowStateContext* InContext);
	
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
	virtual void OnPreInitialize(IFlowStateInterface* LastState) override {}
	virtual void OnPostInitialize() override {}
	virtual bool CheckCondition() override { return true; }

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
	virtual void PreIniProperties(UFlowStateBase* LastState);

	UFUNCTION(BlueprintImplementableEvent, Category = "FlowState")
	void OnPreInitProperties(UFlowStateBase* LastState);

protected:
	UPROPERTY(BlueprintReadOnly, Category = "FlowState", meta = (AllowPrivateAccess = true))
	UFlowStateContext* ParentContext;

private:
	float Private_DeltaTime;
};


/**
 * 该状态会创建一个新的状态机并将状态切换至该状态机
 * 若当前状态的条件不满足则会跳出这一状态机器
 */
UCLASS()
class UFlowStateContextState : public UFlowStateBase
{
	GENERATED_BODY()

public:


	
protected:
	// 创建的新的状态机！！！
	UPROPERTY()
	UFlowStateContext* StateContext;

	// 当前状态指向的状态机中的状态
	UPROPERTY()
	UFlowStateBase* ContextState;
};
