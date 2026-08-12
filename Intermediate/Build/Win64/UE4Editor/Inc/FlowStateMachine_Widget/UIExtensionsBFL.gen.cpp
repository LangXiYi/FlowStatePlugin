// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Widget/Public/Library/UIExtensionsBFL.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeUIExtensionsBFL() {}
// Cross Module References
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UUIExtensionsBFL_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UUIExtensionsBFL();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Widget();
	UMG_API UClass* Z_Construct_UClass_UPanelWidget_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	UMG_API UClass* Z_Construct_UClass_UWidget_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UUIExtensionsBFL::execFindAllChildOfType)
	{
		P_GET_OBJECT(UPanelWidget,Z_Param_Parent);
		P_GET_OBJECT(UClass,Z_Param_Type);
		P_GET_TARRAY_REF(UWidget*,Z_Param_Out_OutArray);
		P_FINISH;
		P_NATIVE_BEGIN;
		UUIExtensionsBFL::FindAllChildOfType(Z_Param_Parent,Z_Param_Type,Z_Param_Out_OutArray);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUIExtensionsBFL::execFindChildWidgetOfType)
	{
		P_GET_OBJECT(UPanelWidget,Z_Param_Parent);
		P_GET_OBJECT(UClass,Z_Param_Type);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UWidget**)Z_Param__Result=UUIExtensionsBFL::FindChildWidgetOfType(Z_Param_Parent,Z_Param_Type);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UUIExtensionsBFL::execFindParentWidgetOfType)
	{
		P_GET_OBJECT(UWidget,Z_Param_StartWidget);
		P_GET_OBJECT(UClass,Z_Param_Type);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UWidget**)Z_Param__Result=UUIExtensionsBFL::FindParentWidgetOfType(Z_Param_StartWidget,Z_Param_Type);
		P_NATIVE_END;
	}
	void UUIExtensionsBFL::StaticRegisterNativesUUIExtensionsBFL()
	{
		UClass* Class = UUIExtensionsBFL::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FindAllChildOfType", &UUIExtensionsBFL::execFindAllChildOfType },
			{ "FindChildWidgetOfType", &UUIExtensionsBFL::execFindChildWidgetOfType },
			{ "FindParentWidgetOfType", &UUIExtensionsBFL::execFindParentWidgetOfType },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics
	{
		struct UIExtensionsBFL_eventFindAllChildOfType_Parms
		{
			UPanelWidget* Parent;
			TSubclassOf<UWidget>  Type;
			TArray<UWidget*> OutArray;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Parent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Parent;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Type;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OutArray_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OutArray_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_OutArray;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Parent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Parent = { "Parent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindAllChildOfType_Parms, Parent), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Parent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Parent_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindAllChildOfType_Parms, Type), Z_Construct_UClass_UWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray_Inner = { "OutArray", nullptr, (EPropertyFlags)0x0000000000080000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray = { "OutArray", nullptr, (EPropertyFlags)0x0010008000000180, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindAllChildOfType_Parms, OutArray), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Parent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::NewProp_OutArray,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::Function_MetaDataParams[] = {
		{ "Category", "UIExtensionsBFL" },
		{ "DeterminesOutputType", "Type" },
		{ "ModuleRelativePath", "Public/Library/UIExtensionsBFL.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUIExtensionsBFL, nullptr, "FindAllChildOfType", nullptr, nullptr, sizeof(UIExtensionsBFL_eventFindAllChildOfType_Parms), Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics
	{
		struct UIExtensionsBFL_eventFindChildWidgetOfType_Parms
		{
			UPanelWidget* Parent;
			TSubclassOf<UWidget>  Type;
			UWidget* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Parent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Parent;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Type;
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Parent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Parent = { "Parent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindChildWidgetOfType_Parms, Parent), Z_Construct_UClass_UPanelWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Parent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Parent_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindChildWidgetOfType_Parms, Type), Z_Construct_UClass_UWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindChildWidgetOfType_Parms, ReturnValue), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Parent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::Function_MetaDataParams[] = {
		{ "Category", "UIExtensionsBFL" },
		{ "DeterminesOutputType", "Type" },
		{ "ModuleRelativePath", "Public/Library/UIExtensionsBFL.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUIExtensionsBFL, nullptr, "FindChildWidgetOfType", nullptr, nullptr, sizeof(UIExtensionsBFL_eventFindChildWidgetOfType_Parms), Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics
	{
		struct UIExtensionsBFL_eventFindParentWidgetOfType_Parms
		{
			UWidget* StartWidget;
			TSubclassOf<UWidget>  Type;
			UWidget* ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartWidget_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_StartWidget;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Type;
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_StartWidget_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_StartWidget = { "StartWidget", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindParentWidgetOfType_Parms, StartWidget), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_StartWidget_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_StartWidget_MetaData)) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_Type = { "Type", nullptr, (EPropertyFlags)0x0014000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindParentWidgetOfType_Parms, Type), Z_Construct_UClass_UWidget_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UIExtensionsBFL_eventFindParentWidgetOfType_Parms, ReturnValue), Z_Construct_UClass_UWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_StartWidget,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_Type,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::Function_MetaDataParams[] = {
		{ "Category", "UIExtensionsBFL" },
		{ "DeterminesOutputType", "Type" },
		{ "ModuleRelativePath", "Public/Library/UIExtensionsBFL.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UUIExtensionsBFL, nullptr, "FindParentWidgetOfType", nullptr, nullptr, sizeof(UIExtensionsBFL_eventFindParentWidgetOfType_Parms), Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UUIExtensionsBFL_NoRegister()
	{
		return UUIExtensionsBFL::StaticClass();
	}
	struct Z_Construct_UClass_UUIExtensionsBFL_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UUIExtensionsBFL_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Widget,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UUIExtensionsBFL_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UUIExtensionsBFL_FindAllChildOfType, "FindAllChildOfType" }, // 3316382655
		{ &Z_Construct_UFunction_UUIExtensionsBFL_FindChildWidgetOfType, "FindChildWidgetOfType" }, // 4181451114
		{ &Z_Construct_UFunction_UUIExtensionsBFL_FindParentWidgetOfType, "FindParentWidgetOfType" }, // 1875667430
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UUIExtensionsBFL_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Library/UIExtensionsBFL.h" },
		{ "ModuleRelativePath", "Public/Library/UIExtensionsBFL.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UUIExtensionsBFL_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UUIExtensionsBFL>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UUIExtensionsBFL_Statics::ClassParams = {
		&UUIExtensionsBFL::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UUIExtensionsBFL_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UUIExtensionsBFL_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UUIExtensionsBFL()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UUIExtensionsBFL_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UUIExtensionsBFL, 1781195194);
	template<> FLOWSTATEMACHINE_WIDGET_API UClass* StaticClass<UUIExtensionsBFL>()
	{
		return UUIExtensionsBFL::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UUIExtensionsBFL(Z_Construct_UClass_UUIExtensionsBFL, &UUIExtensionsBFL::StaticClass, TEXT("/Script/FlowStateMachine_Widget"), TEXT("UUIExtensionsBFL"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UUIExtensionsBFL);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
