// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNode.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode_State.generated.h"

class UFlowStateContext;

class IFlowStateInterface
{
public:
	IFlowStateInterface() {}//: Context(InContext) {}
	virtual ~IFlowStateInterface() = default;
	
	/** 当初始化状态时触发该函数 */
	virtual void OnInitialize(UFlowStateContext* InContext) = 0;
	/** 在初始化状态前调用该函数 */
	virtual void OnPreInitialize() = 0;
	/** 当初始化状态后触发该函数 */
	virtual void OnPostInitialize() = 0;
	/** 当进入状态时触发该函数 */
	virtual void OnEnter() = 0;
	/** 当退出状态时触发该函数 */
	virtual void OnExit() = 0;

	/** 检查过度条件 */
	virtual bool CheckCondition() = 0;

protected:
	/** 初始化状态控件 */
	virtual void OnInitWidget(class UFlowStateLayoutWidget* Layout) = 0;
};

UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_State : public UFSMRuntimeNode, public IFlowStateInterface
{
	GENERATED_BODY()

public:
	virtual void OnEnter() override {}
	virtual void OnExit() override {}
	virtual void OnInitialize(UFlowStateContext* InContext) override { Context = InContext; }
	virtual void OnPreInitialize() override {}
	virtual void OnPostInitialize() override {}
	virtual bool CheckCondition() override { return true; }

	UFUNCTION(BlueprintCallable)
	void EndState(int Index);

protected:
	virtual void OnInitWidget(UFlowStateLayoutWidget* Layout) override {}

private:
	UPROPERTY()
	UFlowStateContext* Context;
};