#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FSlateStyleSet;
class FFSMGraphEditor;
class IFlowStateMachineEditor;

class FFlowStateMachine_EditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual TSharedRef<FFSMGraphEditor> CreateFlowStateMachineEditor( const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UObject* Object );

    TSharedPtr<struct FGraphNodeClassHelper> GetClassCache() { return ClassCache; }

public:
    static const FName FlowStateMachineAppIdentifier;
    
private:
    TSharedPtr<struct FGraphNodeClassHelper> ClassCache;

    TSharedPtr<FSlateStyleSet> StyleSet;
};
