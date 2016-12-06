#pragma once

#include "GameFramework/Character.h"
#include <deque>
#include <iostream>
#include "SwitchOff.h"
#include "DoubleSwitch.h"
#include "MainCharacter.generated.h"

using namespace std;

UCLASS()
class LITTLEPSYCHO_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

	UPROPERTY(EditAnywhere)
	float maxWalkSpeed;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void MoveForward(float Value);

	virtual void MoveRight(float Value);

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	virtual void NotifyActorBeginOverlap(class AActor* Other) override;

	virtual void NotifyActorEndOverlap(class AActor* Other) override;

	void useObject();

private:
	UPROPERTY(EditAnywhere, Category = "Character")
	bool bCheckLightingCondition;

	UPROPERTY(VisibleAnywhere, Category = "Character")
	bool bIsInLight;

	deque<FVector> dequeOfLastMoves;

	const int maxSizeOfLastMoves = 100;
	
	void HandleLightDetection();

	void HandleLackOfLight();

	bool CheckIfFull();

	void OperateOnLastMovesVector(FVector vector);

	void MoveBack();
	
	bool IsLightSwitch(class ASwitchOff* Other);

	bool IsDoubleLightSwitch(class ADoubleSwitch* Other);

	ASwitchOff* currentSwitch;

	ADoubleSwitch* currentDoubleSwitch;	
};
