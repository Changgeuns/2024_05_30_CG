// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItem.h"
#include "MyItemComponent.generated.h"

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

	void Setmy();
public:
	UFUNCTION()
		bool AddmyItem(class AMyItem* Item);

	UFUNCTION()
		void DropmyItem(AActor* my_char);

	/*UFUNCTION()
		void DeadAllDropItem();*/

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InvenCom, meta = (AllowPrivateAccess = "true"))
		TArray<class AMyItem*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = InvenCom, meta = (AllowPrivateAccess = "true"))
		int32 MaxInventorySize = 5;
};
