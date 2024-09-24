// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDecalActor.h"
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"

#include "MyGameInstance.h"
#include "MyEffectManager.h"

AMyDecalActor::AMyDecalActor()
{
	PrimaryActorTick.bCanEverTick = true;
	_delayTime = 1.0f;
	_runtime = 0.0f;
}

void AMyDecalActor::BeginPlay()
{
	Super::BeginPlay();

	_runtime = 0.0f;
	FVector scale = FVector(1.0f, 0.0f, 0.0f);
	_bIsPlay = true;
	_fieldAttackDelegate.AddUObject(this, &AMyDecalActor::DeActiveEvent);

}

void AMyDecalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_delayTime == 0.0f || _bIsPlay == false) return;

	// TODO :
	// 시간이 지나다가 딜레이타임을 넘어가는 순간.
	FVector curScale = GetActorScale();


	if (_runtime > _delayTime)
	{
		_fieldAttackDelegate.Broadcast(GetActorLocation());
		_runtime = 0.0f;
		curScale.Y = 0.0f;
		curScale.Z = 0.0f;

		SetActorScale3D(curScale);
		_bIsPlay = _bLoop;


		return;
	}

	_runtime += DeltaTime;
	curScale.Y = (_runtime / _delayTime) * _areaRadius;
	curScale.Z = (_runtime / _delayTime) * _areaRadius;

	SetActorScale3D(curScale);
}

void AMyDecalActor::Active(FVector location)
{
	_bIsPlay = true;
	SetActorLocation(location);
}

void AMyDecalActor::DeActiveEvent(FVector location)
{
	_bIsPlay = false;
	EffectManager->Play("Explosion", location);
}

