#pragma once


#include "CoreMinimal.h"
#include "K2Node.h"
#include "K2Node_ConstructObjectFromClass.h"
#include "K2Node_SpawnAndBindActor.generated.h"


/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_NODE_API UK2Node_SpawnAndBindActor : public UK2Node_ConstructObjectFromClass
{
	GENERATED_BODY()

public:
	//~ Begin UEdGraphNode Interface.
	virtual void AllocateDefaultPins() override;
	virtual void GetPinHoverText(const UEdGraphPin& Pin, FString& HoverTextOut) const override;
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual bool IsCompatibleWithGraph(const UEdGraph* TargetGraph) const override;
	//~ End UEdGraphNode Interface.

	//~ Begin UK2Node Interface
	virtual bool IsNodeSafeToIgnore() const override { return true; }
	virtual void ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins) override;
	virtual void GetNodeAttributes( TArray<TKeyValuePair<FString, FString>>& OutNodeAttributes ) const override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	//~ End UK2Node Interface

	//~ Begin UK2Node_ConstructObjectFromClass Interface
	virtual UClass* GetClassPinBaseClass() const override;
	virtual bool IsSpawnVarPin(UEdGraphPin* Pin) const override;
	virtual FText GetBaseNodeTitle() const override;
	virtual FText GetDefaultNodeTitle() const override;
	virtual FText GetNodeTitleFormat() const override;
	//~ End UK2Node_ConstructObjectFromClass Interface

private:
	/** Get the spawn transform input pin */	
	UEdGraphPin* GetSpawnTransformPin() const;
	/** Get the collision handling method input pin */
	UEdGraphPin* GetCollisionHandlingOverridePin() const;
	/** Get the actor owner pin */
	UEdGraphPin* GetOwnerPin() const;
	/** 获取生命周期的引脚 */
	UEdGraphPin* GetLifetimePin() const;
	/** 获取标签引脚 */
	UEdGraphPin* GetActorTagPin() const;

	void MaybeUpdateCollisionPin(TArray<UEdGraphPin*>& OldPins);
};

