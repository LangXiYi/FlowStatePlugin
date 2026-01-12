#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Data/FSMCommonData.h"
#include "Data/CommonDataType/FSMCommonDataType.h"
#include "Utility/FSMUtility.h"

#include "FSMCommonDataManager.Generated.h"

class UFlowStateContext;
class UFSMCommonData;

UCLASS()
class UFSMCommonDataManager : public UObject
{
	GENERATED_BODY()

	friend class UFSMCommonDataType;

public:
	void Initialize(const UFSMCommonData& NewAsset);

	FCommonData::FKey GetKeyID(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	UObject* GetValueAsObject(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	UClass* GetValueAsClass(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	uint8 GetValueAsEnum(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	int32 GetValueAsInt(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	float GetValueAsFloat(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	bool GetValueAsBool(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	FString GetValueAsString(const FName& KeyName) const;
	
	UFUNCTION(BlueprintPure)
	FName GetValueAsName(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	FVector GetValueAsVector(const FName& KeyName) const;

	UFUNCTION(BlueprintPure)
	FRotator GetValueAsRotator(const FName& KeyName) const;

	UFUNCTION(BlueprintCallable)
	void SetValueAsObject(const FName& KeyName, UObject* ObjectValue);
	
	UFUNCTION(BlueprintCallable)
	void SetValueAsClass(const FName& KeyName, UClass* ClassValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsEnum(const FName& KeyName, uint8 EnumValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsInt(const FName& KeyName, int32 IntValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsFloat(const FName& KeyName, float FloatValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsBool(const FName& KeyName, bool BoolValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsString(const FName& KeyName, FString StringValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsName(const FName& KeyName, FName NameValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsVector(const FName& KeyName, FVector VectorValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsRotator(const FName& KeyName, FRotator VectorValue);

protected:
	template<class TDataClass>
	bool SetValue(const FName& KeyName, typename TDataClass::FDataType Value);

	template<class TDataClass>
	bool SetValue(FCommonData::FKey KeyID, typename TDataClass::FDataType Value);
	
	template<class TDataClass>
	typename TDataClass::FDataType GetValue(const FName& KeyName) const;

	template<class TDataClass>
	typename TDataClass::FDataType GetValue(FCommonData::FKey KeyID) const;

protected:
	UPROPERTY(Transient)
	UFSMCommonData* CommonDataInstance;
	
	/** reset to false every time a new BB asset is assigned to this component */
	uint32 bSynchronizedKeyPopulated : 1;
};

template <class TDataClass>
bool UFSMCommonDataManager::SetValue(const FName& KeyName, typename TDataClass::FDataType Value)
{
	const FCommonData::FKey KeyID = GetKeyID(KeyName);
	return SetValue<TDataClass>(KeyID, Value);
}

template <class TDataClass>
bool UFSMCommonDataManager::SetValue(FCommonData::FKey KeyID, typename TDataClass::FDataType Value)
{
	const FCommonDataEntry* EntryInfo = CommonDataInstance ? CommonDataInstance->GetKey(KeyID) : nullptr;
	if ((EntryInfo == nullptr) || (EntryInfo->KeyType == nullptr) || (EntryInfo->KeyType->GetClass() != TDataClass::StaticClass()))
	{
		return false;
	}
	UFSMCommonDataType* KeyOb = EntryInfo->KeyType;
	return TDataClass::SetValue((TDataClass*)KeyOb, Value);
}

template <class TDataClass>
typename TDataClass::FDataType UFSMCommonDataManager::GetValue(const FName& KeyName) const
{
	const FCommonData::FKey KeyID = GetKeyID(KeyName);
	return GetValue<TDataClass>(KeyID);
}

template <class TDataClass>
typename TDataClass::FDataType UFSMCommonDataManager::GetValue(FCommonData::FKey KeyID) const
{
	const FCommonDataEntry* EntryInfo = CommonDataInstance ? CommonDataInstance->GetKey(KeyID) : nullptr;
	if ((EntryInfo == nullptr) || (EntryInfo->KeyType == nullptr) || (EntryInfo->KeyType->GetClass() != TDataClass::StaticClass()))
	{
		return TDataClass::InvalidValue;
	}
	UFSMCommonDataType* KeyOb = EntryInfo->KeyType;
	return TDataClass::GetValue((TDataClass*)KeyOb);
}


