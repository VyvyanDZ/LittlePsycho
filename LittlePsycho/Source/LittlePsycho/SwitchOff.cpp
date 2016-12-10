#include "LittlePsycho.h"
#include "Switch.h"
#include "DoubleSwitch.h"
#include "SwitchOff.h"

ASwitchOff::ASwitchOff()
{
	SwitchOffMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch Off mesh"));
	SwitchOffMesh->SetEnableGravity(false);
	SwitchOffMesh->SetSimulatePhysics(false);
	RootComponent = SwitchOffMesh;
	
	SwitchOffLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Switch Off light to turn off"));
	SwitchOffLight->SetRelativeLocation(FVector(100.f, 150.f, 120.f));
	SwitchOffLight->SetVisibility(false);
	SwitchOffLight->SetCastShadows(true);
	SwitchOffLight->SetIntensity(200.f);
	SwitchOffLight->SetAttenuationRadius(2.f);
	SwitchOffLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SwitchOffCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Switch Off collision"));
	SwitchOffCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	SwitchOffCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SwitchOffCollision->SetSphereRadius(60.f);
	SwitchOffCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ASwitchOff::BeginPlay()
{
	Super::BeginPlay();
}

void ASwitchOff::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASwitchOff::TurnOffLight()
{
	SwitchOffLight->SetVisibility(false);
}

void ASwitchOff::ToggleLight()
{
	if (SwitchOffLight->IsVisible())
	{
		SwitchOffLight->SetVisibility(false);
	}
	else
	{
		SwitchOffLight->SetVisibility(true);
	}
}

void ASwitchOff::UseSwitch()
{
	TArray<AActor*> FoundSwitches;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwitch::StaticClass(), FoundSwitches);

	for (AActor* actor : FoundSwitches)
	{
		if (actor->ActorHasTag(TagToBound))
		{
			ASwitchOff* boundedSwitchOff = Cast<ASwitchOff>(actor);
			if (boundedSwitchOff != nullptr)
			{
				boundedSwitchOff->TurnOffLight();
			}
			else
			{
				ADoubleSwitch* boundedDoubleSwitch = Cast<ADoubleSwitch>(actor);
				boundedDoubleSwitch->TurnOffLight();
			}
		}
	}
	ToggleLight();
}