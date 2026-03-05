// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FlowStatePluginEditorTarget : TargetRules
{
	public FlowStatePluginEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "FlowStatePlugin" });
	}
}