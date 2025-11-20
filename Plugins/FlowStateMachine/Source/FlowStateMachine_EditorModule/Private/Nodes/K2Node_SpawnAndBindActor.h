#pragma once


#include "CoreMinimal.h"
#include "K2Node.h"
#include "K2Node_ConstructObjectFromClass.h"
#include "Utility/FlowStateUtility.h"
#include "K2Node_SpawnAndBindActor.generated.h"

BEGIN_NAMESPACE_FSM

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_EDITORMODULE_API UK2Node_SpawnAndBindActor : public UK2Node_ConstructObjectFromClass
{
	GENERATED_BODY()

public:
	UK2Node_SpawnAndBindActor(const FObjectInitializer& ObjectInitializer);

public:
	//~ Begin UEdGraphNode Interface.
	virtual void AllocateDefaultPins() override;
	virtual FLinearColor GetNodeTitleColor() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	virtual bool IsDeprecated() const override { return false; }
	virtual FEdGraphNodeDeprecationResponse GetDeprecationResponse(EEdGraphNodeDeprecationType DeprecationType) const override;
	virtual FSlateIcon GetIconAndTint(FLinearColor& OutColor) const override;
	virtual bool IsCompatibleWithGraph(const UEdGraph* TargetGraph) const override;
	virtual void PostPlacedNewNode() override;
	//~ End UEdGraphNode Interface.

	//~ Begin UObject Interface
	virtual void Serialize(FArchive& Ar) override;
	virtual void PostLoad() override;
	//~ End UObject Interface

	//~ Begin UK2Node Interface
	virtual void ExpandNode(class FKismetCompilerContext& CompilerContext, UEdGraph* SourceGraph) override;
	virtual void ReallocatePinsDuringReconstruction(TArray<UEdGraphPin*>& OldPins) override;
	virtual class FNodeHandlingFunctor* CreateNodeHandler(class FKismetCompilerContext& CompilerContext) const override;
	virtual void GetNodeAttributes(TArray<TKeyValuePair<FString, FString>>& OutNodeAttributes) const override;
	//~ End UK2Node Interface

	virtual void CreatePinsForClass(UClass* InClass, TArray<UEdGraphPin*>* OutClassPins) override;
	virtual bool IsNodeSafeToIgnore() const override { return true; }
	virtual bool IsSpawnVarPin(UEdGraphPin* Pin) const override;
	virtual UClass* GetClassPinBaseClass() const override;

private:
	void FixupScaleMethodPin();

	UEdGraphPin* GetLifetimePin() const;
	UEdGraphPin* GetActorTagPin() const;

	/** Get the spawn transform input pin */	
	UEdGraphPin* GetSpawnTransformPin() const;
	/** Get the collision handling method input pin */
	UEdGraphPin* GetCollisionHandlingOverridePin() const;
	/** Get the collision handling method input pin */
	UEdGraphPin* GetScaleMethodPin() const;
	UEdGraphPin* TryGetScaleMethodPin() const;
	/** Get the actor owner pin */
	UEdGraphPin* GetOwnerPin() const;
	void MaybeUpdateCollisionPin(TArray<UEdGraphPin*>& OldPins);
};

END_NAMESPACE_FSM