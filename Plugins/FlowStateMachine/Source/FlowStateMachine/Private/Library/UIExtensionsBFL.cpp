// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/UIExtensionsBFL.h"

#include "Blueprint/WidgetTree.h"
#include "Components/PanelWidget.h"
#include "Components/Widget.h"

BEGIN_NAMESPACE_FSM

UWidget* UUIExtensionsBFL::FindParentWidgetOfType(UWidget* StartWidget, TSubclassOf<UWidget> Type)
{
	while ( StartWidget )
	{
		UWidget* LocalRoot = StartWidget;
		UWidget* LocalParent = LocalRoot->GetParent();
		while (LocalParent)
		{
			if (LocalParent->IsA(Type))
			{
				return LocalParent;
			}
			LocalRoot = LocalParent;
			LocalParent = LocalParent->GetParent();
		}

		UWidgetTree* WidgetTree = Cast<UWidgetTree>(LocalRoot->GetOuter());
		if ( WidgetTree == nullptr )
		{
			break;
		}

		StartWidget = Cast<UUserWidget>(WidgetTree->GetOuter());
		if ( StartWidget && StartWidget->IsA(Type) )
		{
			return StartWidget;
		}
	}

	return nullptr;
}

UWidget* UUIExtensionsBFL::FindChildWidgetOfType(UPanelWidget* Parent, TSubclassOf<UWidget> Type)
{
	// �ݹ���������������������µ��������� Or Parent Ϊ��
	if (nullptr == Parent || false == IsValid(Parent))
	{
		return nullptr;
	}
	// ��ȡ Check Box Group ������ Check Box ���͵Ŀؼ�
	TArray<UWidget*> AllChildren = Parent->GetAllChildren();
	for (int32 i = 0; i < AllChildren.Num(); ++i)
	{
		// ���� Check Box �̳��� Panel Widget ����Ҫ�����жϸ������Ƿ�Ϊ Check Box ���͡�
		if (false == AllChildren[i]->IsA(Type))
		{
			// ��������Ϊ Panel Widget ��ݹ���øú���������������Ϊ��������
			if (true == AllChildren[i]->IsA(UPanelWidget::StaticClass()))
			{
				UPanelWidget* PanelWidget = Cast<UPanelWidget>(AllChildren[i]);
				return FindChildWidgetOfType(PanelWidget, Type);
			}
			continue;
		}
		return AllChildren[i];
	}
	return nullptr;
}

void UUIExtensionsBFL::FindAllChildOfType(UPanelWidget* Parent, TSubclassOf<UWidget> Type, TArray<UWidget*>& OutArray)
{
	// �ݹ���������������������µ��������� Or Parent Ϊ��
	if (nullptr == Parent || false == IsValid(Parent))
	{
		return;
	}
	// ��ȡ Check Box Group ������ Check Box ���͵Ŀؼ�
	TArray<UWidget*> AllChildren = Parent->GetAllChildren();
	for (int32 i = 0; i < AllChildren.Num(); ++i)
	{
		// ���� Check Box �̳��� Panel Widget ����Ҫ�����жϸ������Ƿ�Ϊ Check Box ���͡�
		if (false == AllChildren[i]->IsA(Type))
		{
			// ��������Ϊ Panel Widget ��ݹ���øú���������������Ϊ��������
			if (true == AllChildren[i]->IsA(UPanelWidget::StaticClass()))
			{
				UPanelWidget* PanelWidget = Cast<UPanelWidget>(AllChildren[i]);
				FindAllChildOfType(PanelWidget, Type, OutArray);
			}
			continue;
		}

		// ======= ���� Check Box ��������
		OutArray.Add(AllChildren[i]);
	}
}

END_NAMESPACE_FSM