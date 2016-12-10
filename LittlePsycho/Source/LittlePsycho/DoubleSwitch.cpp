#include "LittlePsycho.h"
#include "Switch.h"
#include "SwitchOff.h"
#include "DoubleSwitch.h"



ADoubleSwitch::ADoubleSwitch()
{	
	SwitchMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Switch mesh"));
	SwitchMesh->SetEnableGravity(false);
	SwitchMesh->SetSimulatePhysics(false);
	RootComponent = SwitchMesh;

	doubleSwitchSecondLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Switch light to turn off"));
	doubleSwitchSecondLight->SetRelativeLocation(FVector(100.f, 150.f, 120.f));
	doubleSwitchSecondLight->SetVisibility(false);
	doubleSwitchSecondLight->SetCastShadows(true);
	doubleSwitchSecondLight->SetIntensity(200.f);
	doubleSwitchSecondLight->SetAttenuationRadius(2.f);
	doubleSwitchSecondLight->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

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

void ADoubleSwitch::BeginPlay()
{
	Super::BeginPlay();
}

void ADoubleSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoubleSwitch::ToggleSecondLight()
{
	if (doubleSwitchSecondLight->IsVisible())
	{
		doubleSwitchSecondLight->SetVisibility(false);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Setting double light2 to false"));
	}
	else
	{
		doubleSwitchSecondLight->SetVisibility(true);
		GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Yellow, TEXT("Setting double light2 to true"));
	}
}

void ADoubleSwitch::ToggleLight()
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
				switchToAdd->SwitchLightToOff->SetVisibility(true);
			}
			else
			{
				ADoubleSwitch* switchToAdd2 = Cast<ADoubleSwitch>(actor);
				switchToAdd2->ToggleSecondLight();
			}
		}
	}

	if (SwitchFirstLight->IsVisible())
	{
		SwitchFirstLight->SetVisibility(false);
	}
	else
	{
		SwitchFirstLight->SetVisibility(true);
	}
}

void ADoubleSwitch::UseSwitch()
{
	ToggleSecondLight();
	ToggleLight();
}