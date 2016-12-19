#include "LittlePsycho.h"
#include "DialogActor.h"

ADialogActor::ADialogActor()
{
	PrimaryActorTick.bCanEverTick = true;

	CharacterMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Character Mesh"));
	CharacterMesh->SetEnableGravity(false);
	CharacterMesh->SetSimulatePhysics(false);
	RootComponent = CharacterMesh;

	CharacterCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Character Collision"));
	CharacterCollision->SetSphereRadius(150.f);
	CharacterCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CharacterCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	CharacterText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Character Text"));
	CharacterText->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ADialogActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADialogActor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}



