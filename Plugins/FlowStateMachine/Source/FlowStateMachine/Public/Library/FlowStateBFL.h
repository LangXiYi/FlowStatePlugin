// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Utility/FlowStateUtility.h"
#include "GameplayTags.h"
#include "SM/FlowState.h"
#include "FlowStateBFL.generated.h"

class ASkeletalMeshActor;

class UFlowState;
class UFlowStateContext;
class UFlowStateDataAsset;
class UFlowStateDataFragment;
class UFlowStateLayoutWidget;
class AFlowStateCameraActor;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFlowStateBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	///////////////////////////////////////////////////////
	// Flow State Data
	///////////////////////////////////////////////////////
	
	UFUNCTION(BlueprintPure, Category = "OperationGuideDataBFL", meta = (WorldContext = "WorldContextObject"))
	static TSubclassOf<UFlowState> GetStartFlowState(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "OperationGuideDataBFL", meta = (WorldContext = "WorldContextObject"))
	static UFlowStateDataAsset* GetFlowStateDataAsset(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "OperationGuideDataBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "FragmentClass"))
	static UFlowStateDataFragment* FindFlowStateDataFragment(UObject* WorldContextObject, TSubclassOf<UFlowStateDataFragment> FragmentClass);

	template<class T>
	static T* FindFlowStateDataFragment(UObject* WorldContextObject)
	{
		return (T*)FindFlowStateDataFragment(WorldContextObject, T::StaticClass());
	}

	///////////////////////////////////////////////////////
	// Flow State
	///////////////////////////////////////////////////////

	UFUNCTION(BlueprintPure, Category = "OperationGuideDataBFL", meta = (WorldContext = "WorldContextObject"))
	static bool IsFlowStateLevel(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "FlowStateClass"))
	static UFlowState* SwitchToFlowState(UObject* WorldContextObject, TSubclassOf<UFlowState> FlowStateClass);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "FlowStateClass"))
	static UFlowState* SwitchToFlowStateByIndex(UObject* WorldContextObject, int32 Index);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "FlowStateClass"))
	static UFlowState* SwitchToFlowStateAndInitWidget(UObject* WorldContextObject, TSubclassOf<UFlowState> FlowStateClass, UFlowStateLayoutWidget* Layout);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "FlowStateClass"))
	static UFlowState* SwitchToFlowStateAndInitWidgetByIndex(UObject* WorldContextObject, int32 Index, UFlowStateLayoutWidget* Layout);

	UFUNCTION(BlueprintPure, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject"))
	static UFlowStateContext* GetFlowStateContext(UObject* WorldContextObject);

	template<class T>
	static T* GetFlowStateContext(UObject* WorldContextObject)
	{
		return static_cast<T*>(GetFlowStateContext(WorldContextObject));
	}

	UFUNCTION(BlueprintPure, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject"))
	static UFlowState* GetCurFlowState(UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Type"))
	static UFlowState* GetCurFlowStateAs(UObject* WorldContextObject, TSubclassOf<UFlowState> Type);

	template<class T>
	static T* GetCurFlowStateAs(UObject* WorldContextObject)
	{
		return static_cast<T*>(GetCurFlowStateAs(WorldContextObject, T::StaticClass()));
	}

	///////////////////////////////////////////////////////
	// Camera
	///////////////////////////////////////////////////////
	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "bIsForceReset"))
	static AFlowStateCameraActor* SetViewTarget(UObject* WorldContextObject, FName CameraName, float FOV, bool bIsForceReset = true);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "bIsForceReset"))
	static AFlowStateCameraActor* SetViewTargetAndRotationModeByPos(UObject* WorldContextObject, FName CameraName, float FOV,
		FVector OriginPos, ECameraRotationMode RotationMode, bool bIsForceReset = true);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", AdvancedDisplay = "OriginOffset, bIsForceReset"))
	static AFlowStateCameraActor* SetViewTargetAndRotationModeByActors(UObject* WorldContextObject, FName CameraName, float FOV,
		TArray<AActor*> OriginTarget, ECameraRotationMode RotationMode, FVector OriginOffset = FVector::ZeroVector, bool bIsForceReset = true);

	///////////////////////////////////////////////////////
	// Animation
	///////////////////////////////////////////////////////
	
	// 手动控制动画播放的进度，从 0 ~ 1，播放完成后返回true
	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL")
	static void ManualPlayAnim(ASkeletalMeshActor* Target, UAnimSequence* Animation, float Rate);

	///////////////////////////////////////////////////////
	// Trace
	///////////////////////////////////////////////////////
	
	/**
	 * 按样条线进行碰撞检测
	 */
	UFUNCTION(BlueprintCallable, Category="FlowStateBFL", meta=(bIgnoreSelf="true", WorldContext="WorldContextObject", AutoCreateRefTerm="ActorsToIgnore", DisplayName = "SplineTraceByChannel", AdvancedDisplay="TraceColor,TraceHitColor,DrawTime", Keywords="sweep"))
	static bool SplineTraceByChannel(const UObject* WorldContextObject, class USplineComponent* Spline, int32 Precision, float Radius, ETraceTypeQuery TraceChannel, bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit, float& Time, bool bIgnoreSelf, FLinearColor TraceColor = FLinearColor::Red, FLinearColor TraceHitColor = FLinearColor::Green, float DrawTime = 5.0f);

	///////////////////////////////////////////////////////
	// Stream Level
	///////////////////////////////////////////////////////
	
	/** Stream the level (by Name); Calling again before it finishes has no effect */
	UFUNCTION(BlueprintCallable, meta=(WorldContext = "WorldContextObject", Latent = "", LatentInfo = "LatentInfo", DisplayName = "Load Stream Level (by Name)"), Category = "FlowStateBFL")
	static void LoadStreamLevel(UObject* WorldContextObject, FName LevelName, EFlowStateLifetime Lifetime, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo LatentInfo);

	/** Stream the level (by Object Reference); Calling again before it finishes has no effect */
	UFUNCTION(BlueprintCallable, meta=(WorldContext = "WorldContextObject", Latent = "", LatentInfo = "LatentInfo", DisplayName = "Load Stream Level (by Reference)"), Category = "FlowStateBFL")
	static void LoadStreamLevelBySoftObjectPtr(UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level, EFlowStateLifetime Lifetime, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo LatentInfo);
	
