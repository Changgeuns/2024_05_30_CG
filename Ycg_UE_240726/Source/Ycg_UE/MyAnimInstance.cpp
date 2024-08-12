// Fill out your copyright notice in the Description page of Project Settings.



#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> am
	(TEXT("/Script/Engine.AnimMontage'/Game/BluePrint/Animasion/myAnimMontage.myAnimMontage'"));
	


	if (am.Succeeded())
	{
		_myAnimMontage = am.Object;
	}

	
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaSecinds)
{
	// 진짜 중요					dynamic cast
	AMyCharacter* MyCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	if (MyCharacter != nullptr)
	{
		_speed = MyCharacter->GetVelocity().Size();
		_isFalling = MyCharacter->GetMovementComponent()->IsFalling();
		_vertical = _vertical + (MyCharacter->_vertical - _vertical) * (DeltaSecinds);
		_horizontal = _horizontal + (MyCharacter->_horizontal - _horizontal) * (DeltaSecinds);
		_isDeed = (MyCharacter->GetCurHp() <= 0);
	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(_myAnimMontage))
	{
		Montage_Play(_myAnimMontage);

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
		MyCharacter->_myDelegate3.BindUObject(this, &UMyAnimInstance::DelegateTest2);
		// 구독신청을 한다
		//MyCharacter->_myDelegate1.BindUObject(this, &UMyAnimInstance::DelegateTest);

	}
}



void UMyAnimInstance::DelegateTest()
{
	UE_LOG(LogTemp, Warning, TEXT("Delegate Test"));
}

void UMyAnimInstance::DelegateTest2(int32 hp, int32 mp)
{
	UE_LOG(LogTemp, Warning, TEXT("hp : %d, mp : %d"), hp, mp);
}

void UMyAnimInstance::JumpToSection(int32 sectionIndex)
{
	FName sectionName = FName(*FString::Printf(TEXT("Attack%d"), sectionIndex));
	Montage_JumpToSection(sectionName);
}

void UMyAnimInstance::AnimNotify_AttackHit()
{
	// 공격시점 
	// 
	//
	_attackDelegate.Broadcast();
}

void UMyAnimInstance::AnimNotify_Deedth()
{
	_deathDelegate.Broadcast();
}

