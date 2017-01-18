// Fill out your copyright notice in the Description page of Project Settings.
#include "TD_BuildingEscapRoom.h"
#include "oDoorHit.h"

#define OUT

// Sets default values for this component's properties
UoDoorHit::UoDoorHit(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UoDoorHit::BeginPlay(){
	Super::BeginPlay();

	// find the owning actor
	Owner = GetOwner();
	
	if (!TriggerHit) {
		UE_LOG(LogTemp, Error, TEXT("%s missing TriggerHit"), *GetOwner()->GetName());
	}
}

// Called every frame
void UoDoorHit::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	TArray<AActor*> OverlappingActors;

	TriggerHit->GetOverlappingActors(OUT OverlappingActors);
	//Modification de la référence(cellule)du TArray

	if (OverlappingActors.Num() > 0) {
		OpenDoor();
	}
}

void UoDoorHit::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.0f, -110.0f, 0.0f));
}

