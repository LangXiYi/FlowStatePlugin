// Fill out your copyright notice in the Description page of Project Settings.


#include "Utility/FSMCreateWidgetHelper.h"

#include "Actions/Actions_CreateWidgets.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "SM/FlowStateContext.h"
#include "Widgets/FlowStateLayoutWidget.h"


void UFSMCreateWidgetHelper::CreateWidget(UFlowStateContext* InStateContext)
{
	ensure(WidgetTag.IsValid());
	if (!WidgetTag.IsValid())
	{
		ensure(false);
		return;
	}

	check(InStateContext);
	if (!InStateContext)
	{
		return;
	}

	TSharedPtr<FSMGC> GCManager = InStateContext->GetGCManager();
	if (!GCManager.IsValid())
	{
		return;
	}
	UFlowStateLayoutWidget* LayoutWidget = InStateContext->GetLayoutWidget(WidgetLayer);
	if (!LayoutWidget)
	{
		return;
	}

	UWidget* CreateWidget = nullptr;
	// 从缓存中查找控件，只有在缓存中不存在的控件才会被创建
	EFlowStateLifetime OldLifetime = GCManager->FindRefByCache<FGameplayTag>(WidgetTag, CreateWidget);
	if (CreateWidget == nullptr)
	{
		CreateWidget = UWidgetBlueprintLibrary::Create(InStateContext, WidgetClass, GetPlayerController());
		LayoutWidget->AddChildTo(WidgetTag, CreateWidget);
		GCManager->AddToCache(CreateWidget, WidgetLifetime);
		OverrideProperty(CreateWidget);
		InitializeWidget(CreateWidget);
	}
	else
	{
		if (WidgetLifetime != OldLifetime)
		{
			GCManager->SwitchCache(CreateWidget, OldLifetime, WidgetLifetime);
		}
		OverrideProperty(CreateWidget);
	}
	CreateWidget->SetVisibility(Visibility);
}

bool UFSMCreateWidgetHelper::IsValid() const
{
	return WidgetTag.IsValid() && WidgetClass != nullptr && WidgetLifetime != EFlowStateLifetime::None;
}

#if WITH_EDITOR

void UFSMCreateWidgetHelper::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	UObject::PostEditChangeProperty(PropertyChangedEvent);
	if (PropertyChangedEvent.GetPropertyName() == GET_MEMBER_NAME_CHECKED(UFSMCreateWidgetHelper, Events))
	{
		UObject* MyOuter = GetOuter();
		if (UFSMRuntimeSubNode* RuntimeNode = Cast<UFSMRuntimeSubNode>(GetOuter()))
		{
			UFSMRuntimeNode* ParentNode = RuntimeNode->GetParentNode<UFSMRuntimeNode>();
			if (ParentNode)
			{
				// TODO::为节点添加额外的引脚
				FSMLOGW("Post Edit Change Property Events")
			}
		} 
	}
}

#endif

APlayerController* UFSMCreateWidgetHelper::GetPlayerController_Implementation()
{
	if (GetWorld())
	{
		return GetWorld()->GetFirstPlayerController();
	}
	return nullptr;
}
