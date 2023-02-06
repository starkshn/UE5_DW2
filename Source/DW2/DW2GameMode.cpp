// Copyright Epic Games, Inc. All Rights Reserved.

#include "DW2GameMode.h"
#include "DW2Character.h"
#include "UObject/ConstructorHelpers.h"

ADW2GameMode::ADW2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
