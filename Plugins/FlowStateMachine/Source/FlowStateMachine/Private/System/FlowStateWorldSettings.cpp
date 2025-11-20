// Fill out your copyright notice in the Description page of Project Settings.


#include "System/FlowStateWorldSettings.h"

#include "Actors/FlowStateCameraActor.h"
#include "Camera/CameraActor.h"
#include "Data/FlowStateDataAsset.h"
#include "Engine/AssetManager.h"
#include "Engine/StreamableManager.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FlowStateContext.h"


AFlowStateWorldSettings::AFlowStateWorldSettings()
{
	PrimaryActorTick.bCanEverTick = true;

	FlowStateContextClass = UFlowStateContext::StaticClass();
}

AFlowStateWorldSettings* AFlowStateWorldSettings::Get(UObject* WorldContextObject)
{
	UWorld* World = WorldContextObject->GetWorld();
	if (World)
	{
		return (AFlowStateWorldSettings*)World->GetWorldSettings();
	}
	return nullptr;
}

void AFlowStateWorldSettings::BeginPlay()
{
	Super::BeginPlay();
	if (bIsFlowStateLevel)
	{
		checkf(FlowStateContextClass, TEXT("FlowStateContextClass is nullptr."));
		FlowStateContextClass = FlowStateContextClass ? FlowStateContextClass : UFlowStateContext::StaticClass();
		FlowStateContext = NewObject<UFlowStateContext>(this, FlowStateContextClass);
		check(FlowStateContext);
		FlowStateContext->Initialize();

		Cameras.Empty();
		UGameplayStatics::GetAllActorsOfClass(this, AFlowStateCameraActor::StaticClass(), Cameras);
	}
}

void AFlowStateWorldSettings::NotifyBeginPlay()
{
	Super::NotifyBeginPlay();

	if (bIsFlowStateLevel)
	{
		// FlowStateContext = NewObject<UFlowStateContext>(this);
		// check(FlowStateContext);

		// 尝试加载数据资产
		/*check(FlowStateDataID.IsValid());
		LoadHandle = UAssetManager::Get().LoadPrimaryAsset(FlowStateDataID);
		if (LoadHandle.IsValid())
		{
			if (!LoadHandle->HasLoadCompleted())
			{
				LoadHandle->BindCompleteDelegate(
					FStreamableDelegate::CreateUObject(this, &AFlowStateWorldSettings::OnCompletedLoadPrimaryAsset));
			}
			else
			{
				OnCompletedLoadPrimaryAsset();
			}
		}*/
	}
}

void AFlowStateWorldSettings::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	if (bIsFlowStateLevel)
	{
		check(FlowStateDataID.IsValid());
		UKismetSystemLibrary::UnloadPrimaryAsset(FlowStateDataID);
	}
}

void AFlowStateWorldSettings::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bIsFlowStateLevel && FlowStateContext)
	{
		FlowStateContext->Tick(DeltaSeconds);
	}
}

AActor* AFlowStateWorldSettings::FindCamera(FName Name)
{
	for (AActor* Camera : Cameras)
	{
		UE_LOG(LogFlowState, Log, TEXT("camera name is  '%s'"), *Camera->GetFName().ToString())
		if (Camera && Camera->GetFName() == Name)
		{
			return Camera;
		}
	}
	UE_LOG(LogFlowState, Warning, TEXT("Not find camera by '%s'"), *Name.ToString())
	return nullptr;
}

void AFlowStateWorldSettings::OnCompletedLoadPrimaryAsset()
{
	LoadHandle.Reset();
	UObject* AssetObject = UAssetManager::Get().GetPrimaryAssetObject(FlowStateDataID);
	if (UFlowStateDataAsset* GuideDataAsset = Cast<UFlowStateDataAsset>(AssetObject))
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("文件加载完成"));
		FlowStateData = GuideDataAsset;

		FlowStateContext->SwitchToByClass(FlowStateData->StartState);
		OnStartFlowState.Broadcast();
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("文件加载失败"));
	}
}
