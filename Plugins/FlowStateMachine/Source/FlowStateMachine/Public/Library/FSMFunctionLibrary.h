// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SM/FlowStateBase.h"
#include "SM/FlowStateContext.h"
#include "Utility/FSMUtility.h"
#include "FSMFunctionLibrary.generated.h"


class ASkeletalMeshActor;
class UFlowStateLayoutWidget;
class UFlowStateBase;
class UFlowStateContext;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UFSMFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

    //////////////////////////////////////////////////////////////////
    // Flow State Machine Meta Data
    //////////////////////////////////////////////////////////////////
public:
    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    static UFlowStateContext* GetFlowStateContext(UObject* WorldContextObject);

    template <class T>
    static T* GetFlowStateContext(UObject* WorldContextObject)
    {
        return static_cast<T*>(GetFlowStateContext(WorldContextObject));
    }

    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    static UFlowStateBase* GetCurFlowState(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeterminesOutputType = "Type"))
    static UFlowStateBase* GetCurFlowStateAs(UObject* WorldContextObject, TSubclassOf<UFlowStateBase> Type);

    template <class T>
    static T* GetCurFlowStateAs(UObject* WorldContextObject)
    {
        return static_cast<T*>(GetCurFlowState(WorldContextObject));
    }

    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeterminesOutputType = "Type"))
    static UFSMCommonDataManager* GetCommonDataManager(UObject* WorldContextObject);

    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    static EFlowStateLifetime FindActorFromCache(UObject* WorldContextObject, FName ActorTag, AActor*& FindActor);

    UFUNCTION(BlueprintPure, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
    static EFlowStateLifetime FindWidgetFromCache(UObject* WorldContextObject, FGameplayTag WidgetTag,
                                                  UWidget*& FindActor);

    /////////////////////////////////////////////////////////////////////
    /// Blueprint Internal Use Only Function
    /////////////////////////////////////////////////////////////////////
    UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category = "FSMFunctionLibrary",
        meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DeterminesOutputType = "Class",
            BlueprintInternalUseOnly = "true"))
    static UUserWidget* CreateAndBindWidget(UObject* WorldContextObject, UFlowStateLayoutWidget* WidgetLayout,
                                            TSubclassOf<UUserWidget> WidgetType, FGameplayTag WidgetSlotTag,
                                            EFlowStateLifetime Lifetime);

    UFUNCTION(BlueprintCallable, Category = "FSMFunctionLibrary", meta = (BlueprintInternalUseOnly = "true"))
    static AActor* InitActorLifetimeState(AActor* Target, EFlowStateLifetime Lifetime, FName ActorTag);
};