public:
	///////////////////////////////////////////////////////
	// Blueprint Internal Use Only Function
	///////////////////////////////////////////////////////

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (BlueprintInternalUseOnly = "true"))
	static void SetActorStaticMesh(AActor* Target, UStaticMesh* Mesh);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (BlueprintInternalUseOnly = "true"))
	static void SetActorSkeletalMesh(AActor* Target, USkeletalMesh* Mesh);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", DeterminesOutputType = "Class", BlueprintInternalUseOnly = "true"))
	static UUserWidget* CreateAndBindWidget(UObject* WorldContextObject, UFlowStateLayoutWidget* WidgetLayout, TSubclassOf<UUserWidget> WidgetType, FGameplayTag WidgetSlotTag, EFlowStateLifetime Lifetime = EFlowStateLifetime::Kill);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (WorldContext = "WorldContextObject", BlueprintInternalUseOnly = "True"))
	static bool FindActorFromCache(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, FName ActorTag, AActor*& FindActor);

	UFUNCTION(BlueprintCallable, Category = "FlowStateBFL", meta = (BlueprintInternalUseOnly = "true"))
	static AActor* InitActorLifetimeState(AActor* Target, EFlowStateLifetime Lifetime, FName ActorTag);

protected:
	template<class T>
	static void InitTargetLifetime(UFlowState* FlowState, T Target, EFlowStateLifetime Lifetime)
	{
		if (FlowState == nullptr)
		{
			UE_LOG(LogFlowState, Error, TEXT("%hs FlowState is nullptr."), __FUNCTION__)
			return;
		}
		switch (Lifetime)
		{
		case EFlowStateLifetime::None:
			break;
		case EFlowStateLifetime::Kill:
			FlowState->AddToKills(Target);
			break;
		case EFlowStateLifetime::Hien:
			FlowState->AddToHiddens(Target);
			break;
		}
	}
};

