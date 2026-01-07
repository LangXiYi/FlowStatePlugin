#pragma once

struct FCompareNodeYLocation
{
	FORCEINLINE bool operator()(const UEdGraphPin& A, const UEdGraphPin& B) const
	{
		const UEdGraphNode* NodeA = A.GetOwningNode();
		const UEdGraphNode* NodeB = B.GetOwningNode();

		if (NodeA->NodePosY == NodeB->NodePosY)
		{
			return NodeA->NodePosX < NodeB->NodePosX;
		}

		return NodeA->NodePosY < NodeB->NodePosY;
	}
};

enum class EFSMSubNodeType : uint8
{
	None = 0,
	Condition,
	Action,
	Service,
};