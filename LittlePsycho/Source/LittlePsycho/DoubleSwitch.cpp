#include "LittlePsycho.h"
#include "Switch.h"
#include "SwitchOff.h"
#include "DoubleSwitch.h"

ADoubleSwitch::ADoubleSwitch()
{	
	DoubleSwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Double Switch mesh"));
	DoubleSwitchMesh->SetEnableGravity(false);
	DoubleSwitchMesh->SetSimulatePhysics(false);
	RootComponent = DoubleSwitchMesh;

	DoubleSwitchLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("Double Switch light to toggle"));
	DoubleSwitchLight->SetRelativeLocation(FVector(100.f, 150.f, 120.f));
	DoubleSwitchLight->SetVisibility(false);
	DoubleSwitchLight->SetCastShadows(true);
	DoubleSwitchLight->SetIntensity(200.f);
	DoubleSwitchLight->SetAttenuationRadius(2.f);
	DoubleSwitchLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	DoubleSwitchCollision = CreateDefaultSubobject<USphereComponent>(TEXT("Switch collision"));
	DoubleSwitchCollision->SetRelativeLocation(FVector(0.f, 60.f, 0.f));
	DoubleSwitchCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DoubleSwitchCollision->SetSphereRadius(60.f);
	DoubleSwitchCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

void ADoubleSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void ADoubleSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoubleSwitch::ToggleLight()
{
	if (DoubleSwitchLight->IsVisible())
	{
		DoubleSwitchLight->SetVisibility(false);
	}
	else
	{
		DoubleSwitchLight->SetVisibility(true);
	}
}

void ADoubleSwitch::TurnOffLight()
{
	DoubleSwitchLight->SetVisibility(false);
}

void ADoubleSwitch::UseSwitch()
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
				boundedSwitchOff->ToggleLight();
			}
			else
			{
				ADoubleSwitch* boundedDoubleSwitch = Cast<ADoubleSwitch>(actor);
				boundedDoubleSwitch->ToggleLight();
			}
		}
	}
	ToggleLight();
}