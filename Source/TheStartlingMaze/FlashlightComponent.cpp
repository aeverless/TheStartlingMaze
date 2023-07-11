#include "FlashlightComponent.h"

#include "Components/SpotLightComponent.h"


UFlashlightComponent::UFlashlightComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	if (!SpotLightComponent)
	{
		SpotLightComponent = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLightComponent"));
	}
}

void UFlashlightComponent::BeginPlay()
{
	Super::BeginPlay();

	SpotLightComponent->SetVisibility(bTurnedOn);
}

void UFlashlightComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (SpotLightComponent->IsVisible() && (!BatteryLifeTime || !(BatteryLifeTime = FMath::Max(0, BatteryLifeTime - DeltaTime))))
	{
		SpotLightComponent->SetVisibility(false);
	}
}

void UFlashlightComponent::TurnOn()
{
	if (bTurnedOn) {
		return;
	}

	bTurnedOn = true;
	SpotLightComponent->SetVisibility(true);

	OnTurnOn();
}

void UFlashlightComponent::TurnOff()
{
	if (!bTurnedOn) {
		return;
	}

	bTurnedOn = false;
	SpotLightComponent->SetVisibility(false);

	OnTurnOff();
}

bool UFlashlightComponent::Toggle()
{
	if (bTurnedOn)
	{
		TurnOff();
	}
	else
	{
		TurnOn();
	}

	return bTurnedOn;
}
