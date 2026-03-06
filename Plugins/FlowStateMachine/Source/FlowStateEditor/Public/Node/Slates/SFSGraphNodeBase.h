#pragma once

#include "SGraphNode.h"

class UFSGraphNodeBase;

class FLOWSTATEEDITOR_API SFSGraphNodeBase : public SGraphNode
{
public:
    SLATE_BEGIN_ARGS(SFSGraphNodeBase)
    {
    }

    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs, UFSGraphNodeBase* InGraphNode);

    FText GetNodeName() const;

    // TODO::检查错误，若节点存在错误信息，则弹出提示内容
};
