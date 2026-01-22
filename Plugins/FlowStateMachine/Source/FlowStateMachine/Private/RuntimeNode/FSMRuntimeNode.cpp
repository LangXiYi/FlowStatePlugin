// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNode.h"

#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "SM/FlowStateContext.h"


void UFSMRuntimeNode::OnInitialize()
{
	// 执行所有 Action
	for (UFSMRuntimeSubNode_Action* Action : Actions)
	{
		Action->ExecuteAction(this);
	}
}

void UFSMRuntimeNode::OnEnter()
{
	/** 实现自定义的进入函数 */
}

void UFSMRuntimeNode::OnExit()
{
	OnExitDelegate.Broadcast();
	/** 实现自定义的退出函数 */
}

bool UFSMRuntimeNode::CheckCondition()
{
	for (const UFSMRuntimeSubNode_Condition* Condition : Conditions)
	{
		if (!Condition->Condition(StateContext))
		{
			FSMLOGW("前置条件 [%s] 未通过", *Condition->GetNodeName())
			return false;
		}
	}
	return true;
}

bool UFSMRuntimeNode::TrySwitchTo(int Index)
{
	if (StateContext && ChildStateHelpers.IsValidIndex(Index))
	{
		return StateContext->GotoStateNode(ChildStateHelpers[Index].ChildNodeInstance);
	}
	return false;
}

bool UFSMRuntimeNode::SwitchToByName(FName Name)
{
	if (StateContext)
	{
		for (int i = 0; i < ChildStateHelpers.Num(); ++i)
		{
			if (ChildStateHelpers[i].PinName == Name)
			{
				return StateContext->GotoStateNode(ChildStateHelpers[i].ChildNodeInstance);
			}
		}
	}
	return false;
}

void UFSMRuntimeNode::AddSubNode(UFSMRuntimeNodeBase* InSubNode)
{
	if (InSubNode == nullptr)
	{
		return;
	}

	if (UFSMRuntimeSubNode_Action* ActionNode = Cast<UFSMRuntimeSubNode_Action>(InSubNode))
	{
		Actions.Add(ActionNode);
	}
	else if (UFSMRuntimeSubNode_Service* ServiceNode = Cast<UFSMRuntimeSubNode_Service>(InSubNode))
	{
		Services.Add(ServiceNode);
	}
	else if (UFSMRuntimeSubNode_Condition* ConditionNode = Cast<UFSMRuntimeSubNode_Condition>(InSubNode))
	{
		Conditions.Add(ConditionNode);
	}
	else
	{
		checkNoEntry();
	}

	SubNodes.Add(InSubNode);
}

void UFSMRuntimeNode::ReplaceSubNode(UFSMRuntimeNodeBase* NewSubNode, int Index)
{
	check(NewSubNode && SubNodes.IsValidIndex(Index))
	checkf(!NewSubNode->bIsTemplateInstance, TEXT("不得使用模板节点作为运行时实例"))
	if (UFSMRuntimeSubNode_Action* ActionNode = Cast<UFSMRuntimeSubNode_Action>(SubNodes[Index]))
	{
		const int32 ActionIndex = Actions.Find(ActionNode);
		Actions[ActionIndex] = (UFSMRuntimeSubNode_Action*)NewSubNode;
	}
	else if (UFSMRuntimeSubNode_Service* ServiceNode = Cast<UFSMRuntimeSubNode_Service>(SubNodes[Index]))
	{
		const int32 ServiceIndex = Services.Find(ServiceNode);
		Services[ServiceIndex] = (UFSMRuntimeSubNode_Service*)NewSubNode;
	}
	else if (UFSMRuntimeSubNode_Condition* ConditionNode = Cast<UFSMRuntimeSubNode_Condition>(SubNodes[Index]))
	{
		const int32 ConditionIndex = Conditions.Find(ConditionNode);
		Conditions[ConditionIndex] = (UFSMRuntimeSubNode_Condition*)NewSubNode;
	}
	SubNodes[Index] = NewSubNode;
}

void UFSMRuntimeNode::ClearSubNodes()
{
	SubNodes.Empty();
	Actions.Empty();
	Services.Empty();
	Conditions.Empty();
}

/*
bool UFSMRuntimeNode::HasAction(UClass* ActionClass) const
{
	for (UFSMRuntimeSubNode* Action : Actions)
	{
		if (Action->IsA(ActionClass))
		{
			return true;
		}
	}
}
*/

UWorld* UFSMRuntimeNode::GetWorld() const
{
	// 优先返回 Context 对象的世界上下文，因为 Context 是在运行时由 FlowStateMachineSubsystem 动态创建的。
	if (StateContext)
	{
		return StateContext->GetWorld();
	}
	return Super::GetWorld();
}


#if WITH_EDITOR

void UFSMRuntimeNode::AddChildState(FName FromPinName, UFSMRuntimeNode* NodeInstance)
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

void UFSMRuntimeNode::RemoveChildState(int Index)
{
	ChildStateHelpers.RemoveAt(Index);
}

void UFSMRuntimeNode::ClearChildStates()
{
	ChildStateHelpers.Empty();
}

#endif

void UFSMRuntimeNode::ReplaceChildState(UFSMRuntimeNode* NewChildNode, int Index)
{
	checkf(NewChildNode, TEXT("The replaced child state is nullptr"));
	checkf(!NewChildNode->bIsTemplateInstance, TEXT("The replaced child state is template instance."))
	if (ChildStateHelpers.IsValidIndex(Index))
	{
		ChildStateHelpers[Index].ChildNodeInstance = NewChildNode;
	}
}