// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Components/ActorComponent.h"
#include "oDoorBalls.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UoDoorBalls : public UActorComponent{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *Floor = nullptr;	//Set TriggerVolume Editable UE4

	AActor *Owner = nullptr;

public:	
	// Sets default values for this component's properties
	UoDoorBalls();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();

	//Méthode fermer porte
	void CloseDoor();

	
};
