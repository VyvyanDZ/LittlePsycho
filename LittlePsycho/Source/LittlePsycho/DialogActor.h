#pragma once

#include "GameFramework/Actor.h"
#include <unordered_map>
#include <vector>
#include "MainCharacter.h"
#include "DialogActor.generated.h"

UCLASS()
class LITTLEPSYCHO_API ADialogActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category = CharacterMesh)
	UStaticMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = CharacterCollision)
	USphereComponent* CharacterCollision;

	ADialogActor();

	virtual void BeginPlay() override;
	
	virtual void Tick(float) override;

	UFUNCTION(BlueprintCallable, Category = DialogHeader)
	FText getActualDialogHeader(int key);

	UFUNCTION(BlueprintCallable, Category = DialogData)
	TArray<FText> getActualDialogData(int key);

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	bool isDialogDataAccurate(int chosenArrayIndex);

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	void endDialog();

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int getChosenNumber();

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int getArrayIndex();

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int getHeaderIndex();

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	AMainCharacter* getMainCharacter();

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	AMainCharacter* setMainCharacter(AMainCharacter* newMainCharacter);

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int setChosenNumber(int newChosenNumber);

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int setArrayIndex(int newArrayIndex);

	UFUNCTION(BlueprintCallable, Category = DialogNavi)
	int setHeaderIndex(int newHeaderIndex);

private:
	TArray<FText> DialogHeaders;

	std::vector<TArray<FText>> DialogData;

	int ChosenNumber;

	int ArrayIndex;

	int HeaderIndex;

	AMainCharacter* MainCharacter;
};
