// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Components/ActorComponent.h"
#include "oDoorCoul.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UoDoorCoul : public UActorComponent{
	GENERATED_BODY()

private:
	//Set TriggerVolume Editable UE4
	UPROPERTY(EditAnywhere)
		ATriggerVolume *TriggerYellow = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *TriggerRed = nullptr;
	UPROPERTY(EditAnywhere)
		ATriggerVolume *TriggerBlue = nullptr;
	//Set AActor Editable UE4
	UPROPERTY(EditAnywhere)
		AActor *CubeYellow = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *CubeRed = nullptr;
	UPROPERTY(EditAnywhere)
		AActor *CubeBlue = nullptr;

	AActor *Owner = nullptr;

public:	
	// Sets default values for this component's properties
	UoDoorCoul();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();

	//Méthode fermer porte
	void CloseDoor();
	
};
