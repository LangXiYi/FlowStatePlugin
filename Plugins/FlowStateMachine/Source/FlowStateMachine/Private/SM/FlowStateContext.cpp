// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowStateContext.h"

#include "Components/Widget.h"
#include "Data/FlowStateDataAsset.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"


void UFlowStateContext::Initialize()
{
	OnInitialize();
	LoadingFlowStateData([this]()
	{
		// Loading Success Callback
		BeginPlay();
	});
}

void UFlowStateContext::BeginPlay()
{
	OnBeignPlay();
	if (FlowStateData)
	{
		SwitchToByClass(FlowStateData->StartState);
	}
}

UFlowState* UFlowStateContext::SwitchTo(UFlowState* NewState)
{
	// 当前状态有效，但未通过检测时，跳过执行
	if (CurState && !CurState->Condition(NewState))
	{
		return nullptr;
	}

	// 清理上上次的状态
	if (LastState != nullptr)
	{
		LastState->ConditionalBeginDestroy();
	}
	if (CurState != nullptr)
	{
		LastState = CurState;
		CurState->Exit();
	}
	check(NewState);
	CurState = NewState;
	CurState->PreIniProperties(LastState);
	FlowStateList = CurState->FlowStates;
	CurState->Enter(this);
	return CurState;
}

UFlowState* UFlowStateContext::SwitchToByIndex(int32 Index)
{
	if (!FlowStateList.IsValidIndex(Index))
	{
		UE_LOG(LogFlowState, Error, TEXT("Index is not valid by %d"), Index);
		return nullptr;
	}
	return SwitchToByClass(FlowStateList[Index]);
}

void UFlowStateContext::Tick(float DeltaTime)
{
	if (CurState != nullptr)
	{
		CurState->Tick(DeltaTime);
	}
#if !UE_BUILD_SHIPPING
	if (GEngine)
	{
		FStringFormatNamedArguments FormatArguments;
		FormatArguments.Add("StateName", CurState ? CurState->GetName() : "None");
		FormatArguments.Add("HiddenActors", HiddenActorsCache.Num());
		FormatArguments.Add("HiddenWidgets", HiddenWidgetsCache.Num());
		FormatArguments.Add("HiddenLevels", HiddenLevelsCache.Num());
		FString Str = FString::Format(
			TEXT("Train State {StateName}\n"
				 "      Hidden Actors  : {HiddenActors}\n"
				 "      Hidden Widgets : {HiddenWidgets}\n"
				 "      Hidden Level   : {HiddenLevels}"), FormatArguments);
		GEngine->AddOnScreenDebugMessage(-1, 0.f, FColor::Red, Str);
	}
#endif
}

AActor* UFlowStateContext::FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag)
{
	for (AActor* HiddenActor : HiddenActorsCache)
	{
		if (HiddenActor && HiddenActor->IsA(Type) && HiddenActor->ActorHasTag(ActorTag))
		{
			// UE_LOG(LogTemp, Log, TEXT("找到标签为 %s 的对象"), *ActorTag.ToString())
			return HiddenActor;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("未找到标签为 %s 的 %s"), *ActorTag.ToString(), *Type->GetName())
	return nullptr;
}

void UFlowStateContext::ClearCache()
{
	for (AActor* ActorsCache : HiddenActorsCache)
	{
		ActorsCache->Destroy();
	}
	HiddenActorsCache.Empty();
	for (UWidget* WidgetsCache : HiddenWidgetsCache)
	{
		WidgetsCache->RemoveFromParent();
	}
	HiddenWidgetsCache.Empty();
	for (FName LevelName : HiddenLevelsCache)
	{
		UGameplayStatics::UnloadStreamLevel(this, LevelName, FLatentActionInfo(), false);
	}
	HiddenLevelsCache.Empty();
}

UFlowStateDataFragment* UFlowStateContext::FindFlowStateDataFragment(TSubclassOf<UFlowStateDataFragment> FragmentClass)
{
	if (FlowStateData)
	{
		return FlowStateData->FindDataFragment(FragmentClass);
	}
	return nullptr;
}

void UFlowStateContext::LoadingFlowStateData(std::function<void()> Callback)
{
	if (!FlowStateDataID.IsValid())
	{
		UE_LOG(LogFlowState, Error, TEXT("%hs::FlowStateDataID is invalid"), __FUNCTION__);
		return;
	}
	auto OnLoadedFunc = [this, Callback]()
	{
		FlowStateDataLoadHandle.Reset();
		UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(FlowStateDataID);
		if (UFlowStateDataAsset* GuideDataAsset = Cast<UFlowStateDataAsset>(AssetObject))
		{
			UE_LOG(LogFlowState, Log, TEXT("FlowStateData loading success."));
			FlowStateData = GuideDataAsset;
			Callback();
		}
		else
		{
			UE_LOG(LogFlowState, Error, TEXT("FlowStateData loading error."));
		}
	};
	// 尝试加载数据资产
	FlowStateDataLoadHandle = UAssetManager::Get().LoadPrimaryAsset(FlowStateDataID);
	if (FlowStateDataLoadHandle.IsValid())
	{
		if (!FlowStateDataLoadHandle->HasLoadCompleted())
		{
			FlowStateDataLoadHandle->BindCompleteDelegate(
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
