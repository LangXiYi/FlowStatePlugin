// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Blueprint/UserWidget.h"
#include "Data/FSMCommonData.h"
#include "Data/CommonDataType/FSMCommonDataType.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "RuntimeNode/FSMRuntimeNode_Composites.h"
#include "RuntimeNode/FSMRuntimeSubNode.h"
#include "RuntimeNode/Composites/FSMRuntimeNode_Jump.h"
#include "SM/FlowStateBase.h"
#include "SM/FlowStateMachine.h"
#include "SM/FSMCommonDataManager.h"
#include "SM/FSMGC.h"
#include "Utility/FSMUtility.h"


UFlowStateContext::UFlowStateContext(const FObjectInitializer& ObjectInitializer):
	Super(ObjectInitializer)
{
	CommonDataManager = CreateDefaultSubobject<UFSMCommonDataManager>("CommonDataManager");
	// CommonDataManager->Initialize(this);
}

void UFlowStateContext::RegisterFlowStateMachine(UFlowStateMachine& FlowStateMachine)
{
	StateMachine = &FlowStateMachine;
	if (StateMachine && StateMachine->RootRuntimeNode)
	{
		// TODO::创建用户布局控件，监听图表节点的属性改变事件
		// LayoutWidget = CreateWidget<UFlowStateLayoutWidget>(GetWorld(), StateMachine->LayoutWidget);

		// 创建垃圾管理器
		GCManager = MakeShareable(new FSMGC);

		// 重置执行链
		InstanceStack.Empty();

		// 清理缓存的模板实例与运行时实例的映射
		CacheTemplateObjects.Reset();

		// 使用递归函数处理所有的子级节点
		TArray<UFSMRuntimeNodeBase*> Stack;
		RootState = CreateChildrenInstance(FlowStateMachine.RootRuntimeNode, nullptr, Stack);
		check(Stack.Num() <= 0);

		// 创建零碎节点的运行时实例
		CreateScatteredInstance(Stack);
		check(Stack.Num() <= 0);

		// 初始化运行时的公用数据实例
		if (CommonDataManager && StateMachine->CommonData)
		{
			CommonDataManager->Initialize(*StateMachine->CommonData);
		}
		GotoStateNode(RootState);

		// 所有对象全部转换完成后即可清除缓存，避免无效的内存占用。
		CacheTemplateObjects.Empty();
		bIsRegisterFlowStateMachine = true;
	}
}

bool UFlowStateContext::GotoStateNode(UFSMRuntimeNode* Node)
{
	if (!Node || !Node->CheckCondition())
	{
		return false;
	}

	// 将实例加入执行链
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
		OnExitCurState();
		OnEnterNewState(State);
		return true;
	}

	// 若目标是一个组合节点，则需要将其添加到执行链中并执行
	UFSMRuntimeNode_Composites* Composites = Cast<UFSMRuntimeNode_Composites>(Node);
	if (Composites)
	{
		OnExitCurState();
		OnEnterNewState(Composites);
		// TODO::将其添加到执行链中并执行
		return true;
	}
	FSMLOGW("切换至指定的节点失败，该对象的类型不是 State 或 Composites 。")
	return false;
}

bool UFlowStateContext::GotoScatteredNode(FGuid Key)
{
	UFSMRuntimeNode* ScatteredNode = ScatteredNodeMapping.FindRef(Key);
	return GotoStateNode(ScatteredNode);
}

void UFlowStateContext::Tick(float DeltaTime)
{
	if (bIsRegisterFlowStateMachine == false || IsPendingKillOrUnreachable())
	{
		return;
	}

	if (CurState != nullptr)
	{
		CurState->Tick(DeltaTime);
	}

	for (UFSMRuntimeNode* Instance : InstanceStack)
	{
		// TODO::执行执行链的实例对象
		// 执行链中的实例对象可以影响它以及它之后的所有状态的执行
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
	if (GCManager)
	{
		FText CacheInfo = GCManager->Debug_GetCacheInfo();
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Green, CacheInfo.ToString());
		}
	}

#endif
}

void UFlowStateContext::OnExitCurState()
{
	if (CurState)
	{
		CurState->OnExit();
	}
	OnExitState.Broadcast(CurState);
	CurState = nullptr;

	// 通知GC清理缓存
	GCManager->KillCache();
	GCManager->HiddenCache();
}

