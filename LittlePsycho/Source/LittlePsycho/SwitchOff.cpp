#include "LittlePsycho.h"
#include "Switch.h"
#include "DoubleSwitch.h"
#include "SwitchOff.h"

ASwitchOff::ASwitchOff()
{
	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch mesh"));
	SwitchMesh->SetEnableGravity(false);
	SwitchMesh->SetSimulatePhysics(false);
	RootComponent = SwitchMesh;
	
	SwitchLightToOff = CreateDefaultSubobject<UPointLightComponent>(TEXT("Switch light to turn off"));
	SwitchLightToOff->SetRelativeLocation(FVector(100.f, 150.f, 120.f));
	SwitchLightToOff->SetVisibility(false);
	SwitchLightToOff->SetCastShadows(true);
	SwitchLightToOff->SetIntensity(200.f);
	SwitchLightToOff->SetAttenuationRadius(2.f);
	SwitchLightToOff->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SwitchCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Switch collision"));
	SwitchCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	SwitchCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SwitchCollision->SetSphereRadius(60.f);
	SwitchCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	SwitchFirstLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Switch light to toggle"));
	SwitchFirstLight->SetRelativeLocation(FVector(100.f, 150.f, 120.f));
	SwitchFirstLight->SetVisibility(false);
	SwitchFirstLight->SetCastShadows(true);
	SwitchFirstLight->SetIntensity(200.f);
	SwitchFirstLight->SetAttenuationRadius(2.f);
	SwitchFirstLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
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
	TArray<AActor*> FoundSwitches;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASwitch::StaticClass(), FoundSwitches);
	for (AActor* actor : FoundSwitches)
	{
		if (actor->ActorHasTag(TagToBound))
		{
			ASwitchOff* switchToAdd = Cast<ASwitchOff>(actor);
			if (switchToAdd != nullptr)
			{
				switchToAdd->SwitchFirstLight->SetVisibility(false);
			}
			else
			{
				ADoubleSwitch* switchToAdd2 = Cast<ADoubleSwitch>(actor);
				switchToAdd2->SwitchFirstLight->SetVisibility(false);
			}
		}
	}
	SwitchLightToOff->SetVisibility(false);
}

void ASwitchOff::ToggleLight()
{
	if (SwitchFirstLight->IsVisible())
	{
		SwitchFirstLight->SetVisibility(false);
	}
	else
	{
		SwitchFirstLight->SetVisibility(true);
	}
}

void ASwitchOff::UseSwitch()
{
	TurnOffLight();
	ToggleLight();
}


