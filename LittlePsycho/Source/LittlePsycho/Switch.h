#pragma once

#include "GameFramework/Actor.h"
#include "Switch.generated.h"

UCLASS()
class LITTLEPSYCHO_API ASwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	ASwitch();

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;
};
