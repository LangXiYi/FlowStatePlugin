// Fill out your copyright notice in the Description page of Project Settings.


#include "RuntimeNode/FSMRuntimeNode.h"

#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "RuntimeNode/FSMRuntimeSubNode_Action.h"
#include "RuntimeNode/FSMRuntimeSubNode_Service.h"
#include "RuntimeNode/FSMRuntimeSubNode_Condition.h"
#include "SM/FlowStateContext.h"


void UFSMRuntimeNode::OnInitialize(UFlowStateContext* InContext)
{
	Context = InContext;

	// 执行所有 Action
	for (UFSMRuntimeSubNode_Action* Action : Actions)
	{
		Action->ExecuteAction();
	}
}

void UFSMRuntimeNode::OnEnter()
{
	/** 实现自定义的进入函数 */
}

void UFSMRuntimeNode::OnExit()
{
	/** 实现自定义的退出函数 */
}

bool UFSMRuntimeNode::CheckCondition()
{
	for (const UFSMRuntimeSubNode_Condition* Condition : Conditions)
	{
		if (!Condition->Condition(Context))
		{
			FSMLOGW("前置条件 [%s] 未通过", *Condition->GetNodeName())
			return false;
		}
	}
	return true;
}

bool UFSMRuntimeNode::TrySwitchTo(int Index)
{
	if (!Context || !ChildrenNodes.IsValidIndex(Index))
	{
		FSMLOGW("状态机上下文不存在或下标索引 [%d] 非法", Index);
		return false;
	}
	if (UFSMRuntimeNode* Node = Cast<UFSMRuntimeNode>(ChildrenNodes[Index]))
	{
		return Context->TrySwitchTo(Node);
	}
	// 这里不应该会被执行，因为正常来说 ChildrenNodes 中所有的对象都继承自 UFSMRuntimeNode 。
	checkNoEntry()
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

	InSubNode->ParentNode = this;
	SubNodes.Add(InSubNode);
}

void UFSMRuntimeNode::ReplaceSubNode(UFSMRuntimeNodeBase* NewSubNode, int Index)
{
	if (NewSubNode == nullptr || !SubNodes.IsValidIndex(Index))
	{
		return;
	}

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
	NewSubNode->ParentNode = this;

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
	if (Context)
	{
		return Context->GetWorld();
	}
	return Super::GetWorld();
}

