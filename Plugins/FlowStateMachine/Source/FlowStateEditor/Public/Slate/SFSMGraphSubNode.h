#pragma once

#include "SFSMGraphNodeBase.h"

class UFSGraphSubNode;

class FLOWSTATEEDITOR_API SFSMGraphSubNode : public SFSMGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSMGraphSubNode)
    {
    }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UFSGraphSubNode* InGraphNode);

    virtual FString GetNodeComment() const override;

    virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

    virtual void UpdateGraphNode() override;

protected:
    virtual TSharedRef<SWidget> CreateNodeContentArea() override;

    FSlateColor GetBorderBackgroundColor() const;
};
