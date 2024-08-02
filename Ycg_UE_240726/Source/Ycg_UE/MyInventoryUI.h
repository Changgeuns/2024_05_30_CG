// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyInventoryUI.generated.h"

/**
 * 
 */
UCLASS()
class YCG_UE_API UMyInventoryUI : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	UFUNCTION()
		void SetItem(int32 itemId, int32 index);

public:
	UPROPERTY(meta = (BindWidget))
		class UUniformGridPanel* SlotGrid;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<class UButton*> _slotBtns;
	TArray<class UImage*> _slotBtnImages;
	class UTexture2D* _axe;
	class UTexture2D* _defalut;
};
