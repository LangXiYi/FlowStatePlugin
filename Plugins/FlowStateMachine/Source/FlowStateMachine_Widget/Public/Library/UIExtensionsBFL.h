// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UIExtensionsBFL.generated.h"

class UPanelWidget;
class UWidget;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_WIDGET_API UUIExtensionsBFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UIExtensionsBFL", meta = (DeterminesOutputType = Type))
	static UWidget* FindParentWidgetOfType(UWidget* StartWidget, TSubclassOf<UWidget> Type);

	template<class T>
	static T* FindParentWidgetOfType(UWidget* StartWidget)
	{
		return static_cast<T*>(FindParentWidgetOfType(StartWidget, T::StaticClass()));
	}

	UFUNCTION(BlueprintPure, Category = "UIExtensionsBFL", meta = (DeterminesOutputType = Type))
	static UWidget* FindChildWidgetOfType(UPanelWidget* Parent, TSubclassOf<UWidget> Type);

	template<class T>
	static T* FindChildWidgetOfType(UWidget* Parent)
	{
		return static_cast<T*>(FindChildWidgetOfType(Parent, T::StaticClass()));
	}

	UFUNCTION(BlueprintCallable, Category = "UIExtensionsBFL", meta = (DeterminesOutputType = Type))
	static void FindAllChildOfType(UPanelWidget* Parent, TSubclassOf<UWidget> Type, TArray<UWidget*>& OutArray);
};
