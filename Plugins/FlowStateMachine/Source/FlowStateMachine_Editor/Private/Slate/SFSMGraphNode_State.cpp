#include "Slate/SFSMGraphNode_State.h"

#include "IDocumentation.h"
#include "NodeFactory.h"
#include "SGraphPanel.h"
#include "SGraphPin.h"
#include "SPinTypeSelector.h"
#include "TutorialMetaData.h"
#include "Node/FSMGraphNode.h"
#include "KismetWidgets/Public/SLevelOfDetailBranchNode.h"
#include "Node/FSMGraphNode_State.h"
#include "Widgets/Text/SInlineEditableTextBlock.h"

void SFSMGraphNode_State::Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode)
{
	GraphNode = InGraphNode;

	SetCursor(EMouseCursor::CardinalCross);
	UpdateGraphNode();
}

void SFSMGraphNode_State::SetOwner(const TSharedRef<SGraphPanel>& OwnerPanel)
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

void SFSMGraphNode_State::UpdateGraphNode()
{
	// SGraphNode::UpdateGraphNode();
	InputPins.Empty();
	OutputPins.Empty();

	// Reset variables that are going to be exposed, in case we are refreshing an already setup node.
	RightNodeBox.Reset();
	LeftNodeBox.Reset();

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

	UFSMGraphNode_State* FSMNode = Cast<UFSMGraphNode_State>(GraphNode);
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
	
	TSharedPtr<SWidget> TitleAreaWidget = CreateTitleWidget(NodeTitle);
	TSharedPtr<SWidget> AppendAreaWidget = CreateNodeAppendArea();
	TSharedPtr<SWidget> CenterAreaWidget = CreateNodeContentArea();

	if (SWidget::GetToolTip().IsValid() == false)
	{
		TSharedRef<SToolTip> DefaultToolTip = IDocumentation::Get()->CreateToolTip( TAttribute< FText >( this, &SGraphNode::GetNodeTooltip ), NULL, GraphNode->GetDocumentationLink(), GraphNode->GetDocumentationExcerptName() );
		SetToolTip(DefaultToolTip);
	}

	// Setup a meta tag for this node
	FGraphNodeMetaData TagMeta(TEXT("Graphnode"));
	PopulateMetaTag(&TagMeta);
	
	TSharedPtr<SVerticalBox> InnerVerticalBox;
	this->ContentScale.Bind( this, &SGraphNode::GetContentScale );
	
	// 获得节点内容槽
	GetOrAddSlot(ENodeZone::Center)
	.HAlign(HAlign_Fill)
	.VAlign(VAlign_Fill)
	[
		SNew(SBorder)
		.AddMetaData<FGraphNodeMetaData>(TagMeta)
		.BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
		.BorderBackgroundColor(this, &SFSMGraphNode_State::GetBorderBackgroundColor)
		.OnMouseButtonDown(this, &SFSMGraphNode_State::OnMouseButtonDown)
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(0.f)
		[
			SNew(SOverlay)

			// 节点内容区域
			+SOverlay::Slot()
			[
				SNew(SVerticalBox)
				// 节点标题
				+SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				[
					TitleAreaWidget.ToSharedRef()
				]
				// 附加内容
				+SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				[
					AppendAreaWidget.ToSharedRef()
				]
				// 主体内容区域
				+SVerticalBox::Slot()
				.AutoHeight()
				.HAlign(HAlign_Fill)
				[
					CenterAreaWidget.ToSharedRef()
				]
			]

			// 拖拽遮罩
			/*+SOverlay::Slot()
			[
				
			]*/
		]
	];

	CreatePinWidgets();
}

TSharedPtr<SGraphPin> SFSMGraphNode_State::CreatePinWidget(UEdGraphPin* Pin) const
{
	return SNew(SGraphPin_FSM, Pin)
		.ToolTipText( this, &SFSMGraphNode_State::GetPinTooltip, Pin);
}

TSharedPtr<SToolTip> SFSMGraphNode_State::GetComplexTooltip()
{
	return SGraphNode::GetComplexTooltip();
}

