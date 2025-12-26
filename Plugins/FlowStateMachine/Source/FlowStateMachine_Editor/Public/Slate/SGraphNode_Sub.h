#pragma once

#include "SGraphNode.h"

class UFSMGraphSubNode;

class FLOWSTATEMACHINE_EDITOR_API SGraphNode_Sub : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SGraphNode_Sub)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphSubNode* InGraphNode);
	
	virtual FString GetNodeComment() const override;
	
};
