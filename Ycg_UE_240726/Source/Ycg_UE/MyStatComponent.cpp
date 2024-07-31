// Fill out your copyright notice in the Description page of Project Settings.


#include "MyStatComponent.h"
#include "MyGameInstance.h"

// Sets default values for this component's properties
UMyStatComponent::UMyStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UMyStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyStatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyStatComponent::Reset()
{
	_curHP = _maxHP;
}


void UMyStatComponent::SetLevelAndInit(int level)
{
	auto myGameInstance = Cast<UMyGameInstance>(GetWorld()->GetGameInstance());
	if (myGameInstance)
	{
		FMyStatData* data = myGameInstance->GetStatDataByLevel(level);
		_maxHP = data->maxHP;
		_attackDamage = data->attack;
		_curHP = _maxHP;

		UE_LOG(LogTemp, Log, TEXT("%s... HP : %d, attackDamage : %d"), *GetOwner()->GetName(), _maxHP, _attackDamage);
	}
}

int UMyStatComponent::AddcurHP(float amount)
{
	int beforeHp = _curHP;

	// amount damage가 들어왔을 때
	// 방어력 스탯마다, 데미지 경감등의 옵션으로amount가 줄어든 채로 curHP에 더해진다.
	// ex) amount * 0.8;
	_curHP += amount;

	if (_curHP < 0)
		_curHP = 0;

	if (_curHP > _maxHP)
		_curHP = _maxHP;

	return beforeHp - _curHP;
}

void UMyStatComponent::AddAttackDamage(float amount)
{
	_attackDamage += amount;
}

