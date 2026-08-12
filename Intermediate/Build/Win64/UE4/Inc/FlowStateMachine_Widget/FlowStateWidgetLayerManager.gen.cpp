// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine_Widget/Public/Widgets/FlowStateWidgetLayerManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFlowStateWidgetLayerManager() {}
// Cross Module References
	FLOWSTATEMACHINE_WIDGET_API UEnum* Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine_Widget();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	FLOWSTATEMACHINE_WIDGET_API UClass* Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister();
// End Cross Module References
	static UEnum* EFlowStateWidgetLayer_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer, Z_Construct_UPackage__Script_FlowStateMachine_Widget(), TEXT("EFlowStateWidgetLayer"));
		}
		return Singleton;
	}
	template<> FLOWSTATEMACHINE_WIDGET_API UEnum* StaticEnum<EFlowStateWidgetLayer>()
	{
		return EFlowStateWidgetLayer_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EFlowStateWidgetLayer(EFlowStateWidgetLayer_StaticEnum, TEXT("/Script/FlowStateMachine_Widget"), TEXT("EFlowStateWidgetLayer"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer_Hash() { return 1850039006U; }
	UEnum* Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_FlowStateMachine_Widget();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EFlowStateWidgetLayer"), 0, Get_Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EFlowStateWidgetLayer::GameLayer", (int64)EFlowStateWidgetLayer::GameLayer },
				{ "EFlowStateWidgetLayer::GameMenu", (int64)EFlowStateWidgetLayer::GameMenu },
				{ "EFlowStateWidgetLayer::MenuLayer", (int64)EFlowStateWidgetLayer::MenuLayer },
				{ "EFlowStateWidgetLayer::ModalLayer", (int64)EFlowStateWidgetLayer::ModalLayer },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "GameLayer.Comment", "// \xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe6\x98\xbe\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\x8d\xb3\xe7\x94\x9f\xe5\x91\xbd\xe6\x9d\xa1\xe3\x80\x81\xe6\xad\xa6\xe5\x99\xa8\xe6\xa7\xbd\xe7\xad\x89\n" },
				{ "GameLayer.Name", "EFlowStateWidgetLayer::GameLayer" },
				{ "GameLayer.ToolTip", "\xe9\x80\x9a\xe5\xb8\xb8\xe7\x94\xa8\xe4\xba\x8e\xe6\x98\xbe\xe7\xa4\xba\xe6\xb8\xb8\xe6\x88\x8f\xe7\x8a\xb6\xe6\x80\x81\xef\xbc\x8c\xe5\x8d\xb3\xe7\x94\x9f\xe5\x91\xbd\xe6\x9d\xa1\xe3\x80\x81\xe6\xad\xa6\xe5\x99\xa8\xe6\xa7\xbd\xe7\xad\x89" },
				{ "GameMenu.Comment", "// \xe6\xb8\xb8\xe6\x88\x8f\xe5\x86\x85\xe7\x9a\x84\xe8\x8f\x9c\xe5\x8d\x95\xef\xbc\x8c\xe5\x8d\xb3\xe8\x83\x8c\xe5\x8c\x85\xe7\xad\x89\n" },
				{ "GameMenu.Name", "EFlowStateWidgetLayer::GameMenu" },
				{ "GameMenu.ToolTip", "\xe6\xb8\xb8\xe6\x88\x8f\xe5\x86\x85\xe7\x9a\x84\xe8\x8f\x9c\xe5\x8d\x95\xef\xbc\x8c\xe5\x8d\xb3\xe8\x83\x8c\xe5\x8c\x85\xe7\xad\x89" },
				{ "MenuLayer.Comment", "// \xe6\xb8\xb8\xe6\x88\x8f\xe8\x8f\x9c\xe5\x8d\x95\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe6\xb8\xb8\xe6\x88\x8f\xe5\xbc\x80\xe5\xa7\x8b\xe7\x95\x8c\xe9\x9d\xa2\xe3\x80\x81\xe8\xae\xbe\xe7\xbd\xae\xe7\x95\x8c\xe9\x9d\xa2\xe7\xad\x89\xe3\x80\x82\n" },
				{ "MenuLayer.Name", "EFlowStateWidgetLayer::MenuLayer" },
				{ "MenuLayer.ToolTip", "\xe6\xb8\xb8\xe6\x88\x8f\xe8\x8f\x9c\xe5\x8d\x95\xef\xbc\x8c\xe4\xbe\x8b\xe5\xa6\x82\xe6\xb8\xb8\xe6\x88\x8f\xe5\xbc\x80\xe5\xa7\x8b\xe7\x95\x8c\xe9\x9d\xa2\xe3\x80\x81\xe8\xae\xbe\xe7\xbd\xae\xe7\x95\x8c\xe9\x9d\xa2\xe7\xad\x89\xe3\x80\x82" },
				{ "ModalLayer.Comment", "// \xe6\xb8\xb8\xe6\x88\x8f\xe5\xbc\xb9\xe7\xaa\x97,\xe4\xbe\x8b\xe5\xa6\x82\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe6\x88\x96\xe8\x80\x85\xe6\x9b\xb4\xe6\x94\xb9\xe6\xb8\xb8\xe6\x88\x8f\xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xb6\xe5\xbc\xb9\xe7\xaa\x97\xe7\x9a\x84\xe7\xa1\xae\xe5\xae\x9a\xe5\xbc\xb9\xe7\xaa\x97\xe4\xb9\x8b\xe7\xb1\xbb\xe3\x80\x82\n" },
				{ "ModalLayer.Name", "EFlowStateWidgetLayer::ModalLayer" },
				{ "ModalLayer.ToolTip", "\xe6\xb8\xb8\xe6\x88\x8f\xe5\xbc\xb9\xe7\xaa\x97,\xe4\xbe\x8b\xe5\xa6\x82\xe4\xbf\x9d\xe5\xad\x98\xe6\xb8\xb8\xe6\x88\x8f\xe6\x88\x96\xe8\x80\x85\xe6\x9b\xb4\xe6\x94\xb9\xe6\xb8\xb8\xe6\x88\x8f\xe8\xae\xbe\xe7\xbd\xae\xe6\x97\xb6\xe5\xbc\xb9\xe7\xaa\x97\xe7\x9a\x84\xe7\xa1\xae\xe5\xae\x9a\xe5\xbc\xb9\xe7\xaa\x97\xe4\xb9\x8b\xe7\xb1\xbb\xe3\x80\x82" },
				{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_FlowStateMachine_Widget,
				nullptr,
				"EFlowStateWidgetLayer",
				"EFlowStateWidgetLayer",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	DEFINE_FUNCTION(UFlowStateWidgetLayerManager::execGetLayerWidget)
	{
		P_GET_ENUM(EFlowStateWidgetLayer,Z_Param_Layer);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UFlowStateLayoutWidget**)Z_Param__Result=P_THIS->GetLayerWidget(EFlowStateWidgetLayer(Z_Param_Layer));
		P_NATIVE_END;
	}
	void UFlowStateWidgetLayerManager::StaticRegisterNativesUFlowStateWidgetLayerManager()
	{
		UClass* Class = UFlowStateWidgetLayerManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetLayerWidget", &UFlowStateWidgetLayerManager::execGetLayerWidget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics
	{
		struct FlowStateWidgetLayerManager_eventGetLayerWidget_Parms
		{
			EFlowStateWidgetLayer Layer;
			UFlowStateLayoutWidget* ReturnValue;
		};
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_Layer_Underlying;
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_Layer;
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
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_Layer_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_Layer = { "Layer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateWidgetLayerManager_eventGetLayerWidget_Parms, Layer), Z_Construct_UEnum_FlowStateMachine_Widget_EFlowStateWidgetLayer, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000080588, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FlowStateWidgetLayerManager_eventGetLayerWidget_Parms, ReturnValue), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_ReturnValue_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_ReturnValue_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_Layer_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_Layer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "FlowStateWidgetLayerManager" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFlowStateWidgetLayerManager, nullptr, "GetLayerWidget", nullptr, nullptr, sizeof(FlowStateWidgetLayerManager_eventGetLayerWidget_Parms), Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager_NoRegister()
	{
		return UFlowStateWidgetLayerManager::StaticClass();
	}
	struct Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameLayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameLayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GameMenu_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_GameMenu;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MenuLayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MenuLayer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ModalLayer_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ModalLayer;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine_Widget,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFlowStateWidgetLayerManager_GetLayerWidget, "GetLayerWidget" }, // 3836314188
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "Widgets/FlowStateWidgetLayerManager.h" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameLayer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FlowStateWidgetLayerManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameLayer = { "GameLayer", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateWidgetLayerManager, GameLayer), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameLayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameLayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameMenu_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FlowStateWidgetLayerManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameMenu = { "GameMenu", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateWidgetLayerManager, GameMenu), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameMenu_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameMenu_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_MenuLayer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FlowStateWidgetLayerManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_MenuLayer = { "MenuLayer", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateWidgetLayerManager, MenuLayer), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_MenuLayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_MenuLayer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_ModalLayer_MetaData[] = {
		{ "BindWidget", "" },
		{ "Category", "FlowStateWidgetLayerManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Widgets/FlowStateWidgetLayerManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_ModalLayer = { "ModalLayer", nullptr, (EPropertyFlags)0x002008000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFlowStateWidgetLayerManager, ModalLayer), Z_Construct_UClass_UFlowStateLayoutWidget_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_ModalLayer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_ModalLayer_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameLayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_GameMenu,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_MenuLayer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::NewProp_ModalLayer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFlowStateWidgetLayerManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::ClassParams = {
		&UFlowStateWidgetLayerManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFlowStateWidgetLayerManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFlowStateWidgetLayerManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFlowStateWidgetLayerManager, 1309164796);
	template<> FLOWSTATEMACHINE_WIDGET_API UClass* StaticClass<UFlowStateWidgetLayerManager>()
	{
		return UFlowStateWidgetLayerManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFlowStateWidgetLayerManager(Z_Construct_UClass_UFlowStateWidgetLayerManager, &UFlowStateWidgetLayerManager::StaticClass, TEXT("/Script/FlowStateMachine_Widget"), TEXT("UFlowStateWidgetLayerManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFlowStateWidgetLayerManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
