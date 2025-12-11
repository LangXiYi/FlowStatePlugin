// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Components/Widget.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateBase.h"
#include "SM/FlowStateMachine.h"
#include "SM/FSMGC.h"
#include "Utility/FSMUtility.h"


void UFlowStateContext::Initialize()
{
	// 创建垃圾回收对象
	GC = MakeShareable(new FSMGC);

	// 调用蓝图实现函数，初始化对象
	OnInitialize();

	check(StateMachine)
	// 加载数据资产至内存并在完成后调用 BeginPlay
	LoadingFlowStateData(StateMachine->GetMetaDataID(), [this]()
	{
		// Loading Success Callback
		BeginPlay();
	});
}

void UFlowStateContext::BeginPlay()
{
	OnBeignPlay();
}

UFlowStateContext::UFlowStateContext()//:
	// UFlowStateBase(InContext)
{
	CurState = nullptr;
}

void UFlowStateContext::RegisterFlowStateMachine(UFlowStateMachine* FlowStateMachine)
{
	StateMachine = FlowStateMachine;
	// TODO::注册状态机并运行
	
}

void UFlowStateContext::Tick(float DeltaTime)
{
	OnTick(DeltaTime);
	if (CurState != nullptr)
	{
		CurState->Tick(DeltaTime);
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

UFlowStateBase* UFlowStateContext::SwitchTo(UFlowStateBase* NewState)
{
	if (CurState != nullptr)
	{
		CurState->OnExit();
	}
	NewState->OnInitialize(this);
	CurState = NewState;

	// TODO::初始化控件
	// CurState->OnInitWidget(Layout);
	return CurState;
}

UFlowStateBase* UFlowStateContext::SwitchTo(const TSubclassOf<UFlowStateBase>& NewStateClass)
{
	FSMLOG("正在切换状态至 -----> %s", *NewStateClass->GetName())
	UFlowStateBase* State = NewObject<UFlowStateBase>(this, NewStateClass);
	if (State == nullptr)
	{
		FSMLOGE("创建新的状态对象失败")
		return nullptr;
	}
	return SwitchTo(State);
}

UWorld* UFlowStateContext::GetWorld() const
{
	if (!HasAnyFlags(RF_ClassDefaultObject) && ensureMsgf(GetOuter(),
		TEXT("Actor: %s has a null OuterPrivate in AActor::GetWorld()"), *GetFullName())
		&& !GetOuter()->HasAnyFlags(RF_BeginDestroyed) && !GetOuter()->IsUnreachable())
	{
		if (ULevel* Level = GetLevel())
		{
			return Level->OwningWorld;
		}
	}
	return nullptr;
}

ULevel* UFlowStateContext::GetLevel() const
{
	return GetTypedOuter<ULevel>();
}
