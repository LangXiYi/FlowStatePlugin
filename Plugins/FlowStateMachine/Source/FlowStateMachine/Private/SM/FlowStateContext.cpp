// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Components/Widget.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
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

	// 创建垃圾管理器
	GCManager = MakeShareable(new FSMGC);

	// TODO::创建用户布局控件
	LayoutWidget = nullptr;
	
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
		FSMLOGW("切换至指定的节点失败，该对象的所有前置条件为满足。")
		return false;
	}

	// 若目标是一个状态节点，那么直接切换过去即可
	UFSMRuntimeNode_State* State = Cast<UFSMRuntimeNode_State>(Node);
	if (State)
	{
		// 退出上一节点
		if (CurNode)
		{
			CurNode->OnExit();
			CurNode = nullptr;
		}
		
		State->OnInitialize(this);
		State->OnEnter();

		CurNode = State;
		return true;
	}

	// 若目标是一个组合节点，则需要将其添加到执行链中并执行
	UFSMRuntimeNode_Composites* Composites = Cast<UFSMRuntimeNode_Composites>(Node);
	if (Composites)
	{
		// 退出上一节点
		if (CurNode)
		{
			CurNode->OnExit();
			CurNode = nullptr;
		}
		// TODO::将其添加到执行链中并执行
		
		CurNode = Composites;
		return true;
	}
	FSMLOGW("切换至指定的节点失败，该对象的类型不是 State 或 Composites 。")
	return false;
}

void UFlowStateContext::BeginPlay()
{
	OnBeginPlay();
}

UFlowStateContext::UFlowStateContext()//:
	// UFlowStateBase(InContext)
{
	CurState = nullptr;
}

void UFlowStateContext::Tick(float DeltaTime)
{
	if (CurNode != nullptr)
	{
		CurNode->Tick(DeltaTime);
	}
}

void UFlowStateContext::LoadingFlowStateData(const FPrimaryAssetId& FlowStateDataID, TFunction<void()> Callback)
{
	if (!FlowStateDataID.IsValid())
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("%hs::FlowStateDataID is invalid"), __FUNCTION__);
		return;
	}
	auto OnLoadedFunc = [this, Callback, FlowStateDataID]()
	{
		MetaDataLoadHandle.Reset();
		UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(FlowStateDataID);
		if (UFSMMetaDataAsset* GuideDataAsset = Cast<UFSMMetaDataAsset>(AssetObject))
		{
			UE_LOG(LogFlowStateMachine, Log, TEXT("FlowStateData loading success."));
			FlowStateData = GuideDataAsset;
			Callback();
		}
		else
		{
			UE_LOG(LogFlowStateMachine, Error, TEXT("FlowStateData loading error."));
		}
	};
	// 尝试加载数据资产
	MetaDataLoadHandle = UAssetManager::Get().LoadPrimaryAsset(FlowStateDataID);
	checkf(MetaDataLoadHandle.IsValid(), TEXT("The MetaDataLoadHandle is not valid. Check your 'AssetManager' added the MetaData."));
	if (MetaDataLoadHandle.IsValid())
	{
		if (!MetaDataLoadHandle->HasLoadCompleted())
		{
			MetaDataLoadHandle->BindCompleteDelegate(
				FStreamableDelegate::CreateLambda(OnLoadedFunc));
		}
		else
		{
			OnLoadedFunc();
		}
	}
}


UWorld* UFlowStateContext::GetWorld() const
{
	return GetOuter()->GetWorld();
}
