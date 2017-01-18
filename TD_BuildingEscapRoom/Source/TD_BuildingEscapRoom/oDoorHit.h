// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Components/ActorComponent.h"
#include "oDoorHit.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UoDoorHit : public UActorComponent{
	GENERATED_BODY()

private:
	//Set TriggerVolume Editable UE4
	UPROPERTY(EditAnywhere)
		ATriggerVolume *TriggerHit = nullptr;

	AActor *Owner = nullptr;

public:	
	// Sets default values for this component's properties
	UoDoorHit();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();

		
	
};
