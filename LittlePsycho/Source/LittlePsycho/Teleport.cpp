#include "LittlePsycho.h"
#include "Teleport.h"

ATeleport::ATeleport()
{
	PrimaryActorTick.bCanEverTick = false;

	TeleportMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Teleport mesh"));
	TeleportMesh->SetEnableGravity(false);
	TeleportMesh->SetSimulatePhysics(false);
	RootComponent = TeleportMesh;

	TeleportCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Teleport collision"));
	TeleportCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	TeleportCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TeleportCollision->SetSphereRadius(60.f);
	TeleportCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ATeleport::BeginPlay()
{
	Super::BeginPlay();
}

void ATeleport::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

