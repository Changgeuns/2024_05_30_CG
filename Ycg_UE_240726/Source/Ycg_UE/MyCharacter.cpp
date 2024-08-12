// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// UI
#include "MyGameInstance.h"
#include "MyUIManager.h"
#include "MyInventoryUI.h"

#include "Components/CapsuleComponent.h"
#include "MyAnimInstance.h"
#include "Engine/DamageEvents.h" 
#include "Math/UnrealMathUtility.h"
#include "MyItem.h"
#include "MyStatComponent.h"
#include "MyItemComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "MyHpBar.h"
#include "MyPlayerController.h"
#include "Components/Button.h"

// AI
#include "MyAIController.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> sm
	(TEXT("/Script/Engine.SkeletalMesh'/Game/ParagonPhase/Characters/Heroes/Phase/Meshes/Phase_GDC.Phase_GDC'"));

	if (sm.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(sm.Object);
	}

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));

	RootComponent = GetCapsuleComponent();

	//Stat
	_statCom = CreateDefaultSubobject<UMyStatComponent>(TEXT("Stat"));
	_statCom->_deathDelegate.AddLambda([this]()-> void { this->GetController()->UnPossess(); });

	// Inventory
	//_InventoryCom = CreateDefaultSubobject<UMyItemComponent>(TEXT("Inventory1"));


	_hpbarWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HpBaa"));
	_hpbarWidget->SetupAttachment(GetMesh());
	_hpbarWidget->SetWidgetSpace(EWidgetSpace::Screen);
	_hpbarWidget->SetRelativeLocation(FVector(0.0f, 0.0f, 230.0f));

	_InvenCom = CreateDefaultSubobject<UMyItemComponent>(TEXT("InvenCom"));
	

	static ConstructorHelpers::FClassFinder<UUserWidget> hpBar(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/BluePrint/UI/MyHpBar_BP.MyHpBar_BP_C'"));

	if (hpBar.Succeeded())
	{
		_hpbarWidget->SetWidgetClass(hpBar.Class);
	}
	

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();


	Init();

	// TODO : InvenWidget
	/*auto invenUI = UIManager->GetInvenUI();

	if (invenUI)
	{
		_InvenCom->_itemAddedEvent.AddUObject(invenUI, &UMyInventoryUI::SetItem);
		invenUI->DropBtn->OnClicked.AddDynamic(_InvenCom, &UMyItemComponent::DropmyItem);
	}*/
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

	_statCom->SetLevelAndInit(1);

	_hpbarWidget->InitWidget();
	auto hpBar = Cast<UMyHpBar>(_hpbarWidget->GetUserWidgetObject());

	if (hpBar)
	{
		_statCom->_hpChangedDelegate.AddUObject(hpBar, &UMyHpBar::SetHpBarValue);
	}

	// TODO : InvenWidget
	/*auto invenUI = UIManager->GetInvenUI();

	if (invenUI)
	{
		_invenCom->_itemAddedEvent.AddUObject(invenUI, &UMyInventoryUI::SetItem);
		invenUI->DropBtn->OnClicked.AddDynamic(_invenCom, &UMyInvenComponent::DropItem);
	}*/
	// 콘텐츠 브라우져에서 드래그해서 월드에 배치할 경우
	// 이 함수가 먼저 호출되는 상황
}



float AMyCharacter::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(Damage, DamageEvent, EventInstigator, DamageCauser);
	// TODO :
	// 1. hp -= Damage
	// 2. 공격자 이름 출력
	//_curHP -= Damage;
	float damaged = _statCom->AddCurHp(-Damage);
	UE_LOG(LogTemp, Log, TEXT("Name : %s, HP : %d / %d"), *DamageCauser->GetName(), _statCom->GetCurHp(), _statCom->GetMaxHp());


	return damaged;
}

void AMyCharacter::onAttackEnded(UAnimMontage* Montage, bool bInterrupted)
{
	_isAttcking = false;
	_attackEndedDelegate.Broadcast();
}

