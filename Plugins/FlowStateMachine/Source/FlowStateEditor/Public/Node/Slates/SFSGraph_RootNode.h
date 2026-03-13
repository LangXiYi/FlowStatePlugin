#pragma once

#include "SFSGraphNodeBase.h"
#include "SGraphNode.h"

class UFSGraphNode;

class FLOWSTATEEDITOR_API SFSGraph_RootNode : public SFSGraphNodeBase
{
public:
    SLATE_BEGIN_ARGS(SFSGraph_RootNode)
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
