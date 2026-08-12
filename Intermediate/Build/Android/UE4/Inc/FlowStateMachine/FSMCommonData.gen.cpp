// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/FSMCommonData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMCommonData() {}
// Cross Module References
	FLOWSTATEMACHINE_API UScriptStruct* Z_Construct_UScriptStruct_FCommonDataEntry();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonData_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonData();
	ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
// End Cross Module References
class UScriptStruct* FCommonDataEntry::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FLOWSTATEMACHINE_API uint32 Get_Z_Construct_UScriptStruct_FCommonDataEntry_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FCommonDataEntry, Z_Construct_UPackage__Script_FlowStateMachine(), TEXT("CommonDataEntry"), sizeof(FCommonDataEntry), Get_Z_Construct_UScriptStruct_FCommonDataEntry_Hash());
	}
	return Singleton;
}
template<> FLOWSTATEMACHINE_API UScriptStruct* StaticStruct<FCommonDataEntry>()
{
	return FCommonDataEntry::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FCommonDataEntry(FCommonDataEntry::StaticStruct, TEXT("/Script/FlowStateMachine"), TEXT("CommonDataEntry"), false, nullptr, nullptr);
static struct FScriptStruct_FlowStateMachine_StaticRegisterNativesFCommonDataEntry
{
	FScriptStruct_FlowStateMachine_StaticRegisterNativesFCommonDataEntry()
	{
		UScriptStruct::DeferCppStructOps<FCommonDataEntry>(FName(TEXT("CommonDataEntry")));
	}
} ScriptStruct_FlowStateMachine_StaticRegisterNativesFCommonDataEntry;
	struct Z_Construct_UScriptStruct_FCommonDataEntry_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EntryName_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_EntryName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_KeyType_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_KeyType;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCommonDataEntry_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/Data/FSMCommonData.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCommonDataEntry>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_EntryName_MetaData[] = {
		{ "Category", "CommonDataEntry" },
		{ "ModuleRelativePath", "Public/Data/FSMCommonData.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_EntryName = { "EntryName", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCommonDataEntry, EntryName), METADATA_PARAMS(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_EntryName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_EntryName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_KeyType_MetaData[] = {
		{ "Category", "CommonDataEntry" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Data/FSMCommonData.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_KeyType = { "KeyType", nullptr, (EPropertyFlags)0x001200000008001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FCommonDataEntry, KeyType), Z_Construct_UClass_UFSMCommonDataType_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_KeyType_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_KeyType_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCommonDataEntry_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_EntryName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCommonDataEntry_Statics::NewProp_KeyType,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCommonDataEntry_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
		nullptr,
		&NewStructOps,
		"CommonDataEntry",
		sizeof(FCommonDataEntry),
		alignof(FCommonDataEntry),
		Z_Construct_UScriptStruct_FCommonDataEntry_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000005),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCommonDataEntry_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FCommonDataEntry()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FCommonDataEntry_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("CommonDataEntry"), sizeof(FCommonDataEntry), Get_Z_Construct_UScriptStruct_FCommonDataEntry_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FCommonDataEntry_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FCommonDataEntry_Hash() { return 941335036U; }
	void UFSMCommonData::StaticRegisterNativesUFSMCommonData()
	{
	}
	UClass* Z_Construct_UClass_UFSMCommonData_NoRegister()
	{
		return UFSMCommonData::StaticClass();
	}
	struct Z_Construct_UClass_UFSMCommonData_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Keys_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Keys_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_Keys;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMCommonData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDataAsset,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonData_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \xe7\xb1\xbb\xe4\xbc\xbc Blackboard \xe4\xbe\x9b\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xac\xe5\x85\xb1\xe6\x95\xb0\xe6\x8d\xae\n */" },
		{ "IncludePath", "Data/FSMCommonData.h" },
		{ "ModuleRelativePath", "Public/Data/FSMCommonData.h" },
		{ "ToolTip", "\xe7\xb1\xbb\xe4\xbc\xbc Blackboard \xe4\xbe\x9b\xe7\x8a\xb6\xe6\x80\x81\xe6\x9c\xba\xe8\xaf\xbb\xe5\x8f\x96\xe5\x85\xac\xe5\x85\xb1\xe6\x95\xb0\xe6\x8d\xae" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys_Inner = { "Keys", nullptr, (EPropertyFlags)0x0000008000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FCommonDataEntry, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys_MetaData[] = {
		{ "Category", "FSMCommonData" },
		{ "ModuleRelativePath", "Public/Data/FSMCommonData.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys = { "Keys", nullptr, (EPropertyFlags)0x0010008000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMCommonData, Keys), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMCommonData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonData_Statics::NewProp_Keys,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMCommonData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMCommonData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMCommonData_Statics::ClassParams = {
		&UFSMCommonData::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMCommonData_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonData_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMCommonData_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMCommonData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMCommonData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMCommonData, 3910487167);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMCommonData>()
	{
		return UFSMCommonData::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMCommonData(Z_Construct_UClass_UFSMCommonData, &UFSMCommonData::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMCommonData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMCommonData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
