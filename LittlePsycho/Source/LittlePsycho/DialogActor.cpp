#include "LittlePsycho.h"
#include "DialogActor.h"
#include <unordered_map>
#include <vector>

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
}

void ADialogActor::BeginPlay()
{
	Super::BeginPlay();
}

void ADialogActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

FText ADialogActor::getActualDialogHeader(int key)
{
	return DialogHeaders[key];
}

TArray<FText> ADialogActor::getActualDialogData(int key)
{
	return DialogData[key];
}

bool ADialogActor::isDialogDataAccurate(int chosenArrayIndex)
{
	if (ChosenNumber == chosenArrayIndex)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ADialogActor::endDialog()
{
	Destroy();
}

int ADialogActor::getChosenNumber()
{
	return ChosenNumber;
}

int ADialogActor::getArrayIndex()
{
	return ArrayIndex;
}

AMainCharacter * ADialogActor::getMainCharacter()
{
	return MainCharacter;
}

int ADialogActor::getHeaderIndex()
{
	return HeaderIndex;
};

AMainCharacter* ADialogActor::setMainCharacter(AMainCharacter* newMainCharacter)
{
	MainCharacter = newMainCharacter;
	return MainCharacter;
}

int ADialogActor::setChosenNumber(int newChosenNumber)
{
	ChosenNumber = newChosenNumber;
	return ChosenNumber;
}

int ADialogActor::setArrayIndex(int newArrayIndex)
{
	ArrayIndex = newArrayIndex;
	return ArrayIndex;
}

int ADialogActor::setHeaderIndex(int newHeaderIndex)
{
	HeaderIndex = newHeaderIndex;
	return HeaderIndex;
};
