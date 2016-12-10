#pragma once

#include "GameFramework/GameMode.h"
#include "LittlePsychoGameMode.generated.h"

UCLASS()
class LITTLEPSYCHO_API ALittlePsychoGameMode : public AGameMode
{
	GENERATED_BODY()
	
	virtual void StartPlay();
};
