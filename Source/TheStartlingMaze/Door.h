#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"


UCLASS()
class THESTARTLINGMAZE_API ADoor : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<class UStaticMeshComponent> StaticMeshComponent;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bLocked = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bUnlockable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOpened = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NotesRequiredToUnlock = 0;

public:
	ADoor();

	UFUNCTION(BlueprintCallable)
	bool Open(AActor* ByActor);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOpen();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocked();
};
