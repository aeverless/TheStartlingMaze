#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "FlashlightComponent.generated.h"


UCLASS(ClassGroup=(Custom), Meta=(BlueprintSpawnableComponent))
class THESTARTLINGMAZE_API UFlashlightComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bTurnedOn = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float BatteryLifeTime = 0;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<class USpotLightComponent> SpotLightComponent;

	virtual void BeginPlay() override;

public:
	UFlashlightComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void TurnOn();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTurnOn();

	UFUNCTION(BlueprintCallable)
	void TurnOff();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTurnOff();

	UFUNCTION(BlueprintCallable)
	bool Toggle();
};
