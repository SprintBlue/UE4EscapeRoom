// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Components/ActorComponent.h"
#include "oDoorKey.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UoDoorKey : public UActorComponent{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *Serrure = nullptr;	//Set TriggerVolume Editable UE4
	UPROPERTY(EditAnywhere)
		AActor *Key = nullptr;				//Set AActor Editable UE4

	AActor *Owner = nullptr;

public:	
	// Sets default values for this component's properties
	UoDoorKey();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();
	
};
