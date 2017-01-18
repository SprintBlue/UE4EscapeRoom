// Fill out your copyright notice in the Description page of Project Settings.
#include "TD_BuildingEscapRoom.h"
#include "oDoorKey.h"

#define OUT

// Sets default values for this component's properties
UoDoorKey::UoDoorKey(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UoDoorKey::BeginPlay(){
	Super::BeginPlay();

	// find the owning actor
	Owner = GetOwner();
	
	if (!Serrure) {
		UE_LOG(LogTemp, Error, TEXT("%s missing serrure"), *GetOwner()->GetName());
	}
	if (!Key) {
		UE_LOG(LogTemp, Error, TEXT("%s missing key"), *GetOwner()->GetName());
	}
}

// Called every frame
void UoDoorKey::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );
	//UE_LOG(LogTemp, Warning, TEXT("pas de cle ..."));

	//if the ActorThatOpens is in volume (en commentaire)
	if (Serrure->IsOverlappingActor(Key)){
		OpenDoor();
	}
}

void UoDoorKey::OpenDoor(){
	Owner->SetActorRotation(FRotator(0.0f, 90.0f, 0.0f));
}