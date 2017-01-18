// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BuildingEscapRoom.h"
#include "Grabber.h"
#define OUT


// Sets default values for this component's properties
UGrabber::UGrabber(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay(){
	Super::BeginPlay();

	FindPhysicsHandleComponenet();
	
	SetInputComponent();
	
}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ){
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	if (!PhysicsHandle) { return; }

	if (PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}

}

void UGrabber::Grab() {
	Handle();
}
void UGrabber::Release() {
	if (!PhysicsHandle) { return; }
	PhysicsHandle->ReleaseComponent();
}

void UGrabber::FindPhysicsHandleComponenet() {
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle) {
		//Found
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s missing physics handleComponent"), *GetOwner()->GetName());
	}
}
void UGrabber::SetInputComponent() {
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s missing physics inputComponent"), *GetOwner()->GetName());
		return;
	}
}
const FHitResult UGrabber::GetFirstPhysicsBodyInReach() {
	FVector PlayerVector;
	FRotator PlayerRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerVector, OUT PlayerRotator);

	FVector LineTraceEnd = PlayerVector + PlayerRotator.Vector() * Reach;

	/*DrawDebugLine(
		GetWorld(),
		PlayerVector,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		-1.0f,		// durée de vie
		0.0f,		// priorité de pronfondeur
		12.333);	// épaisseur*/

	// setup query parameters
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerVector,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters);

	// see what we hit
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Warning, TEXT("Line Trace hit : %s"), *(ActorHit->GetName()))
	}

	return Hit;
}

void UGrabber::Handle() {
	auto HitResult = GetFirstPhysicsBodyInReach();
	auto ComponentToGrab = HitResult.GetComponent();
	auto ActorHit = HitResult.GetActor();

	if (ActorHit) {
		if (!PhysicsHandle) { return; }
		PhysicsHandle->GrabComponent(
			ComponentToGrab,
			NAME_None,
			ComponentToGrab->GetOwner()->GetActorLocation(),
			true
			);
	}
}

FVector UGrabber::GetReachLineStart(){
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation;
}

FVector UGrabber::GetReachLineEnd(){
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(
		OUT PlayerViewPointLocation,
		OUT PlayerViewPointRotation
		);
	return PlayerViewPointLocation + PlayerViewPointRotation.Vector() * Reach;
}