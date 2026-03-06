#include "Node/Slates/SFSGraph_StateNode.h"

#include "GraphEditorSettings.h"
#include "IDocumentation.h"
#include "NodeFactory.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "SPinTypeSelector.h"
#include "TutorialMetaData.h"
#include "Node/FSGraphNode.h"
#include "KismetWidgets/Public/SLevelOfDetailBranchNode.h"
#include "Node/FSGraph_StateNode.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"

void SFSGraph_StateNode::Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode)
{
    GraphNode = InGraphNode;

    SetCursor(EMouseCursor::CardinalCross);
    UpdateGraphNode();
}

FReply SFSGraph_StateNode::OnDragOver(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
    // TODO::拖拽放置子节点
    return SFSGraphNodeBase::OnDragOver(MyGeometry, DragDropEvent);
}

FReply SFSGraph_StateNode::OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent)
{
    // TODO::拖拽放置子节点
    return SFSGraphNodeBase::OnDrop(MyGeometry, DragDropEvent);
}

void SFSGraph_StateNode::SetOwner(const TSharedRef<SGraphPanel>& OwnerPanel)
{
    SGraphNode::SetOwner(OwnerPanel);

    for (auto& ChildWidget : SubNodes)
    {
        if (ChildWidget.IsValid())
        {
            ChildWidget->SetOwner(OwnerPanel);
            OwnerPanel->AttachGraphEvents(ChildWidget);
        }
    }
}

void SFSGraph_StateNode::UpdateGraphNode()
{
    // SGraphNode::UpdateGraphNode();
    InputPins.Empty();
    OutputPins.Empty();

    // Reset variables that are going to be exposed, in case we are refreshing an already setup node.
    RightNodeBox.Reset();
    LeftNodeBox.Reset();

    TSharedPtr<SVerticalBox> MainVerticalBox;

    if (ConditionBox.IsValid())
    {
        ConditionBox->ClearChildren();
    }
    else
    {
        SAssignNew(ConditionBox, SVerticalBox);
    }
    if (ServiceBox.IsValid())
    {
        ServiceBox->ClearChildren();
    }
    else
    {
        SAssignNew(ServiceBox, SVerticalBox);
    }
    if (ActionBox.IsValid())
    {
        ActionBox->ClearChildren();
    }
    else
    {
        SAssignNew(ActionBox, SVerticalBox);
    }

    UFSGraph_StateNode* FSMNode = Cast<UFSGraph_StateNode>(GraphNode);
    if (FSMNode)
    {
        for (int i = 0; i < FSMNode->Actions.Num(); ++i)
        {
            if (FSMNode->Actions[i])
            {
                TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(FSMNode->Actions[i]);
                if (OwnerGraphPanelPtr.IsValid())
                {
                    NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
                    OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
                }
                AddAction(NewNode);
                NewNode->UpdateGraphNode();
            }
        }
        for (int i = 0; i < FSMNode->Services.Num(); ++i)
        {
            if (FSMNode->Services[i])
            {
                TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(FSMNode->Services[i]);
                if (OwnerGraphPanelPtr.IsValid())
                {
                    NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
                    OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
                }
                AddService(NewNode);
                NewNode->UpdateGraphNode();
            }
        }
        for (int i = 0; i < FSMNode->Conditions.Num(); ++i)
        {
            if (FSMNode->Conditions[i])
            {
                TSharedPtr<SGraphNode> NewNode = FNodeFactory::CreateNodeWidget(FSMNode->Conditions[i]);
                if (OwnerGraphPanelPtr.IsValid())
                {
                    NewNode->SetOwner(OwnerGraphPanelPtr.Pin().ToSharedRef());
                    OwnerGraphPanelPtr.Pin()->AttachGraphEvents(NewNode);
                }
                AddCondition(NewNode);
                NewNode->UpdateGraphNode();
            }
        }
        // TODO:: 添加其他子节点
        // TODO:: 目前添加子节点无法正确显示
    }

    TSharedPtr<SNodeTitle> NodeTitle = SNew(SNodeTitle, GraphNode);

    TSharedPtr<SWidget> TitleAreaWidget  = CreateTitleWidget(NodeTitle);
    TSharedPtr<SWidget> AppendAreaWidget = CreateNodeAppendArea();
    TSharedPtr<SWidget> CenterAreaWidget = CreateNodeContentArea();

    if (SWidget::GetToolTip().IsValid() == false)
    {
        TSharedRef<SToolTip> DefaultToolTip = IDocumentation::Get()->CreateToolTip(TAttribute<FText>(this, &SGraphNode::GetNodeTooltip), nullptr, GraphNode->GetDocumentationLink(), GraphNode->GetDocumentationExcerptName());
        SetToolTip(DefaultToolTip);
    }

    // Setup a meta tag for this node
    FGraphNodeMetaData TagMeta(TEXT("Graphnode"));
    PopulateMetaTag(&TagMeta);

    TSharedPtr<SVerticalBox> InnerVerticalBox = SNew(SVerticalBox)
                                              // 节点标题
                                              + SVerticalBox::Slot()
                                                    .AutoHeight()
                                                    .HAlign(HAlign_Fill)
                                                        [TitleAreaWidget.ToSharedRef()]
                                              // 附加内容
                                              + SVerticalBox::Slot()
                                                    .AutoHeight()
                                                    .HAlign(HAlign_Fill)
                                                        [AppendAreaWidget.ToSharedRef()]
                                              // 主体内容区域
                                              + SVerticalBox::Slot()
                                                    .AutoHeight()
                                                    .HAlign(HAlign_Fill)
                                                        [CenterAreaWidget.ToSharedRef()];
    this->ContentScale.Bind(this, &SGraphNode::GetContentScale);

    // 获得节点内容槽
    this->GetOrAddSlot(ENodeZone::Center)
        .HAlign(HAlign_Center)
        .VAlign(VAlign_Center)
            [SAssignNew(MainVerticalBox, SVerticalBox)
                + SVerticalBox::Slot()
                    .AutoHeight()
                        [SNew(SOverlay)
                                .AddMetaData<FGraphNodeMetaData>(TagMeta)
                            + SOverlay::Slot()
                                .Padding(Settings->GetNonPinNodeBodyPadding())
                                    [SNew(SImage)
                                            .Image(GetNodeBodyBrush())
                                            .ColorAndOpacity(this, &SGraphNode::GetNodeBodyColor)]
                            + SOverlay::Slot()
                                [InnerVerticalBox.ToSharedRef()]]];

    CreateBelowWidgetControls(MainVerticalBox);
    CreatePinWidgets();
    CreateInputSideAddButton(LeftNodeBox);
    CreateOutputSideAddButton(RightNodeBox);
    CreateBelowPinControls(InnerVerticalBox);
    CreateAdvancedViewArrow(InnerVerticalBox);
}

