#include "SM/FSMGC.h"

#include "Components/Widget.h"
#include "Library/UIExtensionsBFL.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/GameplayTagSlot.h"

void FSMGC::HiddenCache()
{
	for (int i = 0; i < Hidden_Actors.Num(); ++i)
	{
		TWeakObjectPtr<AActor> Actor = Hidden_Actors[i];
		if (Actor.IsValid())
		{
			_HiddenCacheFrom(Actor.Get());
		}
		else
		{
			Hidden_Actors.RemoveAt(i--);
		}
	}

	for (int i = 0; i < Hidden_Widgets.Num(); ++i)
	{
		TWeakObjectPtr<UWidget> Widget = Hidden_Widgets[i];
		if (Widget.IsValid())
		{
			_HiddenCacheFrom(Widget.Get());
		}
		else
		{
			Hidden_Widgets.RemoveAt(i--);
		}
	}

	for (int i = 0; i < Hidden_SubLevels.Num(); ++i)
	{
		FName SubLevel = Hidden_SubLevels[i];
		if (SubLevel != NAME_None)
		{
			_HiddenCacheFrom(SubLevel);
		}
		else
		{
			Hidden_SubLevels.RemoveAt(i--);
		}
	}
}

void FSMGC::KillCache()
{
	for (TWeakObjectPtr<AActor> KillActor : Kill_Actors)
	{
		if (KillActor.IsValid())
		{
			_KillCacheFrom(KillActor.Get());
		}
	}
	Kill_Actors.Empty();

	for (TWeakObjectPtr<UWidget> KillWidget : Kill_Widgets)
	{
		if (KillWidget.IsValid())
		{
			_KillCacheFrom(KillWidget.Get());
		}
	}
	Kill_Widgets.Empty();
	
	for (FName KillSubLevel : Kill_SubLevels)
	{
		if (KillSubLevel != NAME_None)
		{
			_KillCacheFrom(KillSubLevel);
		}
	}
	Kill_SubLevels.Empty();
}

void FSMGC::ClearAllCache()
{
	ClearCacheBy(EFlowStateLifetime::Static);
	ClearCacheBy(EFlowStateLifetime::Kill);
	ClearCacheBy(EFlowStateLifetime::Hidden);
}

void FSMGC::ClearCacheBy(EFlowStateLifetime Lifetime)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::Static:
		Static_Actors.Empty();
		Static_Widgets.Empty();
		Static_SubLevels.Empty();
		break;
	case EFlowStateLifetime::Kill:
		Kill_Actors.Empty();
		Kill_Widgets.Empty();
		Kill_SubLevels.Empty();
		break;
	case EFlowStateLifetime::Hidden:
		Hidden_Actors.Empty();
		Hidden_Widgets.Empty();
		Hidden_SubLevels.Empty();
		break;
	}
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AActor*& OutTarget)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::Static:
		for (int i = 0; i < Static_Actors.Num(); ++i)
		{
			TWeakObjectPtr<AActor> CacheItem = Static_Actors[i];
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
			else
			{
				Static_Actors.RemoveAt(i);
				i--;
			}
		}
		break;
	case EFlowStateLifetime::Kill:
		for (int i = 0; i < Kill_Actors.Num(); ++i)
		{
			TWeakObjectPtr<AActor> CacheItem = Kill_Actors[i];
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
			else
			{
				Kill_Actors.RemoveAt(i);
				i--;
			}
		}
		break;
	case EFlowStateLifetime::Hidden:
		for (int i = 0; i < Hidden_Actors.Num(); ++i)
		{
			TWeakObjectPtr<AActor> CacheItem = Hidden_Actors[i];
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
			else
			{
				Hidden_Actors.RemoveAt(i);
				i--;
			}
		}
		break;
	}
	return false;
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ASkeletalMeshActor*& OutTarget)
{
	return _FindRefByCache(Tag, Lifetime, (AActor*&)OutTarget);
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AStaticMeshActor*& OutTarget)
{
	return _FindRefByCache(Tag, Lifetime, (AActor*&)OutTarget);
}

bool FSMGC::_FindRefByCache(FGameplayTag Tag, EFlowStateLifetime Lifetime, UWidget*& OutTarget)
{
	auto CheckFunc = [](TWeakObjectPtr<UWidget> InCacheItem, FGameplayTag InTag, UWidget*& Out)->bool
	{
		if (InCacheItem.IsValid())
		{
			if (UGameplayTagSlot* TagSlot = Cast<UGameplayTagSlot>(InCacheItem.Get()->GetParent()))
			{
				if (InTag.MatchesTagExact(TagSlot->Tag))
				{
					Out = InCacheItem.Get();
					return true;
				}
			}
		}
		return false;
	};
	
	switch (Lifetime)
	{
	case EFlowStateLifetime::Static:
		for (int i = 0; i < Static_Widgets.Num(); ++i)
		{
			if (CheckFunc(Static_Widgets[i], Tag, OutTarget))
			{
				return true;
			}
		}
		break;
	case EFlowStateLifetime::Kill:
		for (int i = 0; i < Kill_Widgets.Num(); ++i)
		{
			if (CheckFunc(Kill_Widgets[i], Tag, OutTarget))
			{
				return true;
			}
		}
		break;
	case EFlowStateLifetime::Hidden:
		for (int i = 0; i < Hidden_Widgets.Num(); ++i)
		{
			if (CheckFunc(Hidden_Widgets[i], Tag, OutTarget))
			{
				return true;
			}
		}
		break;
	default:
		break;
	}
	return false;
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ULevel*& OutTarget)
{
	checkNoEntry()
	return false;
}

void FSMGC::_KillCacheFrom(AActor* Actor)
{
	check(Actor)
	Actor->Destroy();
}

void FSMGC::_KillCacheFrom(UWidget* Widget)
{
	check(Widget)
	Widget->RemoveFromParent();
}

void FSMGC::_KillCacheFrom(FName SubLevel)
{
}

void FSMGC::_HiddenCacheFrom(AActor* Actor)
{
	Actor->SetActorHiddenInGame(true);
}

void FSMGC::_HiddenCacheFrom(UWidget* Widget)
{
	Widget->SetVisibility(ESlateVisibility::Hidden);
}

void FSMGC::_HiddenCacheFrom(FName SubLevel)
{
	checkNoEntry();
}


FText FSMGC::Debug_GetCacheInfo() const
{
	FTextFormat Format = FTextFormat::FromString(
		"==== Cache Info ====\n"
		"\tStatic/Hidden/Kill Actors ({StaticActors}/{HiddenActors}/{KillActors})\n"
		"\tStatic/Hidden/Kill Widgets ({StaticWidgets}/{HiddenWidgets}/{KillWidgets})\n"
		"\tStatic/Hidden/Kill SubLevels ({StaticLevels}/{HiddenSubLevels}/{KillSubLevels})\n");
	FFormatNamedArguments Args;
	Args.Add("StaticActors", Static_Actors.Num());
	Args.Add("HiddenActors", Hidden_Actors.Num());
	Args.Add("KillActors", Kill_Actors.Num());
	Args.Add("StaticWidgets", Static_Widgets.Num());
	Args.Add("HiddenWidgets", Hidden_Widgets.Num());
	Args.Add("KillWidgets", Kill_Widgets.Num());
	Args.Add("StaticLevels", Static_SubLevels.Num());
	Args.Add("HiddenSubLevels", Hidden_SubLevels.Num());
	Args.Add("KillSubLevels", Kill_SubLevels.Num());
	return FText::Format(Format, Args);
}
