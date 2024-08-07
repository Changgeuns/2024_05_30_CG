// Fill out your copyright notice in the Description page of Project Settings.


#include "MyItemComponent.h"
#include "MyCharacter.h"
#include "MyItem.h"

// Sets default values for this component's properties
UMyItemComponent::UMyItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	

	// ...
}


// Called when the game starts
void UMyItemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}



// Called every frame
void UMyItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UMyItemComponent::AddmyItem(AMyItem* Item)
{
	if (Inventory.Num() < MaxInventorySize)
	{
		Inventory.Add(Item);

		UE_LOG(LogTemp, Log, TEXT("인벤토리에 아이템 추가: %s"), *Item->GetName());
		_itemAddedEvent.Broadcast(Item->_itemId, Inventory.Num() - 1);

		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("인벤토리가 가득 찼습니다!"));
		return false;
	}
}

void UMyItemComponent::DropTaget(AActor* my_char)
{
	auto myCharacter = Cast<AMyCharacter>(my_char);

	player_this = myCharacter;
	DropmyItem();
}

void UMyItemComponent::DropmyItem()
{
	if (player_this == nullptr)
	{
		&AMyCharacter::DropmyItem;
	}

	if (Inventory.Num() > 0)
	{
		// 인벤토리에서 마지막 아이템을 드랍
		AMyItem* ItemToDrop = Inventory.Last();
		int itemSize = Inventory.Num();
		Inventory.Remove(ItemToDrop);
		_itemAddedEvent.Broadcast(-1, itemSize - 1);

		float randflase = FMath::FRandRange(0, PI * 2.0f);

		float X = cosf(randflase) * 300.0f;
		float Y = sinf(randflase) * 300.0f;
		FVector playerPos = GetOwner()->GetActorLocation();
		playerPos.Z = GetOwner()->GetActorLocation().Z;
		FVector itemPos = playerPos + FVector(X, Y, 0);
		ItemToDrop->SetItemPos(itemPos);
		player_this->AddAttackDamage(player_this, -10);

		UE_LOG(LogTemp, Log, TEXT("아이템 드랍: %s"), *ItemToDrop->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("드랍할 아이템이 없습니다."));
	}
}

//void UMyItemComponent::DeadAllDropItem()
//{
//	if (!Inventory.IsEmpty())
//	{
//		// 인벤토리 내 모든 아이템을 드랍
//		for (AMyItem* Item : Inventory)
//		{
//			if (Item)
//			{
//				// 아이템의 위치를 캐릭터의 현재 위치로 설정
//				FVector DropLocation = GetOwner()->GetActorLocation();
//				float rand_X = FMath::RandRange(-2, 2);
//				float rand_Y = FMath::RandRange(-2, 2);
//				// 램덤한값을 더해서 아이템이 겹치는걸 어느정도 예방
//				DropLocation += FVector(rand_X * 50, rand_Y * 50, 0);
//
//				Item->SetActorLocation(DropLocation);
//				Item->SetActorHiddenInGame(false);
//				Item->SetActorEnableCollision(true);
//
//				UE_LOG(LogTemp, Log, TEXT("아이템 드랍: %s"), *Item->GetName());
//			}
//		}
//
//		// 인벤토리 비우기
//		Inventory.Empty();
//	}
//}
