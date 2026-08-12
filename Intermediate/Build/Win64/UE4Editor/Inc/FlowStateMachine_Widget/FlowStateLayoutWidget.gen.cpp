// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Widget/Public/Widgets/FlowStateLayoutWidget.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateLayoutWidget() {}
// Cross Module References
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateLayoutWidget();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Widget();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UGameplayTagSlot_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFlowStateLayoutWidget::execAddChildTo)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_SlotTag);
		P_GET_OBJECT(UWidget,Z_Param_Child);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AddChildTo(Z_Param_SlotTag,Z_Param_Child);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateLayoutWidget::execCheckSlot)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_SlotTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->CheckSlot(Z_Param_SlotTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateLayoutWidget::execFindSlot)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_SlotTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UGameplayTagSlot**)Z_Param__Result=P_THIS->FindSlot(Z_Param_SlotTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFlowStateLayoutWidget::execClearChildSlots)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ClearChildSlots();
		P_NATIVE_END;
	}
	void UFlowStateLayoutWidget::StaticRegisterNativesUFlowStateLayoutWidget()
	{
		UClass* Class = UFlowStateLayoutWidget::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AddChildTo", &UFlowStateLayoutWidget::execAddChildTo },
			{ "CheckSlot", &UFlowStateLayoutWidget::execCheckSlot },
			{ "ClearChildSlots", &UFlowStateLayoutWidget::execClearChildSlots },
			{ "FindSlot", &UFlowStateLayoutWidget::execFindSlot },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics
	{
		struct FlowStateLayoutWidget_eventAddChildTo_Parms
		{
			FGameplayTag SlotTag;
			UWidget* Child;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SlotTag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Child_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Child;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_SlotTag = { "SlotTag", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateLayoutWidget_eventAddChildTo_Parms, SlotTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_Child_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_Child = { "Child", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateLayoutWidget_eventAddChildTo_Parms, Child), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_Child_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_Child_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_SlotTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::NewProp_Child,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateWidget" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateLayoutWidget, nullptr, "AddChildTo", nullptr, nullptr, sizeof(FlowStateLayoutWidget_eventAddChildTo_Parms), Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics
	{
		struct FlowStateLayoutWidget_eventCheckSlot_Parms
		{
			FGameplayTag SlotTag;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SlotTag;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_SlotTag = { "SlotTag", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateLayoutWidget_eventCheckSlot_Parms, SlotTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FlowStateLayoutWidget_eventCheckSlot_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FlowStateLayoutWidget_eventCheckSlot_Parms), &Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_SlotTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateWidget" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateLayoutWidget, nullptr, "CheckSlot", nullptr, nullptr, sizeof(FlowStateLayoutWidget_eventCheckSlot_Parms), Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateWidget" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateLayoutWidget, nullptr, "ClearChildSlots", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics
	{
		struct FlowStateLayoutWidget_eventFindSlot_Parms
		{
			FGameplayTag SlotTag;
			UGameplayTagSlot* ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SlotTag;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_SlotTag = { "SlotTag", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateLayoutWidget_eventFindSlot_Parms, SlotTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateLayoutWidget_eventFindSlot_Parms, ReturnValue), Z_Construct_UClass_UGameplayTagSlot_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_SlotTag,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateWidget" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateLayoutWidget, nullptr, "FindSlot", nullptr, nullptr, sizeof(FlowStateLayoutWidget_eventFindSlot_Parms), Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister()
	{
		return UFlowStateLayoutWidget::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateLayoutWidget_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TagSlots_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TagSlots_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TagSlots;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RootWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RootWidget;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateLayoutWidget_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Widget,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateLayoutWidget_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateLayoutWidget_AddChildTo, "AddChildTo" }, // 1692552743
		{ &Z_Construct_UFunction_UFlowStateLayoutWidget_CheckSlot, "CheckSlot" }, // 988407487
		{ &Z_Construct_UFunction_UFlowStateLayoutWidget_ClearChildSlots, "ClearChildSlots" }, // 4175930321
		{ &Z_Construct_UFunction_UFlowStateLayoutWidget_FindSlot, "FindSlot" }, // 616141328
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateLayoutWidget_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widgets/FlowStateLayoutWidget.h" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots_Inner = { "TagSlots", nullptr, (EPropertyFlags)0x0000000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UGameplayTagSlot_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots_MetaData[] = {
		{ "Category", "FlowStateWidget" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots = { "TagSlots", nullptr, (EPropertyFlags)0x002008800000001c, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateLayoutWidget, TagSlots), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_RootWidget_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateLayoutWidget.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_RootWidget = { "RootWidget", nullptr, (EPropertyFlags)0x0040000000080008, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateLayoutWidget, RootWidget), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_RootWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_RootWidget_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFlowStateLayoutWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_TagSlots,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateLayoutWidget_Statics::NewProp_RootWidget,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateLayoutWidget_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateLayoutWidget>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateLayoutWidget_Statics::ClassParams = {
		&UFlowStateLayoutWidget::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFlowStateLayoutWidget_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateLayoutWidget_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateLayoutWidget()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateLayoutWidget_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateLayoutWidget, 2928586926);
	template<> FLOWSTATEMACHINE_WIDGET_API UClass* StaticClass<UFlowStateLayoutWidget>()
	{
		return UFlowStateLayoutWidget::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateLayoutWidget(Z_Construct_UClass_UFlowStateLayoutWidget, &UFlowStateLayoutWidget::StaticClass, TEXT("/Script/FlowStateMachine_Widget"), TEXT("UFlowStateLayoutWidget"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateLayoutWidget);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
