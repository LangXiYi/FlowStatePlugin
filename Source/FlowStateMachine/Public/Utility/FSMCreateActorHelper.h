#pragma once

#include "CoreMinimal.h"
#include "FlowStateCollectInterface.h"
#include "Utility/FSMUtility.h"
#include "FSMCreateActorHelper.generated.h"

class UFlowStateContext;

UENUM(BlueprintType)
enum class ECreateActorActionMode : uint8
{
	World = 0, // 使用世界原点作为 Actor 生成位置的参考坐标系
	Relative,  // 相对的作为，需要提供共一个额外的坐标作为参考
};

/**
 * 继承该类型即可实现对自定义类型的Actor进行管理
 * 采用建造者模式，抽象所有不可控步骤给子类实现
 */
UCLASS(Abstract, Blueprintable, EditInlineNew)
class FLOWSTATEMACHINE_API UFSMCreateActorHelper : public UObject, public IFlowStateCollectInterface
{
	GENERATED_BODY()

public:
    virtual class UWorld* GetWorld() const override;
	
    virtual void CreateActor(UFlowStateContext* InStateContext);

	virtual void GetStatePinInfos(TArray<FStatePinInfo>& PinInfos) const override;

protected:
	/** 初始化目标角色（只执行一次），只会在对象被创建的是否触发 */
	virtual void InitializeActor(AActor* Target);
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "InitializeActor")
	void NativeInitializeActor(AActor* Target);

	/** 重载目标属性(会多次触发)，不论Actor是否已经存在都会触发该函数 */
	virtual void OverrideProperty(AActor* ResultActor);
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "OverrideProperty")
	void NativeOverrideProperty(AActor* ResultActor);

	/** 获取需要创建的对象类 */
	TSubclassOf<AActor> GetCreateClass() const;
	virtual TSubclassOf<AActor> GetDefaultCreateClass() const;
	UFUNCTION(BlueprintImplementableEvent, DisplayName = "GetCreateClass")
	TSubclassOf<AActor> NativeGetCreateClass() const;

	/** 改变目标的位置信息 */
	virtual void UpdateActorTransform(AActor* ResultActor);

public:
	/** 返回对象的有效性 */
	virtual bool IsValid() const;

protected:
	/** 用于标识对象的唯一名称 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FName UniqueName;

	/** 对象的生命周期 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	EFlowStateLifetime Lifetime;

	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FRotator Rotator;

	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FVector Scale = FVector(1, 1, 1);

	/** 行为模式: None 不做任何处理，Override 覆盖旧Actor的内容，Additive 与之前的值进行叠加 */
	UPROPERTY(EditAnywhere, AdvancedDisplay, Category = "CreateActor|Advanced")
	ECreateActorActionMode TransformMode = ECreateActorActionMode::World;

	// FCollisionProfile
};

UCLASS()
class UCreateSkeletalActorHelper : public UFSMCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual void InitializeActor(AActor* Target) override;
	virtual void OverrideProperty(AActor* ResultActor) override;

	virtual TSubclassOf<AActor> GetDefaultCreateClass() const override;
	
protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	TSoftObjectPtr<USkeletalMesh> Mesh;

	/** 碰撞预设 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FName CollisionProfileName;

	UPROPERTY(EditAnywhere, Category = "CreateActor|Advanced")
	TSoftObjectPtr<UAnimSequence> AnimationAsset;

	UPROPERTY(EditAnywhere, Category = "CreateActor|Advanced")
	bool bIsAutoPlay = true;

	UPROPERTY(EditAnywhere, Category = "CreateActor|Advanced")
	bool bIsLoop = true;

	UPROPERTY(EditAnywhere, Category = "CreateActor|Advanced")
	float InitAnimPos = 0.f;
};

UCLASS()
class UCreateStaticActorHelper : public UFSMCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual void InitializeActor(AActor* Target) override;
	virtual void OverrideProperty(AActor* ResultActor) override;
	
	virtual TSubclassOf<AActor> GetDefaultCreateClass() const override;
	
protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	TSoftObjectPtr<UStaticMesh> Mesh;

	/** 碰撞预设 */
	UPROPERTY(EditAnywhere, Category = "CreateActor")
	FName CollisionProfileName;
};
