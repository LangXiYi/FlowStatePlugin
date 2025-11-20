// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FlowState.generated.h"

class UFlowStateDataAsset;
class UFlowStateDataFragment;
class UWidget;
class UFlowStateLayoutWidget;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class FLOWSTATEMACHINE_API UFlowState : public UObject
{
	GENERATED_BODY()

	friend class UFlowStateContext;

public:
	virtual void Tick(float DeltaTime);
	UFUNCTION(BlueprintImplementableEvent, Category="FlowState", DisplayName="Tick")
	void OnTick(float DeltaTime);

	virtual UWorld* GetWorld() const override;

	virtual ULevel* GetLevel() const;

	/**
	 * 
	 * @param Context 
	 */
	virtual void Enter(UFlowStateContext* Context);
	UFUNCTION(BlueprintImplementableEvent, Category="Flow State")
	void OnEnter();

	/**
	 * 初始化控件
	 */
	virtual void InitWidget(UFlowStateLayoutWidget* Layout);
	UFUNCTION(BlueprintImplementableEvent, Category="Flow State")
	void OnInitWidget(UFlowStateLayoutWidget* Layout);

	/**
	 * 
	 */
	virtual void Exit();
	UFUNCTION(BlueprintImplementableEvent, Category="Flow State")
	void OnExit();

	UFlowStateContext* GetContext() { return StateContext; }

	UFUNCTION(BlueprintCallable, Category="Flow State")
	void ClearCache();

	// 重载该函数即可实现对指定类型的物体的生命周期管理
	void AddToKills(AActor* Target) { KillActors.Add(Target); }
	void AddToKills(UWidget* Target){ KillWidgets.Add(Target); }
	void AddToKills(FName LevelName){ KillLevels.Add(LevelName); }

	// 重载该函数即可实现对指定类型的物体的生命周期管理
	void AddToHiddens(AActor* Target) { HiddenActors.Add(Target); }
	void AddToHiddens(UWidget* Target){ HiddenWidgets.Add(Target); }
	void AddToHiddens(FName LevelName){ HiddenLevels.Add(LevelName); }

	UFUNCTION(BlueprintCallable, Category="Flow State", meta = (DeterminesOutputType = Type))
	AActor* FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag);

	template<class T>
	T* FindActorFromCache(TSubclassOf<AActor> Type, FName ActorTag)
	{
		return static_cast<T*>(FindActorFromCache(Type, ActorTag));
	}

	UFUNCTION(BlueprintPure, Category="Flow State")
	float GetDeltaTime() const { return Private_DeltaTime; }

	UFUNCTION(BlueprintPure, Category = "Flow State", meta = (DeterminesOutputType = "AssetType"))
	UObject* FindAssetByName(TSubclassOf<UObject> AssetType, FName AssetName) const;

	UFUNCTION(BlueprintPure, Category = "Flow State")
	UFlowStateDataAsset* GetFlowStateData() const;

	UFUNCTION(BlueprintPure, Category = "Flow State", meta = (DeterminesOutputType = "FragmentClass"))
	UFlowStateDataFragment* FindFlowStateDataFragment(TSubclassOf<UFlowStateDataFragment> FragmentClass) const;

	template<class T>
	T* FindFlowStateDataFragment() const
	{
		return (T*)FindFlowStateDataFragment(T::StaticClass());
	}

	/** 获取上一状态的信息，不保证对象有效性，不要直接使用 */
	UFUNCTION(BlueprintPure, Category = "Flow State")
	UFlowState* GetLastFlowState() const;

protected:
	virtual void PreIniProperties(UFlowState* LastState);
	
	UFUNCTION(BlueprintImplementableEvent, Category = "Flow State")
	void OnPreInitProperties(UFlowState* LastState);

	/**
	 * 从当前状态转移至目标状态是否符合条件
	 * @param LastState 
	 * @return 
	 */
	virtual bool Condition(UFlowState* LastState);

	UFUNCTION(BlueprintImplementableEvent, Category="Flow State", DisplayName="Condition")
	bool BP_Condition();

	// 临时使用，不作为最终使用方案，但调用方式可以不变
	UPROPERTY(EditDefaultsOnly, Category="Flow State");
	TArray<TSubclassOf<UFlowState>> FlowStates;
	
protected:
	UPROPERTY(BlueprintReadOnly, Category = "Flow State", meta = (AllowPrivateAccess = true))
	UFlowStateContext* StateContext;

private:
	TArray<AActor*> KillActors;
	TArray<AActor*> HiddenActors;

	TArray<UWidget*> KillWidgets;
	TArray<UWidget*> HiddenWidgets;

	TArray<FName> HiddenLevels;
	TArray<FName> KillLevels;

	float Private_DeltaTime;
};
