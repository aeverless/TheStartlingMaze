#pragma once

#include "CoreMinimal.h"

#include "StoryNote.generated.h"


UCLASS()
class THESTARTLINGMAZE_API AStoryNote : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;

public:
	AStoryNote();
};
