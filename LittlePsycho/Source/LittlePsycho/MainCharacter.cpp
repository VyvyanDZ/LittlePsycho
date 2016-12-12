#include "LittlePsycho.h"
#include "MainCharacter.h"
#include <deque>
#include <iostream>
#include "SwitchOff.h"
#include "DoubleSwitch.h"
#include "Coin.h"
#include "CoinSocket.h"

AMainCharacter::AMainCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	if (CharacterSkeletalMesh)
	{
		GetMesh()->SetSkeletalMesh(CharacterSkeletalMesh);
	}

	CurrentSwitch = nullptr;
	CurrentDoubleSwitch = nullptr;
	CurrentCoin = nullptr;
	CurrentCoinSocket = nullptr;
}

void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	InputComponent->BindAxis("Turn", this, &AMainCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &AMainCharacter::AddControllerPitchInput);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacter::UseObject);
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
	GetCharacterMovement()->MaxWalkSpeed = MaxWalkSpeed;
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
			CurrentSwitch = Cast<ASwitchOff>(Other);
		}
		else if (IsDoubleLightSwitch(Cast<ADoubleSwitch>(Other)))
		{
			CurrentDoubleSwitch = Cast<ADoubleSwitch>(Other);
		}
		else if (IsCoin(Cast<ACoin>(Other)))
		{
			if (!bIsSlotLocked)
			{
				CurrentCoin = Cast<ACoin>(Other);
			}
		}
		else if (IsCoinSocket(Cast<ACoinSocket>(Other)))
		{
			CurrentCoinSocket = Cast<ACoinSocket>(Other);
		}
	}
}

void AMainCharacter::NotifyActorEndOverlap(AActor* Other)
{
	if (Other != nullptr)
	{
		if (IsLightSwitch(Cast<ASwitchOff>(Other)) && CurrentSwitch != nullptr)
		{
			CurrentSwitch = nullptr;
		}
		else if (IsDoubleLightSwitch(Cast<ADoubleSwitch>(Other)) && CurrentDoubleSwitch != nullptr)
		{
			CurrentDoubleSwitch = nullptr;
		}
		else if (IsCoin(Cast<ACoin>(Other)) && CurrentCoin != nullptr)
		{
			CurrentCoin = nullptr;
		}
		else if (IsCoinSocket(Cast<ACoinSocket>(Other)) && CurrentCoinSocket != nullptr)
		{
			CurrentCoinSocket = nullptr;
		}
	}
}

void AMainCharacter::UseObject()
{
	GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Left Mouse Button pressed"));

	if (CurrentSwitch != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("toggle light"));
		CurrentSwitch->UseSwitch();
	}
	else if (CurrentDoubleSwitch != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("toggle double light"));
		CurrentDoubleSwitch->UseSwitch();
	}
	else if (CurrentCoin != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("getting coin"));
		if (!CurrentCoin->bIsPicked && !bIsSlotLocked)
		{
			CurrentCoin->PickUp(this);	
			bIsSlotLocked = true;
		}
		else
		{
			CurrentCoin->ThrowOut();
			bIsSlotLocked = false;
		}
	}
	else if (CurrentCoinSocket != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("inserting coin socket"));
		if (!CurrentCoinSocket->bIsBusy)
		{
			CurrentCoinSocket->InsertIntoSocket();
			LastCoin = CurrentCoin;
			CurrentCoin = nullptr;
		}
		else if(CurrentCoinSocket->bIsBusy)
		{
			CurrentCoinSocket->RemoveFromSocket();
			CurrentCoin = LastCoin;
			LastCoin = nullptr;
		}
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
	if (DequeOfLastMoves.size() == MaxSizeOfLastMoves)
	{
		return true;
	}
	return false;
}

void AMainCharacter::OperateOnLastMovesVector(FVector Vector)
{
	if (CheckIfFull())
	{
		DequeOfLastMoves.pop_front();
		DequeOfLastMoves.push_back(Vector);
	}
	else 
	{
		DequeOfLastMoves.push_back(Vector);
	}
}

void AMainCharacter::MoveBack()
{
		for (int i = MaxSizeOfLastMoves - 1; i >= 0; --i)
		{
			SetActorLocation(DequeOfLastMoves[i], false, nullptr, ETeleportType::TeleportPhysics);
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

bool AMainCharacter::IsCoin(ACoin* Other)
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

bool AMainCharacter::IsCoinSocket(ACoinSocket * Other)
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
