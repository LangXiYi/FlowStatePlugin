#include "SM/FSMCommonDataManager.h"

#include "Data/CommonDataType/FSMCommonDataType_Bool.h"
#include "Data/CommonDataType/FSMCommonDataType_Class.h"
#include "Data/CommonDataType/FSMCommonDataType_Enum.h"
#include "Data/CommonDataType/FSMCommonDataType_Float.h"
#include "Data/CommonDataType/FSMCommonDataType_Int.h"
#include "Data/CommonDataType/FSMCommonDataType_Name.h"
#include "Data/CommonDataType/FSMCommonDataType_Object.h"
#include "Data/CommonDataType/FSMCommonDataType_Rotator.h"
#include "Data/CommonDataType/FSMCommonDataType_String.h"
#include "Data/CommonDataType/FSMCommonDataType_Vector.h"

void UFSMCommonDataManager::Initialize(const UFSMCommonData& NewAsset)
{
    CommonDataInstance = Cast<UFSMCommonData>(StaticDuplicateObject(&NewAsset, this));
    check(CommonDataInstance)

    for (int i = 0; i < CommonDataInstance->Keys.Num(); ++i)
    {
        if (CommonDataInstance->Keys[i].KeyType)
        {
            UFSMCommonDataType* DataType = Cast<UFSMCommonDataType>(
                StaticDuplicateObject(CommonDataInstance->Keys[i].KeyType, this));
            CommonDataInstance->Keys[i].KeyType = DataType;
        }
        else
        {
            CommonDataInstance->Keys.RemoveAt(i--);
        }
    }
}

FCommonData::FKey UFSMCommonDataManager::GetKeyID(FName KeyName) const
{
    return CommonDataInstance ? CommonDataInstance->GetKeyID(KeyName) : INDEX_NONE;
}

UObject* UFSMCommonDataManager::GetValueAsObject(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Object>(KeyName);
}

UClass* UFSMCommonDataManager::GetValueAsClass(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Class>(KeyName);
}

uint8 UFSMCommonDataManager::GetValueAsEnum(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Enum>(KeyName);
}

int32 UFSMCommonDataManager::GetValueAsInt(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Int>(KeyName);
}

float UFSMCommonDataManager::GetValueAsFloat(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Float>(KeyName);
}

bool UFSMCommonDataManager::GetValueAsBool(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Bool>(KeyName);
}

FString UFSMCommonDataManager::GetValueAsString(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_String>(KeyName);
}

FName UFSMCommonDataManager::GetValueAsName(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Name>(KeyName);
}

FVector UFSMCommonDataManager::GetValueAsVector(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Vector>(KeyName);
}

FRotator UFSMCommonDataManager::GetValueAsRotator(FName KeyName) const
{
    return GetValue<UFSMCommonDataType_Rotator>(KeyName);
}

void UFSMCommonDataManager::SetValueAsObject(FName KeyName, UObject* ObjectValue)
{
    SetValue<UFSMCommonDataType_Object>(KeyName, ObjectValue);
}

void UFSMCommonDataManager::SetValueAsClass(FName KeyName, UClass* ClassValue)
{
    SetValue<UFSMCommonDataType_Class>(KeyName, ClassValue);
}

void UFSMCommonDataManager::SetValueAsEnum(FName KeyName, uint8 EnumValue)
{
    SetValue<UFSMCommonDataType_Int>(KeyName, EnumValue);
}

void UFSMCommonDataManager::SetValueAsInt(FName KeyName, int32 IntValue)
{
    SetValue<UFSMCommonDataType_Int>(KeyName, IntValue);
}

void UFSMCommonDataManager::SetValueAsFloat(FName KeyName, float FloatValue)
{
    SetValue<UFSMCommonDataType_Float>(KeyName, FloatValue);
}

void UFSMCommonDataManager::SetValueAsBool(FName KeyName, bool BoolValue)
{
    SetValue<UFSMCommonDataType_Bool>(KeyName, BoolValue);
}

void UFSMCommonDataManager::SetValueAsString(FName KeyName, FString StringValue)
{
    SetValue<UFSMCommonDataType_String>(KeyName, StringValue);
}

void UFSMCommonDataManager::SetValueAsName(FName KeyName, FName NameValue)
{
    SetValue<UFSMCommonDataType_Name>(KeyName, NameValue);
}

void UFSMCommonDataManager::SetValueAsVector(FName KeyName, FVector VectorValue)
{
    SetValue<UFSMCommonDataType_Vector>(KeyName, VectorValue);
}

void UFSMCommonDataManager::SetValueAsRotator(FName KeyName, FRotator VectorValue)
{
    SetValue<UFSMCommonDataType_Rotator>(KeyName, VectorValue);
}
