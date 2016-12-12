#include "LittlePsycho.h"
#include "Coin.h"
#include "CoinSocket.h"

ACoinSocket::ACoinSocket()
{
	PrimaryActorTick.bCanEverTick = false;

	CoinSocketMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin socket mesh"));
	CoinSocketMesh->SetEnableGravity(false);
	CoinSocketMesh->SetSimulatePhysics(false);
	RootComponent = CoinSocketMesh;

	CoinSocketCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Coin collision"));
	CoinSocketCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	CoinSocketCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CoinSocketCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CoinInSocketMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin in socket mesh"));
	CoinInSocketMesh->SetRelativeLocation(FVector(0.f, 30.f, 0.f));
	CoinInSocketMesh->SetEnableGravity(false);
	CoinInSocketMesh->SetSimulatePhysics(false);
	CoinInSocketMesh->SetVisibility(false);
	CoinInSocketMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ACoinSocket::BeginPlay()
{
	Super::BeginPlay();
}

void ACoinSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACoinSocket::InsertIntoSocket()
{
	CoinInSocketMesh->SetVisibility(true);
	ChangeState();
}

void ACoinSocket::RemoveFromSocket()
{
	CoinInSocketMesh->SetVisibility(false);
	ChangeState();
}

void ACoinSocket::ChangeState()
{
	bIsBusy = !bIsBusy;
}

