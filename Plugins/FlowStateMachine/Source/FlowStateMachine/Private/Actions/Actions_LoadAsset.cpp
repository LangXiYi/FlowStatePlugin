// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_LoadAsset.h"

#include "Engine/StreamableManager.h"
#include "Conditions/Conditions_AssetCheck.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/AssetManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Library/FSMMetaDataFunctionLibrary.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "SM/FlowStateContext.h"

UActions_LoadAsset::UActions_LoadAsset(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("LoadAsset");
}

void UActions_LoadAsset::ExecuteAction(UFSMRuntimeNode* Instance)
{
	check(!bIsTemplateInstance)

	// 加载当前步骤的资产
	LoadAsset(bSyncLoad);
	// 监听 Context 的状态退出事件，在切换至目标状态后，移除加载资产
	if (bAutoReleaseAsset)
	{
		UFSMRuntimeNode* MyParent = GetParentNode<UFSMRuntimeNode>();
		MyParent->OnExitDelegate.AddUObject(this, &UActions_LoadAsset::UnloadAsset);
	}
}

void UActions_LoadAsset::OnPreprocessing()
{
	Super::OnPreprocessing();
	if (bAllowPreLoading)
	{
		LoadAsset(bSyncLoad);
	}
}

void UActions_LoadAsset::LoadAsset(bool IsSyncLoad, bool IsPreload)
{
	UAssetManager& AssetManager = UAssetManager::Get();
	if (LoadingHandle.IsValid())
	{
		// 预加载句柄有效，则说明该资产已经被加载过了，无需重复加载！！
		return;
	}

	// 异步加载只在非根节点中有效
	if (IsSyncLoad)
	{
		// 阻塞加载资产
		FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(AssetId);
		// 手动注册该资产至资产管理器，确保后续可以通过资产管理器找到该它
		LoadingHandle = AssetManager.GetStreamableManager().RequestSyncLoad(AssetPath);
		// 同步加载执行完成后更新元数据
		MetaData = UFSMMetaDataFunctionLibrary::FindMetaDataAsset(this, AssetId);
		AssetManager.RegisterSpecificPrimaryAsset(AssetId, MetaData.Get());
	}
	else
	{
		auto LoadCallbackFunc = [this]()
		{
			UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(AssetId);
			if (UFSMMetaDataAsset* DataAsset = Cast<UFSMMetaDataAsset>(AssetObject)) MetaData = DataAsset;
			else FSMLOGE("加载文件失败")
		};
		TArray<FName> LoadBounds;
		LoadingHandle = IsPreload ?
			AssetManager.PreloadPrimaryAssets({AssetId}, LoadBounds, false, FStreamableDelegate::CreateLambda(LoadCallbackFunc), FStreamableManager::DefaultAsyncLoadPriority) :
			AssetManager.LoadPrimaryAsset(AssetId, LoadBounds, FStreamableDelegate::CreateLambda(LoadCallbackFunc), FStreamableManager::AsyncLoadHighPriority);
		PrintLoadBoundMessage(LoadBounds);
	}
}

void UActions_LoadAsset::UnloadAsset()
{
	UAssetManager& AssetManager = UAssetManager::Get();
	AssetManager.UnloadPrimaryAsset(AssetId);
	LoadingHandle.Reset();
}

bool UActions_LoadAsset::HasLoadCompleted() const
{
	if (LoadingHandle.IsValid())
	{
		return LoadingHandle->HasLoadCompleted();
	}
	return false;
}

void UActions_LoadAsset::PrintLoadBoundMessage(const TArray<FName>& LoadBounds) const
{
	if (LoadBounds.Num() > 0)
	{
		FSMLOGW("Load Message ====>");
		for (auto LoadBound : LoadBounds)
		{
			FSMLOGW("\t %s", *LoadBound.ToString());
		}
	}
}

void UActions_LoadAsset::OnExitState()
{
	// 释放当前加载的资产
	UnloadAsset();
}
