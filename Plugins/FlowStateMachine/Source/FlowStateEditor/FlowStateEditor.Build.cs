using UnrealBuildTool;

public class FlowStateEditor : ModuleRules
{
	public FlowStateEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"FlowStateMachine",
				"FlowStateMachine_Widget"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"Kismet",
				"UnrealEd",
				"PropertyEditor",
				"EditorStyle",
				"AIGraph",
				"ToolMenus",
				"GraphEditor",
				"KismetWidgets",
				"ApplicationCore",
			}
		);
	}
}