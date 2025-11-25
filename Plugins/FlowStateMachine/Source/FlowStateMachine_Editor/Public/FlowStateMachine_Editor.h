#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FFlowStateMachineEditor;
class IFlowStateMachineEditor;

class FFlowStateMachine_EditorModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

    virtual TSharedRef<FFlowStateMachineEditor> CreateFlowStateMachineEditor( const EToolkitMode::Type Mode, const TSharedPtr< class IToolkitHost >& InitToolkitHost, class UObject* Object );


public:
    static const FName FlowStateMachineAppIdentifier;
    
protected:
};
