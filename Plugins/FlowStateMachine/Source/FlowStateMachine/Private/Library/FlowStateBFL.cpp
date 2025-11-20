// Fill out your copyright notice in the Description page of Project Settings.


#include "Library/FlowStateBFL.h"

#include "Actors/FlowStateCameraActor.h"
#include "Animation/AnimSingleNodeInstance.h"
#include "Animation/SkeletalMeshActor.h"
#include "Components/SplineComponent.h"
#include "Data/FlowStateDataAsset.h"
#include "Engine/StaticMeshActor.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"
#include "System/FlowStateWorldSettings.h"
#include "Widgets/FlowStateLayoutWidget.h"
#include "Widgets/GameplayTagSlot.h"

TSubclassOf<UFlowState> UFlowStateBFL::GetStartFlowState(UObject* WorldContextObject)
{
	UFlowStateDataAsset* Asset = GetFlowStateDataAsset(WorldContextObject);
	if (Asset)
	{
		return Asset->StartState;
	}
	return nullptr;
}

UFlowStateDataAsset* UFlowStateBFL::GetFlowStateDataAsset(UObject* WorldContextObject)
{
	AFlowStateWorldSettings* WorldSettings = AFlowStateWorldSettings::Get(WorldContextObject);;
	if (WorldSettings)
	{
		return WorldSettings->GetOperationGuideDataAsset();
	}
	return nullptr;
}

UFlowStateDataFragment* UFlowStateBFL::FindFlowStateDataFragment(UObject* WorldContextObject,
	TSubclassOf<UFlowStateDataFragment> FragmentClass)
{
	UFlowStateDataAsset* DataAsset = GetFlowStateDataAsset(WorldContextObject);
	if (DataAsset != nullptr)
	{
		return DataAsset->FindDataFragment(FragmentClass);
	}
	return nullptr;
}

bool UFlowStateBFL::IsFlowStateLevel(UObject* WorldContextObject)
{
	AFlowStateWorldSettings* WorldSettings = AFlowStateWorldSettings::Get(WorldContextObject);
	if (WorldSettings)
	{
		return WorldSettings->IsTrainLevel();
	}
	return false;
}

UFlowState* UFlowStateBFL::SwitchToFlowState(UObject* WorldContextObject, TSubclassOf<UFlowState> FlowStateClass)
{
	check(FlowStateClass);
	if (FlowStateClass)
	{
		UFlowStateContext* Context = GetFlowStateContext(WorldContextObject);
		return Context->SwitchToByClass(FlowStateClass);
	}
	return nullptr;
}

UFlowState* UFlowStateBFL::SwitchToFlowStateByIndex(UObject* WorldContextObject, int32 Index)
{
	UFlowStateContext* Context = GetFlowStateContext(WorldContextObject);
	if (Context)
	{
		return Context->SwitchToByIndex(Index);
	}
	return nullptr;
}

UFlowState* UFlowStateBFL::SwitchToFlowStateAndInitWidget(UObject* WorldContextObject,
                                                          TSubclassOf<UFlowState> FlowStateClass, UFlowStateLayoutWidget* Layout)
{
	UFlowState* FlowState = SwitchToFlowState(WorldContextObject, FlowStateClass);
	if (FlowState)
	{
		FlowState->InitWidget(Layout);
	}
	return FlowState;
}

UFlowState* UFlowStateBFL::SwitchToFlowStateAndInitWidgetByIndex(UObject* WorldContextObject, int32 Index,
	UFlowStateLayoutWidget* Layout)
{
	UFlowState* FlowState = SwitchToFlowStateByIndex(WorldContextObject, Index);
	if (FlowState)
	{
		FlowState->InitWidget(Layout);
	}
	return FlowState;
}

