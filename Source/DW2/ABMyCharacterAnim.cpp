// Fill out your copyright notice in the Description page of Project Settings.


#include "ABMyCharacterAnim.h"

UABMyCharacterAnim::UABMyCharacterAnim()
{
	CurrentPawnSpeed = 0.f;
	IsInAir = false;
}

void UABMyCharacterAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (!::IsValid(Pawn)) return;

	if (!IsDead)
	{
		if (::IsValid(Pawn))
		{
			CurrentPawnSpeed = Pawn->GetVelocity().Size();
			auto Character = Cast<ACharacter>(Pawn);
			if (Character)
				IsInAir = Character->GetMovementComponent()->IsFalling();
		}
	}
}
