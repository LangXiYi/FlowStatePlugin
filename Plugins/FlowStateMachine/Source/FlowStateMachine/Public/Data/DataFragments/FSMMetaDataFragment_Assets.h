#pragma once
#include "CoreMinimal.h"
#include "FSMMetaDataFragment.h"
#include "FSMMetaDataFragment_Assets.generated.h"

/**
 * 该数据保存在 OperationGuideDataAsset 中，内部保存的数据会跟随该资产被一起加载。
 * 关卡实例保存的是数据资产的ID而非数据资产本身，故调用 OpenLevel 打开新关卡时不会同步加载这些资产
 * 在关卡打开且所有Actor的 BeginPlay 事件被触发后，才会触发资产加载事件，将资源加载到内存中。
 * 数据长期有效，除非数据资产被卸载
 */
UCLASS(NotBlueprintable)
class UFSMMetaDataFragment_Assets : public UFSMMetaDataFragment
{
	GENERATED_BODY()

public:
	virtual UObject* FindAsset(const FName Name, TSubclassOf<UObject> AssetType) const;

	template<class T>
	T* FindAsset(const FName Name) const
	{
		return (T*)FindAsset(Name, T::StaticClass());
	}

protected:
	UObject* FindAssetByStaticMesh(const FName Name) const;
	UObject* FindAssetBySkeletalMesh(const FName Name) const;
	UObject* FindAssetByAnimSequence(const FName Name) const;

private:
	/** 需要使用到的模型资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "MetaDataFragment", meta = (AllowPrivateAccess = true))
	TMap<FName, UStaticMesh*> SM_Meshes;

	/** 需要使用到的骨骼资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "MetaDataFragment", meta = (AllowPrivateAccess = true))
	TMap<FName, USkeletalMesh*> SK_Meshes;

	/** 需要使用到的动画资产 */
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "MetaDataFragment", meta = (AllowPrivateAccess = true))
	TMap<FName, UAnimSequence*> Animations;
};

