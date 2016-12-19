#pragma once

#include "GameFramework/Actor.h"
#include "DialogActor.generated.h"

USTRUCT(Blueprintable)
struct FDialogData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question01;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question02;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question03;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question11;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question12;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question13;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question21;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question22;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question23;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question31;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question32;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question33;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question41;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question42;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question43;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question51;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question52;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question53;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question61;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question62;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question63;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question71;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question72;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question73;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	FText Question81;
};


UCLASS()
class LITTLEPSYCHO_API ADialogActor : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, Category = CharacterMesh)
	UStaticMeshComponent* CharacterMesh;

	UPROPERTY(EditAnywhere, Category = CharacterCollision)
	USphereComponent* CharacterCollision;

	UPROPERTY(EditAnywhere, Category = CharacterText)
	UTextRenderComponent* CharacterText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialog)
	UDataTable* DialogDataTable;
	
	ADialogActor();

	virtual void BeginPlay() override;
	
	virtual void Tick( float DeltaSeconds ) override;
};
