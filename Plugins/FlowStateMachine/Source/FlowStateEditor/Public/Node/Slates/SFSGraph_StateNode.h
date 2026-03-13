#pragma once

#include "SFSGraphNodeBase.h"
#include "SGraphNode.h"
#include "SGraphPin.h"
#include "Node/FSGraphSubNode.h"

class UFSGraphNode;

class FLOWSTATEEDITOR_API SFSGraph_StateNode : public SFSGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSGraph_StateNode)
        {
        }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode);

    // SGraphNode interface
    virtual FReply OnDragOver(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
    virtual FReply OnDrop(const FGeometry& MyGeometry, const FDragDropEvent& DragDropEvent) override;
    virtual void SetOwner(const TSharedRef<SGraphPanel>& OwnerPanel) override;
    virtual void UpdateGraphNode() override;
    virtual void CreatePinWidgets() override;
    virtual TSharedPtr<SToolTip> GetComplexTooltip() override;
    virtual void GetOverlayBrushes(bool bSelected, const FVector2D WidgetSize,
                                   TArray<FOverlayBrushInfo>& Brushes) const override;
    virtual TArray<FOverlayWidgetInfo> GetOverlayWidgets(bool bSelected, const FVector2D& WidgetSize) const override;
    virtual TSharedRef<SGraphNode>
    GetNodeUnderMouse(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
    virtual void MoveTo(const FVector2D& NewPosition, FNodeSet& NodeFilter, bool bMarkDirty = true) override;
    virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
    virtual FString GetNodeComment() const override;
    virtual void AddPin(const TSharedRef<SGraphPin>& PinToAdd) override;
    // End of SGraphNode interface

    /** 添加行为节点的控件到该节点内 */
    void AddAction(TSharedPtr<SGraphNode> ActionWidget);

    /** 添加服务节点的控件到该节点内 */
    void AddService(TSharedPtr<SGraphNode> ServiceWidget);

    /** 添加条件节点的控件到该节点内 */
    void AddCondition(TSharedPtr<SGraphNode> ConditionWidget);

protected:
    virtual TSharedRef<SWidget> CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle) override;
    virtual TSharedPtr<SWidget> CreateNodeAppendArea();
    virtual TSharedRef<SWidget> CreateNodeContentArea() override;
    virtual TSharedPtr<SGraphPin> CreatePinWidget(UEdGraphPin* Pin) const override;

    virtual bool UseLowDetailNodeTitles() const override;

    virtual FSlateColor GetBorderBackgroundColor() const;

    FText GetPinTooltip(UEdGraphPin* Pin) const;

private:
    TSharedPtr<SVerticalBox> ActionBox;
    TSharedPtr<SVerticalBox> ServiceBox;
    TSharedPtr<SVerticalBox> ConditionBox;

    TArray<TSharedPtr<SGraphNode>> ActionWidgets;
    TArray<TSharedPtr<SGraphNode>> ServiceWidgets;
    TArray<TSharedPtr<SGraphNode>> ConditionWidgets;

    /** 统计所有子节点 */
    TArray<TSharedPtr<SGraphNode>> SubNodes;
};

class FLOWSTATEEDITOR_API SGraphPin_FSM : public SGraphPin
{
public:
    SLATE_BEGIN_ARGS(SGraphPin_FSM)
        {
        }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UEdGraphPin* InPin);

protected:
    //~ Begin SGraphPin Interface
    virtual TSharedRef<SWidget> GetDefaultValueWidget() override;
    virtual FSlateColor GetPinColor() const override;
    //~ End SGraphPin Interface
    const FSlateBrush* GetPinBorder() const;
};
