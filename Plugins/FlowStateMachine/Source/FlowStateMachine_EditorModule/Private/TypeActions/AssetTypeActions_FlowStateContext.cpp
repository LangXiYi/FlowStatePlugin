#include "TypeActions/AssetTypeActions_FlowStateContext.h"


void FAssetTypeActions_FlowStateContext::OpenAssetEditor(const TArray<UObject*>& InObjects,
	TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	// todo:: Create My Toolkit
	FAssetTypeActions_Blueprint::OpenAssetEditor(InObjects, EditWithinLevelEditor);
}
