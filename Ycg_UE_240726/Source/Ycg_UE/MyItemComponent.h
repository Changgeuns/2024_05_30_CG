// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyItemComponent.generated.h"

class AMyItem;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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
	UFUNCTION()
		bool AddmyItem(class AMyItem* Item);

	UFUNCTION()
		void DropmyItem();

	UFUNCTION()
		void DeadAllDropItem();

private:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
        TArray<AMyItem*> Inventory;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
        int32 MaxInventorySize = 5;
};
