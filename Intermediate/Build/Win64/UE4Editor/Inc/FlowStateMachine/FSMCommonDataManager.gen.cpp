// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FlowStateMachine/Public/SM/FSMCommonDataManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFSMCommonDataManager() {}
// Cross Module References
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataManager_NoRegister();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonDataManager();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	UPackage* Z_Construct_UPackage__Script_FlowStateMachine();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FRotator();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	FLOWSTATEMACHINE_API UClass* Z_Construct_UClass_UFSMCommonData_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsRotator)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_STRUCT(FRotator,Z_Param_VectorValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsRotator(Z_Param_KeyName,Z_Param_VectorValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsVector)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_STRUCT(FVector,Z_Param_VectorValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsVector(Z_Param_KeyName,Z_Param_VectorValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_PROPERTY(FNameProperty,Z_Param_NameValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsName(Z_Param_KeyName,Z_Param_NameValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsString)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_PROPERTY(FStrProperty,Z_Param_StringValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsString(Z_Param_KeyName,Z_Param_StringValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsBool)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_UBOOL(Z_Param_BoolValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsBool(Z_Param_KeyName,Z_Param_BoolValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsFloat)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_PROPERTY(FFloatProperty,Z_Param_FloatValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsFloat(Z_Param_KeyName,Z_Param_FloatValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsInt)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_PROPERTY(FIntProperty,Z_Param_IntValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsInt(Z_Param_KeyName,Z_Param_IntValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsEnum)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_PROPERTY(FByteProperty,Z_Param_EnumValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsEnum(Z_Param_KeyName,Z_Param_EnumValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsClass)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_OBJECT(UClass,Z_Param_ClassValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsClass(Z_Param_KeyName,Z_Param_ClassValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execSetValueAsObject)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_GET_OBJECT(UObject,Z_Param_ObjectValue);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetValueAsObject(Z_Param_KeyName,Z_Param_ObjectValue);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsRotator)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FRotator*)Z_Param__Result=P_THIS->GetValueAsRotator(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsVector)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetValueAsVector(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsName)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FName*)Z_Param__Result=P_THIS->GetValueAsName(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsString)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=P_THIS->GetValueAsString(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsBool)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->GetValueAsBool(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsFloat)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(float*)Z_Param__Result=P_THIS->GetValueAsFloat(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsInt)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=P_THIS->GetValueAsInt(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsEnum)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(uint8*)Z_Param__Result=P_THIS->GetValueAsEnum(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsClass)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UClass**)Z_Param__Result=P_THIS->GetValueAsClass(Z_Param_KeyName);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFSMCommonDataManager::execGetValueAsObject)
	{
		P_GET_PROPERTY(FNameProperty,Z_Param_KeyName);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UObject**)Z_Param__Result=P_THIS->GetValueAsObject(Z_Param_KeyName);
		P_NATIVE_END;
	}
	void UFSMCommonDataManager::StaticRegisterNativesUFSMCommonDataManager()
	{
		UClass* Class = UFSMCommonDataManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetValueAsBool", &UFSMCommonDataManager::execGetValueAsBool },
			{ "GetValueAsClass", &UFSMCommonDataManager::execGetValueAsClass },
			{ "GetValueAsEnum", &UFSMCommonDataManager::execGetValueAsEnum },
			{ "GetValueAsFloat", &UFSMCommonDataManager::execGetValueAsFloat },
			{ "GetValueAsInt", &UFSMCommonDataManager::execGetValueAsInt },
			{ "GetValueAsName", &UFSMCommonDataManager::execGetValueAsName },
			{ "GetValueAsObject", &UFSMCommonDataManager::execGetValueAsObject },
			{ "GetValueAsRotator", &UFSMCommonDataManager::execGetValueAsRotator },
			{ "GetValueAsString", &UFSMCommonDataManager::execGetValueAsString },
			{ "GetValueAsVector", &UFSMCommonDataManager::execGetValueAsVector },
			{ "SetValueAsBool", &UFSMCommonDataManager::execSetValueAsBool },
			{ "SetValueAsClass", &UFSMCommonDataManager::execSetValueAsClass },
			{ "SetValueAsEnum", &UFSMCommonDataManager::execSetValueAsEnum },
			{ "SetValueAsFloat", &UFSMCommonDataManager::execSetValueAsFloat },
			{ "SetValueAsInt", &UFSMCommonDataManager::execSetValueAsInt },
			{ "SetValueAsName", &UFSMCommonDataManager::execSetValueAsName },
			{ "SetValueAsObject", &UFSMCommonDataManager::execSetValueAsObject },
			{ "SetValueAsRotator", &UFSMCommonDataManager::execSetValueAsRotator },
			{ "SetValueAsString", &UFSMCommonDataManager::execSetValueAsString },
			{ "SetValueAsVector", &UFSMCommonDataManager::execSetValueAsVector },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsBool_Parms
		{
			FName KeyName;
			bool ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsBool_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FSMCommonDataManager_eventGetValueAsBool_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMCommonDataManager_eventGetValueAsBool_Parms), &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsBool", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsBool_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsClass_Parms
		{
			FName KeyName;
			UClass* ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsClass_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsClass_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsClass", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsClass_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsEnum_Parms
		{
			FName KeyName;
			uint8 ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsEnum_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsEnum_Parms, ReturnValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsEnum", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsEnum_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsFloat_Parms
		{
			FName KeyName;
			float ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsFloat_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsFloat_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsFloat", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsFloat_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsInt_Parms
		{
			FName KeyName;
			int32 ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsInt_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsInt_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsInt", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsInt_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsName_Parms
		{
			FName KeyName;
			FName ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsName_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsName_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsName", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsName_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsObject_Parms
		{
			FName KeyName;
			UObject* ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsObject_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsObject", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsObject_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsRotator_Parms
		{
			FName KeyName;
			FRotator ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsRotator_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsRotator_Parms, ReturnValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsRotator", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsRotator_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsString_Parms
		{
			FName KeyName;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsString_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsString_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsString", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsString_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics
	{
		struct FSMCommonDataManager_eventGetValueAsVector_Parms
		{
			FName KeyName;
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsVector_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventGetValueAsVector_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "GetValueAsVector", nullptr, nullptr, sizeof(FSMCommonDataManager_eventGetValueAsVector_Parms), Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsBool_Parms
		{
			FName KeyName;
			bool BoolValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static void NewProp_BoolValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_BoolValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsBool_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_BoolValue_SetBit(void* Obj)
	{
		((FSMCommonDataManager_eventSetValueAsBool_Parms*)Obj)->BoolValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_BoolValue = { "BoolValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(FSMCommonDataManager_eventSetValueAsBool_Parms), &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_BoolValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::NewProp_BoolValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsBool", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsBool_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsClass_Parms
		{
			FName KeyName;
			UClass* ClassValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_ClassValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsClass_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::NewProp_ClassValue = { "ClassValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsClass_Parms, ClassValue), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::NewProp_ClassValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsClass", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsClass_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsEnum_Parms
		{
			FName KeyName;
			uint8 EnumValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EnumValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsEnum_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::NewProp_EnumValue = { "EnumValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsEnum_Parms, EnumValue), nullptr, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::NewProp_EnumValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsEnum", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsEnum_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsFloat_Parms
		{
			FName KeyName;
			float FloatValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FloatValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsFloat_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::NewProp_FloatValue = { "FloatValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsFloat_Parms, FloatValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::NewProp_FloatValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsFloat", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsFloat_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsInt_Parms
		{
			FName KeyName;
			int32 IntValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IntValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsInt_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::NewProp_IntValue = { "IntValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsInt_Parms, IntValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::NewProp_IntValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsInt", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsInt_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsName_Parms
		{
			FName KeyName;
			FName NameValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_NameValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsName_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::NewProp_NameValue = { "NameValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsName_Parms, NameValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::NewProp_NameValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsName", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsName_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsObject_Parms
		{
			FName KeyName;
			UObject* ObjectValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ObjectValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsObject_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::NewProp_ObjectValue = { "ObjectValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsObject_Parms, ObjectValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::NewProp_ObjectValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsObject", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsObject_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsRotator_Parms
		{
			FName KeyName;
			FRotator VectorValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VectorValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsRotator_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::NewProp_VectorValue = { "VectorValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsRotator_Parms, VectorValue), Z_Construct_UScriptStruct_FRotator, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::NewProp_VectorValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsRotator", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsRotator_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsString_Parms
		{
			FName KeyName;
			FString StringValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_StringValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsString_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::NewProp_StringValue = { "StringValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsString_Parms, StringValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::NewProp_StringValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsString", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsString_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics
	{
		struct FSMCommonDataManager_eventSetValueAsVector_Parms
		{
			FName KeyName;
			FVector VectorValue;
		};
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_KeyName;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_VectorValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::NewProp_KeyName = { "KeyName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsVector_Parms, KeyName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::NewProp_VectorValue = { "VectorValue", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FSMCommonDataManager_eventSetValueAsVector_Parms, VectorValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::NewProp_KeyName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::NewProp_VectorValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFSMCommonDataManager, nullptr, "SetValueAsVector", nullptr, nullptr, sizeof(FSMCommonDataManager_eventSetValueAsVector_Parms), Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UFSMCommonDataManager_NoRegister()
	{
		return UFSMCommonDataManager::StaticClass();
	}
	struct Z_Construct_UClass_UFSMCommonDataManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CommonDataInstance_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CommonDataInstance;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFSMCommonDataManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_FlowStateMachine,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UFSMCommonDataManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsBool, "GetValueAsBool" }, // 2301031791
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsClass, "GetValueAsClass" }, // 3646275142
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsEnum, "GetValueAsEnum" }, // 4002924747
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsFloat, "GetValueAsFloat" }, // 4230800253
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsInt, "GetValueAsInt" }, // 1115823280
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsName, "GetValueAsName" }, // 187001690
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsObject, "GetValueAsObject" }, // 3465227124
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsRotator, "GetValueAsRotator" }, // 2799675181
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsString, "GetValueAsString" }, // 1899084185
		{ &Z_Construct_UFunction_UFSMCommonDataManager_GetValueAsVector, "GetValueAsVector" }, // 1361655827
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsBool, "SetValueAsBool" }, // 3681981532
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsClass, "SetValueAsClass" }, // 1127777999
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsEnum, "SetValueAsEnum" }, // 3514407170
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsFloat, "SetValueAsFloat" }, // 2196903022
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsInt, "SetValueAsInt" }, // 997929457
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsName, "SetValueAsName" }, // 3851456703
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsObject, "SetValueAsObject" }, // 1151182148
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsRotator, "SetValueAsRotator" }, // 2689579519
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsString, "SetValueAsString" }, // 2963429876
		{ &Z_Construct_UFunction_UFSMCommonDataManager_SetValueAsVector, "SetValueAsVector" }, // 2357221971
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataManager_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SM/FSMCommonDataManager.h" },
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFSMCommonDataManager_Statics::NewProp_CommonDataInstance_MetaData[] = {
		{ "ModuleRelativePath", "Public/SM/FSMCommonDataManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UFSMCommonDataManager_Statics::NewProp_CommonDataInstance = { "CommonDataInstance", nullptr, (EPropertyFlags)0x0020080000002000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UFSMCommonDataManager, CommonDataInstance), Z_Construct_UClass_UFSMCommonData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataManager_Statics::NewProp_CommonDataInstance_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataManager_Statics::NewProp_CommonDataInstance_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UFSMCommonDataManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UFSMCommonDataManager_Statics::NewProp_CommonDataInstance,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFSMCommonDataManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFSMCommonDataManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UFSMCommonDataManager_Statics::ClassParams = {
		&UFSMCommonDataManager::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UFSMCommonDataManager_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataManager_Statics::PropPointers),
		0,
		0x000000A0u,
		METADATA_PARAMS(Z_Construct_UClass_UFSMCommonDataManager_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UFSMCommonDataManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UFSMCommonDataManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UFSMCommonDataManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UFSMCommonDataManager, 4118687571);
	template<> FLOWSTATEMACHINE_API UClass* StaticClass<UFSMCommonDataManager>()
	{
		return UFSMCommonDataManager::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UFSMCommonDataManager(Z_Construct_UClass_UFSMCommonDataManager, &UFSMCommonDataManager::StaticClass, TEXT("/Script/FlowStateMachine"), TEXT("UFSMCommonDataManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFSMCommonDataManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
