#pragma once
#include "Utility/FSMUtility.h"

class UWidget;

// 辅助 FlowStateContext 管理资源
class FSMGC
{
public:
	template<class T>
	T* FindByCache(FName Name) const
	{
		return nullptr;
	}
	AActor* FindByCache(FName Name, TSubclassOf<AActor> Type) const;

	void ClearAllCache();

	////////////////////////////////////////////////////////////////
	//  Add to Cache
	////////////////////////////////////////////////////////////////
	
public:
	template<class T>
	void AddToCache(T* Target, EFlowStateLifetime Lifetime);

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

	CREATE_CACHE_OBJECT_HELPER(TWeakObjectPtr<AActor>, Actors);
	CREATE_CACHE_OBJECT_HELPER(TWeakObjectPtr<UWidget>, Widgets);
	CREATE_CACHE_OBJECT_HELPER(FName, SubLevels);

private:
	FText Debug_GetCacheInfo() const;
};

template <class T>
void FSMGC::AddToCache(T* Target, EFlowStateLifetime Lifetime)
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
