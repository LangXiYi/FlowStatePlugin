// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "SM/FlowStateBase.h"
#include "SM/FlowStateMachine.h"
#include "SM/FSMGC.h"
#include "Utility/FSMUtility.h"


void UFlowStateContext::RegisterFlowStateMachine(UFlowStateMachine* FlowStateMachine)
{
	if (!FlowStateMachine)
	{
		FSMLOGE("传入的状态机对象为空。");
		return;
	}

	StateMachine = FlowStateMachine;
	// TODO::创建用户布局控件，监听图表节点的属性改变事件
	// LayoutWidget = CreateWidget<UFlowStateLayoutWidget>(GetWorld(), StateMachine->LayoutWidget);

	// 创建垃圾管理器
	GCManager = MakeShareable(new FSMGC);

	if (UFSMRuntimeNode* RootState = Cast<UFSMRuntimeNode>(StateMachine->RootRuntimeNode))
	{
		if (TrySwitchTo(RootState))
		{
			// 触发事件，开始运行 FSM
			OnStartFlowStateMachine.Broadcast();
		}
	}
}

bool UFlowStateContext::TrySwitchTo(UFSMRuntimeNode* Node)
{
	if (!Node)
	{
		FSMLOGW("切换至指定的节点失败，该对象并非有效值。")
		return false;
	}

	// 检查节点是否满足所有条件
	if (!Node->CheckCondition())
	{
		return false;
	}


	// 若目标是一个状态节点，那么直接切换过去即可
	UFSMRuntimeNode_State* State = Cast<UFSMRuntimeNode_State>(Node);
	if (State)
	{
		ExitCurrentState();
		EnterNewState(State);
		return true;
	}

	// 若目标是一个组合节点，则需要将其添加到执行链中并执行
	UFSMRuntimeNode_Composites* Composites = Cast<UFSMRuntimeNode_Composites>(Node);
	if (Composites)
	{
		ExitCurrentState();
		EnterNewState(Composites);
		// TODO::将其添加到执行链中并执行
		return true;
	}
	FSMLOGW("切换至指定的节点失败，该对象的类型不是 State 或 Composites 。")
	return false;
}

void UFlowStateContext::Tick(float DeltaTime)
{
	if (CurState != nullptr)
	{
		CurState->Tick(DeltaTime);
	}
}

void UFlowStateContext::ExitCurrentState()
{
	if (CurState)
	{
		CurState->OnExit();
	}
	OnExitState.Broadcast(CurState);
	CurState = nullptr;
}

void UFlowStateContext::EnterNewState(UFSMRuntimeNode* NewState)
{
	if (NewState)
	{
		CurState = NewState;

		OnPreInitializeState.Broadcast(NewState);
		NewState->OnInitialize(this);

		NewState->OnEnter();
		OnEnterState.Broadcast(CurState);
	}
}

TArray<UFSMRuntimeNode*> UFlowStateContext::GetNextStates() const
{
	TArray<UFSMRuntimeNode*> NextStates;
	for (UFSMRuntimeNodeBase* Node : CurState->ChildrenNodes)
	{
		if (UFSMRuntimeNode* RuntimeNode = Cast<UFSMRuntimeNode>(Node))
		{
			NextStates.Add(RuntimeNode);
		}
	}
	return NextStates;
}
