// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "DW2.h"
#include "GameFramework/Character.h"
#include "ABMyCharacter.generated.h"

UCLASS()
class DW2_API AABMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AABMyCharacter();

public:
	enum class ControlMode
	{
		GTA,
		DAIBLO,
	};

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);

	void ViewChange();
	void RunP();
	void RunR();

public:
	void SetControlMode(ControlMode Mode);

public:
	UPROPERTY(VisibleAnywhere, Category = Camera)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera)
		UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = Character, BlueprintReadOnly, meta = (AllowPrivateAccess = true))
		USkeletalMeshComponent* SK_Mesh;

	UPROPERTY(VisibleAnywhere, Category = Character, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
		UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, Category = Movement, BlueprintReadWrite, meta = (AllowPrivateAccess = true))
	bool IsRunning;

private:
	// Camera && ControlMode
	ControlMode		CurrentControlMode = ControlMode::GTA;
	FVector			DirectionToMove = FVector::ZeroVector;
	float			ArmLengthTo = 0.0f;
	FRotator		ArmRotationTo = FRotator::ZeroRotator;
	float			ArmLengthSpeed = 0.f;
	float			ArmRotationSpeed = 0.f;
};
