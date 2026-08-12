// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Utility/FSMUtility.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMUtility() {}
// Cross Module References
	FLOWSTATEMACHINE_API UFunction* Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UEnum* Z_Construct_UEnum_FlowStateMachine_EFlowStateLifetime();
	FLOWSTATEMACHINE_API UScriptStruct* Z_Construct_UScriptStruct_FStateChildNodeHelper();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNode_NoRegister();
	FLOWSTATEMACHINE_API UScriptStruct* Z_Construct_UScriptStruct_FStatePinInfo();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_FlowStateMachine, nullptr, "StateExecuteDelegate__DelegateSignature", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00120000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_FlowStateMachine_StateExecuteDelegate__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	static UEnum* EFlowStateLifetime_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_FlowStateMachine_EFlowStateLifetime, Z_Construct_UPackage__Script_FlowStateMachine(), TEXT("EFlowStateLifetime"));
		}
		return Singleton;
	}
	template<> FLOWSTATEMACHINE_API UEnum* StaticEnum<EFlowStateLifetime>()
	{
		return EFlowStateLifetime_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EFlowStateLifetime(EFlowStateLifetime_StaticEnum, TEXT("/Script/FlowStateMachine"), TEXT("EFlowStateLifetime"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_FlowStateMachine_EFlowStateLifetime_Hash() { return 3345543810U; }
	UEnum* Z_Construct_UEnum_FlowStateMachine_EFlowStateLifetime()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EFlowStateLifetime"), 0, Get_Z_Construct_UEnum_FlowStateMachine_EFlowStateLifetime_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EFlowStateLifetime::None", (int64)EFlowStateLifetime::None },
				{ "EFlowStateLifetime::Static", (int64)EFlowStateLifetime::Static },
				{ "EFlowStateLifetime::Kill", (int64)EFlowStateLifetime::Kill },
				{ "EFlowStateLifetime::Hidden", (int64)EFlowStateLifetime::Hidden },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "Hidden.Comment", "// \xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe7\xbb\x93\xe6\x9d\x9f\xe5\x90\x8e\xe9\x9a\x90\xe8\x97\x8f\n" },
				{ "Hidden.Name", "EFlowStateLifetime::Hidden" },
				{ "Hidden.ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe7\xbb\x93\xe6\x9d\x9f\xe5\x90\x8e\xe9\x9a\x90\xe8\x97\x8f" },
				{ "Kill.Comment", "// \xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe7\xbb\x93\xe6\x9d\x9f\xe5\x90\x8e\xe6\xad\xbb\xe4\xba\xa1\n" },
				{ "Kill.Name", "EFlowStateLifetime::Kill" },
				{ "Kill.ToolTip", "\xe5\xbd\x93\xe5\x89\x8d\xe7\x8a\xb6\xe6\x80\x81\xe7\xbb\x93\xe6\x9d\x9f\xe5\x90\x8e\xe6\xad\xbb\xe4\xba\xa1" },
				{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
				{ "None.Name", "EFlowStateLifetime::None" },
				{ "Static.Comment", "// \xe9\x95\xbf\xe6\x9c\x9f\xe5\xad\x98\xe5\x9c\xa8\n" },
				{ "Static.Name", "EFlowStateLifetime::Static" },
				{ "Static.ToolTip", "\xe9\x95\xbf\xe6\x9c\x9f\xe5\xad\x98\xe5\x9c\xa8" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_FlowStateMachine,
				nullptr,
				"EFlowStateLifetime",
				"EFlowStateLifetime",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FStateChildNodeHelper::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_API uint32 Get_Z_Construct_UScriptStruct_FStateChildNodeHelper_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStateChildNodeHelper, Z_Construct_UPackage__Script_FlowStateMachine(), TEXT("StateChildNodeHelper"), sizeof(FStateChildNodeHelper), Get_Z_Construct_UScriptStruct_FStateChildNodeHelper_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_API UScriptStruct* StaticStruct<FStateChildNodeHelper>()
{
	return FStateChildNodeHelper::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStateChildNodeHelper(FStateChildNodeHelper::StaticStruct, TEXT("/Script/FlowStateMachine"), TEXT("StateChildNodeHelper"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_StaticRegisterNativesFStateChildNodeHelper
{
	FScriptStruct_FlowStateMachine_StaticRegisterNativesFStateChildNodeHelper()
	{
		UScriptStruct::DeferCppStructOps<FStateChildNodeHelper>(FName(TEXT("StateChildNodeHelper")));
	}
} ScriptStruct_FlowStateMachine_StaticRegisterNativesFStateChildNodeHelper;
	struct Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PinName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_PinName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChildNodeInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ChildNodeInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStateChildNodeHelper>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_PinName_MetaData[] = {
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_PinName = { "PinName", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStateChildNodeHelper, PinName), METADATA_PARAMS(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_PinName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_PinName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_ChildNodeInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_ChildNodeInstance = { "ChildNodeInstance", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStateChildNodeHelper, ChildNodeInstance), Z_Construct_UClass_UFSMRuntimeNode_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_ChildNodeInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_ChildNodeInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_PinName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::NewProp_ChildNodeInstance,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
		nullptr,
		&NewStructOps,
		"StateChildNodeHelper",
		sizeof(FStateChildNodeHelper),
		alignof(FStateChildNodeHelper),
		Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStateChildNodeHelper()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStateChildNodeHelper_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StateChildNodeHelper"), sizeof(FStateChildNodeHelper), Get_Z_Construct_UScriptStruct_FStateChildNodeHelper_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStateChildNodeHelper_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStateChildNodeHelper_Hash() { return 228665380U; }
class UScriptStruct* FStatePinInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_API uint32 Get_Z_Construct_UScriptStruct_FStatePinInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FStatePinInfo, Z_Construct_UPackage__Script_FlowStateMachine(), TEXT("StatePinInfo"), sizeof(FStatePinInfo), Get_Z_Construct_UScriptStruct_FStatePinInfo_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_API UScriptStruct* StaticStruct<FStatePinInfo>()
{
	return FStatePinInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FStatePinInfo(FStatePinInfo::StaticStruct, TEXT("/Script/FlowStateMachine"), TEXT("StatePinInfo"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_StaticRegisterNativesFStatePinInfo
{
	FScriptStruct_FlowStateMachine_StaticRegisterNativesFStatePinInfo()
	{
		UScriptStruct::DeferCppStructOps<FStatePinInfo>(FName(TEXT("StatePinInfo")));
	}
} ScriptStruct_FlowStateMachine_StaticRegisterNativesFStatePinInfo;
	struct Z_Construct_UScriptStruct_FStatePinInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PinCategory_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_PinCategory;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PinName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_PinName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatePinInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FStatePinInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinCategory_MetaData[] = {
		{ "Category", "FlowStateCollectData" },
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinCategory = { "PinCategory", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStatePinInfo, PinCategory), METADATA_PARAMS(Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinCategory_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinCategory_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinName_MetaData[] = {
		{ "Category", "FlowStateCollectData" },
		{ "ModuleRelativePath", "Public/Utility/FSMUtility.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinName = { "PinName", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FStatePinInfo, PinName), METADATA_PARAMS(Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FStatePinInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinCategory,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FStatePinInfo_Statics::NewProp_PinName,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FStatePinInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
		nullptr,
		&NewStructOps,
		"StatePinInfo",
		sizeof(FStatePinInfo),
		alignof(FStatePinInfo),
		Z_Construct_UScriptStruct_FStatePinInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatePinInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FStatePinInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FStatePinInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FStatePinInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FStatePinInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("StatePinInfo"), sizeof(FStatePinInfo), Get_Z_Construct_UScriptStruct_FStatePinInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FStatePinInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FStatePinInfo_Hash() { return 4227427224U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
