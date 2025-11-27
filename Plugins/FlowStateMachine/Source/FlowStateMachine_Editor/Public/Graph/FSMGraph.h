#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FSMGraph.generated.h"

UCLASS()
class FLOWSTATEMACHINE_EDITOR_API UFSMGraph : public UEdGraph
{
	GENERATED_BODY()
	
public:
	virtual void Initialize();
	virtual void OnCreateGraph();
	virtual void OnLoadedGraph();
};

