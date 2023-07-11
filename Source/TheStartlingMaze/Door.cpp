#include "Door.h"

#include "PlayerCharacter.h"


ADoor::ADoor()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	if (!StaticMeshComponent)
	{
		StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshFinder(TEXT("/Game/Meshes/SM_Door.SM_Door"));
		if (MeshFinder.Succeeded())
		{
			StaticMeshComponent->SetStaticMesh(MeshFinder.Object);
			StaticMeshComponent->SetRelativeLocation({0, -StaticMeshComponent->GetStaticMesh()->GetBoundingBox().GetExtent().Y, 0});
		}

		StaticMeshComponent->SetupAttachment(RootComponent);
	}
}

bool ADoor::Open(AActor* ByActor)
{
	if (bOpened)
	{
		return false;
	}

	if (bLocked)
	{
		if (!bUnlockable)
		{
			OnLocked();
			return false;
		}

		if (auto const PlayerCharacter = Cast<APlayerCharacter>(ByActor); PlayerCharacter && PlayerCharacter->GetNotesCollected() >= NotesRequiredToUnlock)
		{
			bLocked = false;
		}
		else
		{
			OnLocked();
			return false;
		}
	}

	bOpened = true;

	OnOpen();

	return true;
}
