#pragma once

#include "CoreMinimal.h"
#include "Utility/FSMUtility.h"
#include "FSMCreateActorHelper.generated.h"

class UFlowStateContext;

UENUM(BlueprintType)
enum class ECreateActorActionMode : uint8
{
	None = 0,
	Override_World, // 覆盖 世界坐标系
	Override_Local, // 覆盖 本地坐标系
	Additive_World, // 叠加 世界坐标系
	Additive_Local, // 叠加 本地坐标系
};

/**
 * 继承该类型即可实现对自定义类型的Actor进行管理
 * 采用建造者模式，抽象所有不可控步骤给子类实现
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class FLOWSTATEMACHINE_API UFSMCreateActorHelper : public UObject
{
	GENERATED_BODY()

public:
	virtual void CreateActor(UFlowStateContext* InStateContext);
	/** 获取需要创建的对象类 */
	UFUNCTION(BlueprintNativeEvent)
	TSubclassOf<AActor> GetCreateClass() const;
	/** 重载目标属性，不论Actor是否已经存在都会触发该函数 */
	UFUNCTION(BlueprintNativeEvent)
	void OverrideActorProperty(AActor* ResultActor);
	/** 改变目标的位置信息 */
	UFUNCTION(BlueprintNativeEvent)
	void UpdateActorTransform(AActor* ResultActor);
	/** 初始化目标角色，只会在对象被创建的是否触发 */
	UFUNCTION(BlueprintNativeEvent)
	void InitializeActor(AActor* Target);

	/** 返回对象的有效性 */
	virtual bool IsValid() const;

	/** 将目标添加至缓存 */
	virtual void AddActorToCache(UFlowStateContext* InStateContext, AActor* ResultActor);
	/** 切换目标的缓冲区 */
	virtual void SwitchActorCache(UFlowStateContext* InStateContext, AActor* ResultActor, EFlowStateLifetime OldLifetime);

protected:
	/** 用于标识对象的唯一名称 */
	UPROPERTY(EditAnywhere, Category = "Basic")
	FName UniqueName;

	/** 对象的生命周期 */
	UPROPERTY(EditAnywhere, Category = "Basic")
	EFlowStateLifetime Lifetime;

	/** 位置信息,在创建对象时固定使用一次，否则会依据 */
	UPROPERTY(EditAnywhere, Category = "Basic")
	FTransform Transform;

	/** 行为模式: None 不做任何处理，Override 覆盖旧Actor的内容，Additive 与之前的值进行叠加 */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "Basic|Advanced")
	ECreateActorActionMode TransformMode = ECreateActorActionMode::None;
};

UCLASS()
class UCreateSkeletalActorHelper : public UFSMCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual void InitializeActor_Implementation(AActor* Target) override;
	virtual TSubclassOf<AActor> GetCreateClass_Implementation() const override;
	virtual void OverrideActorProperty_Implementation(AActor* ResultActor) override;

protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere, Category = "SkeletalMeshActor")
	TSoftObjectPtr<USkeletalMesh> Mesh;

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshActor")
	TSoftObjectPtr<UAnimSequence> AnimationAsset;

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshActor|Advanced")
	bool bIsAutoPlay = true;

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshActor|Advanced")
	bool bIsLoop = true;

	UPROPERTY(EditAnywhere, Category = "SkeletalMeshActor|Advanced")
	float InitAnimPos = 0.f;
};

UCLASS()
class UCreateStaticActorHelper : public UFSMCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual void InitializeActor_Implementation(AActor* Target) override;
	virtual TSubclassOf<AActor> GetCreateClass_Implementation() const override;
	virtual void OverrideActorProperty_Implementation(AActor* ResultActor) override;
	virtual void UpdateActorTransform_Implementation(AActor* ResultActor) override;

protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere, Category = "StaticMeshActor")
	TSoftObjectPtr<UStaticMesh> Mesh;

	/** 静态Actor的移动性 */
	UPROPERTY(EditAnywhere, Category = "StaticMeshActor")
	bool bMoveable = false;
};
