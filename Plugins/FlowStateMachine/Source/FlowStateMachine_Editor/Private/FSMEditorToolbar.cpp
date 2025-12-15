#include "FSMEditorToolbar.h"

#include "WorkflowOrientedApp/SModeWidget.h"

#define LOCTEXT_NAMESPACE "FSMEditorToolbar"


class SFlowStateMachineModeSeparator : public SBorder
{
public:
	SLATE_BEGIN_ARGS(SFlowStateMachineModeSeparator) {}
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
		const float Height = 20.0f;
		const float Thickness = 16.0f;
		return FVector2D(Thickness, Height);
	}
	// End of SWidget interface
};

void FFSMEditorToolbar::AddModesToolbar(TSharedPtr<FExtender> Extender)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFSMGraphEditor> StateMachineEditorPtr = FlowStateMachineEditor.Pin();

	Extender->AddToolBarExtension(
		"Asset",
		EExtensionHook::After,
		StateMachineEditorPtr->GetToolkitCommands(),
		FToolBarExtensionDelegate::CreateSP( this, &FFSMEditorToolbar::FillModesToolbar ) );
}

void FFSMEditorToolbar::AddDebuggerToolbar(TSharedPtr<FExtender> Extender)
{
}

void FFSMEditorToolbar::AddBehaviorTreeToolbar(TSharedPtr<FExtender> Extender)
{
}

void FFSMEditorToolbar::FillModesToolbar(FToolBarBuilder& ToolbarBuilder)
{
	check(FlowStateMachineEditor.IsValid());
	TSharedPtr<FFSMGraphEditor> StateMachineEditorPtr = FlowStateMachineEditor.Pin();

	TAttribute<FName> GetActiveMode(StateMachineEditorPtr.ToSharedRef(), &FFSMGraphEditor::GetCurrentMode);
	FOnModeChangeRequested SetActiveMode = FOnModeChangeRequested::CreateSP(StateMachineEditorPtr.ToSharedRef(), &FFSMGraphEditor::SetCurrentMode);

	// Left side padding
	StateMachineEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));

	StateMachineEditorPtr->AddToolbarWidget(
		SNew(SModeWidget, FFSMGraphEditor::GetLocalizedMode( FFSMGraphEditor::FlowStateMachineMode ), FFSMGraphEditor::FlowStateMachineMode)
		.OnGetActiveMode(GetActiveMode)
		.OnSetActiveMode(SetActiveMode)
		.CanBeSelected(StateMachineEditorPtr.Get(), &FFSMGraphEditor::CanAccessFlowStateMachineMode)
		.ToolTipText(LOCTEXT("FlowStateMachineModeButtonTooltip", "Switch to FlowStateMachine Mode"))
		// TODO::Use Custom Image
		.IconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode"))
		.SmallIconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode.Small"))
	);

	StateMachineEditorPtr->AddToolbarWidget(SNew(SFlowStateMachineModeSeparator));

	StateMachineEditorPtr->AddToolbarWidget(
		SNew(SModeWidget, FFSMGraphEditor::GetLocalizedMode( FFSMGraphEditor::CommonDataMode ), FFSMGraphEditor::CommonDataMode)
		.OnGetActiveMode(GetActiveMode)
		.OnSetActiveMode(SetActiveMode)
		.CanBeSelected(StateMachineEditorPtr.Get(), &FFSMGraphEditor::CanAccessCommonDataMode)
		.ToolTipText(LOCTEXT("CommonDataModeButtonTooltip", "Switch to CommonData Mode"))
		// TODO::Use Custom Image
		.IconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBlackboardMode"))
		.SmallIconImage(FEditorStyle::GetBrush("BTEditor.SwitchToBlackboardMode.Small"))
	);
	// Right side padding
	StateMachineEditorPtr->AddToolbarWidget(SNew(SSpacer).Size(FVector2D(4.0f, 1.0f)));
}

void FFSMEditorToolbar::FillDebuggerToolbar(FToolBarBuilder& ToolbarBuilder)
{
}

void FFSMEditorToolbar::FillBehaviorTreeToolbar(FToolBarBuilder& ToolbarBuilder)
{
}


#undef LOCTEXT_NAMESPACE