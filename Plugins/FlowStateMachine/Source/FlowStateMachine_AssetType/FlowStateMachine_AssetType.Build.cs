using UnrealBuildTool;

public class FlowStateMachine_AssetType : ModuleRules
{
	public FlowStateMachine_AssetType(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"FlowStateMachine",
				"FlowStateEditor"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
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