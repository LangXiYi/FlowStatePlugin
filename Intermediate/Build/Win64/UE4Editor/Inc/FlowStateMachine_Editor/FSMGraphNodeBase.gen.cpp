// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Editor/Public/Node/FSMGraphNodeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMGraphNodeBase() {}
// Cross Module References
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNodeBase_NoRegister();
	FLOWSTATEMACHINE_EDITOR_API UClass* Z_Construct_UClass_UFSMGraphNodeBase();
	ENGINE_API UClass* Z_Construct_UClass_UEdGraphNode();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Editor();
	AIGRAPH_API UScriptStruct* Z_Construct_UScriptStruct_FGraphNodeClassData();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister();
// End Cross Module References
	void UFSMGraphNodeBase::StaticRegisterNativesUFSMGraphNodeBase()
	{
	}
	UClass* Z_Construct_UClass_UFSMGraphNodeBase_NoRegister()
	{
		return UFSMGraphNodeBase::StaticClass();
	}
	struct Z_Construct_UClass_UFSMGraphNodeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SubNodes_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SubNodes_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_SubNodes;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ClassData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ClassData;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RuntimeNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RuntimeNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ParentNode_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ParentNode;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ErrorMessage_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ErrorMessage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CopySubNodeIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CopySubNodeIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMGraphNodeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UEdGraphNode,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Editor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Node/FSMGraphNodeBase.h" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes_Inner = { "SubNodes", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UFSMGraphNodeBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes_MetaData[] = {
		{ "Comment", "/** \xe6\x89\x80\xe6\x9c\x89\xe6\xac\xa1\xe8\xa6\x81\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "\xe6\x89\x80\xe6\x9c\x89\xe6\xac\xa1\xe8\xa6\x81\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes = { "SubNodes", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, SubNodes), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ClassData_MetaData[] = {
		{ "Comment", "/** \xe7\xb1\xbb\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe7\x9b\xae\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe6\x98\xaf AIGraphType \xe4\xb8\xad\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\x90\x8e\xe7\xbb\xad\xe5\x8f\xaf\xe4\xbb\xa5\xe8\x80\x83\xe8\x99\x91\xe4\xbd\xbf\xe7\x94\xa8\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "\xe7\xb1\xbb\xe5\x9e\x8b\xe6\x95\xb0\xe6\x8d\xae\xef\xbc\x8c\xe7\x9b\xae\xe5\x89\x8d\xe4\xbd\xbf\xe7\x94\xa8\xe7\x9a\x84\xe6\x98\xaf AIGraphType \xe4\xb8\xad\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b\xef\xbc\x8c\xe5\x90\x8e\xe7\xbb\xad\xe5\x8f\xaf\xe4\xbb\xa5\xe8\x80\x83\xe8\x99\x91\xe4\xbd\xbf\xe7\x94\xa8\xe8\x87\xaa\xe5\xae\x9a\xe4\xb9\x89\xe7\x9a\x84\xe7\xb1\xbb\xe5\x9e\x8b" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ClassData = { "ClassData", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, ClassData), Z_Construct_UScriptStruct_FGraphNodeClassData, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ClassData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ClassData_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_RuntimeNode_MetaData[] = {
		{ "Comment", "/**\x09\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x8a\x82\xe7\x82\xb9\xe5\xae\x9e\xe4\xbe\x8b */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "\xe8\xbf\x90\xe8\xa1\x8c\xe6\x97\xb6\xe8\x8a\x82\xe7\x82\xb9\xe5\xae\x9e\xe4\xbe\x8b" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_RuntimeNode = { "RuntimeNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, RuntimeNode), Z_Construct_UClass_UFSMRuntimeNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_RuntimeNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_RuntimeNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ParentNode_MetaData[] = {
		{ "Comment", "/** \xe7\x88\xb6\xe7\xba\xa7\xe8\x8a\x82\xe7\x82\xb9 */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "\xe7\x88\xb6\xe7\xba\xa7\xe8\x8a\x82\xe7\x82\xb9" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ParentNode = { "ParentNode", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, ParentNode), Z_Construct_UClass_UFSMGraphNodeBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ParentNode_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ParentNode_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData[] = {
		{ "Comment", "/** error message for node */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "error message for node" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ErrorMessage = { "ErrorMessage", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, ErrorMessage), METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ErrorMessage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData[] = {
		{ "Comment", "/** subnode index assigned during copy operation to connect nodes again on paste */" },
		{ "ModuleRelativePath", "Public/Node/FSMGraphNodeBase.h" },
		{ "ToolTip", "subnode index assigned during copy operation to connect nodes again on paste" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_CopySubNodeIndex = { "CopySubNodeIndex", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMGraphNodeBase, CopySubNodeIndex), METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_CopySubNodeIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMGraphNodeBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_SubNodes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ClassData,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_RuntimeNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ParentNode,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_ErrorMessage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMGraphNodeBase_Statics::NewProp_CopySubNodeIndex,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMGraphNodeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMGraphNodeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMGraphNodeBase_Statics::ClassParams = {
		&UFSMGraphNodeBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMGraphNodeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMGraphNodeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMGraphNodeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMGraphNodeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMGraphNodeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMGraphNodeBase, 4078798376);
	template<> FLOWSTATEMACHINE_EDITOR_API UClass* StaticClass<UFSMGraphNodeBase>()
	{
		return UFSMGraphNodeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMGraphNodeBase(Z_Construct_UClass_UFSMGraphNodeBase, &UFSMGraphNodeBase::StaticClass, TEXT("/Script/FlowStateMachine_Editor"), TEXT("UFSMGraphNodeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMGraphNodeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
