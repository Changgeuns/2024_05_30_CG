// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MyAnimInstance.generated.h"

DECLARE_MULTICAST_DELEGATE(AttackDelegate);
/**
 * 
 */
UCLASS()
class YCG_UE_API UMyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UMyAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSecinds) override;

	void PlayAttackMontage();
	void DelegateTest();
	void DelegateTest2(int32 hp, int32 mp);

	void JumpToSection(int32 sectionIndex);

	UFUNCTION()
	void AnimNotify_AttackHit();

	AttackDelegate _attackDelegate;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float _speed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool _isFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float _vertical;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float _horizontal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Pawn, Meta = (AllowPrivateAccess = true))
		class UAnimMontage* _myAnimMontage;

	
};
