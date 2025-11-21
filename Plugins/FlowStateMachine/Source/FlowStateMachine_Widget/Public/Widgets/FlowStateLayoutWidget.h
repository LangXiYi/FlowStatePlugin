// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTags.h"
#include "FlowStateLayoutWidget.generated.h"


class UGameplayTagSlot;

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_WIDGET_API UFlowStateLayoutWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual TSharedRef<SWidget> RebuildWidget() override;

	UFUNCTION(BlueprintCallable)
	virtual void ClearChildren();

	UFUNCTION(BlueprintCallable)
	UGameplayTagSlot* FindSlot(FGameplayTag SlotTag) const;

	UFUNCTION(BlueprintCallable)
	bool CheckSlot(FGameplayTag SlotTag) const;

	UFUNCTION(BlueprintCallable)
	void AddChildTo(FGameplayTag SlotTag, UWidget* Child);

protected:
	UPROPERTY(BlueprintReadOnly)
	TArray<UGameplayTagSlot*> TagSlots;

private:
	UPROPERTY(meta = (BindWidget))
	UPanelWidget* RootWidget;
};

