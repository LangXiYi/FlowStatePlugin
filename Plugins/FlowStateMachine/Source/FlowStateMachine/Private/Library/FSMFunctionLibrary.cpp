// Fill out your copyright notice in the Description page of Project Settings.
#include "Library/FSMFunctionLibrary.h"

#include "Chaos/GeometryParticlesfwd.h"
#include "Engine/StaticMeshActor.h"
#include "FlowStateMachine_Widget/Public/Widgets/FlowStateLayoutWidget.h"
#include "FlowStateMachine_Widget/Public/Widgets/GameplayTagSlot.h"
#include "Library/FSMMetaDataFunctionLibrary.h"
#include "SM/FlowStateContext.h"
#include "System/FlowStateMachineSubsystem.h"

UFlowStateContext* UFSMFunctionLibrary::GetFlowStateContext(UObject* WorldContextObject)
{
	UWorld* World = FlowStateMachine::GetWorldFromContextObject(WorldContextObject);
	if (World)
	{
		UFlowStateMachineSubsystem* Subsystem = World->GetSubsystem<UFlowStateMachineSubsystem>();
		if (Subsystem)
		{
			return Subsystem->GetRunningStateContext();
		}
	}
	return nullptr;
	// AFSMWorldSettings* WorldSettings = AFSMWorldSettings::Get(WorldContextObject);
	// return WorldSettings ? WorldSettings->GetFlowStateContext() : nullptr;
}

UFlowStateBase* UFSMFunctionLibrary::GetCurFlowState(UObject* WorldContextObject)
{
	UFlowStateContext* FlowStateContext = GetFlowStateContext(WorldContextObject);
	return FlowStateContext ? static_cast<UFlowStateBase*>(FlowStateContext->GetCurrentState()) : nullptr;
}

UFlowStateBase* UFSMFunctionLibrary::GetCurFlowStateAs(UObject* WorldContextObject, TSubclassOf<UFlowStateBase> Type)
{
	UFlowStateBase* State = GetCurFlowState(WorldContextObject);
	if (State && State->IsA(Type))
	{
		return State;
	}
	return nullptr;
}

UUserWidget* UFSMFunctionLibrary::CreateAndBindWidget(UObject* WorldContextObject, UFlowStateLayoutWidget* WidgetLayout,
	TSubclassOf<UUserWidget> WidgetType, FGameplayTag WidgetSlotTag, EFlowStateLifetime Lifetime)
{
	if (WidgetLayout == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Widget Layout is nullptr."));
		return nullptr;
	}
	UFlowStateContext* FlowStateContext = GetFlowStateContext(WorldContextObject);
	if (FlowStateContext == nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("%hs FlowStateContext is nullptr."), __FUNCTION__)
		return nullptr;
	}

	UGameplayTagSlot* Slot = WidgetLayout->FindSlot(WidgetSlotTag);
	bool bCreateNewWidget = true;
	if (Slot && Slot->HasAnyChildren())
	{
		UWidget* ChildWidget = Slot->GetChildAt(0);
		if (ChildWidget->GetClass() != WidgetType)
		{
			UE_LOG(LogTemp, Warning, TEXT("目标插槽存在其他对象，期望创建的控件类型与槽内控件类型不一致，请检查代码避免重复创建"))
			return nullptr;
		}
		// 槽内存在同类控件
		bCreateNewWidget = false;
	}
	UUserWidget* Widget = bCreateNewWidget ? CreateWidget(WidgetLayout, WidgetType) : static_cast<UUserWidget*>(Slot->GetChildAt(0));
	if (Widget)
	{
		if (bCreateNewWidget)
		{
			WidgetLayout->AddChildTo(WidgetSlotTag, Widget);
		}
		else
		{
			Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		FlowStateContext->AddToCache(Widget, Lifetime);
		return Widget;
	}
	return nullptr;
}

UFSMCommonDataManager* UFSMFunctionLibrary::GetCommonDataManager(UObject* WorldContextObject)
{
	if (UFlowStateContext* FlowStateContext = GetFlowStateContext(WorldContextObject))
	{
		return FlowStateContext->GetCommonDataManager();
	}
	return nullptr;
}

EFlowStateLifetime UFSMFunctionLibrary::FindActorFromCache(UObject* WorldContextObject, FName ActorTag, AActor*& FindActor)
{
	if (UFlowStateContext* FlowStateContext = GetFlowStateContext(WorldContextObject))
	{
		if (TSharedPtr<FSMGC> Manager = FlowStateContext->GetGCManager())
		{
			return Manager->FindRefByCache(ActorTag, FindActor);
		}
	}
	return EFlowStateLifetime::None;
}

EFlowStateLifetime UFSMFunctionLibrary::FindWidgetFromCache(UObject* WorldContextObject, FGameplayTag WidgetTag,
	UWidget*& FindActor)
{
	if (UFlowStateContext* FlowStateContext = GetFlowStateContext(WorldContextObject))
	{
		if (TSharedPtr<FSMGC> Manager = FlowStateContext->GetGCManager())
		{
			return Manager->FindRefByCache(WidgetTag, FindActor);
		}
	}
	return EFlowStateLifetime::None;
}

AActor* UFSMFunctionLibrary::InitActorLifetimeState(AActor* Target, EFlowStateLifetime Lifetime, FName ActorTag)
{
	if (Target == nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("%hs Target is nullptr."), __FUNCTION__)
		return nullptr;
	}
	UFlowStateContext* FlowStateContext = GetFlowStateContext(Target);
	if (FlowStateContext == nullptr)
	{
		UE_LOG(LogFlowStateMachine, Error, TEXT("%hs FlowStateContext is nullptr."), __FUNCTION__)
		return nullptr;
	}
	if (ActorTag != NAME_None)
	{
		Target->Tags.AddUnique(ActorTag);
	}
	Target->SetActorHiddenInGame(false);
	FlowStateContext->AddToCache(Target, Lifetime);
	return Target;
}
