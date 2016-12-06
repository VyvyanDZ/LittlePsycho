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

	UPROPERTY(EditAnywhere, Category = "Switch - mesh")
	UStaticMeshComponent* SwitchMesh;

	UPROPERTY(EditAnywhere, Category = "Switch - collision")
	USphereComponent* SwitchCollision;

	UPROPERTY(EditAnywhere, Category = "Switch - light to toggle")
	UPointLightComponent* SwitchFirstLight;

	UPROPERTY(EditAnywhere, Category = "Switch - tag to bounded light")
	FName TagToBound;

	UPROPERTY(EditAnywhere, Category = "Switch - second light to toggle")
	UPointLightComponent* doubleSwitchSecondLight;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	void UseSwitch();

	void ToggleSecondLight();

	void ToggleLight();
};
