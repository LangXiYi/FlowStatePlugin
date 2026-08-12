// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Node/Composites/FSMGraphNode_Branch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMGraphNode_Branch() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Branch_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Branch();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Composites();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
// End Cross Module References
	void UFSMGraphNode_Branch::StaticRegisterNativesUFSMGraphNode_Branch()
	{
	}
	UClass* Z_Construct_UClass_UFSMGraphNode_Branch_NoRegister()
	{
		return UFSMGraphNode_Branch::StaticClass();
	}
	struct Z_Construct_UClass_UFSMGraphNode_Branch_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMGraphNode_Branch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMGraphNode_Composites,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNode_Branch_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Node/Composites/FSMGraphNode_Branch.h" },
		{ "ModuleRelativePath", "Public/Node/Composites/FSMGraphNode_Branch.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMGraphNode_Branch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMGraphNode_Branch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMGraphNode_Branch_Statics::ClassParams = {
		&UFSMGraphNode_Branch::StaticClass,
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
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNode_Branch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Branch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMGraphNode_Branch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMGraphNode_Branch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMGraphNode_Branch, 834648060);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UFSMGraphNode_Branch>()
	{
		return UFSMGraphNode_Branch::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMGraphNode_Branch(Z_Construct_UClass_UFSMGraphNode_Branch, &UFSMGraphNode_Branch::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UFSMGraphNode_Branch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMGraphNode_Branch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
