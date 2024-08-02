// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyItem.generated.h"

//UENUM()
//enum class ItemType
//{
//
//};
//
//USTRUCT()
//struct ItemInfo
//{
//	int itemId;
//	ItemType type;
//};

UCLASS()
class YCG_UE_API AMyItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	void OnMyCharacterOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromWeep, const FHitResult& SweepResult);

	void Init();
	void Disable();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetItemPos(FVector pos, FRotator rot = FRotator::ZeroRotator);

	UPROPERTY(VisibleAnywhere)
	class UStaticMeshComponent* _meshComponent;

	UPROPERTY(VisibleAnywhere)
	class USphereComponent* _trigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 _itemId = -1;
};
