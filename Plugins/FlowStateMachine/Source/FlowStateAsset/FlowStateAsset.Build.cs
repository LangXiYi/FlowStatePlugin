using UnrealBuildTool;

public class FlowStateAsset : ModuleRules
{
    public FlowStateAsset(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "FlowStateEditor",
                "FlowStateMachine",
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "Engine",
                "SlateCore",
                "CoreUObject",
                "UnrealEd",
                "AssetTools",
                "Projects",
            }
        );
    }
}