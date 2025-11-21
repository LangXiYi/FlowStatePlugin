// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/NamedSlot.h"
#include "GameplayTagSlot.generated.h"

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_WIDGET_API UGameplayTagSlot : public UNamedSlot
{
	GENERATED_BODY()

	friend class UOverlay_Slots;

public:
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
	FGameplayTag GetGameplayTag() const
	{
		return Tag;
	}
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = NameSlot)
	FGameplayTag Tag;
};

