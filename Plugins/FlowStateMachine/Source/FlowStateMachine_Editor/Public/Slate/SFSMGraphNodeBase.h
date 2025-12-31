#pragma once

#include "SGraphNode.h"

class UFSMGraphNode;

class FLOWSTATEMACHINE_EDITOR_API SFSMGraphNodeBase : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphNodeBase)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode);
	
};
