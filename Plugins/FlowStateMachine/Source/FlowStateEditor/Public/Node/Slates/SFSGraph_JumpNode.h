#pragma once

#include "SFSGraphNodeBase.h"
#include "SGraphNode.h"

class UFSGraphNode;

class FLOWSTATEEDITOR_API SFSGraph_JumpStartNode : public SFSGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSGraph_JumpStartNode)
        {
        }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode);

    virtual FString GetNodeComment() const override;

protected:
    // SGraphNode interface
    virtual TSharedRef<SWidget> CreateNodeContentArea() override;
    // End of SGraphNode interface
};

class FLOWSTATEEDITOR_API SFSGraph_JumpToNode : public SFSGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSGraph_JumpToNode)
        {
        }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UFSGraphNode* InGraphNode);
    virtual TSharedRef<SWidget> CreateTitleWidget(TSharedPtr<SNodeTitle> NodeTitle) override;

    virtual FString GetNodeComment() const override;

protected:
    // SGraphNode interface
    virtual TSharedRef<SWidget> CreateNodeContentArea() override;
    // End of SGraphNode interface
};
