#pragma once

#include "SGraphNode.h"

class UFSMGraphNode;

class FLOWSTATEMACHINE_EDITOR_API SGraphNode_Root : public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SGraphNode_Root)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode);
	
	virtual FString GetNodeComment() const override;

protected:
	// SGraphNode interface
	virtual TSharedRef<SWidget> CreateNodeContentArea() override;
	// End of SGraphNode interface
};
