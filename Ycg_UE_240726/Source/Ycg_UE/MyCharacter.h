// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyStatComponent.h"
#include "MyItemComponent.h"
#include "MyCharacter.generated.h" // 제너레이터 헤더는 항상 맨밑에 와야함

class UInputComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_DELEGATE(DelegateTest1);
DECLARE_DELEGATE_OneParam(DelegateTestOneParam, int32)
DECLARE_DELEGATE_TwoParams(DelegateTestTwoParams, int32, int32)
DECLARE_MULTICAST_DELEGATE(Delegate_AttackEnded);

UCLASS()
class YCG_UE_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;


	UFUNCTION()
		void onAttackEnded(class UAnimMontage* Montage, bool bInterrupted);

	UFUNCTION()
		void AttackHit();

	// Stat 관련
	int GetCurHp() { return _statCom->GetCurHp(); }
	void AddAttackDamage(AActor* actor, int amount);


	bool AddmyItem(class AMyItem* Item);
	void DropmyItem();

	Delegate_AttackEnded _attackEndedDelegate;
protected:

	virtual void Init();

	UFUNCTION()
	virtual void Disable();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		bool _isAttcking = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		int _curAttackIndex = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		float _vertical = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		float _Horizontal = 0.0f;


public:
	// Animation
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	class UMyAnimInstance* _animInstance;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
		class UMyStatComponent* _statCom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
		class UWidgetComponent* _hpbarWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = InvenCom, meta = (AllowPrivateAccess = "true"))
		class UMyItemComponent* _InvenCom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inven, meta = (AllowPrivateAccess = "true"))
		class AAIController* _aiController;

	//UI
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Stat, meta = (AllowPrivateAccess = "true"))
	//	class UUserWidget* _invenWidget;
	// UCLASS 매크로가 있고, UObject를 상속받는 클래스 자체를 지정할수 있는 변수 자료형
	//TSubclassOf<class UUserWidget> _invenClass;



	

	DelegateTestTwoParams _myDelegate3;


};
