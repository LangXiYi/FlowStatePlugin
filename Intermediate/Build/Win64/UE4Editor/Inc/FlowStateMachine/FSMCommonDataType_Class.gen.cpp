// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/CommonDataType/FSMCommonDataType_Class.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMCommonDataType_Class() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Class_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Class();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
// End Cross Module References
	void UFSMCommonDataType_Class::StaticRegisterNativesUFSMCommonDataType_Class()
	{
	}
	UClass* Z_Construct_UClass_UFSMCommonDataType_Class_NoRegister()
	{
		return UFSMCommonDataType_Class::StaticClass();
	}
	struct Z_Construct_UClass_UFSMCommonDataType_Class_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DataValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_DataValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMCommonDataType_Class_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMCommonDataType,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Class_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Data/CommonDataType/FSMCommonDataType_Class.h" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Class.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Class_Statics::NewProp_DataValue_MetaData[] = {
		{ "Category", "FSMCommonDataType_Class" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Class.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_UFSMCommonDataType_Class_Statics::NewProp_DataValue = { "DataValue", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMCommonDataType_Class, DataValue), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Class_Statics::NewProp_DataValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Class_Statics::NewProp_DataValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMCommonDataType_Class_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonDataType_Class_Statics::NewProp_DataValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMCommonDataType_Class_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMCommonDataType_Class>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMCommonDataType_Class_Statics::ClassParams = {
		&UFSMCommonDataType_Class::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMCommonDataType_Class_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Class_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Class_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Class_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMCommonDataType_Class()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMCommonDataType_Class_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMCommonDataType_Class, 2036197981);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMCommonDataType_Class>()
	{
		return UFSMCommonDataType_Class::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMCommonDataType_Class(Z_Construct_UClass_UFSMCommonDataType_Class, &UFSMCommonDataType_Class::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMCommonDataType_Class"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMCommonDataType_Class);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
