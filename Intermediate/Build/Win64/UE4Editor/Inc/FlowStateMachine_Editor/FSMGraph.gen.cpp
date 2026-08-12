// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Graph/FSMGraph.h"
#include "Serialization/ArchiveUObjectFromStructuredArchive.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMGraph() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraph_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraph();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraph();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_NoRegister();
// End Cross Module References
	void UFSMGraph::StaticRegisterNativesUFSMGraph()
	{
	}
	UClass* Z_Construct_UClass_UFSMGraph_NoRegister()
	{
		return UFSMGraph::StaticClass();
	}
	struct Z_Construct_UClass_UFSMGraph_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ScatteredNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ScatteredNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_ScatteredNodes;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMGraph_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraph,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraph_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Graph/FSMGraph.h" },
		{ "ModuleRelativePath", "Public/Graph/FSMGraph.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes_Inner = { "ScatteredNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMGraphNode_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes_MetaData[] = {
		{ "ModuleRelativePath", "Public/Graph/FSMGraph.h" },
		{ "NativeConstTemplateArg", "" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes = { "ScatteredNodes", nullptr, (EPropertyFlags)0x0020080000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraph, ScatteredNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMGraph_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraph_Statics::NewProp_ScatteredNodes,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMGraph_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMGraph>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMGraph_Statics::ClassParams = {
		&UFSMGraph::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMGraph_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraph_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMGraph_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraph_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMGraph()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMGraph_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMGraph, 4201153496);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UFSMGraph>()
	{
		return UFSMGraph::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMGraph(Z_Construct_UClass_UFSMGraph, &UFSMGraph::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UFSMGraph"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMGraph);
	IMPLEMENT_FSTRUCTUREDARCHIVE_SERIALIZER(UFSMGraph)
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