void SFSMGraphNode_State::GetOverlayBrushes(bool bSelected, const FVector2D WidgetSize,
	TArray<FOverlayBrushInfo>& Brushes) const
{
	SGraphNode::GetOverlayBrushes(bSelected, WidgetSize, Brushes);
}

TArray<FOverlayWidgetInfo> SFSMGraphNode_State::GetOverlayWidgets(bool bSelected, const FVector2D& WidgetSize) const
{
	return SGraphNode::GetOverlayWidgets(bSelected, WidgetSize);
}

TSharedRef<SGraphNode> SFSMGraphNode_State::GetNodeUnderMouse(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return SGraphNode::GetNodeUnderMouse(MyGeometry, MouseEvent);
}

void SFSMGraphNode_State::MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty)
{
	SGraphNode::MoveTo(NewPosition, NodeFilter, bMarkDirty);
}

FReply SFSMGraphNode_State::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	return SGraphNode::OnMouseButtonDown(MyGeometry, MouseEvent);
}

void SFSMGraphNode_State::AddAction(TSharedPtr<SGraphNode> ActionWidget)
{
	ActionBox->AddSlot()
	.AutoHeight()
	.HAlign(HAlign_Fill)
	[
		ActionWidget.ToSharedRef()
	];

	ActionWidgets.Add(ActionWidget);
	SubNodes.Add(ActionWidget);
}

void SFSMGraphNode_State::AddService(TSharedPtr<SGraphNode> ServiceWidget)
{
	ServiceBox->AddSlot()
	.AutoHeight()
	.HAlign(HAlign_Fill)
	[
		ServiceWidget.ToSharedRef()
	];

	ServiceWidgets.Add(ServiceWidget);
	SubNodes.Add(ServiceWidget);
}

void SFSMGraphNode_State::AddCondition(TSharedPtr<SGraphNode> ConditionWidget)
{
	ConditionBox->AddSlot()
	.AutoHeight()
	.HAlign(HAlign_Fill)
	[
		ConditionWidget.ToSharedRef()
	];

	ConditionWidgets.Add(ConditionWidget);
	SubNodes.Add(ConditionWidget);
}

TSharedPtr<SWidget> SFSMGraphNode_State::CreateNodeAppendArea()
{
	return SNew(SVerticalBox)
		+SVerticalBox::Slot()
		[
			SNew(SBorder)
			.HAlign(HAlign_Center)
			[
				ServiceBox.ToSharedRef()
			]
		];
}

TSharedRef<SWidget> SFSMGraphNode_State::CreateNodeContentArea()
{
	return SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		.AutoWidth()
		.HAlign(HAlign_Left)
		[
			// 输入引脚
			SAssignNew(LeftNodeBox, SVerticalBox)
		]
		+SHorizontalBox::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(5.f)
		[
			SNew(SBox)
			.MinDesiredWidth(80.f)
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
				.BorderBackgroundColor(FSlateColor(FLinearColor::Gray))
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					// 条件框
					ConditionBox.ToSharedRef()
				]
			]
		]
		+SHorizontalBox::Slot()
		.Padding(5.f)
		[
			SNew(SBox)
			.MinDesiredWidth(80.f)
			[
				SNew(SBorder)
				.BorderImage(FEditorStyle::GetBrush("Graph.StateNode.Body"))
				.BorderBackgroundColor(FSlateColor(FLinearColor::Gray))
				[
					// 行为列表
					ActionBox.ToSharedRef()
				]
			]
		]
		+SHorizontalBox::Slot()
		.AutoWidth()
		.HAlign(HAlign_Right)
		[
			// 输出引脚
			SAssignNew(RightNodeBox, SVerticalBox)
		];
}

