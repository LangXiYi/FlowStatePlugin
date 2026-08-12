// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/DataFragments/FSMMetaDataFragment_Assets.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMMetaDataFragment_Assets() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMMetaDataFragment_Assets_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMMetaDataFragment_Assets();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMMetaDataFragment();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAnimSequence_NoRegister();
// End Cross Module References
	void UFSMMetaDataFragment_Assets::StaticRegisterNativesUFSMMetaDataFragment_Assets()
	{
	}
	UClass* Z_Construct_UClass_UFSMMetaDataFragment_Assets_NoRegister()
	{
		return UFSMMetaDataFragment_Assets::StaticClass();
	}
	struct Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SM_Meshes_ValueProp;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SM_Meshes_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SM_Meshes_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_SM_Meshes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SK_Meshes_ValueProp;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SK_Meshes_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SK_Meshes_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_SK_Meshes;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Animations_ValueProp;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_Animations_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Animations_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_Animations;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMMetaDataFragment,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \xe8\xaf\xa5\xe6\x95\xb0\xe6\x8d\xae\xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\xa8 OperationGuideDataAsset \xe4\xb8\xad\xef\xbc\x8c\xe5\x86\x85\xe9\x83\xa8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe4\xbc\x9a\xe8\xb7\x9f\xe9\x9a\x8f\xe8\xaf\xa5\xe8\xb5\x84\xe4\xba\xa7\xe8\xa2\xab\xe4\xb8\x80\xe8\xb5\xb7\xe5\x8a\xa0\xe8\xbd\xbd\xe3\x80\x82\n * \xe5\x85\xb3\xe5\x8d\xa1\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x98\xaf\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe7\x9a\x84ID\xe8\x80\x8c\xe9\x9d\x9e\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe6\x9c\xac\xe8\xba\xab\xef\xbc\x8c\xe6\x95\x85\xe8\xb0\x83\xe7\x94\xa8 OpenLevel \xe6\x89\x93\xe5\xbc\x80\xe6\x96\xb0\xe5\x85\xb3\xe5\x8d\xa1\xe6\x97\xb6\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x90\x8c\xe6\xad\xa5\xe5\x8a\xa0\xe8\xbd\xbd\xe8\xbf\x99\xe4\xba\x9b\xe8\xb5\x84\xe4\xba\xa7\n * \xe5\x9c\xa8\xe5\x85\xb3\xe5\x8d\xa1\xe6\x89\x93\xe5\xbc\x80\xe4\xb8\x94\xe6\x89\x80\xe6\x9c\x89""Actor\xe7\x9a\x84 BeginPlay \xe4\xba\x8b\xe4\xbb\xb6\xe8\xa2\xab\xe8\xa7\xa6\xe5\x8f\x91\xe5\x90\x8e\xef\xbc\x8c\xe6\x89\x8d\xe4\xbc\x9a\xe8\xa7\xa6\xe5\x8f\x91\xe8\xb5\x84\xe4\xba\xa7\xe5\x8a\xa0\xe8\xbd\xbd\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb0\x86\xe8\xb5\x84\xe6\xba\x90\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x88\xb0\xe5\x86\x85\xe5\xad\x98\xe4\xb8\xad\xe3\x80\x82\n * \xe6\x95\xb0\xe6\x8d\xae\xe9\x95\xbf\xe6\x9c\x9f\xe6\x9c\x89\xe6\x95\x88\xef\xbc\x8c\xe9\x99\xa4\xe9\x9d\x9e\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe8\xa2\xab\xe5\x8d\xb8\xe8\xbd\xbd\n */" },
		{ "IncludePath", "Data/DataFragments/FSMMetaDataFragment_Assets.h" },
		{ "IsBlueprintBase", "false" },
		{ "ModuleRelativePath", "Public/Data/DataFragments/FSMMetaDataFragment_Assets.h" },
		{ "ToolTip", "\xe8\xaf\xa5\xe6\x95\xb0\xe6\x8d\xae\xe4\xbf\x9d\xe5\xad\x98\xe5\x9c\xa8 OperationGuideDataAsset \xe4\xb8\xad\xef\xbc\x8c\xe5\x86\x85\xe9\x83\xa8\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x95\xb0\xe6\x8d\xae\xe4\xbc\x9a\xe8\xb7\x9f\xe9\x9a\x8f\xe8\xaf\xa5\xe8\xb5\x84\xe4\xba\xa7\xe8\xa2\xab\xe4\xb8\x80\xe8\xb5\xb7\xe5\x8a\xa0\xe8\xbd\xbd\xe3\x80\x82\n\xe5\x85\xb3\xe5\x8d\xa1\xe5\xae\x9e\xe4\xbe\x8b\xe4\xbf\x9d\xe5\xad\x98\xe7\x9a\x84\xe6\x98\xaf\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe7\x9a\x84ID\xe8\x80\x8c\xe9\x9d\x9e\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe6\x9c\xac\xe8\xba\xab\xef\xbc\x8c\xe6\x95\x85\xe8\xb0\x83\xe7\x94\xa8 OpenLevel \xe6\x89\x93\xe5\xbc\x80\xe6\x96\xb0\xe5\x85\xb3\xe5\x8d\xa1\xe6\x97\xb6\xe4\xb8\x8d\xe4\xbc\x9a\xe5\x90\x8c\xe6\xad\xa5\xe5\x8a\xa0\xe8\xbd\xbd\xe8\xbf\x99\xe4\xba\x9b\xe8\xb5\x84\xe4\xba\xa7\n\xe5\x9c\xa8\xe5\x85\xb3\xe5\x8d\xa1\xe6\x89\x93\xe5\xbc\x80\xe4\xb8\x94\xe6\x89\x80\xe6\x9c\x89""Actor\xe7\x9a\x84 BeginPlay \xe4\xba\x8b\xe4\xbb\xb6\xe8\xa2\xab\xe8\xa7\xa6\xe5\x8f\x91\xe5\x90\x8e\xef\xbc\x8c\xe6\x89\x8d\xe4\xbc\x9a\xe8\xa7\xa6\xe5\x8f\x91\xe8\xb5\x84\xe4\xba\xa7\xe5\x8a\xa0\xe8\xbd\xbd\xe4\xba\x8b\xe4\xbb\xb6\xef\xbc\x8c\xe5\xb0\x86\xe8\xb5\x84\xe6\xba\x90\xe5\x8a\xa0\xe8\xbd\xbd\xe5\x88\xb0\xe5\x86\x85\xe5\xad\x98\xe4\xb8\xad\xe3\x80\x82\n\xe6\x95\xb0\xe6\x8d\xae\xe9\x95\xbf\xe6\x9c\x9f\xe6\x9c\x89\xe6\x95\x88\xef\xbc\x8c\xe9\x99\xa4\xe9\x9d\x9e\xe6\x95\xb0\xe6\x8d\xae\xe8\xb5\x84\xe4\xba\xa7\xe8\xa2\xab\xe5\x8d\xb8\xe8\xbd\xbd" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_ValueProp = { "SM_Meshes", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_Key_KeyProp = { "SM_Meshes_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "MetaDataFragment" },
		{ "Comment", "/** \xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe6\xa8\xa1\xe5\x9e\x8b\xe8\xb5\x84\xe4\xba\xa7 */" },
		{ "ModuleRelativePath", "Public/Data/DataFragments/FSMMetaDataFragment_Assets.h" },
		{ "ToolTip", "\xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe6\xa8\xa1\xe5\x9e\x8b\xe8\xb5\x84\xe4\xba\xa7" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes = { "SM_Meshes", nullptr, (EPropertyFlags)0x0040000000010015, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMMetaDataFragment_Assets, SM_Meshes), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_ValueProp = { "SK_Meshes", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_USkeletalMesh_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_Key_KeyProp = { "SK_Meshes_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "MetaDataFragment" },
		{ "Comment", "/** \xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe9\xaa\xa8\xe9\xaa\xbc\xe8\xb5\x84\xe4\xba\xa7 */" },
		{ "ModuleRelativePath", "Public/Data/DataFragments/FSMMetaDataFragment_Assets.h" },
		{ "ToolTip", "\xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe9\xaa\xa8\xe9\xaa\xbc\xe8\xb5\x84\xe4\xba\xa7" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes = { "SK_Meshes", nullptr, (EPropertyFlags)0x0040000000010015, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMMetaDataFragment_Assets, SK_Meshes), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_ValueProp = { "Animations", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UClass_UAnimSequence_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_Key_KeyProp = { "Animations_Key", nullptr, (EPropertyFlags)0x0000000000000001, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_MetaData[] = {
		{ "AllowPrivateAccess", "TRUE" },
		{ "Category", "MetaDataFragment" },
		{ "Comment", "/** \xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe5\x8a\xa8\xe7\x94\xbb\xe8\xb5\x84\xe4\xba\xa7 */" },
		{ "ModuleRelativePath", "Public/Data/DataFragments/FSMMetaDataFragment_Assets.h" },
		{ "ToolTip", "\xe9\x9c\x80\xe8\xa6\x81\xe4\xbd\xbf\xe7\x94\xa8\xe5\x88\xb0\xe7\x9a\x84\xe5\x8a\xa8\xe7\x94\xbb\xe8\xb5\x84\xe4\xba\xa7" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations = { "Animations", nullptr, (EPropertyFlags)0x0040000000010015, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMMetaDataFragment_Assets, Animations), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SM_Meshes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_SK_Meshes,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::NewProp_Animations,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMMetaDataFragment_Assets>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::ClassParams = {
		&UFSMMetaDataFragment_Assets::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::PropPointers),
		0,
		0x000010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMMetaDataFragment_Assets()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMMetaDataFragment_Assets_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMMetaDataFragment_Assets, 2249549518);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMMetaDataFragment_Assets>()
	{
		return UFSMMetaDataFragment_Assets::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMMetaDataFragment_Assets(Z_Construct_UClass_UFSMMetaDataFragment_Assets, &UFSMMetaDataFragment_Assets::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMMetaDataFragment_Assets"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMMetaDataFragment_Assets);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
