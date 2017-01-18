// Fill out your copyright notice in the Description page of Project Settings.
#include "TD_BuildingEscapRoom.h"
#include "oDoorBalls.h"

#define OUT

// Sets default values for this component's properties
UoDoorBalls::UoDoorBalls(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UoDoorBalls::BeginPlay(){
	Super::BeginPlay();

	// find the owning actor
	Owner = GetOwner();
	
	if (!Floor) {
		UE_LOG(LogTemp, Error, TEXT("%s missing Floor"), *GetOwner()->GetName());
	}
}

// Called every frame
void UoDoorBalls::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	TArray<AActor*> OverlappingActors;

	Floor->GetOverlappingActors(OUT OverlappingActors);
	//Modification de la référence(cellule)du TArray

	//UE_LOG(LogTemp, Warning, TEXT("%ld objets dans la salle"), OverlappingActors.Num());
	if (OverlappingActors.Num() > 1) {
		CloseDoor();
	}
	else {
		OpenDoor();
	}

}

void UoDoorBalls::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.0f, -170.0f, 0.0f));
}

void UoDoorBalls::CloseDoor() {
	Owner->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
}

