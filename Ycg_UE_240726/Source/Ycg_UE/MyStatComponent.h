// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"

#include "MyStatComponent.generated.h"


USTRUCT()
struct FMyStatData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 level;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 maxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 attack;

};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class YCG_UE_API UMyStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyStatComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void Reset();

	int32 GetCurHP() { return _curHP; }
	int32 GetMaxHP() { return _maxHP; }
	int32 GetAttackDamage() { return _attackDamage; }

	void SetLevelAndInit(int level);

	int AddcurHP(float amount);
	void AddAttackDamage(float amount);

	bool IsDead() { return _curHP <= 0; }
protected:
	//stat
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
		int32 _curHP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
		int32 _maxHP = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
		int32 _attackDamage = 0;
		
};
