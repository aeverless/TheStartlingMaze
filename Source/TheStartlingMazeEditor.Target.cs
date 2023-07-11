using UnrealBuildTool;
using System.Collections.Generic;

public class TheStartlingMazeEditorTarget : TargetRules
{
	public TheStartlingMazeEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.Add("TheStartlingMaze");
	}
}
