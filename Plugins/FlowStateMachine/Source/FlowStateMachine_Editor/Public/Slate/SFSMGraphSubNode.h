#pragma once

#include "SFSMGraphNodeBase.h"

class UFSMGraphSubNode;

class FLOWSTATEMACHINE_EDITOR_API SFSMGraphSubNode : public SFSMGraphNodeBase
{
public:
	SLATE_BEGIN_ARGS(SFSMGraphSubNode)
		{}
		
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs, UFSMGraphSubNode* InGraphNode);
	
	virtual FString GetNodeComment() const override;

	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual void UpdateGraphNode() override;
};
