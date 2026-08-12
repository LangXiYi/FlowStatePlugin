// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/DataFragments/FSMMetaDataFragment.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMMetaDataFragment() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMMetaDataFragment_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMMetaDataFragment();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
// End Cross Module References
	void UFSMMetaDataFragment::StaticRegisterNativesUFSMMetaDataFragment()
	{
	}
	UClass* Z_Construct_UClass_UFSMMetaDataFragment_NoRegister()
	{
		return UFSMMetaDataFragment::StaticClass();
	}
	struct Z_Construct_UClass_UFSMMetaDataFragment_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMMetaDataFragment_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMMetaDataFragment_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * \xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe5\xad\x90\xe7\xb1\xbb\n */" },
		{ "IncludePath", "Data/DataFragments/FSMMetaDataFragment.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/Data/DataFragments/FSMMetaDataFragment.h" },
		{ "ToolTip", "\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe5\xad\x90\xe7\xb1\xbb" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMMetaDataFragment_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMMetaDataFragment>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMMetaDataFragment_Statics::ClassParams = {
		&UFSMMetaDataFragment::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x001010A1u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMMetaDataFragment_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMMetaDataFragment()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMMetaDataFragment_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMMetaDataFragment, 1054450839);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMMetaDataFragment>()
	{
		return UFSMMetaDataFragment::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMMetaDataFragment(Z_Construct_UClass_UFSMMetaDataFragment, &UFSMMetaDataFragment::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMMetaDataFragment"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMMetaDataFragment);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