UFlowStateContext* UFlowStateBFL::GetFlowStateContext(UObject* WorldContextObject)
{
	check(WorldContextObject);
	if (WorldContextObject == nullptr)
	{
		return nullptr;
	}
	UWorld* World = WorldContextObject->GetWorld();
	check(World);
	if (World == nullptr)
	{
		return nullptr;
	}
	AFlowStateWorldSettings* WorldSettings = Cast<AFlowStateWorldSettings>(World->GetWorldSettings());
	check(WorldSettings);
	if (WorldSettings == nullptr)
	{
		return nullptr;
	}
	return WorldSettings->GetFlowStateContext();
}

UFlowState* UFlowStateBFL::GetCurFlowState(UObject* WorldContextObject)
{
	return GetCurFlowStateAs<UFlowState>(WorldContextObject);
}

UFlowState* UFlowStateBFL::GetCurFlowStateAs(UObject* WorldContextObject, TSubclassOf<UFlowState> Type)
{
	check(WorldContextObject);
	check(Type)
	UFlowStateContext* Context = UFlowStateBFL::GetFlowStateContext(WorldContextObject);
	if (Context)
	{
		return Context->GetCurrentState(Type);
	}
	return nullptr;
}

AFlowStateCameraActor* UFlowStateBFL::SetViewTarget(UObject* WorldContextObject, FName CameraName, float FOV,
	bool bIsForceReset)
{
	AFlowStateWorldSettings* WorldSettings = AFlowStateWorldSettings::Get(WorldContextObject);
	if (WorldSettings)
	{
		AFlowStateCameraActor* FlowStateCameraActor = WorldSettings->FindCamera<AFlowStateCameraActor>(CameraName);
		if (FlowStateCameraActor)
		{
			FlowStateCameraActor->PreBecomeViewTarget(FOV, bIsForceReset);
			APlayerController* PC = WorldContextObject->GetWorld()->GetFirstPlayerController();
			check(PC);
			PC->SetViewTarget(FlowStateCameraActor);
			return FlowStateCameraActor;
		}
	}
	return nullptr;
}

AFlowStateCameraActor* UFlowStateBFL::SetViewTargetAndRotationModeByPos(UObject* WorldContextObject, FName CameraName,
	float FOV, FVector OriginPos, ECameraRotationMode RotationMode, bool bIsForceReset)
{
	AFlowStateWorldSettings* WorldSettings = AFlowStateWorldSettings::Get(WorldContextObject);
	if (WorldSettings)
	{
		AFlowStateCameraActor* FlowStateCameraActor = WorldSettings->FindCamera<AFlowStateCameraActor>(CameraName);
		if (FlowStateCameraActor)
		{
			FlowStateCameraActor->PreBecomeViewTarget(FOV, bIsForceReset, RotationMode, OriginPos);
			APlayerController* PC = WorldContextObject->GetWorld()->GetFirstPlayerController();
			check(PC);
			PC->SetViewTarget(FlowStateCameraActor);
			return FlowStateCameraActor;
		}
	}
	return nullptr;
}
AFlowStateCameraActor* UFlowStateBFL::SetViewTargetAndRotationModeByActors(UObject* WorldContextObject,
	FName CameraName, float FOV, TArray<AActor*> OriginTarget, ECameraRotationMode RotationMode, FVector OriginOffset,
	bool bIsForceReset)
{
	AFlowStateWorldSettings* WorldSettings = AFlowStateWorldSettings::Get(WorldContextObject);
	if (WorldSettings)
	{
		AFlowStateCameraActor* FlowStateCameraActor = WorldSettings->FindCamera<AFlowStateCameraActor>(CameraName);
		if (FlowStateCameraActor)
		{
			FVector NewLocation = FVector::ZeroVector;
			for (AActor* Actor : OriginTarget)
			{
				if (Actor != nullptr)
				{
					NewLocation += Actor->GetActorLocation();
				}
			}
			NewLocation /= (OriginTarget.Num() > 0 ? OriginTarget.Num() : 1);
			NewLocation += OriginOffset;
			FlowStateCameraActor->PreBecomeViewTarget(FOV, bIsForceReset, RotationMode, NewLocation);
			APlayerController* PC = WorldContextObject->GetWorld()->GetFirstPlayerController();
			check(PC);
			PC->SetViewTarget(FlowStateCameraActor);
			return FlowStateCameraActor;
		}
	}
	return nullptr;
}

