#include "PlayerCharacter.h"

#include "StoryNote.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	if (!CameraComponent)
	{
		CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	}

	if (!SpringArmComponent)
	{
		SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
		SpringArmComponent->SetupAttachment(RootComponent);

		CameraComponent->AttachToComponent(SpringArmComponent, FAttachmentTransformRules::KeepRelativeTransform);

		SpringArmComponent->bUsePawnControlRotation = true;
		SpringArmComponent->bEnableCameraLag = true;
		SpringArmComponent->TargetArmLength = ArmLength;
	}
}

int32 APlayerCharacter::GetNotesCollected() const
{
	return NotesCollected;
}

void APlayerCharacter::Move(FVector2D Direction)
{
	AddMovementInput(GetControlRotation().RotateVector({Direction.X, Direction.Y, 0}).GetSafeNormal2D());
}

void APlayerCharacter::Look(FVector2D Direction)
{
	AddControllerYawInput(Direction.X);
	AddControllerPitchInput(Direction.Y);
}

void APlayerCharacter::CollectNote(AStoryNote* Note)
{
	if (!Note)
	{
		return;
	}

	NotesCollected++;
	Note->Destroy();

	OnCollectNote();
}