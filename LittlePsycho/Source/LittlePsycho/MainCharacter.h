#pragma once

#include "GameFramework/Character.h"
#include <deque>
#include <iostream>
#include "SwitchOff.h"
#include "DoubleSwitch.h"
#include "Coin.h"
#include "MainCharacter.generated.h"

using namespace std;

UCLASS()
class LITTLEPSYCHO_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AMainCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Assets")
	USkeletalMesh* CharacterSkeletalMesh;

	FName HandSocket = "hand_r";

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void MoveForward(float Value);

	virtual void MoveRight(float Value);

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

	virtual void NotifyActorBeginOverlap(class AActor* Other) override;

	virtual void NotifyActorEndOverlap(class AActor* Other) override;

	void UseObject();

private:
	UPROPERTY(EditAnywhere)
	float MaxWalkSpeed;

	UPROPERTY(EditAnywhere, Category = "Character")
	bool bCheckLightingCondition;

	UPROPERTY(VisibleAnywhere, Category = "Character")
	bool bIsInLight;

	deque<FVector> DequeOfLastMoves;

	

	const int MaxSizeOfLastMoves = 100;
	
	void HandleLightDetection();

	void HandleLackOfLight();

	bool CheckIfFull();

	void OperateOnLastMovesVector(FVector vector);

	void MoveBack();
	
	bool IsLightSwitch(class ASwitchOff* Other);

	bool IsDoubleLightSwitch(class ADoubleSwitch* Other);

	bool IsCoin(class ACoin* Other);

	ASwitchOff* CurrentSwitch;

	ADoubleSwitch* CurrentDoubleSwitch;

	ACoin* CurrentCoin;

	bool bIsSlotLocked = false;
};
