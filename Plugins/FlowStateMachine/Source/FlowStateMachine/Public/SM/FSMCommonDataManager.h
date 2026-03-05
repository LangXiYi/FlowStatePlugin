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

	FCommonData::FKey GetKeyID(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	UObject* GetValueAsObject(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	UClass* GetValueAsClass(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	uint8 GetValueAsEnum(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	int32 GetValueAsInt(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	float GetValueAsFloat(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	bool GetValueAsBool(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	FString GetValueAsString(FName KeyName) const;
	
	UFUNCTION(BlueprintPure)
	FName GetValueAsName(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	FVector GetValueAsVector(FName KeyName) const;

	UFUNCTION(BlueprintPure)
	FRotator GetValueAsRotator(FName KeyName) const;

	UFUNCTION(BlueprintCallable)
	void SetValueAsObject(FName KeyName, UObject* ObjectValue);
	
	UFUNCTION(BlueprintCallable)
	void SetValueAsClass(FName KeyName, UClass* ClassValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsEnum(FName KeyName, uint8 EnumValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsInt(FName KeyName, int32 IntValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsFloat(FName KeyName, float FloatValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsBool(FName KeyName, bool BoolValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsString(FName KeyName, FString StringValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsName(FName KeyName, FName NameValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsVector(FName KeyName, FVector VectorValue);

	UFUNCTION(BlueprintCallable)
	void SetValueAsRotator(FName KeyName, FRotator VectorValue);

protected:
	template<class TDataClass>
	bool SetValue(FName KeyName, typename TDataClass::FDataType Value);

	template<class TDataClass>
	bool SetValue(FCommonData::FKey KeyID, typename TDataClass::FDataType Value);
	
	template<class TDataClass>
	typename TDataClass::FDataType GetValue(FName KeyName) const;

	template<class TDataClass>
	typename TDataClass::FDataType GetValue(FCommonData::FKey KeyID) const;

UPROPERTY(Transient)
	UFSMCommonData* CommonDataInstance;
	
	/** reset to false every time a new BB asset is assigned to this component */
	uint32 bSynchronizedKeyPopulated : 1;
};

template <class TDataClass>
bool UFSMCommonDataManager::SetValue(FName KeyName, typename TDataClass::FDataType Value)
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
	return TDataClass::SetValue(static_cast<TDataClass*>(KeyOb), Value);
}

template <class TDataClass>
typename TDataClass::FDataType UFSMCommonDataManager::GetValue(FName KeyName) const
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
	return TDataClass::GetValue(static_cast<TDataClass*>(KeyOb));
}


