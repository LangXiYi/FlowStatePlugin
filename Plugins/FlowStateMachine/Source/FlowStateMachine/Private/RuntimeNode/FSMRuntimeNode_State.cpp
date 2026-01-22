// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNode_State.h"

#include "SM/FlowStateContext.h"
#include "Utility/FSMUtility.h"

void UFSMRuntimeNode_State::OnInitialize()
{
	Super::OnInitialize();

	// 初始化当前状态的用户控件
	/*UFlowStateLayoutWidget* LayoutWidget = StateContext->GetLayoutWidget();
	if (LayoutWidget)
	{
		OnInitWidget(LayoutWidget);
	}
	else
	{
		FSMLOGW("状态机中的布局控件为空！！！")
	}*/
}

void UFSMRuntimeNode_State::GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const
{
	PinInfos.Insert(FStatePinInfo("DefaultPin", "Then"), 0);
	Super::GetStatePinInfos(PinInfos);
}
