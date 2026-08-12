// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/CommonDataType/FSMCommonDataType_Object.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMCommonDataType_Object() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Object_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Object();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UFSMCommonDataType_Object::StaticRegisterNativesUFSMCommonDataType_Object()
	{
	}
	UClass* Z_Construct_UClass_UFSMCommonDataType_Object_NoRegister()
	{
		return UFSMCommonDataType_Object::StaticClass();
	}
	struct Z_Construct_UClass_UFSMCommonDataType_Object_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DataValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_DataValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMCommonDataType_Object_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMCommonDataType,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Object_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Data/CommonDataType/FSMCommonDataType_Object.h" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Object.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Object_Statics::NewProp_DataValue_MetaData[] = {
		{ "Category", "FSMCommonDataType_Object" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Object.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMCommonDataType_Object_Statics::NewProp_DataValue = { "DataValue", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMCommonDataType_Object, DataValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Object_Statics::NewProp_DataValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Object_Statics::NewProp_DataValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMCommonDataType_Object_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonDataType_Object_Statics::NewProp_DataValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMCommonDataType_Object_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMCommonDataType_Object>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMCommonDataType_Object_Statics::ClassParams = {
		&UFSMCommonDataType_Object::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMCommonDataType_Object_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Object_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Object_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Object_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMCommonDataType_Object()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMCommonDataType_Object_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMCommonDataType_Object, 2118862747);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMCommonDataType_Object>()
	{
		return UFSMCommonDataType_Object::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMCommonDataType_Object(Z_Construct_UClass_UFSMCommonDataType_Object, &UFSMCommonDataType_Object::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMCommonDataType_Object"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMCommonDataType_Object);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
