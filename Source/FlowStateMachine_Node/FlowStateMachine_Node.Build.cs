using UnrealBuildTool;

public class FlowStateMachine_Node : ModuleRules
{
    public FlowStateMachine_Node(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "FlowStateMachine",
                "FlowStateMachine_Widget"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "UnrealEd",
                "GraphEditor",
                "BlueprintGraph",
                "KismetCompiler", 
                "GameplayTags",
                "UMG"
            }
        );
        /*
         *
         * PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "GameplayTags",
                "FlowStateMachine",
                "UnrealEd",
                "GraphEditor",
                "BlueprintGraph",
                "KismetCompiler",
                "UMG",
                "AssetTools",
                "Kismet"
            }
        );
         */
    }
}