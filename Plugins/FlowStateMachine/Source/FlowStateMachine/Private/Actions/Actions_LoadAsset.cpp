// Fill out your copyright notice in the Description page of Project Settings.


#include "Actions/Actions_LoadAsset.h"

#include "Engine/StreamableManager.h"
#include "Conditions/Conditions_AssetCheck.h"
#include "Data/FSMMetaDataAsset.h"
#include "Engine/AssetManager.h"
#include "Kismet/KismetSystemLibrary.h"
#include "RuntimeNode/FSMRuntimeNode.h"
#include "SM/FlowStateContext.h"

UActions_LoadAsset::UActions_LoadAsset(const FObjectInitializer& ObjectInitializer)
{
	NodeName = TEXT("LoadAsset");
}

void UActions_LoadAsset::ExecuteAction()
{
	UFlowStateContext* Context = GetContext();
	if (Context == nullptr)
	{
		checkNoEntry()
		return;
	}

#if WITH_EDITOR
	CheckCondition();
#endif

	// 加载当前步骤的资产
	LoadAsset();

	// 监听 Context 的状态退出事件，在切换至目标状态后，移除加载资产
	if (bAutoReleaseAsset)
	{
		OnExitStateHandle = Context->OnExitState.AddUObject(this, &UActions_LoadAsset::OnExitState);
	}

	// 加载下一步骤需要的资产
	if (bAllowPreLoading)
	{
		TArray<UFSMRuntimeNode*> NextStates = Context->GetNextStates();
		for (UFSMRuntimeNode* NextState : NextStates)
		{
			if (auto OtherAction = NextState->FindSubNode<UActions_LoadAsset>())
			{
				// 遍历所有子级节点，将所有具有加载资产行为的节点的资产引用加入预加载列表
				OtherAction->PreloadAsset(Context->OnPreInitializeState);
			}
		}
	}
}

void UActions_LoadAsset::LoadAsset(bool bIsASync)
{
	UAssetManager& AssetManager = UAssetManager::Get();
	if (PreloadingHandle.IsValid())
	{
		// 预加载句柄有效，则说明该资产已经被加载过了，无需重复加载！！
		LoadingHandle = PreloadingHandle;
	}
	// 异步加载只在非根节点中有效
	else if (bIsASync && !ParentNode->bIsRootNode)
	{
		TArray<FName> LoadBounds;
		LoadingHandle = AssetManager.LoadPrimaryAsset(AssetId, LoadBounds,
			FStreamableDelegate::CreateLambda([this]()
			{
				// 资产加载完成...
				UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(AssetId);
				if (UFSMMetaDataAsset* DataAsset = Cast<UFSMMetaDataAsset>(AssetObject))
				{
					MetaData = DataAsset;
				}
				else
				{
					FSMLOGE("加载文件失败")
				}
			}), FStreamableManager::AsyncLoadHighPriority);
		PrintLoadBoundMessage(LoadBounds);
	}
	else
	{
		// 阻塞加载资产
		FSoftObjectPath AssetPath = AssetManager.GetPrimaryAssetPath(AssetId);
		MetaData = Cast<UFSMMetaDataAsset>(AssetPath.TryLoad());
		// 手动注册该资产至资产管理器，确保后续可以通过资产管理器找到该它
		AssetManager.RegisterSpecificPrimaryAsset(AssetId,MetaData);
	}
}

void UActions_LoadAsset::UnloadAsset()
{
	UAssetManager& AssetManager = UAssetManager::Get();
	AssetManager.UnloadPrimaryAsset(AssetId);

	LoadingHandle = nullptr;
	PreloadingHandle = nullptr;
}

void UActions_LoadAsset::PreloadAsset(FStateDelegate& PreInitializeDelegate)
{
	UAssetManager& AssetManager = UAssetManager::Get();
	TArray<FName> LoadBounds;
	PreloadingHandle = AssetManager.PreloadPrimaryAssets({AssetId}, LoadBounds, false,
		FStreamableDelegate::CreateLambda([this]()
		{
			// 预加载完成...
			UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(AssetId);
			if (UFSMMetaDataAsset* DataAsset = Cast<UFSMMetaDataAsset>(AssetObject))
			{
				MetaData = DataAsset;
			}
			else
			{
				FSMLOGE("预加载文件失败")
			}
		}));
	PrintLoadBoundMessage(LoadBounds);

	// 在初始化新状态前，先将当前状态中预加载的所有不需要的数据清除。
	// 注意：此事件发生在状态切换前，且执行一次后自动解除绑定。
	OnEnterStateHandle = PreInitializeDelegate.AddLambda([this, &PreInitializeDelegate](UFSMRuntimeNode* Node)
	{
		// 1、若该资产在此阶段仍然处于加载中，资产管理器是否会自动中断？
		// 2、若该资产与其他状态使用的是同以资产，释放该资产释放会导致其他对象的资产引用失效？
		// 3、若该资产已加载完成、且未被其他对象使用，则可直接释放
		if (Node != ParentNode)
		{
			// 仅移除非活动状态预加载的资产
			UnloadAsset();
		}
		// 移除绑定，避免多次触发
		PreInitializeDelegate.Remove(OnEnterStateHandle);
		OnEnterStateHandle.Reset();
	});
}

bool UActions_LoadAsset::HasLoadCompleted() const
{
	TSharedPtr<FStreamableHandle> StreamableHandle = LoadingHandle ? LoadingHandle : PreloadingHandle;
	if (StreamableHandle.IsValid())
	{
		return StreamableHandle->HasLoadCompleted();
	}
	return false;
}

bool UActions_LoadAsset::HasPreloadCompleted() const
{
	if (PreloadingHandle)
	{
		return PreloadingHandle->HasLoadCompleted();
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

void UActions_LoadAsset::OnExitState(UFSMRuntimeNode* ExitNode)
{
	UFlowStateContext* Context = GetContext();
	if (Context)
	{
		// 移除绑定，避免在非活动状态中执行
		Context->OnExitState.Remove(OnExitStateHandle);
	}
	// 释放当前加载的资产
	UnloadAsset();
}

void UActions_LoadAsset::CheckCondition()
{
	UFSMRuntimeNode* FSMParentNode = GetParentNode<UFSMRuntimeNode>();
	if (FSMParentNode && !FSMParentNode->bIsRootNode)
	{
		if (FSMParentNode->FindSubNode<UConditions_AssetCheck>() == nullptr)
		{
			ensureMsgf(false, TEXT("非根节点的 LoadAsset 行为推荐搭配 Conditions_AssetCheck 使用，确保资产加载完成"));
		}
	}
}
