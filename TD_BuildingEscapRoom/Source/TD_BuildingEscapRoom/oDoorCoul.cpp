// Fill out your copyright notice in the Description page of Project Settings.
#include "TD_BuildingEscapRoom.h"
#include "oDoorCoul.h"

#define OUT

// Sets default values for this component's properties
UoDoorCoul::UoDoorCoul(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UoDoorCoul::BeginPlay(){
	Super::BeginPlay();

	// find the owning actor
	Owner = GetOwner();
	
	if (!TriggerYellow) {
		UE_LOG(LogTemp, Error, TEXT("%s missing TriggerYellow"), *GetOwner()->GetName());
	}
	if (!TriggerRed) {
		UE_LOG(LogTemp, Error, TEXT("%s missing TriggerRed"), *GetOwner()->GetName());
	}
	if (!TriggerBlue) {
		UE_LOG(LogTemp, Error, TEXT("%s missing TriggerBlue"), *GetOwner()->GetName());
	}
	if (!CubeYellow) {
		UE_LOG(LogTemp, Error, TEXT("%s missing CubeYellow"), *GetOwner()->GetName());
	}
	if (!CubeRed) {
		UE_LOG(LogTemp, Error, TEXT("%s missing CubeRed"), *GetOwner()->GetName());
	}
	if (!CubeBlue) {
		UE_LOG(LogTemp, Error, TEXT("%s missing Blue"), *GetOwner()->GetName());
	}
}

// Called every frame
void UoDoorCoul::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (TriggerYellow->IsOverlappingActor(CubeYellow) && TriggerRed->IsOverlappingActor(CubeRed) && TriggerBlue->IsOverlappingActor(CubeBlue)) {
		OpenDoor();
	}
	else {
		CloseDoor();
	}
}

void UoDoorCoul::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.0f, -110.0f, 0.0f));
}

void UoDoorCoul::CloseDoor() {
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
}

