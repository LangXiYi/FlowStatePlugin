// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/FlowState.h"

#include "Components/SlateWrapperTypes.h"
#include "Components/Widget.h"
#include "Data/FlowStateDataAsset.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"

UWorld* UFlowState::GetWorld() const
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

ULevel* UFlowState::GetLevel() const
{
	return GetTypedOuter<ULevel>();
}

void UFlowState::Tick(float DeltaTime)
{
	Private_DeltaTime = DeltaTime;
	OnTick(DeltaTime); 
}

void UFlowState::Enter(UFlowStateContext* Context)
{
	StateContext = Context;
	OnEnter();
}

void UFlowState::InitWidget(UFlowStateLayoutWidget* Layout)
{
	OnInitWidget(Layout);
}

void UFlowState::Exit()
{
	for (FName Level : KillLevels)
	{
		UGameplayStatics::UnloadStreamLevel(this, Level, FLatentActionInfo(), false);
	}
	KillLevels.Empty();

	for (AActor* KillActor : KillActors)
	{
		if (StateContext->HiddenActorsCache.Contains(KillActor))
		{
			StateContext->HiddenActorsCache.Remove(KillActor);
		}
		KillActor->Destroy();
	}
	KillActors.Empty();

	for (UWidget* KillWidget : KillWidgets)
	{
		KillWidget->RemoveFromParent();
	}
	KillWidgets.Empty();

	for (FName Level : HiddenLevels)
	{
		ULevelStreaming* LevelStreaming = UGameplayStatics::GetStreamingLevel(this, Level);
		if (LevelStreaming)
		{
			LevelStreaming->SetShouldBeVisible(false);
		}
	}
	HiddenLevels.Empty();
	
	for (AActor* HiddenActor : HiddenActors)
	{
		if (!StateContext->HiddenActorsCache.Contains(HiddenActor))
		{
			StateContext->HiddenActorsCache.Add(HiddenActor);
		}
		HiddenActor->SetActorHiddenInGame(true);
	}
	HiddenActors.Empty();

	for (UWidget* HiddenWidget : HiddenWidgets)
	{
		if (!StateContext->HiddenWidgetsCache.Contains(HiddenWidget))
		{
			StateContext->HiddenWidgetsCache.Add(HiddenWidget);
		}
		HiddenWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	HiddenWidgets.Empty();

	OnExit();
}

void UFlowState::ClearCache()
{
	check(StateContext);
	if (StateContext)
	{
		StateContext->ClearCache();
	}
}

AActor* UFlowState::FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag)
{
	if (HiddenActors.Num() >= 0)
	{
		for (AActor* HiddenActor : HiddenActors)
		{
			if (HiddenActor && HiddenActor->IsA(Type) && HiddenActor->ActorHasTag(ActorTag))
			{
				// UE_LOG(LogTemp, Log, TEXT("找到标签为 %s 的对象"), *ActorTag.ToString())
				return HiddenActor;
			}
		}
	}
	if (StateContext)
	{
		return StateContext->FindActorFromCache(Type, ActorTag);
	}
	return nullptr;
}

UObject* UFlowState::FindAssetByName(TSubclassOf<UObject> AssetType, FName AssetName) const
{
	UDataFragment_Assets* Fragment_Assets = FindFlowStateDataFragment<UDataFragment_Assets>();
	if (Fragment_Assets)
	{
		return Fragment_Assets->FindData(AssetType, AssetName);
	}
	return nullptr;
}

UFlowStateDataAsset* UFlowState::GetFlowStateData() const
{
	check(StateContext);
	return StateContext->FlowStateData; 
}

UFlowStateDataFragment* UFlowState::FindFlowStateDataFragment(TSubclassOf<UFlowStateDataFragment> FragmentClass) const
{
	check(StateContext);
	return StateContext->FindFlowStateDataFragment(FragmentClass);
}

UFlowState* UFlowState::GetLastFlowState() const
{
	check(StateContext);
	return StateContext->LastState;
}

bool UFlowState::Condition(UFlowState* LastState)
{
	// 临时设置
	return BP_Condition(LastState);
}

void UFlowState::PreIniProperties(UFlowState* LastState)
{
	OnPreInitProperties(LastState);
}
