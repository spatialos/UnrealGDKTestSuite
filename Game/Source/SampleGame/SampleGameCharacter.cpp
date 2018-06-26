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
#include "Kismet/KismetSystemLibrary.h"
#include "SampleGameGameStateBase.h"
#include "SpatialNetDriver.h"

#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// ASampleGameCharacter

DEFINE_LOG_CATEGORY_STATIC(LogSampleGameCharacter, Log, All);

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

void ASampleGameCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ASampleGameCharacter, MyStruct);
	//DOREPLIFETIME(ASampleGameCharacter, MyCStyleStruct);
	DOREPLIFETIME(ASampleGameCharacter, MyArrayOfStruct);
	DOREPLIFETIME(ASampleGameCharacter, MyNSStruct);
	DOREPLIFETIME(ASampleGameCharacter, MyCStyleNSStruct);
	DOREPLIFETIME(ASampleGameCharacter, MyArrayOfNSStruct);
}

bool ASampleGameCharacter::Server_DoThings_Validate()
{
	return true;
}

void ASampleGameCharacter::Server_DoThings_Implementation()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASampleGameCharacter::StaticClass(), FoundActors);
	check(FoundActors.Num() > 0);

	int ActorIndex = FMath::RandRange(0, FoundActors.Num() - 1);
	AActor* Actor = FoundActors[ActorIndex];
	MyStruct.MyObject = Actor;
	MyNSStruct.MyObject = Actor;
	
	static int CStyleIndex = 0;
	MyCStyleStruct[CStyleIndex].MyObject = Actor;
	MyCStyleNSStruct[CStyleIndex].MyObject = Actor;
	CStyleIndex = (CStyleIndex + 1) % 5;

	MyArrayOfStruct.Add({Actor});
	MyArrayOfNSStruct.Add({Actor});
}

void ASampleGameCharacter::ShowThings()
{
	UE_LOG(LogSampleGameCharacter, Log, TEXT("!!! ShowThings:"));
	UE_LOG(LogSampleGameCharacter, Log, TEXT("MyStruct: %s"), *UKismetSystemLibrary::GetDisplayName(MyStruct.MyObject));
	UE_LOG(LogSampleGameCharacter, Log, TEXT("MyNSStruct: %s"), *UKismetSystemLibrary::GetDisplayName(MyNSStruct.MyObject));

	{
		FString MyCStyleStructString;
		for (int i = 0; i < 5; i++)
		{
			MyCStyleStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(MyCStyleStruct[i].MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyCStyleStruct: %s"), *MyCStyleStructString);
	}

	{
		FString MyCStyleNSStructString;
		for (int i = 0; i < 5; i++)
		{
			MyCStyleNSStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(MyCStyleNSStruct[i].MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyNSCStyleStruct: %s"), *MyCStyleNSStructString);
	}

	{
		FString MyArrayOfStructString;
		for (auto& Item : MyArrayOfStruct)
		{
			MyArrayOfStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(Item.MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyArrayOfStruct: %s"), *MyArrayOfStructString);
	}

	{
		FString MyArrayOfNSStructString;
		for (auto& Item : MyArrayOfNSStruct)
		{
			MyArrayOfNSStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(Item.MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyArrayOfNSStruct: %s"), *MyArrayOfNSStructString);
	}
}

void ASampleGameCharacter::SendThings()
{
	FMyCStyleStructs CStyleStructs;
	for (int i = 0; i < 5; i++)
	{
		CStyleStructs.MyCStyleStruct[i] = MyCStyleStruct[i];
		CStyleStructs.MyCStyleNSStruct[i] = MyCStyleNSStruct[i];
	}
	Server_ShowThings(MyStruct, MyArrayOfStruct, MyNSStruct, MyArrayOfNSStruct, CStyleStructs);
}

bool ASampleGameCharacter::Server_ShowThings_Validate(FMyStruct Struct, const TArray<FMyStruct>& ArrayOfStruct, FMyNSStruct NSStruct, const TArray<FMyNSStruct>& ArrayOfNSStruct, const FMyCStyleStructs& CStyleStructs)
{
	return true;
}

void ASampleGameCharacter::Server_ShowThings_Implementation(FMyStruct Struct, const TArray<FMyStruct>& ArrayOfStruct, FMyNSStruct NSStruct, const TArray<FMyNSStruct>& ArrayOfNSStruct, const FMyCStyleStructs& CStyleStructs)
{
	UE_LOG(LogSampleGameCharacter, Log, TEXT("!!! Server_ShowThings:"));
	UE_LOG(LogSampleGameCharacter, Log, TEXT("MyStruct: %s"), *UKismetSystemLibrary::GetDisplayName(Struct.MyObject));
	UE_LOG(LogSampleGameCharacter, Log, TEXT("MyNSStruct: %s"), *UKismetSystemLibrary::GetDisplayName(NSStruct.MyObject));

	{
		FString MyCStyleStructString;
		for (int i = 0; i < 5; i++)
		{
			MyCStyleStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(CStyleStructs.MyCStyleStruct[i].MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyCStyleStruct: %s"), *MyCStyleStructString);
	}

	{
		FString MyCStyleNSStructString;
		for (int i = 0; i < 5; i++)
		{
			MyCStyleNSStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(CStyleStructs.MyCStyleNSStruct[i].MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyNSCStyleStruct: %s"), *MyCStyleNSStructString);
	}

	{
		FString MyArrayOfStructString;
		for (auto& Item : ArrayOfStruct)
		{
			MyArrayOfStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(Item.MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyArrayOfStruct: %s"), *MyArrayOfStructString);
	}

	{
		FString MyArrayOfNSStructString;
		for (auto& Item : ArrayOfNSStruct)
		{
			MyArrayOfNSStructString += FString::Printf(TEXT("%s, "), *UKismetSystemLibrary::GetDisplayName(Item.MyObject));
		}
		UE_LOG(LogSampleGameCharacter, Log, TEXT("MyArrayOfNSStruct: %s"), *MyArrayOfNSStructString);
	}
}

void ASampleGameCharacter::BeginPlay()
{
	Super::BeginPlay();
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

bool ASampleGameCharacter::TestMulticast_Validate()
{
	return true;
}

void ASampleGameCharacter::TestMulticast_Implementation()
{
}
