using UnrealBuildTool;

public class FlowStateMachine_AssetType : ModuleRules
{
    public FlowStateMachine_AssetType(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "FlowStateMachine",
                "FlowStateMachine_Editor"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "AssetTools", 
                "UnrealEd"
            }
        );
    }
}