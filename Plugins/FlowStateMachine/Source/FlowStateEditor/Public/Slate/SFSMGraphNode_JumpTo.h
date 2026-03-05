#pragma once

#include "SFSMGraphNodeBase.h"
#include "SGraphNode.h"

class UFSGraphNode;

class FLOWSTATEEDITOR_API SFSMGraphNode_JumpTo : public SFSMGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSMGraphNode_JumpTo)
    {
    }

    SLATE_END_ARGS()

    void                        Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode);
    virtual TSharedRef<SWidget> CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle) override;

    virtual FString GetNodeComment() const override;

protected:
    // SGraphNode interface
    virtual TSharedRef<SWidget> CreateNodeContentArea() override;
    // End of SGraphNode interface
};