TSharedRef<SWidget> SFSMGraphNode_State::CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle)
{
	TSharedRef<SWidget> TitleWidget = SNew(SOverlay)
		+SOverlay::Slot()
		[
			SNew(SImage)
			.Image( FEditorStyle::GetBrush("Graph.Node.TitleGloss") )
			.ColorAndOpacity( this, &SGraphNode::GetNodeTitleIconColor )
		]
		+SOverlay::Slot()
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Center)
		[
			SNew(SBorder)
			.BorderImage( FEditorStyle::GetBrush("Graph.Node.ColorSpill") )
			// The extra margin on the right
			// is for making the color spill stretch well past the node title
			.Padding( FMargin(10,5,10,3) )
			.BorderBackgroundColor( this, &SGraphNode::GetNodeTitleColor )
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Fill)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					.HAlign(HAlign_Center)
					.AutoHeight()
					[
						SGraphNode::CreateTitleWidget(NodeTitle)
					]
					+ SVerticalBox::Slot()
					.AutoHeight()
					[
						NodeTitle.ToSharedRef()
					]
				]
			]
		]
		+SOverlay::Slot()
		.VAlign(VAlign_Top)
		[
			SNew(SBorder)
			.Visibility(EVisibility::HitTestInvisible)			
			.BorderImage( FEditorStyle::GetBrush( "Graph.Node.TitleHighlight" ) )
			.BorderBackgroundColor( this, &SGraphNode::GetNodeTitleIconColor )
			[
				SNew(SSpacer)
				.Size(FVector2D(20,20))
			]
		];

	InlineEditableText->SetColorAndOpacity(TAttribute<FLinearColor>::Create(TAttribute<FLinearColor>::FGetter::CreateSP(this, &SGraphNode::GetNodeTitleTextColor)));

	return SNew(SLevelOfDetailBranchNode)
		.UseLowDetailSlot(this, &SFSMGraphNode_State::UseLowDetailNodeTitles)
		.LowDetail()
		[
			SNew(SBorder)
			.BorderImage( FEditorStyle::GetBrush("Graph.Node.ColorSpill") )
			.Padding( FMargin(75.0f, 22.0f) ) // Saving enough space for a 'typical' title so the transition isn't quite so abrupt
			.BorderBackgroundColor( this, &SGraphNode::GetNodeTitleColor )
		]
		.HighDetail()
		[
			TitleWidget
		];
}

bool SFSMGraphNode_State::UseLowDetailNodeTitles() const
{
	return SGraphNode::UseLowDetailNodeTitles();
}

FSlateColor SFSMGraphNode_State::GetBorderBackgroundColor() const
{
	return FSlateColor(FLinearColor::Black);
}

FText SFSMGraphNode_State::GetPinTooltip(UEdGraphPin* Pin) const
{
	FText HoverText = FText::GetEmpty();

	check(Pin != nullptr);
	UEdGraphNode* OwningGraphNode = Pin->GetOwningNode();
	if (OwningGraphNode != nullptr)
	{
		FString HoverStr;
		OwningGraphNode->GetPinHoverText(*Pin, /*out*/HoverStr);
		if (!HoverStr.IsEmpty())
		{
			HoverText = FText::FromString(HoverStr);
		}
	}

	return HoverText;
}

void SGraphPin_FSM::Construct(const FArguments& InArgs, UEdGraphPin* InPin)
{
	SGraphPin::Construct(SGraphPin::FArguments(), InPin);

	// Call utility function so inheritors can also call it since arguments can't be passed through
	CachePinIcons();
}

TSharedRef<SWidget> SGraphPin_FSM::GetDefaultValueWidget()
{
	return SGraphPin::GetDefaultValueWidget();
}

const FSlateBrush* SGraphPin_FSM::GetPinIcon() const
{
	const FSlateBrush* Brush = NULL;

	if (IsConnected())
	{
		Brush = IsHovered() ? CachedImg_Pin_ConnectedHovered : CachedImg_Pin_Connected;
	}
	else
	{
		Brush = IsHovered() ? CachedImg_Pin_DisconnectedHovered : CachedImg_Pin_Disconnected;
	}

	return Brush;
}

void SGraphPin_FSM::CachePinIcons()
{
	CachedImg_Pin_ConnectedHovered = FEditorStyle::GetBrush(TEXT("Graph.ExecPin.ConnectedHovered"));
	CachedImg_Pin_Connected = FEditorStyle::GetBrush(TEXT("Graph.ExecPin.Connected"));
	CachedImg_Pin_DisconnectedHovered = FEditorStyle::GetBrush(TEXT("Graph.ExecPin.DisconnectedHovered"));
	CachedImg_Pin_Disconnected = FEditorStyle::GetBrush(TEXT("Graph.ExecPin.Disconnected"));
}