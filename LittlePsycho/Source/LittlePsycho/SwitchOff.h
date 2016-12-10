#pragma once

#include "GameFramework/Actor.h"
#include "Switch.h"
#include "SwitchOff.generated.h"

UCLASS()
class LITTLEPSYCHO_API ASwitchOff : public ASwitch
{
	GENERATED_BODY()
	
public:	
	ASwitchOff();

	UPROPERTY(EditAnywhere, Category = "Switch Off - mesh")
	UStaticMeshComponent* SwitchOffMesh;

	UPROPERTY(EditAnywhere, Category = "Switch Off - light to turn off")
	USpotLightComponent* SwitchOffLight;
	
	UPROPERTY(EditAnywhere, Category = "Switch Off - collision")
	USphereComponent* SwitchOffCollision;

	UPROPERTY(EditAnywhere, Category = "Switch Off - tag to bounded light")
	FName TagToBound;

	virtual void BeginPlay() override;												

	virtual void Tick(float) override;

	void UseSwitch();

	void TurnOffLight();

	void ToggleLight();
};
