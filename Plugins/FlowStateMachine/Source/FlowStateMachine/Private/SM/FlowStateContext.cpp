// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Components/Widget.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowState.h"
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

void UFlowStateContext::RegisterFlowStateMachine(UFlowStateMachine* FlowStateMachine)
{
	StateMachine = FlowStateMachine;
	// TODO::注册状态机并运行
}

UFlowState* UFlowStateContext::SwitchTo(UFlowState* NewState)
{
	if (CurState == nullptr)
	{
		return nullptr;
	}
	if (CurState != nullptr)
	{
		CurState->Exit();
	}
	NewState->PreIniProperties(CurState);
	CurState = NewState;
	CurState->Enter(this);
	return CurState;
}

UFlowState* UFlowStateContext::SwitchToByIndex(int32 Index)
{
	return nullptr;
	// if (!FlowStateList.IsValidIndex(Index))
	// {
	// 	UE_LOG(LogFlowStateMachine, Error, TEXT("Index is not valid by %d"), Index);
	// 	return nullptr;
	// }
	// return SwitchToByClass(FlowStateList[Index]);
}

UFlowState* UFlowStateContext::SwitchToByClass(const TSubclassOf<UFlowState>& NewState)
{
	{ return SwitchTo(NewObject<UFlowState>(this, NewState)); }
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
