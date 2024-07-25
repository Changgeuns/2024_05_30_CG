// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Animation/AnimMontage.h"

UMyAnimInstance::UMyAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> am
	(TEXT("/Script/Engine.AnimMontage'/Game/BluePrint/Animasion/MyAnimMontaga.MyAnimMontaga'"));

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

	}
}

void UMyAnimInstance::PlayAttackMontage()
{
	if (!Montage_IsPlaying(_myAnimMontage))
	{
		Montage_Play(_myAnimMontage);

		AMyCharacter* MyCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
		// 구독신청을 한다
		//MyCharacter->_myDelegate1.BindUObject(this, &UMyAnimInstance::DelegateTest);
		MyCharacter->_myDelegate3.BindUObject(this, &UMyAnimInstance::DelegateTest2);
		
	}
}

void UMyAnimInstance::DelegateTest()
{
	UE_LOG(LogTemp, Warning, TEXT("Delegate Test"));
}

void UMyAnimInstance::DelegateTest2(int32 hp, int32 mp)
{
	UE_LOG(LogTemp, Warning, TEXT("hp : %d, mp : %d"), hp,mp);
}

