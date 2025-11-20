// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/NamedSlot.h"
#include "Utility/FlowStateUtility.h"
#include "GameplayTagSlot.generated.h"

BEGIN_NAMESPACE_FSM

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UGameplayTagSlot : public UNamedSlot
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

END_NAMESPACE_FSM
