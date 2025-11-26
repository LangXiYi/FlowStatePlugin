using UnrealBuildTool;

public class FlowStateMachine_Editor : ModuleRules
{
    public FlowStateMachine_Editor(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core", "FlowStateMachine"
            }
        );

        PrivateDependencyModuleNames.AddRange(
            new string[]
            {
                "CoreUObject",
                "Engine",
                "Slate",
                "SlateCore",
                "Kismet",
                "UnrealEd",
                "PropertyEditor"
            }
        );
    }
}