// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/Actions/Actions_Camera.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeActions_Camera() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UActions_Camera_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UActions_Camera();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMRuntimeSubNode_Action();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
// End Cross Module References
	void UActions_Camera::StaticRegisterNativesUActions_Camera()
	{
	}
	UClass* Z_Construct_UClass_UActions_Camera_NoRegister()
	{
		return UActions_Camera::StaticClass();
	}
	struct Z_Construct_UClass_UActions_Camera_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_CameraName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UActions_Camera_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UFSMRuntimeSubNode_Action,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActions_Camera_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \xe8\xbf\x99\xe4\xb8\xaa\xe5\x8f\xaa\xe6\x98\xaf\xe4\xb8\x80\xe4\xb8\xaa\xe9\x9d\x9e\xe5\xb8\xb8\xe7\xae\x80\xe9\x99\x8b\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe6\x97\xa2\xe4\xb8\x8d\xe8\x83\xbd\xe7\xbc\x93\xe5\xad\x98\xe6\x97\xa7\xe7\x9b\xb8\xe6\x9c\xba\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe4\xb9\x9f\xe4\xb8\x8d\xe8\x83\xbd\xe5\x9c\xa8\xe8\xbf\x87\xe7\xa8\x8b\xe4\xb8\xad\xe5\xaf\xb9\xe7\x9b\xb8\xe6\x9c\xba\xe8\xbf\x9b\xe8\xa1\x8c\xe4\xbb\xbb\xe4\xbd\x95\xe6\x93\x8d\xe4\xbd\x9c\n * \xe5\x8f\xaa\xe8\x83\xbd\xe7\xae\x80\xe5\x8d\x95\xe7\x9a\x84\xe5\xb0\x86\xe8\xa7\x86\xe8\xa7\x92\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe6\x8c\x87\xe5\xae\x9a\xe7\x9a\x84\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x81\xe8\xa7\x92\xe5\xba\xa6\xe3\x80\x82\n */" },
		{ "IncludePath", "Actions/Actions_Camera.h" },
		{ "ModuleRelativePath", "Public/Actions/Actions_Camera.h" },
		{ "ToolTip", "\xe8\xbf\x99\xe4\xb8\xaa\xe5\x8f\xaa\xe6\x98\xaf\xe4\xb8\x80\xe4\xb8\xaa\xe9\x9d\x9e\xe5\xb8\xb8\xe7\xae\x80\xe9\x99\x8b\xe7\x9a\x84\xe7\x89\x88\xe6\x9c\xac\xef\xbc\x8c\xe6\x97\xa2\xe4\xb8\x8d\xe8\x83\xbd\xe7\xbc\x93\xe5\xad\x98\xe6\x97\xa7\xe7\x9b\xb8\xe6\x9c\xba\xe4\xbd\x8d\xe7\xbd\xae\xef\xbc\x8c\xe4\xb9\x9f\xe4\xb8\x8d\xe8\x83\xbd\xe5\x9c\xa8\xe8\xbf\x87\xe7\xa8\x8b\xe4\xb8\xad\xe5\xaf\xb9\xe7\x9b\xb8\xe6\x9c\xba\xe8\xbf\x9b\xe8\xa1\x8c\xe4\xbb\xbb\xe4\xbd\x95\xe6\x93\x8d\xe4\xbd\x9c\n\xe5\x8f\xaa\xe8\x83\xbd\xe7\xae\x80\xe5\x8d\x95\xe7\x9a\x84\xe5\xb0\x86\xe8\xa7\x86\xe8\xa7\x92\xe5\x88\x87\xe6\x8d\xa2\xe8\x87\xb3\xe6\x8c\x87\xe5\xae\x9a\xe7\x9a\x84\xe4\xbd\x8d\xe7\xbd\xae\xe3\x80\x81\xe8\xa7\x92\xe5\xba\xa6\xe3\x80\x82" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UActions_Camera_Statics::NewProp_CameraName_MetaData[] = {
		{ "Category", "Camera" },
		{ "ModuleRelativePath", "Public/Actions/Actions_Camera.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_UActions_Camera_Statics::NewProp_CameraName = { "CameraName", nullptr, (EPropertyFlags)0x0020080000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UActions_Camera, CameraName), METADATA_PARAMS(Z_Construct_UClass_UActions_Camera_Statics::NewProp_CameraName_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UActions_Camera_Statics::NewProp_CameraName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UActions_Camera_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UActions_Camera_Statics::NewProp_CameraName,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UActions_Camera_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UActions_Camera>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UActions_Camera_Statics::ClassParams = {
		&UActions_Camera::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UActions_Camera_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UActions_Camera_Statics::PropPointers),
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UActions_Camera_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UActions_Camera_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UActions_Camera()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UActions_Camera_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UActions_Camera, 3800296611);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UActions_Camera>()
	{
		return UActions_Camera::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UActions_Camera(Z_Construct_UClass_UActions_Camera, &UActions_Camera::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UActions_Camera"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UActions_Camera);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
