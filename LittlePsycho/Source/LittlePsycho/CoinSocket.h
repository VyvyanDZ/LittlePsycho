#pragma once

#include "GameFramework/Actor.h"
#include "Coin.h"
#include "CoinSocket.generated.h"

UCLASS()
class LITTLEPSYCHO_API ACoinSocket : public AActor
{
	GENERATED_BODY()
	
public:	
	ACoinSocket();

	UPROPERTY(EditAnywhere, Category = "Coin Socket Mesh")
	UStaticMeshComponent* CoinSocketMesh;

	UPROPERTY(EditAnywhere, Category = "Coin Socket Collision")
	UBoxComponent* CoinSocketCollision;

	UPROPERTY(EditAnywhere, Category = "Coin In Socket Mesh")
	UStaticMeshComponent* CoinInSocketMesh;

	bool bIsBusy = false;

	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	void InsertIntoSocket();

	void RemoveFromSocket();

private:
	void ChangeState();
};
