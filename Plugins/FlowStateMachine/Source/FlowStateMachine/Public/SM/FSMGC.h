#pragma once
#include "Utility/FSMUtility.h"

class UWidget;

// 辅助 FlowStateContext 管理资源
class FSMGC
{
	////////////////////////////////////////////////////////////////
	//  Add to Cache
	////////////////////////////////////////////////////////////////
	
public:
	template<class T>
	void AddToCache(T Target, EFlowStateLifetime Lifetime);

	template<class T>
	void RemoveFromCache(T Target, EFlowStateLifetime Lifetime);

	template<class T>
	bool FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, T*& OutTarget) const;

	void ClearAllCache();

	void ClearCacheBy(EFlowStateLifetime Lifetime);

protected:
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AActor*& OutTarget) const;
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, UWidget*& OutTarget) const;
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ULevel*& OutTarget) const;

private:
#define CREATE_CACHE_OBJECT_HELPER(ClassType, Name) \
	private:\
		TArray<ClassType> Static_##Name;\
		TArray<ClassType> Hidden_##Name;\
		TArray<ClassType> Kill_##Name;\
	protected:\
		void _AddToStaticBy(ClassType Target)\
		{\
			Static_##Name.Add(Target);\
		}\
		void _AddToHiddenBy(ClassType Target)\
		{\
			Hidden_##Name.Add(Target);\
		}\
		void _AddToKillBy(ClassType Target)\
		{\
			Kill_##Name.Add(Target);\
		}\
		void _RemoveFromStatic(ClassType Target)\
		{\
			Static_##Name.Remove(Target);\
		}\
		void _RemoveFromHidden(ClassType Target)\
		{\
			Hidden_##Name.Remove(Target);\
		}\
		void _RemoveFromKill(ClassType Target)\
		{\
			Kill_##Name.Remove(Target);\
		}\

	CREATE_CACHE_OBJECT_HELPER(TWeakObjectPtr<AActor>, Actors);
	CREATE_CACHE_OBJECT_HELPER(TWeakObjectPtr<UWidget>, Widgets);
	CREATE_CACHE_OBJECT_HELPER(FName, SubLevels);

public:
	FText Debug_GetCacheInfo() const;
};

template <class T>
void FSMGC::AddToCache(T Target, EFlowStateLifetime Lifetime)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::None:
		_AddToStaticBy(Target);
		break;
	case EFlowStateLifetime::Kill:
		_AddToKillBy(Target);
		break;
	case EFlowStateLifetime::Hidden:
		_AddToHiddenBy(Target);
		break;
	}
}

template <class T>
void FSMGC::RemoveFromCache(T Target, EFlowStateLifetime Lifetime)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::None:
		_RemoveFromStatic(Target);
		break;
	case EFlowStateLifetime::Kill:
		_RemoveFromKill(Target);
		break;
	case EFlowStateLifetime::Hidden:
		_RemoveFromHidden(Target);
		break;
	}
}

template <class T>
bool FSMGC::FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, T*& OutTarget) const
{
	return _FindRefByCache(Tag, Lifetime, OutTarget);
}
