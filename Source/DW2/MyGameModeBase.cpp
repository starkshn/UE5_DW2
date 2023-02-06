// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "ABMyCharacter.h"
#include "ABPlayerController.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AABMyCharacter::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
}

void AMyGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
