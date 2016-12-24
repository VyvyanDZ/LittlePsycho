#pragma once

#include "GameFramework/Character.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Points)
	int Points = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flags)
	bool bWantSacrifice = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flags)
	bool bWasCurious = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flags)
	bool bFlowersWasTaken = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Flags)
	bool bForcedToTakeCare = false;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	virtual void MoveForward(float Value);

	virtual void MoveRight(float Value);

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere)
	float MaxWalkSpeed;
};
