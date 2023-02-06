// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DW2.h"
#include "Animation/AnimInstance.h"
#include "ABMyCharacterAnim.generated.h"

/**
 * 
 */
UCLASS()
class DW2_API UABMyCharacterAnim : public UAnimInstance
{
	GENERATED_BODY()
	
	
public:
	UABMyCharacterAnim();

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsDead;
};
