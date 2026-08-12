// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Widget/Public/Widgets/GameplayTagSlot.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameplayTagSlot() {}
// Cross Module References
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UGameplayTagSlot_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UGameplayTagSlot();
	UMG_API UClass* Z_Construct_UClass_UNamedSlot();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Widget();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
// End Cross Module References
	void UGameplayTagSlot::StaticRegisterNativesUGameplayTagSlot()
	{
	}
	UClass* Z_Construct_UClass_UGameplayTagSlot_NoRegister()
	{
		return UGameplayTagSlot::StaticClass();
	}
	struct Z_Construct_UClass_UGameplayTagSlot_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Tag_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Tag;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameplayTagSlot_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UNamedSlot,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Widget,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayTagSlot_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widgets/GameplayTagSlot.h" },
		{ "ModuleRelativePath", "Public/Widgets/GameplayTagSlot.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayTagSlot_Statics::NewProp_Tag_MetaData[] = {
		{ "Category", "NameSlot" },
		{ "ModuleRelativePath", "Public/Widgets/GameplayTagSlot.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayTagSlot_Statics::NewProp_Tag = { "Tag", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameplayTagSlot, Tag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(Z_Construct_UClass_UGameplayTagSlot_Statics::NewProp_Tag_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagSlot_Statics::NewProp_Tag_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameplayTagSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayTagSlot_Statics::NewProp_Tag,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameplayTagSlot_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameplayTagSlot>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameplayTagSlot_Statics::ClassParams = {
		&UGameplayTagSlot::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UGameplayTagSlot_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagSlot_Statics::PropPointers),
		0,
		0x00B000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UGameplayTagSlot_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayTagSlot_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameplayTagSlot()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameplayTagSlot_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameplayTagSlot, 2986444174);
	template<> FLOWSTATEMACHINE_WIDGET_API UClass* StaticClass<UGameplayTagSlot>()
	{
		return UGameplayTagSlot::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameplayTagSlot(Z_Construct_UClass_UGameplayTagSlot, &UGameplayTagSlot::StaticClass, TEXT("/Script/FlowStateMachine_Widget"), TEXT("UGameplayTagSlot"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameplayTagSlot);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
