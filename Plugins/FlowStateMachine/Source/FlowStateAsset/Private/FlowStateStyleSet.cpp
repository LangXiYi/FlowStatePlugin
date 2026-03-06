#include "FlowStateStyleSet.h"

#include "Interfaces/IPluginManager.h"
FFlowStateStyleSet::FFlowStateStyleSet(const FString& InPluginName)
    : FSlateStyleSet("FlowStateMachine"), PluginName(InPluginName)
{
}
void FFlowStateStyleSet::RegisterAssetThumbnail(const FString& AssetName, const FString& ImageName, const FVector2D& ImageSize)
{
    FString ResourceDir = GetPluginResourceDir();
    if (!ResourceDir.IsEmpty())
    {
        FSlateImageBrush* FlowStateMachineImage = new FSlateImageBrush(ResourceDir + ImageName, ImageSize);
        Set(FName("ClassThumbnail." + AssetName), FlowStateMachineImage);
    }
}

FString FFlowStateStyleSet::GetPluginResourceDir() const
{
    TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(PluginName);
    return Plugin->GetBaseDir() + "/Resources/";
}