// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Components/ActorComponent.h"
#include "oDoor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDoorEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCloseRequest);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BUILDINGESCAPROOM_API UoDoor : public UActorComponent{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
		ATriggerVolume *PressurePlate = nullptr;	//Set TriggerVolume Editable UE4
    UPROPERTY(EditAnywhere)
		float TriggerMass=15.0f;					//Set float Editable UE4

	AActor *Owner = nullptr;

	float GetTotalMassOfActorsOnPlate();

public:	
	// Sets default values for this component's properties
	UoDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Méthode ouvrir porte
	void OpenDoor();

	//Méthode ferme porte
	void CloseDoor();

	UPROPERTY(BlueprintAssignable)
		FOnOpenRequest OnOpenRequest;

	UPROPERTY(BlueprintAssignable)
		FOnCloseRequest OnCloseRequest;
		
	
};