void SFSGraph_StateNode::CreatePinWidgets()
{
    SFSGraphNodeBase::CreatePinWidgets();
}

TSharedPtr<SGraphPin> SFSGraph_StateNode::CreatePinWidget(UEdGraphPin* Pin) const
{
    return SNew(SGraphPin_FSM, Pin)
        .ToolTipText(this, &SFSGraph_StateNode::GetPinTooltip, Pin);
}

TSharedPtr<SToolTip> SFSGraph_StateNode::GetComplexTooltip()
{
    return SGraphNode::GetComplexTooltip();
}

void SFSGraph_StateNode::GetOverlayBrushes(bool bSelected, const FVector2D WidgetSize,
    TArray<FOverlayBrushInfo>& Brushes) const
{
    SGraphNode::GetOverlayBrushes(bSelected, WidgetSize, Brushes);
}

TArray<FOverlayWidgetInfo> SFSGraph_StateNode::GetOverlayWidgets(bool bSelected, const FVector2D& WidgetSize) const
{
    return SGraphNode::GetOverlayWidgets(bSelected, WidgetSize);
}

TSharedRef<SGraphNode> SFSGraph_StateNode::GetNodeUnderMouse(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
    return SGraphNode::GetNodeUnderMouse(MyGeometry, MouseEvent);
}

void SFSGraph_StateNode::MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty)
{
    SGraphNode::MoveTo(NewPosition, NodeFilter, bMarkDirty);
}

FReply SFSGraph_StateNode::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
    return SGraphNode::OnMouseButtonDown(MyGeometry, MouseEvent);
}

FString SFSGraph_StateNode::GetNodeComment() const
{
    return "Test Node Comment";
}

