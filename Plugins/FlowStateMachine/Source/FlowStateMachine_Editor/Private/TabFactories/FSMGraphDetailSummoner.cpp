#include "TabFactories/FSMGraphDetailSummoner.h"
#include "TabFactories/FSMEditorTabsHelper.h"
#include "SM/FlowStateMachine.h"
#include "FlowStateMachineEditor.h"
#include "Components/VerticalBoxSlot.h"

#define LOCTEXT_NAMESPACE "FlowStateMachineDetailSummoner"

FFSMGraphDetailSummoner::FFSMGraphDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor)
	:FWorkflowTabFactory(FFSMEditorTabsHelper::GraphDetailsID, InEditor) , FlowStateMachineEditor(InEditor)
{
	TabLabel = LOCTEXT("DetailSummonerLabel", "GraphDetailView");
	ViewMenuDescription = LOCTEXT("ViewMenuDescription", "Open detail view");
	ViewMenuTooltip = LOCTEXT("ViewMenuTooltip", "detail view");
	bIsSingleton = true;
}

FText FFSMGraphDetailSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
	return LOCTEXT("FlowStateMachineDetailTooltip", "The details tab is for editing FlowState entries.");
}

TSharedRef<SWidget> FFSMGraphDetailSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
	TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();
	
	FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
	FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);
	
	TSharedRef<IDetailsView> AssetDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);
	TSharedRef<IDetailsView> NodeDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);

	AssetDetailsView->SetObject(StateMachineEditor->GetEditAsset());
	// TODO::需要修改为选择的节点
	NodeDetailsView->SetObject(StateMachineEditor->GetEditAsset());
	
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			AssetDetailsView
		]
		+SVerticalBox::Slot()
		.FillHeight(1.f)
		[
			NodeDetailsView
		];
}

#undef LOCTEXT_NAMESPACE
