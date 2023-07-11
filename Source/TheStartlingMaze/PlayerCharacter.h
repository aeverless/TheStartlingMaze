#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "PlayerCharacter.generated.h"


UCLASS()
class THESTARTLINGMAZE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ArmLength = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NotesCollected = 0;

public:
	APlayerCharacter();

	UFUNCTION(BlueprintCallable)
	int32 GetNotesCollected() const;

	UFUNCTION(BlueprintCallable)
	void Move(FVector2D Direction);

	UFUNCTION(BlueprintCallable)
	void Look(FVector2D Direction);

	UFUNCTION(BlueprintCallable)
	void CollectNote(class AStoryNote* Note);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCollectNote();
};