void UFlowStateBFL::SetActorStaticMesh(AActor* Target, UStaticMesh* Mesh)
{
	if (Target && Target->IsA<AActor>())
	{
		UStaticMeshComponent* StaticMeshComponent = static_cast<UStaticMeshComponent*>(Target->GetComponentByClass(UStaticMeshComponent::StaticClass()));
		if (StaticMeshComponent)
		{
			static_cast<AStaticMeshActor*>(Target)->SetMobility(EComponentMobility::Movable);
			StaticMeshComponent->SetStaticMesh(Mesh);
		}
	}
}

void UFlowStateBFL::SetActorSkeletalMesh(AActor* Target, USkeletalMesh* Mesh)
{
	if (Target && Target->IsA<AActor>())
	{
		USkeletalMeshComponent* SkeletalMeshComponent = static_cast<USkeletalMeshComponent*>(Target->GetComponentByClass(USkeletalMeshComponent::StaticClass()));
		if (SkeletalMeshComponent)
		{
			SkeletalMeshComponent->SetSkeletalMesh(Mesh);
		}
	}
}

void UFlowStateBFL::ManualPlayAnim(ASkeletalMeshActor* Target, UAnimSequence* Animation, float Rate)
{
	if (Target == nullptr)
	{
		return;
	}
	if (Animation == nullptr)
	{
		return;
	}
	class USkeletalMeshComponent* SkeletalMeshComponent = Target->GetSkeletalMeshComponent();
	if (SkeletalMeshComponent->SkeletalMesh == nullptr)
	{
		return;
	}
	SkeletalMeshComponent->SetAnimationMode(EAnimationMode::AnimationSingleNode);
	// 更新动画资产
	class UAnimSingleNodeInstance* SingleNodeInstance = SkeletalMeshComponent->GetSingleNodeInstance();
	if (SingleNodeInstance)
	{
		UAnimationAsset* OriginAnimation = SingleNodeInstance->GetAnimationAsset();
		if (OriginAnimation == nullptr || OriginAnimation != Animation)
		{
			SingleNodeInstance->SetAnimationAsset(Animation, false);
			SingleNodeInstance->SetPlaying(false);
		}
	}
	// 设置动画播放进度
	float PlayPos = Rate * Animation->SequenceLength;
	SkeletalMeshComponent->SetPosition(PlayPos);
}

bool UFlowStateBFL::FindActorFromCache(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass,
	FName ActorTag, AActor*& FindActor)
{
	UFlowState* CurFlowStateAs = GetCurFlowStateAs<UFlowState>(WorldContextObject);
	if (CurFlowStateAs)
	{
		FindActor = CurFlowStateAs->FindActorFromCache(ActorClass, ActorTag);
		return FindActor != nullptr;
	}
	return false;
}

UUserWidget* UFlowStateBFL::CreateAndBindWidget(UObject* WorldContextObject, UFlowStateLayoutWidget* WidgetLayout, TSubclassOf<UUserWidget> WidgetType,
                                                        FGameplayTag WidgetSlotTag, EFlowStateLifetime Lifetime)
{
	if (WidgetLayout == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Widget Layout is nullptr."));
		return nullptr;
	}
	UGameplayTagSlot* Slot = WidgetLayout->FindSlot(WidgetSlotTag);
	bool bCreateNewWidget = true;
	if (Slot && Slot->HasAnyChildren())
	{
		UWidget* ChildWidget = Slot->GetChildAt(0);
		if (ChildWidget->GetClass() != WidgetType)
		{
			UE_LOG(LogTemp, Warning, TEXT("目标插槽存在其他对象，期望创建的控件类型与槽内控件类型不一致，请检查代码避免重复创建"))
			return nullptr;
		}
		// 槽内存在同类控件
		bCreateNewWidget = false;
	}
	UUserWidget* Widget = bCreateNewWidget ? CreateWidget(WidgetLayout, WidgetType) : (UUserWidget*)Slot->GetChildAt(0);
	if (Widget)
	{
		if (bCreateNewWidget)
		{
			WidgetLayout->AddChildTo(WidgetSlotTag, Widget);
		}
		else
		{
			Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		}
		UFlowState* FlowState = GetCurFlowState(WorldContextObject);
		InitTargetLifetime(FlowState, Widget, Lifetime);
		return Widget;
	}
	return nullptr;
}

