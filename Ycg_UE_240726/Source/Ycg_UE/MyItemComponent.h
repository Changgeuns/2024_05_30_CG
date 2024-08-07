// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItemComponent.generated.h"

class AMyIte;

DECLARE_MULTICAST_DELEGATE_TwoParams(ItemAdded, int itemId, int itemIndex)

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class YCG_UE_API UMyItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyItemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	bool AddmyItem(class AMyItem* Item);
	void DropTaget(AActor* my_char);
	UFUNCTION()
	void DropmyItem();

	ItemAdded _itemAddedEvent;

	//void DeadAllDropItem();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InvenCom, meta = (AllowPrivateAccess = "true"))
		TArray<class AMyItem*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = InvenCom, meta = (AllowPrivateAccess = "true"))
		int32 MaxInventorySize = 5;

	class AMyCharacter* player_this;
};
