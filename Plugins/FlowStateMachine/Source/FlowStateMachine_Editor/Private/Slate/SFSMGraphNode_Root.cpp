#include "Slate/SFSMGraphNode_Root.h"
#include "Node/FSMGraphNode.h"

void SFSMGraphNode_Root::Construct(const FArguments& InArgs, UFSMGraphNode* InGraphNode)
{
	GraphNode = InGraphNode;

	this->SetCursor(EMouseCursor::CardinalCross);

	this->UpdateGraphNode();
}

FString SFSMGraphNode_Root::GetNodeComment() const
{
	return TEXT("This is a root node");
}

TSharedRef<SWidget> SFSMGraphNode_Root::CreateNodeContentArea()
{
	return SNew(SBorder)
			.BorderImage(FEditorStyle::GetBrush("NoBorder"))
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(FMargin(0, 3))
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.FillWidth(1.0f)
				[
					// LEFT
					SAssignNew(LeftNodeBox, SVerticalBox)
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.Padding(10)
				[
					SNew(SImage)
					// TODO::为根节点使用自定义的图标
					.Image(FEditorStyle::GetBrush("BTEditor.SwitchToBehaviorTreeMode"))
				]
				+SHorizontalBox::Slot()
				.AutoWidth()
				.HAlign(HAlign_Right)
				.VAlign(VAlign_Center)
				[
					// RIGHT
					SAssignNew(RightNodeBox, SVerticalBox)
				]
			];
}
