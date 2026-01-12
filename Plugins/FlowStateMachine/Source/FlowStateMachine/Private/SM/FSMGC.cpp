#include "SM/FSMGC.h"

AActor* FSMGC::FindByCache(FName Name, TSubclassOf<AActor> Type) const
{
	return nullptr;
}

void FSMGC::ClearAllCache()
{
}

FText FSMGC::Debug_GetCacheInfo() const
{
	FTextFormat Format = FTextFormat::FromString(
		"==== Cache Info ====\n"
		"\tStatic/Hidden/Kill Actors ({StaticActors}/{HiddenActors}/{KillActors})\n"
		"\tStatic/Hidden/Kill Widgets ({StaticWidgets}/{HiddenWidgets}/{KillWidgets})\n"
		"\tStatic/Hidden/Kill SubLevels ({StaticLevels}/{HiddenSubLevels}/{KillSubLevels})\n");
	FFormatNamedArguments Args;
	Args.Add("StaticActors", Static_Actors.Num());
	Args.Add("HiddenActors", Hidden_Actors.Num());
	Args.Add("KillActors", Kill_Actors.Num());
	Args.Add("StaticWidgets", Static_Widgets.Num());
	Args.Add("HiddenWidgets", Hidden_Widgets.Num());
	Args.Add("KillWidgets", Kill_Widgets.Num());
	Args.Add("StaticLevels", Static_SubLevels.Num());
	Args.Add("HiddenSubLevels", Hidden_SubLevels.Num());
	Args.Add("KillSubLevels", Kill_SubLevels.Num());
	return FText::Format(Format, Args);
}
