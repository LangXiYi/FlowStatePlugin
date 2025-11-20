// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/FlowStateLayoutWidget.h"

#include "Components/PanelWidget.h"
#include "Components/Widget.h"
#include "Library/UIExtensionsBFL.h"
#include "Widgets/GameplayTagSlot.h"


BEGIN_NAMESPACE_FSM

TSharedRef<SWidget> UFlowStateLayoutWidget::RebuildWidget()
{
	auto Result =  Super::RebuildWidget();
	TArray<UWidget*> Widgets;
	UUIExtensionsBFL::FindAllChildOfType(RootWidget, UGameplayTagSlot::StaticClass(), Widgets);
	TagSlots.Reserve(Widgets.Num());
	for (UWidget* Widget : Widgets)
	{
		TagSlots.Add(static_cast<UGameplayTagSlot*>(Widget));
	} 
	return Result;
}

void UFlowStateLayoutWidget::ClearChildren()
{
	for (UGameplayTagSlot* Widget : TagSlots)
	{
		Widget->ClearChildren();
	}
}

UGameplayTagSlot* UFlowStateLayoutWidget::FindSlot(FGameplayTag SlotTag) const
{
	for (UGameplayTagSlot* TagSlot : TagSlots)
	{
		if (TagSlot->GetGameplayTag() == SlotTag)
		{
			return TagSlot;
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("Not found '%s' from the ‘%s’."), *SlotTag.ToString(), *GetName())
	return nullptr;
}

bool UFlowStateLayoutWidget::CheckSlot(FGameplayTag SlotTag) const
{
	UGameplayTagSlot* TagSlot = FindSlot(SlotTag);
	return TagSlot && !TagSlot->HasAnyChildren();
}

void UFlowStateLayoutWidget::AddChildTo(FGameplayTag SlotTag, UWidget* Child)
{
	UGameplayTagSlot* FoundSlot = FindSlot(SlotTag);
	if (FoundSlot)
	{
		FoundSlot->AddChild(Child);
	}
}


END_NAMESPACE_FSM