void SFSGraph_StateNode::AddPin(const TSharedRef<SGraphPin>& PinToAdd)
{
    PinToAdd->SetOwner(SharedThis(this));

    const UEdGraphPin* PinObj             = PinToAdd->GetPinObj();
    const bool         bAdvancedParameter = (PinObj != nullptr) && PinObj->bAdvancedView;
    if (bAdvancedParameter)
    {
        PinToAdd->SetVisibility(TAttribute<EVisibility>(PinToAdd, &SGraphPin::IsPinVisibleAsAdvanced));
    }

    if (PinToAdd->GetDirection() == EGPD_Input)
    {
        LeftNodeBox->AddSlot()
            .HAlign(HAlign_Left)
            .VAlign(VAlign_Fill)
            // .Padding(Settings->GetInputPinPadding())
            .Padding(FMargin(2.f, 5.f))
                [PinToAdd];
        InputPins.Add(PinToAdd);
    }
    else // Direction == EEdGraphPinDirection::EGPD_Output
    {
        RightNodeBox->AddSlot()
            .HAlign(HAlign_Right)
            .VAlign(VAlign_Fill)
            // .Padding(Settings->GetInputPinPadding())
            .Padding(FMargin(2.f, 5.f))
                [PinToAdd];
        OutputPins.Add(PinToAdd);
    }
}

void SFSGraph_StateNode::AddAction(TSharedPtr<SGraphNode> ActionWidget)
{
    ActionBox->AddSlot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
            [ActionWidget.ToSharedRef()];

    ActionWidgets.Add(ActionWidget);
    SubNodes.Add(ActionWidget);
}

void SFSGraph_StateNode::AddService(TSharedPtr<SGraphNode> ServiceWidget)
{
    ServiceBox->AddSlot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
            [ServiceWidget.ToSharedRef()];

    ServiceWidgets.Add(ServiceWidget);
    SubNodes.Add(ServiceWidget);
}

void SFSGraph_StateNode::AddCondition(TSharedPtr<SGraphNode> ConditionWidget)
{
    ConditionBox->AddSlot()
        .AutoHeight()
        .HAlign(HAlign_Fill)
            [ConditionWidget.ToSharedRef()];

    ConditionWidgets.Add(ConditionWidget);
    SubNodes.Add(ConditionWidget);
}

TSharedPtr<SWidget> SFSGraph_StateNode::CreateNodeAppendArea()
{
    return SNew(SVerticalBox)
         + SVerticalBox::Slot()
               [SNew(SBorder)
                       .HAlign(HAlign_Fill)
                           [ServiceBox.ToSharedRef()]];
}

TSharedRef<SWidget> SFSGraph_StateNode::CreateNodeContentArea()
{
    return SNew(SHorizontalBox)
         + SHorizontalBox::Slot()
               .AutoWidth()
               .Padding(FMargin(0, 10.f))
                   [
                       // 输入引脚
                       SAssignNew(LeftNodeBox, SVerticalBox)]
         + SHorizontalBox::Slot()
               .HAlign(HAlign_Fill)
               .Padding(5.f)
                   [SNew(SBox)
                           .MinDesiredWidth(100.f)
                           .MinDesiredHeight(100.f)
                               [SNew(SBorder)
                                       .BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
                                       .BorderBackgroundColor(FSlateColor(FLinearColor(0.2f, 0.2f, 0.2f)))
                                           [
                                               // 条件框
                                               ConditionBox.ToSharedRef()]]]
         + SHorizontalBox::Slot()
               .HAlign(HAlign_Fill)
               .Padding(5.f)
                   [SNew(SBox)
                           .MinDesiredWidth(100.f)
                           .MinDesiredHeight(100.f)
                               [SNew(SBorder)
                                       .BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
                                       .BorderBackgroundColor(FSlateColor(FLinearColor(0.2f, 0.2f, 0.2f)))
                                           [
                                               // 行为列表
                                               ActionBox.ToSharedRef()]]]
         + SHorizontalBox::Slot()
               .AutoWidth()
               .Padding(FMargin(0, 10.f))
                   [
                       // 输出引脚
                       SAssignNew(RightNodeBox, SVerticalBox)];
}

