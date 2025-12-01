#include "TabFactories/CommonDataTabSummoner.h"

#include "Data/FSMCommonData.h"
#include "FSMEditor.h"
#include "TabFactories/FSMEditorTabsHelper.h"

FCommonDataEditorSummoner::FCommonDataEditorSummoner(TSharedPtr<FFSMEditor> InEditor):
	FWorkflowTabFactory(FFSMEditorTabsHelper::CommonDataEditorID, InEditor),
	FlowStateMachineEditor(InEditor)

{
}

TSharedRef<SWidget> FCommonDataEditorSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	return FWorkflowTabFactory::CreateTabBody(Info);
}

FText FCommonDataEditorSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FWorkflowTabFactory::GetTabToolTipText(Info);
}


FCommonDataDetailSummoner::FCommonDataDetailSummoner(TSharedPtr<FFSMEditor> InEditor):
	FWorkflowTabFactory(FFSMEditorTabsHelper::CommonDataDetailsID, InEditor),
	FlowStateMachineEditor(InEditor)
{
}

TSharedRef<SWidget> FCommonDataDetailSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFSMEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);
	
	TSharedRef<IDetailsView> AssetDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);

	AssetDetailsView->SetObject(StateMachineEditor->GetCommonData());
	
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			AssetDetailsView
		];
}

FText FCommonDataDetailSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return FWorkflowTabFactory::GetTabToolTipText(Info);
}
