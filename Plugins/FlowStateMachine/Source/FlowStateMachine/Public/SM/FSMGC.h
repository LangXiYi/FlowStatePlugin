#pragma once
#include "Utility/FSMUtility.h"

class UWidget;

// 辅助 FlowStateContext 管理资源
class FSMGC
{
public:
	template<class T>
	void AddToCache(T* Target, EFlowStateLifetime Lifetime)
	{
		switch (Lifetime)
		{
		case EFlowStateLifetime::None:
			_AddToStaticBy(Target);
			break;
		case EFlowStateLifetime::Kill:
			_AddToKillBy(Target);
			break;
		case EFlowStateLifetime::Hien:
			_AddToHiddenBy(Target);
			break;
		}
	}
	
	template<class T>
	T* FindByCache(FName Name) const
	{
		return nullptr;
	}
	AActor* FindByCache(FName Name, TSubclassOf<AActor> Type) const;

	void ClearAllCache();

protected:
	void _AddToStaticBy(AActor* Target)
	{
		
	}
	void _AddToStaticBy(UWidget* Target)
	{
		
	}
	void _AddToKillBy(AActor* Target)
	{
		
	}
	void _AddToKillBy(UWidget* Target)
	{
		
	}
	void _AddToHiddenBy(AActor* Target)
	{
		
	}
	void _AddToHiddenBy(UWidget* Target)
	{
		
	}
private:
	// Array<> Cache
	
	
/*#if !UE_BUILD_SHIPPING
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
#endif*/
};
