#include "StoryNote.h"

#include "Components/StaticMeshComponent.h"


AStoryNote::AStoryNote()
{
	if (!StaticMeshComponent)
	{
		StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));

		static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshFinder(TEXT("/Game/Meshes/SM_Note.SM_Note"));

		if (StaticMeshFinder.Succeeded())
		{
			StaticMeshComponent->SetStaticMesh(StaticMeshFinder.Object);
		}

		if (!RootComponent)
		{
			RootComponent = StaticMeshComponent;
		}
		else {
			StaticMeshComponent->SetupAttachment(RootComponent);
		}

	}
}
