#include "FlowStateEditorToolbar.h"

#include "Framework/MultiBox/SToolBarButtonBlock.h"
#include "Utility/FlowStateEditorHelper.h"
#include "WorkflowOrientedApp/SModeWidget.h"

#define LOCTEXT_NAMESPACE "FSMEditorToolbar"

USING_FLOWSTATE_EDITORHELPER

class SFlowStateMachineModeSeparator : public SBorder
{
public:
    SLATE_BEGIN_ARGS(SFlowStateMachineModeSeparator)
        {
        }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArg)
    {
        SBorder::Construct(
            SBorder::FArguments()
            .BorderImage(FEditorStyle::GetBrush("BlueprintEditor.PipelineSeparator"))
            .Padding(0.0f)
        );
    }

    // SWidget interface
    virtual FVector2D ComputeDesiredSize(float) const override
    {
        constexpr float Height = 20.0f;
        constexpr float Thickness = 16.0f;
        return FVector2D(Thickness, Height);
    }

    // End of SWidget interface
};

void FFlowStateEditorToolbar::AddModesToolbar(TSharedPtr<FExtender> Extender)
{
    check(FlowStateMachineEditor.IsValid());
    TSharedPtr<FFlowStateMachineEditor> StateMachineEditorPtr = FlowStateMachineEditor.Pin();

    Extender->AddToolBarExtension(
        "Asset",
        EExtensionHook::After,
        StateMachineEditorPtr->GetToolkitCommands(),
        FToolBarExtensionDelegate::CreateSP(this, &FFlowStateEditorToolbar::FillModesToolbar));

    /*Extender->AddToolBarExtension(
        "")*/
}

void FFlowStateEditorToolbar::AddDebuggerToolbar(TSharedPtr<FExtender> Extender)
{
}

void FFlowStateEditorToolbar::AddBehaviorTreeToolbar(TSharedPtr<FExtender> Extender)
{
}

void FFlowStateEditorToolbar::FillModesToolbar(FToolBarBuilder& ToolbarBuilder)
{
    check(FlowStateMachineEditor.IsValid());
    TSharedPtr<FFlowStateMachineEditor> StateMachineEditorPtr = FlowStateMachineEditor.Pin();

    TAttribute<FName> GetActiveMode(StateMachineEditorPtr.ToSharedRef(), &FFlowStateMachineEditor::GetCurrentMode);
    FOnModeChangeRequested SetActiveMode = FOnModeChangeRequested::CreateSP(
        StateMachineEditorPtr.ToSharedRef(), &FFlowStateMachineEditor::SetCurrentMode);

    // Left side padding
    StateMachineEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));

    StateMachineEditorPtr->AddToolbarWidget(
        SNew(SModeWidget, FFlowStateMachineEditor::GetLocalizedMode( FEditorHelper::FlowStateMachineMode ),
             FEditorHelper::FlowStateMachineMode)
                                                 .OnGetActiveMode(GetActiveMode)
                                                 .OnSetActiveMode(SetActiveMode)
                                                 .CanBeSelected(StateMachineEditorPtr.Get(),
                                                                &FFlowStateMachineEditor::CanAccessFlowStateMachineMode)
                                                 .ToolTipText(LOCTEXT("FlowStateMachineModeButtonTooltip",
                                                                      "Switch to FlowStateMachine Mode"))
		// TODO::Use Custom Image
                                                 .IconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode"))
                                                 .SmallIconImage(
                                                     FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode.Small"))
    );

    StateMachineEditorPtr->AddToolbarWidget(SNew(SFlowStateMachineModeSeparator));

    StateMachineEditorPtr->AddToolbarWidget(
        SNew(SModeWidget, FFlowStateMachineEditor::GetLocalizedMode( FEditorHelper::CommonDataMode ),
             FEditorHelper::CommonDataMode)
                                           .OnGetActiveMode(GetActiveMode)
                                           .OnSetActiveMode(SetActiveMode)
                                           .CanBeSelected(StateMachineEditorPtr.Get(),
                                                          &FFlowStateMachineEditor::CanAccessCommonDataMode)
                                           .ToolTipText(LOCTEXT("CommonDataModeButtonTooltip",
                                                                "Switch to CommonData Mode"))
		// TODO::Use Custom Image
                                           .IconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBlackboardMode"))
                                           .SmallIconImage(
                                               FEditorStyle::GetBrush("BTEditor.SwitchToBlackboardMode.Small"))
    );
    // Right side padding
    StateMachineEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));
}

void FFlowStateEditorToolbar::FillDebuggerToolbar(FToolBarBuilder& ToolbarBuilder)
{
}

void FFlowStateEditorToolbar::FillBehaviorTreeToolbar(FToolBarBuilder& ToolbarBuilder)
{
    check(FlowStateMachineEditor.IsValid());
    TSharedPtr<FFlowStateMachineEditor> StateMachineEditorPtr = FlowStateMachineEditor.Pin();

    // TODO::Add Refresh All Node button

    /*StateMachineEditorPtr->AddToolbarWidget(
        SNew(SToolBarButtonBlock)
        
        );*/
}


#undef LOCTEXT_NAMESPACE
