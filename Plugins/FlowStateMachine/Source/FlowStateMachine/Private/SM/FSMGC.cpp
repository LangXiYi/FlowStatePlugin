#include "SM/FSMGC.h"

void FSMGC::ClearAllCache()
{
	ClearCacheBy(EFlowStateLifetime::None);
	ClearCacheBy(EFlowStateLifetime::Kill);
	ClearCacheBy(EFlowStateLifetime::Hidden);
}

void FSMGC::ClearCacheBy(EFlowStateLifetime Lifetime)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::None:
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

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AActor*& OutTarget) const
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::None:
		for (TWeakObjectPtr<AActor> CacheItem : Static_Actors)
		{
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
		}
		break;
	case EFlowStateLifetime::Kill:
		for (TWeakObjectPtr<AActor> CacheItem : Kill_Actors)
		{
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
		}
		break;
	case EFlowStateLifetime::Hidden:
		for (TWeakObjectPtr<AActor> CacheItem : Hidden_Actors)
		{
			if (CacheItem.IsValid())
			{
				if (CacheItem->Tags.Contains(Tag))
				{
					OutTarget = CacheItem.Get();
					return true;
				}
			}
		}
		break;
	}
	return false;
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, UWidget*& OutTarget) const
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::None:
		for (TWeakObjectPtr<UWidget> CacheItem : Static_Widgets)
		{
			if (CacheItem.IsValid())
			{
				checkNoEntry()
			}
		}
		break;
	case EFlowStateLifetime::Kill:
		for (TWeakObjectPtr<UWidget> CacheItem : Kill_Widgets)
		{
			if (CacheItem.IsValid())
			{
				checkNoEntry()
			}
		}
		break;
	case EFlowStateLifetime::Hidden:
		for (TWeakObjectPtr<UWidget> CacheItem : Hidden_Widgets)
		{
			if (CacheItem.IsValid())
			{
				checkNoEntry()
			}
		}
		break;
	}
	return false;
}

bool FSMGC::_FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ULevel*& OutTarget) const
{
	checkNoEntry()
	return false;
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
