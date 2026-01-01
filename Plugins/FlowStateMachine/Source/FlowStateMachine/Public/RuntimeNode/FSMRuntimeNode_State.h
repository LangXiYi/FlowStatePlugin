// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FSMRuntimeNode.h"
#include "UObject/Object.h"
#include "FSMRuntimeNode_State.generated.h"

class UFlowStateContext;

UCLASS(Abstract)
class FLOWSTATEMACHINE_API UFSMRuntimeNode_State : public UFSMRuntimeNode
{
	GENERATED_BODY()

public:
	virtual void OnInitialize(UFlowStateContext* InContext) override;
	virtual void OnEnter() override { }
	virtual void OnExit() override {}
	virtual void OnPreInitialize()  {}
	virtual void OnPostInitialize()  {}

protected:
	virtual void OnInitWidget(class UFlowStateLayoutWidget* Layout) {}
};