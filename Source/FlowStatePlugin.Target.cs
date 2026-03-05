// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FlowStatePluginTarget : TargetRules
{
	public FlowStatePluginTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange(new[] { "FlowStatePlugin" });
	}
}