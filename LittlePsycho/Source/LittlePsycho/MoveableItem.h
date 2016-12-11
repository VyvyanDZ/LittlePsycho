#pragma once

#include "GameFramework/Actor.h"
#include "MoveableItem.generated.h"

UCLASS()
class LITTLEPSYCHO_API AMoveableItem : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveableItem();

	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;
};
