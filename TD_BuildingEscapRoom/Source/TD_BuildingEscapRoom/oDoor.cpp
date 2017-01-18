// Fill out your copyright notice in the Description page of Project Settings.
#include "TD_BuildingEscapRoom.h"
#include "oDoor.h"

#define OUT

// Sets default values for this component's properties
UoDoor::UoDoor() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts
void UoDoor::BeginPlay() {
	Super::BeginPlay();

	// find the owning actor
	Owner = GetOwner();
	//ActorThatOpens=GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate"), *GetOwner()->GetName());
	}
}

// Called every frame
void UoDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if the ActorThatOpens is in volume (en commentaire)
	//if(PressurePlate->IsOverlappingActor(ActorThatOpens))

	// Poll the Trigger Volume
	if (GetTotalMassOfActorsOnPlate()>TriggerMass) {
		OpenDoor();
		//Check if it's time to close the door
	}
	else {
		CloseDoor();
	}


}

void UoDoor::OpenDoor() {
	Owner->SetActorRotation(FRotator(0.0f, -110.0f, 0.0f));
	//OnOpenRequest.Broadcast();
}

void UoDoor::CloseDoor() {
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));
	//OnCloseRequest.Broadcast();
}



float UoDoor::GetTotalMassOfActorsOnPlate() {
	//Mass total des actors dans le volume
	float TotalMass = 0.0f;

	TArray<AActor*> OverlappingActors;

	if (!PressurePlate) { return TotalMass; }

	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	//Modification de la référence(cellule)du TArray

	for (const auto& Actor : OverlappingActors) {//Parcours le Tarray jusqu'à la fin de celui-ci
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		//UE_LOG(LogTemp, Warning, TEXT("%lf Kg on pressure plate"), TotalMass);
		//UE_LOG(LogTemp, Warning, TEXT("%s on pressure plate"), *Actor->GetName());

	}

	return TotalMass;
}