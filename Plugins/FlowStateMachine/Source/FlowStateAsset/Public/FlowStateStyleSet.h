#pragma once
#include "Styling/SlateStyle.h"

class FFlowStateStyleSet : public FSlateStyleSet
{
public:
    FFlowStateStyleSet(const FString& InPluginName);
    
    void RegisterAssetThumbnail(const FString& AssetName,const FString& ImageName, const FVector2D& ImageSize);
    
protected:
    FString PluginName;
    FString GetPluginResourceDir() const;
};
