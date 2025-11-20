// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/FlowStateCameraActor.h"

#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Utility/FlowStateUtility.h"


// Sets default values
AFlowStateCameraActor::AFlowStateCameraActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void AFlowStateCameraActor::BeginPlay()
{
	Super::BeginPlay();
	// 记忆自身状态，在结束ViewTarget后恢复
	DefaultTransform = GetActorTransform();
	DefaultFOV = GetCameraComponent()->FieldOfView;
}

void AFlowStateCameraActor::PreBecomeViewTarget(float FOV, bool bIsForceReset, ECameraRotationMode RotationMode,
	FVector OriginPos)
{
	if (bIsForceReset)
	{
		ResetCameraView();
	}
	GetCameraComponent()->SetFieldOfView(FOV);
	SetCameraRotationMode(RotationMode);
	SetCameraViewTarget(OriginPos);
}

void AFlowStateCameraActor::SetCameraViewTarget(FVector TargetPos)
{
	ViewOriginPos = TargetPos;
	Radius = (GetActorLocation() - ViewOriginPos).Size();
	bIsInitViewOriginPos = true;
}

void AFlowStateCameraActor::BecomeViewTarget(class APlayerController* PC)
{
	Super::BecomeViewTarget(PC);
	DefaultFOV = GetCameraComponent()->FieldOfView;
	// 设置为视野目标后可以自由旋转视角？
	switch (CameraRotationMode)
	{
	case ECameraRotationMode::None:
		DisableInput(PC);
		break;
	default:
		EnableInput(PC);
		break;
	}
	Private_PC = PC;
}

void AFlowStateCameraActor::EndViewTarget(class APlayerController* PC)
{
	Super::EndViewTarget(PC);
	DisableInput(Private_PC);
	Private_PC = nullptr;
	ResetCameraView();
}

void AFlowStateCameraActor::EnableInput(APlayerController* PlayerController)
{
	Super::EnableInput(PlayerController);
	// Add Input Mapping
	switch (CameraRotationMode)
	{
	case ECameraRotationMode::None:
		checkNoEntry();
		break;
	case ECameraRotationMode::Origin:
		InputComponent->BindAxis("DefaultPawn_Turn", this, &AFlowStateCameraActor::AddControllerYawInput_Origin);
		InputComponent->BindAxis("DefaultPawn_LookUp", this, &AFlowStateCameraActor::AddControllerPitchInput_Origin);
		break;
	case ECameraRotationMode::Origin_OnlyPitch:
		InputComponent->BindAxis("DefaultPawn_LookUp", this, &AFlowStateCameraActor::AddControllerPitchInput_Origin);
		break;
	case ECameraRotationMode::Origin_OnlyYaw:
		InputComponent->BindAxis("DefaultPawn_Turn", this, &AFlowStateCameraActor::AddControllerYawInput_Origin);
		break;
	case ECameraRotationMode::Self:
		InputComponent->BindAxis("DefaultPawn_Turn", this, &AFlowStateCameraActor::AddControllerYawInput);
		InputComponent->BindAxis("DefaultPawn_LookUp", this, &AFlowStateCameraActor::AddControllerPitchInput);
		break;
	}
}

void AFlowStateCameraActor::DisableInput(APlayerController* PlayerController)
{
	Super::DisableInput(PlayerController);
}

void AFlowStateCameraActor::AddControllerYawInput(float X)
{
	if (X != 0.f && Private_PC && Private_PC->IsLocalPlayerController())
	{
		Private_PC->AddYawInput(X);
	}
}

void AFlowStateCameraActor::AddControllerPitchInput(float X)
{
	if (X != 0.f && Private_PC && Private_PC->IsLocalPlayerController())
	{
		Private_PC->AddPitchInput(X);
	}
}

void AFlowStateCameraActor::AddControllerPitchInput_Origin(float X)
{
	if (!bIsInitViewOriginPos)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ues origin camera rotation mode, Must call 'SetCameraViewOriginPosition' to init view origin position."));
		// return;
	}

	if (X != 0.f && Private_PC && Private_PC->IsLocalPlayerController())
	{
		FRotator ActorRotation = GetActorRotation();
		if (ActorRotation.Pitch > 60.f && X < 0.f || ActorRotation.Pitch < -60.f && X > 0.f)
		{
			return;
		}
		// 使用Camera与OriginPos的距离作为半径
		// OriginPos 作为圆心
		// 输入的X范围 -1 ~ 1 表示旋转方向
		FVector LastLocation = GetActorLocation();
		FVector DirectionVector = LastLocation - ViewOriginPos;
		// FVector TargetLocation = UKismetMathLibrary::RotateAngleAxis(DirectionVector, X, FVector(1, 0, 0)) + ViewOriginPos;
		FVector TargetLocation = UKismetMathLibrary::RotateAngleAxis(DirectionVector, X, UKismetMathLibrary::GetRightVector(GetActorRotation())) + ViewOriginPos;
		SetActorLocation(TargetLocation);
		
		// Update Self Rotation
		float P = FVector::DotProduct(TargetLocation.GetSafeNormal(), LastLocation.GetSafeNormal());
		AddActorLocalRotation(FRotator(P * X * -1, 0, 0));
		// AddActorWorldRotation(FRotator(P * X * -1, 0, 0));
	}
}

void AFlowStateCameraActor::AddControllerYawInput_Origin(float X)
{
	if (!bIsInitViewOriginPos)
	{
		UE_LOG(LogTemp, Warning, TEXT("Ues origin camera rotation mode, Must call 'SetCameraViewOriginPosition' to init view origin position."));
		// return;
	}
	
	if (X != 0.f && Private_PC && Private_PC->IsLocalPlayerController())
	{
		// 使用Camera与OriginPos的距离作为半径
		// OriginPos 作为圆心
		// 输入的X范围 -1 ~ 1 表示旋转方向
		FVector LastLocation = GetActorLocation();
		FVector DirectionVector = LastLocation - ViewOriginPos;
		FVector TargetLocation = UKismetMathLibrary::RotateAngleAxis(DirectionVector, X, UKismetMathLibrary::GetUpVector(GetActorRotation())) + ViewOriginPos;
		SetActorLocation(TargetLocation);
		
		// 计算两向量间夹角
		float P = FVector::DotProduct(TargetLocation.GetSafeNormal(), LastLocation.GetSafeNormal());
		AddActorLocalRotation(FRotator(0, P * X, 0));
		// AddActorWorldRotation(FRotator(0, P * X, 0));
	}
}

void AFlowStateCameraActor::ResetCameraView()
{
	// 重置摄像机视图
	ViewOriginPos = FVector::ZeroVector;
	Radius = 0.f;
	bIsInitViewOriginPos = false;
	CameraRotationMode = ECameraRotationMode::None;
	SetActorTransform(DefaultTransform);
	GetCameraComponent()->FieldOfView = DefaultFOV;
}
