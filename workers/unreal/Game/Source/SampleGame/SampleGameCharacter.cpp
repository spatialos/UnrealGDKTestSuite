// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "SampleGameGameStateBase.h"
#include "SpatialNetDriver.h"

#include "TestCube.h"
#include "Weapons/AutomaticInstantWeapon.h"
#include "Weapons/Weapon.h"

#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// ASampleGameCharacter

ASampleGameCharacter::ASampleGameCharacter()
{
	// Hack to ensure that the game state is created and set to tick on a client as we don't replicate it
	UWorld* World = GetWorld();
	if (World && World->GetGameState() == nullptr)
	{
		AGameStateBase* GameState = World->SpawnActor<AGameStateBase>(ASampleGameGameStateBase::StaticClass());
		World->SetGameState(GameState);
		Cast<ASampleGameGameStateBase>(GameState)->FakeServerHasBegunPlay();
	}

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

												// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

void ASampleGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	// DebugSpawnWeapon();
}

//////////////////////////////////////////////////////////////////////////
// Input

void ASampleGameCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &ASampleGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASampleGameCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &ASampleGameCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &ASampleGameCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ASampleGameCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &ASampleGameCharacter::TouchStopped);

    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ASampleGameCharacter::Interact);
	PlayerInputComponent->BindAction("SpawnCube", IE_Pressed, this, &ASampleGameCharacter::SpawnCubePressed);

	PlayerInputComponent->BindAction("SpawnWeapon", IE_Pressed, this, &ASampleGameCharacter::DebugSpawnWeapon);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ASampleGameCharacter::StartFire);
	PlayerInputComponent->BindAction("Fire", IE_Released, this, &ASampleGameCharacter::StopFire);
}

void ASampleGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASampleGameCharacter, WeaponInventory);
	DOREPLIFETIME(ASampleGameCharacter, EquippedWeaponIndex);
	DOREPLIFETIME(ASampleGameCharacter, EquippedWeapon);
}

void ASampleGameCharacter::Interact()
{
	// Note no authority checks required, since there is no such thing as a listen server!
    FCollisionQueryParams traceParams = FCollisionQueryParams(FName(TEXT("SampleGame_Trace")), true, this);
    traceParams.bTraceComplex = true;
    traceParams.bTraceAsyncScene = true;
    traceParams.bReturnPhysicalMaterial = false;

    FHitResult hitResult(ForceInit);
    FVector traceStart = GetFollowCamera()->GetComponentLocation();
    const float kInteractDistance = 5000.0f;
    FVector traceEnd = traceStart + GetFollowCamera()->GetForwardVector() * kInteractDistance;

    bool didHit = GetWorld()->LineTraceSingleByChannel(
        hitResult,
        traceStart,
        traceEnd,
        ECC_Visibility,
        traceParams);

    if (!didHit)
    {
        return;
    }

    if (GEngine != nullptr)
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan,
            FString::Printf(TEXT("Interact with actor: %s"), *hitResult.GetActor()->GetName()));
    }

    ATestCube* interactableObject = Cast<ATestCube>(hitResult.GetActor());
    if (interactableObject != nullptr)
    {
        interactableObject->Interact(this);
    }
}

void ASampleGameCharacter::SpawnCubePressed()
{
	// Note no authority check required, since there is no such thing as a listen server!
	ServerSpawnCube();
}

void ASampleGameCharacter::DebugSpawnWeapon()
{
	if (StarterWeapon == nullptr)
	{
		UE_LOG(LogClass, Log, TEXT("No starter weapon defined."));
		return;
	}

	if (!HasAuthority()) return;

	// Create a starter weapon.
	AWeapon* startWeapon = GetWorld()->SpawnActor<AAutomaticInstantWeapon>(AAutomaticInstantWeapon::StaticClass(), GetActorTransform());
	startWeapon->AttachToActor(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	// Add and equip the starter weapon.
	//WeaponInventory.Add(startWeapon);
	//EquippedWeaponIndex = WeaponInventory.Num() - 1;
	FTimerHandle tHandle;
	FTimerDelegate tDelegate;
	tDelegate.BindLambda([this, startWeapon]() {
		UE_LOG(LogClass, Log, TEXT("Tried to set equipped weapon for character %s to %s."), *this->GetName(), *startWeapon->GetName());
		EquippedWeapon = startWeapon;
		EquippedWeaponIndex++;
	});
	GetWorld()->GetTimerManager().SetTimer(tHandle, tDelegate, 2.0f, false);
	//EquippedWeapon = startWeapon;
}

void ASampleGameCharacter::StartFire()
{
	AWeapon* equippedWeapon = GetEquippedWeapon();
	if (equippedWeapon != nullptr)
	{
		equippedWeapon->StartFire();
	}
}

void ASampleGameCharacter::StopFire()
{
	AWeapon* equippedWeapon = GetEquippedWeapon();
	if (equippedWeapon != nullptr)
	{
		equippedWeapon->StopFire();
	}
}

AWeapon* ASampleGameCharacter::GetEquippedWeapon()
{
	return EquippedWeapon;

	// TODO(davedolben): switch to this once dynamic arrays work properly
	/*
	if (EquippedWeaponIndex < 0 || EquippedWeaponIndex >= WeaponInventory.Num())
	{
		return nullptr;
	}
	return WeaponInventory[EquippedWeaponIndex];
	*/
}

bool ASampleGameCharacter::ServerSpawnCube_Validate()
{
	return true;
}

void ASampleGameCharacter::ServerSpawnCube_Implementation()
{
	DebugSpawnWeapon();
	return;

	if (TestActorTemplate == nullptr)
	{
		return;
	}

	FVector center = GetFollowCamera()->GetComponentLocation();
	const float kSpawnDistance = 500.0f;
	FVector spawnLocation = center + GetFollowCamera()->GetForwardVector() * kSpawnDistance;
	FTransform spawnTranform(FRotator::ZeroRotator, spawnLocation);

	GetWorld()->SpawnActor<ATestCube>(TestActorTemplate, spawnTranform);
}

void ASampleGameCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void ASampleGameCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void ASampleGameCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASampleGameCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void ASampleGameCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASampleGameCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}