void AMyCharacter::AttackHit()
{
	// TODO : 
	// 1. 히트스캔으로 공격하기, AttackRange는 마음대로
	// 2. Debugdraw까지.
	FHitResult hitResult;
	FCollisionQueryParams params(NAME_None, false, this);

	float attackRange = 500.0f;
	float attackRadius = 100.0f;
	FQuat quat = FQuat::Identity;

	bool bResult = GetWorld()->SweepSingleByChannel
	(
		hitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * attackRange,
		quat,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeCapsule(attackRadius, attackRange),
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
		hitResult.GetActor()->TakeDamage(_statCom->GetAttackDamage(), damageEvent, GetController(), this);
	
		// TODO : 삭제할 코드... 버튼 실습용
		/*if (GetController())
		{
			Cast<AMyPlayerController>(GetController())->ShowUI();
		}*/
	}
	// DEBUG : 범위
	DrawDebugSphere(GetWorld(), center, attackRadius, 36, drawColor, false, 2.0f);
}



void AMyCharacter::AddAttackDamage(AActor* actor, int amount)
{
	// actor는 나의 공격력을 버프해준 대상(무기, 버프등)

	_statCom->AddAttackDamage(amount);
}

void AMyCharacter::Init()
{
	_statCom->Reset();
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	PrimaryActorTick.bCanEverTick = true;

	if (_aiController && GetController() == nullptr)
	{
		auto aI_Controller = Cast<AMyAIController>(_aiController);
		if (aI_Controller)
			aI_Controller->Possess(this);
	}
}

void AMyCharacter::Disable()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	PrimaryActorTick.bCanEverTick = false;

	
}

bool AMyCharacter::AddmyItem(AMyItem* Item)
{
	bool result = false;
	if (!_InvenCom->IsValidLowLevel())
	{
		UE_LOG(LogTemp, Error, TEXT("Inventory null"));
	}
	else
	{
		result = _InvenCom->AddmyItem(Item);
	}
	return result; // 인벤컴포

	/*if (!_InventoryCom)
	{
		UE_LOG(LogTemp, Error, TEXT("Inventory Component is not initialized!"));
		return false;
	}

	return _InventoryCom->AddmyItem(Item);*/

	/*if (Inventory.IsEmpty() < MaxInventorySize)
	{
		Inventory.Add(Item);

		UE_LOG(LogTemp, Log, TEXT("인벤토리에 아이템 추가: %s"), *Item->GetName());
		return true;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("인벤토리가 가득 찼습니다!"));
		return false;
	}*/

}

void AMyCharacter::DropmyItem()
{
	_InvenCom->DropTaget(this); // 인벤컴포
	//AddAttackDamage(this, -20);




	//if (Inventory.Num() > 0)
	//{
	//	// 인벤토리에서 마지막 아이템을 드랍
	//	AMyItem* ItemToDrop = Inventory.Last();
	//	Inventory.Remove(ItemToDrop);
	//	// 장비해제시 효과를 뺴야함
	//	AddAttackDamage(this, -20);

	//	//// 캐릭터의 정면 방향 구하기
	//	//FVector ForwardVector = GetActorForwardVector();

	//	//float DropDistance = 150.0f; // 적당한 거리 값으로 조정
	//	//FVector DropLocation = GetActorLocation() + (ForwardVector * DropDistance);
	//	//
	//	//float rand_X = FMath::RandRange(-2, 2);
	//	//float rand_Y = FMath::RandRange(-2, 2);
	//	//// 램덤한값을 더해서 아이템이 겹치는걸 어느정도 예방
	//	//DropLocation += FVector(rand_X * 50, rand_Y * 50, 0);
	//	// 캐릭터 위치에 아이템 위치 설정
	//	//ItemToDrop->SetActorLocation(DropLocation);//(GetActorLocation() + FVector(300, 0, 0));
	//	//ItemToDrop->SetActorHiddenInGame(false);
	//	//ItemToDrop->SetActorEnableCollision(true);

	//	float randflase = FMath::FRandRange(0, PI * 2.0f);

	//	float X = cosf(randflase) * 300.0f;
	//	float Y = sinf(randflase) * 300.0f;
	//	FVector playerPos = GetActorLocation();
	//	playerPos.Z = GetActorLocation().Z;
	//	FVector itemPos = playerPos + FVector(X, Y, 0);
	//	ItemToDrop->SetItemPos(itemPos);


	//	UE_LOG(LogTemp, Log, TEXT("아이템 드랍: %s"), *ItemToDrop->GetName());
	//}
	//else
	//{
	//	UE_LOG(LogTemp, Warning, TEXT("드랍할 아이템이 없습니다."));
	//}
}


