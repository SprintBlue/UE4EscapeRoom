// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "Components/ActorComponent.h"
#include "Grabber.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )

class TD_BUILDINGESCAPROOM_API UGrabber : public UActorComponent{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		float Reach = 170.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	UInputComponent* InputComponent = nullptr;

	// Proc�dure grab/release
	void Grab();
	void Release();

	// r�cup Physicshandle
	void FindPhysicsHandleComponenet();
	// r�cup Input
	void SetInputComponent();
	// r�cup Hit physics
	const FHitResult GetFirstPhysicsBodyInReach();

	void Handle();

	// Returns current start of reach line
	FVector GetReachLineStart();

	// Returns current end of reach line
	FVector GetReachLineEnd();

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	
};
