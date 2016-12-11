#include "LittlePsycho.h"
#include "MainCharacter.h"
#include "Coin.h"

ACoin::ACoin()
{
	CoinMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin mesh"));
	CoinMesh->SetMobility(EComponentMobility::Movable);

	CoinCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Coin collision"));
	CoinCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	CoinCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CoinCollision->SetSphereRadius(60.f);
	CoinCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ACoin::PickUp(class AMainCharacter* CharacterToAttach)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("In PickUp Method"));
	CoinMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CoinMesh->SetSimulatePhysics(false);
	this->AttachToComponent(CharacterToAttach->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, CharacterToAttach->HandSocket);
	ChangePickedState();
}

void ACoin::ThrowOut()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("In ThrowUp Method"));
	CoinMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CoinMesh->SetSimulatePhysics(true);
	this->AttachToComponent(nullptr, FAttachmentTransformRules::SnapToTargetIncludingScale);
	ChangePickedState();
}

void ACoin::ChangePickedState()
{
	bIsPicked = !bIsPicked;
}