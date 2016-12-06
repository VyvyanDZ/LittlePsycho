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

	UPROPERTY(EditAnywhere, Category = "Switch - mesh")
	UStaticMeshComponent* SwitchMesh;

	UPROPERTY(EditAnywhere, Category = "Switch - collision")
	USphereComponent* SwitchCollision;

	UPROPERTY(EditAnywhere, Category = "Switch - light to toggle")
	UPointLightComponent* SwitchFirstLight;

	UPROPERTY(EditAnywhere, Category = "Switch - light to turn off")
	UPointLightComponent* SwitchLightToOff;

	UPROPERTY(EditAnywhere, Category = "Switch - tag to bounded light")
	FName TagToBound;

	virtual void BeginPlay() override;												

	virtual void Tick(float DeltaSeconds) override;

	void UseSwitch();

	void TurnOffLight();

	void ToggleLight();
};