TSharedRef<SWidget> SFSGraph_StateNode::CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle)
{
    TSharedRef<SWidget> TitleWidget = SNew(SOverlay)
                                    + SOverlay::Slot()
                                          [SNew(SImage)
                                                  .Image(FEditorStyle::GetBrush("Graph.Node.TitleGloss"))
                                                  .ColorAndOpacity(this, &SGraphNode::GetNodeTitleIconColor)]
                                    + SOverlay::Slot()
                                          .HAlign(HAlign_Fill)
                                          .VAlign(VAlign_Center)
                                              [SNew(SBorder)
                                                      .BorderImage(FEditorStyle::GetBrush("Graph.Node.ColorSpill"))
                                                      // The extra margin on the right
                                                      // is for making the color spill stretch well past the node title
                                                      .Padding(FMargin(10, 5, 10, 3))
                                                      .BorderBackgroundColor(this, &SGraphNode::GetNodeTitleColor)
                                                          [SNew(SHorizontalBox)
                                                              + SHorizontalBox::Slot()
                                                                  .HAlign(HAlign_Fill)
                                                                      [SNew(SVerticalBox)
                                                                          + SVerticalBox::Slot()
                                                                              .HAlign(HAlign_Center)
                                                                              .AutoHeight()
                                                                                  [SAssignNew(InlineEditableText, SInlineEditableTextBlock)
                                                                                          .Style(FEditorStyle::Get(), "Graph.Node.NodeTitleInlineEditableText")
                                                                                          .Text(this, &SFSGraphNodeBase::GetNodeName)
                                                                                          .IsReadOnly(true)]]]]
                                    + SOverlay::Slot()
                                          .VAlign(VAlign_Top)
                                              [SNew(SBorder)
                                                      .Visibility(EVisibility::HitTestInvisible)
                                                      .BorderImage(FEditorStyle::GetBrush("Graph.Node.TitleHighlight"))
                                                      .BorderBackgroundColor(this, &SGraphNode::GetNodeTitleIconColor)
                                                          [SNew(SSpacer)
                                                                  .Size(FVector2D(20, 20))]];

    InlineEditableText->SetColorAndOpacity(TAttribute<FLinearColor>::Create(TAttribute<FLinearColor>::FGetter::CreateSP(this, &SGraphNode::GetNodeTitleTextColor)));

    return SNew(SLevelOfDetailBranchNode)
        .UseLowDetailSlot(this, &SFSGraph_StateNode::UseLowDetailNodeTitles)
        .LowDetail()
            [SNew(SBorder)
                    .BorderImage(FEditorStyle::GetBrush("Graph.Node.ColorSpill"))
                    .Padding(FMargin(75.0f, 22.0f)) // Saving enough space for a 'typical' title so the transition isn't quite so abrupt
                    .BorderBackgroundColor(this, &SGraphNode::GetNodeTitleColor)]
        .HighDetail()
            [TitleWidget];
}

bool SFSGraph_StateNode::UseLowDetailNodeTitles() const
{
    return SGraphNode::UseLowDetailNodeTitles();
}

FSlateColor SFSGraph_StateNode::GetBorderBackgroundColor() const
{
    return FSlateColor(FLinearColor(0.0f, 0.0f, 0.0f));
}

FText SFSGraph_StateNode::GetPinTooltip(UEdGraphPin* Pin) const
{
    return Pin ? /*Pin->bAllowFriendlyName ? Pin->PinFriendlyName :*/ FText::FromName(Pin->PinName)
               : FText::FromString("None Pin");
}

void SGraphPin_FSM::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
    SGraphPin::Construct(SGraphPin::FArguments(), InPin);

    this->SetCursor(EMouseCursor::Default);

    bShowLabel = true;

    GraphPinObj = InPin;
    check(GraphPinObj != NULL);

    const UEdGraphSchema* Schema = GraphPinObj->GetSchema();
    check(Schema);

    SBorder::Construct(SBorder::FArguments()
            .BorderImage(this, &SGraphPin_FSM::GetPinBorder)
            .BorderBackgroundColor(this, &SGraphPin_FSM::GetPinColor)
            .OnMouseButtonDown(this, &SGraphPin_FSM::OnPinMouseDown)
            .Cursor(this, &SGraphPin_FSM::GetPinCursor)
            .Padding(FMargin(6.0f)));
}

TSharedRef<SWidget> SGraphPin_FSM::GetDefaultValueWidget()
{
    return SNew(STextBlock);
}

FSlateColor SGraphPin_FSM::GetPinColor() const
{
    UEdGraphPin* GraphPin = GetPinObj();
    if (GraphPin && !GraphPin->IsPendingKill())
    {
        if (GraphPin->bIsDiffing)
        {
            return FSlateColor(FLinearColor(0.9f, 0.2f, 0.15f));
        }
        if (GraphPin->bOrphanedPin)
        {
            return FSlateColor(FLinearColor::Red);
        }
    }
    else
    {
        return FSlateColor(FLinearColor::Yellow);
    }
    return FSlateColor(IsHovered() ? FLinearColor(1.f, 1.f, 0, 0.5f) : FLinearColor(0.5f, 0.5f, 0.5f, 0.5));
}

const FSlateBrush* SGraphPin_FSM::GetPinBorder() const
{
    return FEditorStyle::GetBrush(TEXT("Graph.StateNode.Body"));
}

