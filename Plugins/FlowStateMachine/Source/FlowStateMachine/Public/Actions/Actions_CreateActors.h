// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SM/FlowStateAction.h"
#include "Utility/FSMUtility.h"
#include "Actions_CreateActors.generated.h"

class AStaticMeshActor;
class ASkeletalMeshActor;

template<class T>
struct TCreateActorsHelper
{
public:
};

UENUM(BlueprintType)
enum class ECreateActorActionMode : uint8
{
	None = 0, // 只会在创建是应用一次
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
class FLOWSTATEMACHINE_API UCreateActorHelper : public UObject
{
	GENERATED_BODY()

public:
	virtual void InitializeCreateActor(UFlowStateContext* InStateContext);
	UFUNCTION(BlueprintNativeEvent)
	UClass* GetCreateClass() const;
	UFUNCTION(BlueprintNativeEvent)
	void OverrideActorProperty(AActor* ResultActor);
	UFUNCTION(BlueprintNativeEvent)
	void AddActorToCache(UFlowStateContext* InStateContext, AActor* ResultActor);
	UFUNCTION(BlueprintNativeEvent)
	void SwitchActorCache(UFlowStateContext* InStateContext, AActor* ResultActor, EFlowStateLifetime OldLifetime);
	UFUNCTION(BlueprintNativeEvent)
	void UpdateActorTransform(AActor* ResultActor);
protected:
	/** 用于标识对象的唯一名称 */
	UPROPERTY(EditAnywhere)
	FName UniqueName;

	/** 对象的生命周期 */
	UPROPERTY(EditAnywhere)
	EFlowStateLifetime Lifetime;

	/** 行为模式: None 不做任何处理，Override 覆盖旧Actor的内容，Additive 与之前的值进行叠加 */
	UPROPERTY(EditAnywhere)
	ECreateActorActionMode ActionMode = ECreateActorActionMode::None;

	/** 位置信息 */
	UPROPERTY(EditAnywhere)
	FTransform Transform;
};

UCLASS()
class FLOWSTATEMACHINE_API UCreateSkeletalActorHelper : public UCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual UClass* GetCreateClass_Implementation() const override;
	virtual void OverrideActorProperty_Implementation(AActor* ResultActor) override;

protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<USkeletalMesh> Mesh;
};

UCLASS()
class FLOWSTATEMACHINE_API UCreateStaticActorHelper : public UCreateActorHelper
{
	GENERATED_BODY()

public:
	virtual UClass* GetCreateClass_Implementation() const override;
	virtual void OverrideActorProperty_Implementation(AActor* ResultActor) override;
	virtual void UpdateActorTransform_Implementation(AActor* ResultActor) override;

protected:
	/** 模型资产，若找到了同名的Actor会自动将模型替换为新值 */
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UStaticMesh> Mesh;

	/** 静态Actor的移动性 */
	UPROPERTY(EditAnywhere)
	bool bMoveable = false;
};

/**
 * 
 */
UCLASS()
class FLOWSTATEMACHINE_API UActions_CreateActors : public UFSMRuntimeSubNode_Action
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category = "CreateActors")
	TArray<UCreateActorHelper*> CreateActors;

	virtual void ExecuteAction(UFSMRuntimeNode* Instance) override;
};
