#include "LittlePsycho.h"
#include "MoveableItem.h"

AMoveableItem::AMoveableItem()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMoveableItem::BeginPlay()
{
	Super::BeginPlay();
}

void AMoveableItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

