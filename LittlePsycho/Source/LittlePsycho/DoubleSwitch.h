#pragma once

#include "GameFramework/Actor.h"
#include "Switch.h"
#include "DoubleSwitch.generated.h"

UCLASS()
class LITTLEPSYCHO_API ADoubleSwitch : public ASwitch
{
	GENERATED_BODY()
	
public:	
	ADoubleSwitch();

	UPROPERTY(EditAnywhere, Category = "Double Switch - mesh")
	UStaticMeshComponent* DoubleSwitchMesh;

	UPROPERTY(EditAnywhere, Category = "Double Switch - light to toggle")
	USpotLightComponent* DoubleSwitchLight;
	
	UPROPERTY(EditAnywhere, Category = "Double Switch - collision")
	USphereComponent* DoubleSwitchCollision;

	UPROPERTY(EditAnywhere, Category = "Double Switch - tag to bounded light")
	FName TagToBound;

	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	void UseSwitch();

	void ToggleLight();

	void TurnOffLight();
};
