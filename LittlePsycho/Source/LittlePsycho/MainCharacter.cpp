#include "LittlePsycho.h"
#include "MainCharacter.h"
#include <deque>
#include <iostream>
#include "SwitchOff.h"
#include "DoubleSwitch.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	currentSwitch = nullptr;
	currentDoubleSwitch = nullptr;
}

void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacter::useObject);
}

void AMainCharacter::MoveForward(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
	OperateOnLastMovesVector(GetActorLocation());
}

void AMainCharacter::MoveRight(float Value)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
	OperateOnLastMovesVector(GetActorLocation());
}

void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = maxWalkSpeed;
}

void AMainCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	HandleLightDetection();
	HandleLackOfLight();
}

void AMainCharacter::NotifyActorBeginOverlap(AActor* Other)
{
	if (Other != nullptr)
	{
		if (IsLightSwitch(Cast<ASwitchOff>(Other)))
		{
			currentSwitch = Cast<ASwitchOff>(Other);
		}
		else if (IsDoubleLightSwitch(Cast<ADoubleSwitch>(Other)))
		{
			currentDoubleSwitch = Cast<ADoubleSwitch>(Other);
		}
	}
}

void AMainCharacter::NotifyActorEndOverlap(AActor* Other)
{
	if (Other != nullptr)
	{
		if (IsLightSwitch(Cast<ASwitchOff>(Other)) && currentSwitch != nullptr)
		{
			currentSwitch = nullptr;
		}
		else if (IsDoubleLightSwitch(Cast<ADoubleSwitch>(Other)) && currentDoubleSwitch != nullptr)
		{
			currentDoubleSwitch = nullptr;
		}
	}
}

void AMainCharacter::useObject()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Left Mouse Button pressed"));

	if (currentSwitch != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("toggle light"));
		currentSwitch->UseSwitch();
	}
	else if (currentDoubleSwitch != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("toggle double light"));
		currentDoubleSwitch->UseSwitch();
	}
	else 
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("nothing to use!"));
	}
}

void AMainCharacter::HandleLightDetection()
{
	if (bCheckLightingCondition)
	{
		bool lit = false;

		for (TObjectIterator<ULightComponent> Itr; Itr; ++Itr)
		{
			if (!Itr->IsVisible())
			{
				continue;
			}
				

			if (Itr->GetLightType() == LightType_Directional)
			{
				continue;
			}
				

			if (!Itr->AffectsPrimitive(GetCapsuleComponent())) 
			{
				continue;
			}
				

			if (GetWorld()->LineTraceTestByChannel(Itr->GetComponentLocation(), GetActorLocation(), ECC_Visibility, FCollisionQueryParams(FName(TEXT("VictoreCore Trace")), true, this)))
			{
				continue;
			}
				
			lit = true;
		}

		if (lit)
		{
			bIsInLight = true;
			return;
		}
		bIsInLight = false;
	}
}

void AMainCharacter::HandleLackOfLight()
{
	if (!bIsInLight)
	{	
		GetCharacterMovement()->Deactivate();
		MoveBack();	
	}
	else {
		GetCharacterMovement()->Activate();
	}
}

bool AMainCharacter::CheckIfFull()
{
	if (dequeOfLastMoves.size() == maxSizeOfLastMoves)
	{
		return true;
	}
	return false;
}

void AMainCharacter::OperateOnLastMovesVector(FVector vector)
{
	if (CheckIfFull())
	{
		dequeOfLastMoves.pop_front();
		dequeOfLastMoves.push_back(vector);
	}
	else 
	{
		dequeOfLastMoves.push_back(vector);
	}
}

void AMainCharacter::MoveBack()
{
		for (int i = maxSizeOfLastMoves - 1; i >= 0; --i)
		{
			SetActorLocation(dequeOfLastMoves[i], false, nullptr, ETeleportType::TeleportPhysics);
		}
}

bool AMainCharacter::IsLightSwitch(ASwitchOff* Other)
{
	if (Other != nullptr)
	{
		return true;
	}
	else {
		return false;
	}
}

bool AMainCharacter::IsDoubleLightSwitch(ADoubleSwitch* Other)
{
	if (Other != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}





