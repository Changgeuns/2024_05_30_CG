// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "MyAnimInstance.h"
#include "Engine/DamageEvents.h" 

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// TODE
	// skeletal Mesh
	// 

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> sm
	(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'"));

	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	_springArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	_camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	// 상속관계 설정
	_springArm->SetupAttachment(GetCapsuleComponent());
	_camera->SetupAttachment(_springArm);

	_springArm->TargetArmLength = 500.0f;
	_springArm->SetRelativeRotation(FRotator(-35.0f, 0.0f, 0.0f));

	RootComponent = GetCapsuleComponent();
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Init();
}

void AMyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	_animInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	// 몽타주가 끝날때 _isAttack 을 false로 만들어줬으면 좋겠다.
	_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::onAttackEnded);
	_animInstance->_attackDelegate.AddUObject(this, &AMyCharacter::AttackHit);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Moving
		EnhancedInputComponent->BindAction(_moveAction, ETriggerEvent::Triggered, this, &AMyCharacter::Move);

		// Looking
		EnhancedInputComponent->BindAction(_lookAction, ETriggerEvent::Triggered, this, &AMyCharacter::Look);

		// Jumping
		EnhancedInputComponent->BindAction(_jumpAction, ETriggerEvent::Started, this, &AMyCharacter::JumpA);

		// Attacks
		EnhancedInputComponent->BindAction(_AttackAction, ETriggerEvent::Started, this, &AMyCharacter::AttackA);


	}
}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	// TODO :
	// 1. hp -= Damage
	// 2. 공격자 이름 출력
	_curHP -= Damage;

	UE_LOG(LogTemp, Log, TEXT("Attack : %s, curHP : %d"), *DamageCauser->GetName(), _curHP);
	
	if (_curHP < 0)
		_curHP = 0;


	return _curHP;
}

void AMyCharacter::onAttackEnded(UAnimMontage* Montage, bool bInterrupted)
{
	UE_LOG(LogTemp, Error, TEXT("Attack End!!"));
	_isAttcking = false;
}

void AMyCharacter::AttackHit()
{
	//UE_LOG(LogTemp, Warning, TEXT("Attack!!!"));

	// TODO : 
	// 1. 히트스캔으로 공격하기, AttackRange는 마음대로
	// 2. Debugdraw까지.
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 500.0f;
	float attackRadius = 150.0f;

	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * attackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(attackRadius),
		params
	);

	FVector vec = GetActorForwardVector() * attackRange;
	UE_LOG(LogTemp, Log, TEXT("%s"), *vec.ToString());
	FVector center = GetActorLocation() + vec * 0.5f;

	FColor drawColor = FColor::Green;

	//FDamageEvent DamageEvent = FDamageEvent();

	if (bResult && hitResult.GetActor()->IsValidLowLevel())
	{
		//UE_LOG(LogTemp, Log, TEXT("HitActor : %s"), *hitResult.GetActor()->GetName());
		drawColor = FColor::Red;

		// TODE : TakeDamage
		FDamageEvent damageEvent;
		hitResult.GetActor()->TakeDamage(_attackDamage, damageEvent, GetController(), this);
	}
	DrawDebugSphere(GetWorld(), center, attackRadius, 36, drawColor, false, 2.0f);
}

void AMyCharacter::Move(const FInputActionValue& value)
{
	FVector2D MovementVector = value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		_vertical = MovementVector.Y;
		_Horizontal = MovementVector.X;

		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AMyCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookAxisVector = value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMyCharacter::JumpA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed)
	{
		UE_LOG(LogTemp, Warning, TEXT("Jump!!"));
		ACharacter::Jump();
	}
}

void AMyCharacter::AttackA(const FInputActionValue& value)
{
	bool isPressed = value.Get<bool>();

	if (isPressed && _isAttcking == false && _animInstance != nullptr)
	{
		//auto myAniml = GetMesh()->GetAnimInstance();
		_animInstance->PlayAttackMontage();
		_isAttcking = true;

		_curAttackIndex %= 4;
		_curAttackIndex++;

		_animInstance->JumpToSection(_curAttackIndex);
	}
}

void AMyCharacter::Init()
{
	_curHP = _maxHP;
}

