#pragma once

#include "SFSGraphNodeBase.h"

class UFSGraphSubNode;

class FLOWSTATEEDITOR_API SFSGraphSubNode : public SFSGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSGraphSubNode)
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