void UFlowStateContext::OnEnterNewState(UFSMRuntimeNode* NewState)
{
	if (NewState)
	{
		// 在修改当前状态之前广播事件，可以保证监听该事件的对象可以同时访问旧状态以及新状态
		OnPreInitializeState.Broadcast(NewState);
		CurState = NewState;
		NewState->OnInitialize();

		NewState->OnEnter();
		OnEnterState.Broadcast(CurState);
	}
}

UFSMRuntimeNodeBase* UFlowStateContext::DumpInstance(const UFSMRuntimeNodeBase* Template)
{
	check(Template);
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
	UFSMRuntimeNodeBase* NodeObj = Cast<UFSMRuntimeNodeBase>(StaticDuplicateObject(Template, this));
	// 标记实例为运行时实例
	NodeObj->bIsTemplateInstance = false;
	NodeObj->InitializeFromAsset(StateMachine);
	CacheTemplateObjects.Add(Template, NodeObj);
	return NodeObj;
}

UFSMRuntimeNode* UFlowStateContext::CreateChildrenInstance(const UFSMRuntimeNode* TemplateRootNode,
	UFSMRuntimeNodeBase* ParentNode, TArray<UFSMRuntimeNodeBase*>& Stack)
{
	if (TemplateRootNode == nullptr)
	{
		return nullptr;
	}

	if (TemplateRootNode->bIsTemplateInstance == false)
	{
		return const_cast<UFSMRuntimeNode*>(TemplateRootNode);		
	}
	
	UFSMRuntimeNode* RootNodeInstance = DumpInstance<UFSMRuntimeNode>(TemplateRootNode);
	if (RootNodeInstance == nullptr)
	{
		return nullptr;
	}

	// 将节点压入栈中，确保节点执行不会循环
	if (Stack.Contains(RootNodeInstance))
	{
		return RootNodeInstance;
	}
	Stack.Push(RootNodeInstance);

	// 使用模板对节点实例进行初始化
	RootNodeInstance->InitializeNode(ParentNode, this);
	
	// 替换运行时实例的所有子级节点为运行时实例化的对象
	for (int i = 0; i < RootNodeInstance->ChildrenNodes.Num(); ++i)
	{
		UFSMRuntimeNode* ChildNodeInstance = CreateChildrenInstance(RootNodeInstance->ChildrenNodes[i], RootNodeInstance, Stack);
		if (ChildNodeInstance)
		{
			RootNodeInstance->ReplaceChildNode(ChildNodeInstance, i);
		}
		else
		{
			RootNodeInstance->ChildrenNodes.RemoveAt(i--);
		}
	}
	// 换运行时实例的所有次要节点为运行时实例化的对象
	for (int i = 0; i < RootNodeInstance->SubNodes.Num(); ++i)
	{
		UFSMRuntimeSubNode* SubNodeInstance= DumpInstance<UFSMRuntimeSubNode>(RootNodeInstance->SubNodes[i]);
		if (SubNodeInstance)
		{
			SubNodeInstance->InitializeNode(RootNodeInstance, this);
			RootNodeInstance->ReplaceSubNode(SubNodeInstance, i);
		}
		else
		{
			RootNodeInstance->SubNodes.RemoveAt(i--);
		}
	}
	
	Stack.Pop();
	return RootNodeInstance;
}

void UFlowStateContext::CreateScatteredInstance(TArray<UFSMRuntimeNodeBase*>& Stack)
{
	check(StateMachine)
	ScatteredNodes.Empty();
	ScatteredNodeMapping.Empty();
	for (UFSMRuntimeNode* TemplateScatteredNode : StateMachine->ScatteredNodes)
	{
		if (TemplateScatteredNode == nullptr) continue;

		Stack.Empty();
		UFSMRuntimeNode* ScatteredNodeInstance = CreateChildrenInstance(TemplateScatteredNode, nullptr, Stack);
		if (ScatteredNodeInstance)
		{
			ScatteredNodes.Add(ScatteredNodeInstance);
			if (UFSMRuntimeNode_JumpStart* JumpStart = Cast<UFSMRuntimeNode_JumpStart>(ScatteredNodeInstance))
			{
				ScatteredNodeMapping.Add(JumpStart->JumpStartId, JumpStart);
			}
		}
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
