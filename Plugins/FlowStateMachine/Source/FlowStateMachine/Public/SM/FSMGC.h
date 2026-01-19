#pragma once
#include "Utility/FSMUtility.h"
#include "GameplayTagContainer.h"

class AStaticMeshActor;
class ASkeletalMeshActor;
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
	void SwitchCache(T Target, EFlowStateLifetime FromLifetime, EFlowStateLifetime ToLifetime);

	template<class T>
	void RemoveFromCache(T Target, EFlowStateLifetime Lifetime);

	template<class KeyType, class ValeType>
	bool FindRefByCache(const KeyType& Tag, EFlowStateLifetime Lifetime, ValeType& OutTarget);

	template<class KeyType, class ValeType>
	EFlowStateLifetime FindRefByCache(const KeyType& Tag, ValeType& OutTarget);

	void HiddenCache();
	void KillCache();

	void ClearAllCache();

	void ClearCacheBy(EFlowStateLifetime Lifetime);

protected:
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AActor*& OutTarget);
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ASkeletalMeshActor*& OutTarget);
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, AStaticMeshActor*& OutTarget);
	bool _FindRefByCache(FGameplayTag Tag, EFlowStateLifetime Lifetime, UWidget*& OutTarget);
	bool _FindRefByCache(FName Tag, EFlowStateLifetime Lifetime, ULevel*& OutTarget);

	void _KillCacheFrom(AActor* Actor);
	void _KillCacheFrom(UWidget* Widget);
	void _KillCacheFrom(FName SubLevel);

	void _HiddenCacheFrom(AActor* Actor);
	void _HiddenCacheFrom(UWidget* Widget);
	void _HiddenCacheFrom(FName SubLevel);

private:
#define CREATE_CACHE_OBJECT_HELPER(ClassType, Name) \
	private:\
		TArray<ClassType> Static_##Name;\
		TArray<ClassType> Hidden_##Name;\
		TArray<ClassType> Kill_##Name;\
	protected:\
		void _AddToStaticBy(ClassType Target)\
		{\
			Static_##Name.AddUnique(Target);\
		}\
		void _AddToHiddenBy(ClassType Target)\
		{\
			Hidden_##Name.AddUnique(Target);\
		}\
		void _AddToKillBy(ClassType Target)\
		{\
			Kill_##Name.AddUnique(Target);\
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
	case EFlowStateLifetime::Static:
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
void FSMGC::SwitchCache(T Target, EFlowStateLifetime FromLifetime, EFlowStateLifetime ToLifetime)
{
	RemoveFromCache(Target, FromLifetime);
	AddToCache(Target, ToLifetime);
}

template <class T>
void FSMGC::RemoveFromCache(T Target, EFlowStateLifetime Lifetime)
{
	switch (Lifetime)
	{
	case EFlowStateLifetime::Static:
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

template <class KeyType, class ValeType>
bool FSMGC::FindRefByCache(const KeyType& Tag, EFlowStateLifetime Lifetime, ValeType& OutTarget)
{
	return _FindRefByCache(Tag, Lifetime, OutTarget);
}

template <class KeyType, class ValeType>
EFlowStateLifetime FSMGC::FindRefByCache(const KeyType& Tag, ValeType& OutTarget)
{
	_FindRefByCache(Tag, EFlowStateLifetime::Static, OutTarget);
	if (OutTarget != nullptr)
	{
		return EFlowStateLifetime::Static;
	}
	_FindRefByCache(Tag, EFlowStateLifetime::Kill, OutTarget);
	if (OutTarget != nullptr)
	{
		return EFlowStateLifetime::Kill;
	}
	_FindRefByCache(Tag, EFlowStateLifetime::Hidden, OutTarget);
	if (OutTarget != nullptr)
	{
		return EFlowStateLifetime::Hidden;
	}
	return EFlowStateLifetime::None;
}
