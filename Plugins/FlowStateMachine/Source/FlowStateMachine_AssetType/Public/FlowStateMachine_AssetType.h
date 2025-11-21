#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IAssetTypeActions;

class FFlowStateMachine_AssetTypeModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

protected:
    void RegisterAssetTypeAction(class IAssetTools& AssetTools, TSharedRef<IAssetTypeActions> ActionPtr);
    
protected:
    TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};
