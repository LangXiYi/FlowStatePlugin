// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/FSMCommonData.h"

#include "Data/CommonDataType/FSMCommonDataType.h"
#include "Utility/FSMUtility.h"

const FCommonDataEntry* UFSMCommonData::GetKey(FCommonData::FKey KeyID) const
{
    if (Keys.IsValidIndex(KeyID))
    {
        return &Keys[KeyID];
    }
    return nullptr;
}

FCommonData::FKey UFSMCommonData::GetKeyID(const FName KeyName) const
{
    return InternalGetKeyID(KeyName);
}

FName UFSMCommonData::GetKeyName(FCommonData::FKey KeyID) const
{
    const FCommonDataEntry* KeyEntry = GetKey(KeyID);
    return KeyEntry ? KeyEntry->EntryName : NAME_None;
}

TSubclassOf<UFSMCommonDataType> UFSMCommonData::GetDataType(FCommonData::FKey KeyID) const
{
    const FCommonDataEntry* KeyEntry = GetKey(KeyID);
    return KeyEntry && KeyEntry->KeyType ? KeyEntry->KeyType->GetClass() : nullptr;
}

FCommonData::FKey UFSMCommonData::InternalGetKeyID(const FName& KeyName) const
{
    for (int32 KeyIndex = 0; KeyIndex < Keys.Num(); KeyIndex++)
    {
        if (Keys[KeyIndex].EntryName == KeyName)
        {
            return KeyIndex;
        }
    }
    FSMLOGW("未找到名称为 '%s' 的字段!!!", *KeyName.ToString());
    return FCommonData::InvalidKey;
}
