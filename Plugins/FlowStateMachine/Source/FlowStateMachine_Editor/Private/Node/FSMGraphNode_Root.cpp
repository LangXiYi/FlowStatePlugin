// Fill out your copyright notice in the Description page of Project Settings.


#include "Node/FSMGraphNode_Root.h"


void UFSMGraphNode_Root::AllocateDefaultPins()
{
	Super::AllocateDefaultPins();
	CreatePin(EGPD_Output, "DefaultOutput", "Execute");
}