AActor* UFlowStateBFL::InitActorLifetimeState(AActor* Target, EFlowStateLifetime Lifetime, FName ActorTag)
{
	UFlowState* FlowState = GetCurFlowState(Target);
	InitTargetLifetime(FlowState, Target, Lifetime);
	
	if (ActorTag != NAME_None)
	{
		Target->Tags.Add(ActorTag);
	}
	else
	{
		// 生命周期为空的对象 Tag 不得为空。 
		check(Lifetime != EFlowStateLifetime::None);
	}
	Target->SetActorHiddenInGame(false);
	return Target;
}

bool UFlowStateBFL::SplineTraceByChannel(const UObject* WorldContextObject, class USplineComponent* Spline,
	int32 Precision, float Radius, ETraceTypeQuery TraceChannel, bool bTraceComplex,
	const TArray<AActor*>& ActorsToIgnore, EDrawDebugTrace::Type DrawDebugType, FHitResult& OutHit, float& Time,
	bool bIgnoreSelf, FLinearColor TraceColor, FLinearColor TraceHitColor, float DrawTime)
{
	if (Spline == nullptr)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Red, TEXT("Spline is nullptr."));
		}
		UE_LOG(LogTemp, Error, TEXT("Spline is nullptr."));
		return false;
	}
	float SplineDuration = Spline->Duration;
	float SplineDelta = SplineDuration / Precision; // 每次检查的时间差值
	for (int i = 1; i <= Precision; ++i)
	{
		FVector Start = Spline->GetWorldLocationAtTime(SplineDelta * (i - 1.f));
		FVector End = Spline->GetWorldLocationAtTime(SplineDelta * i);
		bool bIsHit = UKismetSystemLibrary::SphereTraceSingle(WorldContextObject, Start, End, Radius, TraceChannel,
			bTraceComplex, ActorsToIgnore, DrawDebugType, OutHit, bIgnoreSelf, TraceColor, TraceHitColor, DrawTime);
		if (bIsHit)
		{
			Time = i * SplineDelta;
			return true;
		}
	}
	return false;
}

void UFlowStateBFL::LoadStreamLevel(UObject* WorldContextObject, FName LevelName, EFlowStateLifetime Lifetime,
	bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo LatentInfo)
{
	UGameplayStatics::LoadStreamLevel(WorldContextObject, LevelName, bMakeVisibleAfterLoad, bShouldBlockOnLoad, LatentInfo);
	UFlowState* FlowState = GetCurFlowState(WorldContextObject);
	InitTargetLifetime(FlowState, LevelName, Lifetime);
}

void UFlowStateBFL::LoadStreamLevelBySoftObjectPtr(UObject* WorldContextObject, const TSoftObjectPtr<UWorld> Level,
	EFlowStateLifetime Lifetime, bool bMakeVisibleAfterLoad, bool bShouldBlockOnLoad, FLatentActionInfo LatentInfo)
{
	const FName LevelName = FName(*FPackageName::ObjectPathToPackageName(Level.ToString()));
	LoadStreamLevel(WorldContextObject, LevelName, Lifetime, bMakeVisibleAfterLoad, bShouldBlockOnLoad, LatentInfo);
}
