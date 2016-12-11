#pragma once

#include "GameFramework/Actor.h"
#include "Teleport.generated.h"

UCLASS()
class LITTLEPSYCHO_API ATeleport : public AActor
{
	GENERATED_BODY()
	
public:	
	ATeleport();

	UPROPERTY(EditAnywhere, Category="Teleport mesh")
	UStaticMeshComponent* TeleportMesh;

	UPROPERTY(EditAnywhere, Category = "Teleport collision")
	USphereComponent* TeleportCollision;

	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	void TeleportToNextLvl();
};
