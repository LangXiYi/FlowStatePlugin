// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Data/CommonDataType/FSMCommonDataType_Int.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMCommonDataType_Int() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Int_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType_Int();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataType();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
// End Cross Module References
	void UFSMCommonDataType_Int::StaticRegisterNativesUFSMCommonDataType_Int()
	{
	}
	UClass* Z_Construct_UClass_UFSMCommonDataType_Int_NoRegister()
	{
		return UFSMCommonDataType_Int::StaticClass();
	}
	struct Z_Construct_UClass_UFSMCommonDataType_Int_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DataValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_DataValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMCommonDataType_Int_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMCommonDataType,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Int_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Data/CommonDataType/FSMCommonDataType_Int.h" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Int.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataType_Int_Statics::NewProp_DataValue_MetaData[] = {
		{ "Category", "FSMCommonDataType_Int" },
		{ "ModuleRelativePath", "Public/Data/CommonDataType/FSMCommonDataType_Int.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_UFSMCommonDataType_Int_Statics::NewProp_DataValue = { "DataValue", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMCommonDataType_Int, DataValue), METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Int_Statics::NewProp_DataValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Int_Statics::NewProp_DataValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMCommonDataType_Int_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonDataType_Int_Statics::NewProp_DataValue,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMCommonDataType_Int_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMCommonDataType_Int>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMCommonDataType_Int_Statics::ClassParams = {
		&UFSMCommonDataType_Int::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UFSMCommonDataType_Int_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Int_Statics::PropPointers),
		0,
		0x001030A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataType_Int_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataType_Int_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMCommonDataType_Int()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMCommonDataType_Int_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMCommonDataType_Int, 1369398540);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMCommonDataType_Int>()
	{
		return UFSMCommonDataType_Int::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMCommonDataType_Int(Z_Construct_UClass_UFSMCommonDataType_Int, &UFSMCommonDataType_Int::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMCommonDataType_Int"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMCommonDataType_Int);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
