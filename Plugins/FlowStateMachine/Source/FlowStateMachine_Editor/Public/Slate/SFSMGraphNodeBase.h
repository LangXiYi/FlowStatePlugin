#pragma once

#include "SGraphNode.h"

class UFSMGraphNodeBase;

class FLOWSTATEMACHINE_EDITOR_API SFSMGraphNodeBase : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphNodeBase)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphNodeBase* InGraphNode);

	FText GetNodeName() const;

	// TODO::检查错误，若节点存在错误信息，则弹出提示内容
};
