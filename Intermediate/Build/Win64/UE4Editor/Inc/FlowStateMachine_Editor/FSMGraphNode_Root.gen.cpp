// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Node/FSMGraphNode_Root.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMGraphNode_Root() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Root_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode_Root();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNode();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonData_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister();
// End Cross Module References
	void UFSMGraphNode_Root::StaticRegisterNativesUFSMGraphNode_Root()
	{
	}
	UClass* Z_Construct_UClass_UFSMGraphNode_Root_NoRegister()
	{
		return UFSMGraphNode_Root::StaticClass();
	}
	struct Z_Construct_UClass_UFSMGraphNode_Root_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CommonData_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CommonData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WidgetLayerManagerClass_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_WidgetLayerManagerClass;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMGraphNode_Root_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNode_Root_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \xe9\xbb\x98\xe8\xae\xa4\xe7\x9a\x84\xe5\x9b\xbe\xe8\xa1\xa8\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9\n */" },
		{ "IncludePath", "Node/FSMGraphNode_Root.h" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNode_Root.h" },
		{ "ToolTip", "\xe9\xbb\x98\xe8\xae\xa4\xe7\x9a\x84\xe5\x9b\xbe\xe8\xa1\xa8\xe6\xa0\xb9\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_CommonData_MetaData[] = {
		{ "Category", "FSMGraphNode_Root" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNode_Root.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_CommonData = { "CommonData", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNode_Root, CommonData), Z_Construct_UClass_UFSMCommonData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_CommonData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_CommonData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_WidgetLayerManagerClass_MetaData[] = {
		{ "Category", "FSMGraphNode_Root" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNode_Root.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_WidgetLayerManagerClass = { "WidgetLayerManagerClass", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNode_Root, WidgetLayerManagerClass), Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_WidgetLayerManagerClass_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_WidgetLayerManagerClass_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMGraphNode_Root_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_CommonData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNode_Root_Statics::NewProp_WidgetLayerManagerClass,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMGraphNode_Root_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMGraphNode_Root>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMGraphNode_Root_Statics::ClassParams = {
		&UFSMGraphNode_Root::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMGraphNode_Root_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Root_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNode_Root_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNode_Root_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMGraphNode_Root()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMGraphNode_Root_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMGraphNode_Root, 2729993829);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UFSMGraphNode_Root>()
	{
		return UFSMGraphNode_Root::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMGraphNode_Root(Z_Construct_UClass_UFSMGraphNode_Root, &UFSMGraphNode_Root::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UFSMGraphNode_Root"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMGraphNode_Root);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
