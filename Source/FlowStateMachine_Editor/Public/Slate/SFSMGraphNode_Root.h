#pragma once

#include "SFSMGraphNodeBase.h"
#include "SGraphNode.h"

class UFSMGraphNode;

class FLOWSTATEMACHINE_EDITOR_API SFSMGraphNode_Root : public SFSMGraphNodeBase
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphNode_Root)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode);
	
	virtual FString GetNodeComment() const override;

protected:
	// SGraphNode interface
	virtual TSharedRef<SWidget> CreateNodeContentArea() override;
	// End of SGraphNode interface
};
