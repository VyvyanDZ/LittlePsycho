#include "LittlePsycho.h"
#include "Switch.h"

ASwitch::ASwitch()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ASwitch::BeginPlay()
{
	Super::BeginPlay();	
}

void ASwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

