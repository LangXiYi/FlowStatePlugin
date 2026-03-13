#include "TabSummoner/CommonDataTabSummoner.h"

#include "Data/FSMCommonData.h"
#include "FlowStateMachineEditor.h"
#include "Utility/FlowStateEditorHelper.h"

FCommonDataEditorSummoner::FCommonDataEditorSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor) :
    FWorkflowTabFactory(FTabSummonerHelper::CommonDataEditorID, InEditor),
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


FCommonDataDetailSummoner::FCommonDataDetailSummoner(TSharedPtr<FFlowStateMachineEditor> InEditor) :
    FWorkflowTabFactory(FTabSummonerHelper::CommonDataDetailsID, InEditor),
    FlowStateMachineEditor(InEditor)
{
}

TSharedRef<SWidget> FCommonDataDetailSummoner::CreateTabBody(const FWorkflowTabSpawnInfo& Info) const
{
    TSharedPtr<FFlowStateMachineEditor> StateMachineEditor = FlowStateMachineEditor.Pin();

    FPropertyEditorModule& PropertyEditor = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
    FDetailsViewArgs PropertyViewArgs(false, false, true, FDetailsViewArgs::HideNameArea);

    TSharedRef<IDetailsView> AssetDetailsView = PropertyEditor.CreateDetailView(PropertyViewArgs);

    AssetDetailsView->SetObject(StateMachineEditor->GetCommonData());

    return SNew(SVerticalBox)
        + SVerticalBox::Slot()
        .FillHeight(1.f)
        [
            AssetDetailsView
        ];
}

FText FCommonDataDetailSummoner::GetTabToolTipText(const FWorkflowTabSpawnInfo& Info) const
{
    return FWorkflowTabFactory::GetTabToolTipText(Info);
}
