// Fill out your copyright notice in the Description page of Project Settings.


#include "SM/Actions/Actions_Camera.h"

#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "SM/FSMGC.h"

void UActions_Camera::ExecuteAction(UFSMNodeInstance* Instance)
{
	Super::ExecuteAction(Instance);

	TSharedPtr<FSMGC> GCManager = GetGCManager();
	if (GCManager.IsValid())
	{
		if (AActor* Camera = GCManager->FindCamera(CameraName))
		{
			GetWorld()->GetFirstPlayerController()->SetViewTarget(Camera);
		}
	}
}
