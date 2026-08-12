// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Node/Composites/FSMGraphNode_Switch.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMGraphNode_Switch() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Switch_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Switch();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Composites();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
// End Cross Module References
	void UFSMGraphNode_Switch::StaticRegisterNativesUFSMGraphNode_Switch()
	{
	}
	UClass* Z_Construct_UClass_UFSMGraphNode_Switch_NoRegister()
	{
		return UFSMGraphNode_Switch::StaticClass();
	}
	struct Z_Construct_UClass_UFSMGraphNode_Switch_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMGraphNode_Switch_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMGraphNode_Composites,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNode_Switch_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Node/Composites/FSMGraphNode_Switch.h" },
		{ "ModuleRelativePath", "Public/Node/Composites/FSMGraphNode_Switch.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMGraphNode_Switch_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMGraphNode_Switch>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMGraphNode_Switch_Statics::ClassParams = {
		&UFSMGraphNode_Switch::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNode_Switch_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Switch_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMGraphNode_Switch()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMGraphNode_Switch_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMGraphNode_Switch, 1680828265);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UFSMGraphNode_Switch>()
	{
		return UFSMGraphNode_Switch::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMGraphNode_Switch(Z_Construct_UClass_UFSMGraphNode_Switch, &UFSMGraphNode_Switch::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UFSMGraphNode_Switch"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMGraphNode_Switch);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
