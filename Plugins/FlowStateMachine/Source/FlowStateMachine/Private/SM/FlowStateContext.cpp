// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Blueprint/UserWidget.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "SM/FlowStateBase.h"
#include "SM/FlowStateMachine.h"
#include "SM/FSMGC.h"
#include "Utility/FSMUtility.h"


void UFlowStateContext::RegisterFlowStateMachine(UFlowStateMachine& FlowStateMachine)
{
	StateMachine = &FlowStateMachine;
	if (StateMachine && StateMachine->RootRuntimeNode)
	{
		// TODO::创建用户布局控件，监听图表节点的属性改变事件
		// LayoutWidget = CreateWidget<UFlowStateLayoutWidget>(GetWorld(), StateMachine->LayoutWidget);

		// 创建垃圾管理器
		GCManager = MakeShareable(new FSMGC);

		InstanceStack.Empty();
		
		UFSMRuntimeNode* RootState = DumpStateInstance<UFSMRuntimeNode>(StateMachine->RootRuntimeNode, nullptr);
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

	if (Node->bIsTemplateInstance)
	{
		// 从缓存中查找父级节点
		UFSMRuntimeNodeBase* ParentNode = CacheTemplateObjects.FindRef(Node->ParentNode);
		if (ParentNode)
		{
			// 若传入的节点是模板实例，则需要进行转换后才能继续执行下面的逻辑
			Node = DumpStateInstance<UFSMRuntimeNode>(Node, ParentNode);
		}
		else
		{
			// 正常情况下不会走到这里，因为父级比如优于子级执行，除非父级被垃圾回收了
			checkNoEntry()
		}
	}

	if (!Node)
	{
		FSMLOGW("切换至指定的节点失败，转换后的对象并非有效值。")
		return false;
	}

	// 检查节点是否满足所有条件
	if (!Node->CheckCondition())
	{
		return false;
	}

	if (Node->bIsRootNode || Node->IsStackInstance())
	{
		if (InstanceStack.Contains(Node))
		{
			// 若执行链中存在该节点实例，则不会将他加入执行链，而是修改 StackTop 的指向
			StackTop = Node;
		}
		else
		{
			// 将节点实例加入执行链
			InstanceStack.Push(Node);
			StackTop = Node;
		}
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

#if !UE_BUILD_SHIPPING
	// TODO::添加调试信息--->资产加载相关内容
	// TODO::当前的状态是什么？
	// TODO::当前状态的 MetaData 与 资产管理器中缓存的 MetaData列表？

	/**
	 * CurState: XXXX
	 * CurMetaData: XXX (引用计数)
	 * CacheMetaData:
	 *		| XXXX_1 (引用计数)
	 *		| XXXX_2 (引用计数)
	 *		| XXXX_3 (引用计数)
	 */

#endif
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
		// 在修改当前状态之前广播事件，可以保证监听该事件的对象可以同时访问旧状态以及新状态
		OnPreInitializeState.Broadcast(NewState);
		CurState = NewState;
		NewState->OnInitialize(this);

		NewState->OnEnter();
		OnEnterState.Broadcast(CurState);
	}
}

UFSMRuntimeNodeBase* UFlowStateContext::DumpStateInstance(const UFSMRuntimeNodeBase* Template, UFSMRuntimeNodeBase* ParentNode)
{
	if (Template == nullptr || Template->bIsTemplateInstance == false
		|| (ParentNode && ParentNode->bIsTemplateInstance == true)
		)
	{
		return nullptr;
	}

	/** 从缓存中查找已经转换过的节点 */
	if (CacheTemplateObjects.Contains(Template))
	{
		UFSMRuntimeNodeBase* CacheObj = CacheTemplateObjects.FindRef(Template);
		// 返回有效的缓存对象
		if (CacheObj)
			return CacheObj;
		// 移除无效的缓存
		CacheTemplateObjects.Remove(Template);
	}

	// 深度拷贝模板实例
	// BUG::对于蓝图中的一些属性并未同步拷贝，这些值都是需要的。
	UFSMRuntimeNodeBase* NodeObj = Cast<UFSMRuntimeNodeBase>(StaticDuplicateObject(Template, this));
	// 标记实例为运行时实例
	NodeObj->bIsTemplateInstance = false;
	CacheTemplateObjects.Add(Template, NodeObj);

	/** 根据节点实例的类型进行不同处理 */
	UFSMRuntimeNode* NodeInstance = Cast<UFSMRuntimeNode>(NodeObj);
	if (NodeInstance)
	{
		NodeInstance->ClearSubNodes();
		// 深度拷贝目标的所有次要节点
		const UFSMRuntimeNode* TemplateNodeInstance = Cast<UFSMRuntimeNode>(Template);
		for (const UFSMRuntimeNodeBase* TemplateSubNode : TemplateNodeInstance->GetAllSubNodes())
		{
			// 加入次要节点
			if (UFSMRuntimeNodeBase* SubNodeInstance = DumpStateInstance(TemplateSubNode, NodeInstance))
			{
				NodeInstance->AddSubNode(SubNodeInstance);
			}
		}
		// 重新初始化节点，确保数据与模板类型一致（无 UPROPERTY 修饰的属性不会被拷贝）
		NodeInstance->InitializeNode(TemplateNodeInstance, ParentNode);
		NodeInstance->InitializeFromAsset(StateMachine);
	}

	/** 处理次要节点的拷贝 */
	UFSMRuntimeSubNode* SubNodeInstance = Cast<UFSMRuntimeSubNode>(NodeObj);
	if (SubNodeInstance)
	{
		const UFSMRuntimeSubNode* TemplateNodeInstance = Cast<UFSMRuntimeSubNode>(Template);
		// 重新初始化节点，确保数据与模板类型一致（无 UPROPERTY 修饰的属性不会被拷贝）
		SubNodeInstance->InitializeSubNode(TemplateNodeInstance, ParentNode);
		SubNodeInstance->InitializeFromAsset(StateMachine);
	}
	return NodeObj;
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
