using UnrealBuildTool;

public class FlowStateMachine_EditorModule : ModuleRules
{
    public FlowStateMachine_EditorModule(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        
        PublicIncludePaths.AddRange(new string[]
        {
        });

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "FlowStateMachine",
            }
        );

        PrivateDependencyModuleNames.AddRange(
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
    }
}