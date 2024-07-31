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
#include "MyItem.h"

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
	if (_animInstance->IsValidLowLevel())
	{
		_animInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::onAttackEnded);
		_animInstance->_attackDelegate.AddUObject(this, &AMyCharacter::AttackHit);
		_animInstance->_deathDelegate.AddUObject(this, &AMyCharacter::Disable);
	}
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

		// ItemDrop
		EnhancedInputComponent->BindAction(_ItemDropAction, ETriggerEvent::Started, this, &AMyCharacter::DropmyItem);

	}
}

float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	// TODO :
	// 1. hp -= Damage
	// 2. 공격자 이름 출력
	_curHP -= Damage;

	UE_LOG(LogTemp, Log, TEXT("Name : %s, HP : %d / %d"), *DamageCauser->GetName(), _curHP, _maxHP);
	if (_curHP <= 0)
	{
		_curHP = 0;
	}


	return _curHP;
}

void AMyCharacter::onAttackEnded(UAnimMontage* Montage, bool bInterrupted)
{
	_isAttcking = false;
}

void AMyCharacter::AttackHit()
{
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
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void AMyCharacter::Disable()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = false;

	if (!Inventory.IsEmpty())
	{
		// 인벤토리 내 모든 아이템을 드랍
		for (AMyItem* Item : Inventory)
		{
			if (Item)
			{
				// 아이템의 위치를 캐릭터의 현재 위치로 설정
				FVector DropLocation = GetActorLocation();
				float rand_X = FMath::RandRange(-2, 2);
				float rand_Y = FMath::RandRange(-2, 2);
				// 램덤한값을 더해서 아이템이 겹치는걸 어느정도 예방
				DropLocation += FVector(rand_X * 50, rand_Y * 50, 0);

				Item->SetActorLocation(DropLocation);
				Item->SetActorHiddenInGame(false);
				Item->SetActorEnableCollision(true);

				UE_LOG(LogTemp, Log, TEXT("아이템 드랍: %s"), *Item->GetName());
			}
		}

		// 인벤토리 비우기
		Inventory.Empty();
	}
}

void AMyCharacter::AddmyItem(AMyItem* Item)
{
	if (Inventory.Num() < MaxInventorySize)
	{
		Inventory.Add(Item);
		// 필요에 따라 아이템의 콜리전이나 시각적 요소를 비활성화할 수 있습니다.
		Item->SetActorHiddenInGame(true);
		Item->SetActorEnableCollision(false);
		// 아이템효과
		AddAttackDamage(this, 100);

		UE_LOG(LogTemp, Log, TEXT("인벤토리에 아이템 추가: %s"), *Item->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("인벤토리가 가득 찼습니다!"));
	}
}

void AMyCharacter::DropmyItem()
{
	if (Inventory.Num() > 0)
	{
		// 인벤토리에서 마지막 아이템을 드랍
		AMyItem* ItemToDrop = Inventory.Last();
		Inventory.Remove(ItemToDrop);
		// 장비해제시 효과를 뺴야함
		AddAttackDamage(this, -100);

		// 캐릭터의 정면 방향 구하기
		FVector ForwardVector = GetActorForwardVector();

		float DropDistance = 150.0f; // 200~300 사이의 값으로 조정
		FVector DropLocation = GetActorLocation() + (ForwardVector * DropDistance);
		
		float rand_X = FMath::RandRange(-2, 2);
		float rand_Y = FMath::RandRange(-2, 2);
		// 램덤한값을 더해서 아이템이 겹치는걸 어느정도 예방
		DropLocation += FVector(rand_X * 50, rand_Y * 50, 0);


		// 캐릭터 위치에 아이템 위치 설정
		ItemToDrop->SetActorLocation(DropLocation);//(GetActorLocation() + FVector(300, 0, 0));
		ItemToDrop->SetActorHiddenInGame(false);
		ItemToDrop->SetActorEnableCollision(true);

		UE_LOG(LogTemp, Log, TEXT("아이템 드랍: %s"), *ItemToDrop->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("드랍할 아이템이 없습니다."));
	}
}


