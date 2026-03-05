// Fill out your copyright notice in the Description page of Project Settings.


#include "NodeInstance/FSMNodeInstance.h"

#include "NodeInstance/FSMSubNodeInstance.h"
#include "SM/Actions/FlowStateAction.h"
#include "SM/Services/FlowStateService.h"
#include "SM/Conditions/FlowStateCondition.h"
#include "SM/FlowStateContext.h"


void UFSMNodeInstance::OnInitialize()
{
	// 执行所有 Action
	for (UFlowStateAction* Action : Actions)
	{
		Action->ExecuteAction(this);
	}
}

void UFSMNodeInstance::OnEnter()
{
	/** 实现自定义的进入函数 */
}

void UFSMNodeInstance::OnExit()
{
	OnExitDelegate.Broadcast();
	/** 实现自定义的退出函数 */
}

bool UFSMNodeInstance::CheckCondition()
{
	for (const UFlowStateCondition* Condition : Conditions)
	{
		if (!Condition->Condition(StateContext))
		{
			FSMLOGW("前置条件 [%s] 未通过", *Condition->GetNodeName())
			return false;
		}
	}
	return true;
}

bool UFSMNodeInstance::TrySwitchTo(int Index)
{
	if (StateContext && ChildStateHelpers.IsValidIndex(Index))
	{
		return StateContext->GotoStateNode(ChildStateHelpers[Index].ChildNodeInstance);
	}
	return false;
}

bool UFSMNodeInstance::SwitchToByName(FName Name)
{
	if (StateContext)
	{
		for (int i = 0; i < ChildStateHelpers.Num(); ++i)
		{
			if (ChildStateHelpers[i].PinName == Name)
			{
				return TrySwitchTo(i);
			}
		}
	}
	return false;
}

void UFSMNodeInstance::AddSubNode(UFSMNodeInstanceBase* InSubNode)
{
	if (InSubNode == nullptr)
	{
		return;
	}

	if (UFlowStateAction* ActionNode = Cast<UFlowStateAction>(InSubNode))
	{
		Actions.Add(ActionNode);
	}
	else if (UFlowStateService* ServiceNode = Cast<UFlowStateService>(InSubNode))
	{
		Services.Add(ServiceNode);
	}
	else if (UFlowStateCondition* ConditionNode = Cast<UFlowStateCondition>(InSubNode))
	{
		Conditions.Add(ConditionNode);
	}
	else
	{
		checkNoEntry();
	}

	SubNodes.Add(InSubNode);
}

void UFSMNodeInstance::ReplaceSubNode(UFSMNodeInstanceBase* NewSubNode, int Index)
{
	check(NewSubNode && SubNodes.IsValidIndex(Index))
	checkf(!NewSubNode->bIsTemplateInstance, TEXT("不得使用模板节点作为运行时实例"))
	if (UFlowStateAction* ActionNode = Cast<UFlowStateAction>(SubNodes[Index]))
	{
		const int32 ActionIndex = Actions.Find(ActionNode);
		Actions[ActionIndex] = static_cast<UFlowStateAction*>(NewSubNode);
	}
	else if (UFlowStateService* ServiceNode = Cast<UFlowStateService>(SubNodes[Index]))
	{
		const int32 ServiceIndex = Services.Find(ServiceNode);
		Services[ServiceIndex] = static_cast<UFlowStateService*>(NewSubNode);
	}
	else if (UFlowStateCondition* ConditionNode = Cast<UFlowStateCondition>(SubNodes[Index]))
	{
		const int32 ConditionIndex = Conditions.Find(ConditionNode);
		Conditions[ConditionIndex] = static_cast<UFlowStateCondition*>(NewSubNode);
	}
	SubNodes[Index] = NewSubNode;
}

void UFSMNodeInstance::ClearSubNodes()
{
	SubNodes.Empty();
	Actions.Empty();
	Services.Empty();
	Conditions.Empty();
}

/*
bool UFSMNodeInstance::HasAction(UClass* ActionClass) const
{
	for (UFSMSubNodeInstance* Action : Actions)
	{
		if (Action->IsA(ActionClass))
		{
			return true;
		}
	}
}
*/

UWorld* UFSMNodeInstance::GetWorld() const
{
	// 优先返回 Context 对象的世界上下文，因为 Context 是在运行时由 FlowStateMachineSubsystem 动态创建的。
	if (StateContext)
	{
		return StateContext->GetWorld();
	}
	return Super::GetWorld();
}


#if WITH_EDITOR

void UFSMNodeInstance::AddChildState(FName FromPinName, UFSMNodeInstance* NodeInstance)
{
	for (FStateChildNodeHelper& Helper : ChildStateHelpers)
	{
		if (Helper.PinName == FromPinName)
		{
			// 默认情况下，一个引脚只能有一个输出
			checkNoEntry()
			return;
		}
	} 
	ChildStateHelpers.Add(FStateChildNodeHelper(FromPinName, NodeInstance));
}

void UFSMNodeInstance::RemoveChildState(int Index)
{
	ChildStateHelpers.RemoveAt(Index);
}

void UFSMNodeInstance::ClearChildStates()
{
	ChildStateHelpers.Empty();
}

#endif

void UFSMNodeInstance::ReplaceChildState(UFSMNodeInstance* NewChildNode, int Index)
{
	checkf(NewChildNode, TEXT("The replaced child state is nullptr"));
	checkf(!NewChildNode->bIsTemplateInstance, TEXT("The replaced child state is template instance."))
	if (ChildStateHelpers.IsValidIndex(Index))
	{
		ChildStateHelpers[Index].ChildNodeInstance = NewChildNode;
	}
}