#pragma once

#include "MoveableItem.h"
#include "MainCharacter.h"
#include "Coin.generated.h"

UCLASS()
class LITTLEPSYCHO_API ACoin : public AMoveableItem
{
	GENERATED_BODY()

public:
	ACoin();

	UPROPERTY(EditAnywhere, Category = "Coin Mesh")
	UStaticMeshComponent* CoinMesh;

	UPROPERTY(EditAnywhere, Category = "Coin Collision")
	UBoxComponent* CoinCollision;

	bool bIsPicked = false;

	void PickUp(class AMainCharacter* CharacterToAttach);

	void ThrowOut();

private:
	void ChangePickedState();
};
