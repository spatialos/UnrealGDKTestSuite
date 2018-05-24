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

	TestPODStructArray.AddDefaulted(5);
	//TestEnumArray.AddDefaulted(5);
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
	PlayerInputComponent->BindAction("DebugCmd", IE_Pressed, this, &ASampleGameCharacter::DebugCmd);

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

void ASampleGameCharacter::DebugCmd()
{
	UE_LOG(LogTemp, Warning, TEXT("DebugCmd"));

	TArray<FTestMixedStruct> TempArray;
	TempArray.AddZeroed(4);

	Server_TestFunc();
	//Server_TestFunc(TempArray);
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

//void ASampleGameCharacter::Server_TestFunc_Implementation(const TArray<FTestMixedStruct>& StructArg)
void ASampleGameCharacter::Server_TestFunc_Implementation()
{
	// modify replicated members to check network serialisation
	static float Num = 101.f;
	TestPODArray.Add(Num);
	Num += 1.f;

	static FTestMixedStruct _TestMixedStruct{ PlayerState, 42.f };
	//TestMixedStructArray.Add(_TestMixedStruct);
	_TestMixedStruct.Modify();

	static FTestPODStruct _TestPODStruct{ 5.f, 5, 5.0 };

	//TestPODStructArray.Add(_TestPODStruct);
	_TestPODStruct.Modify();

	TestNetSerializeArray.Add(ReplicatedMovement);

	TestMixedStruct = _TestMixedStruct;
	_TestMixedStruct.Modify();

	TestPODStruct = _TestPODStruct;
	_TestPODStruct.Modify();

	TestBookend += 1;

	//UE_LOG(LogTemp, Warning, TEXT("RPC successfully called with an array of %d elements"), StructArg.Num());
}

//bool ASampleGameCharacter::Server_TestFunc_Validate(const TArray<FTestMixedStruct>& StructArg)
bool ASampleGameCharacter::Server_TestFunc_Validate()
{
	return true;
}

void ASampleGameCharacter::Client_TestConstArgs_Implementation(FConstStruct ConstStruct)
{

}

void ASampleGameCharacter::OnRep_TestPODArray()
{
	FString TestString;
	for (auto i : TestPODArray)
	{
		TestString.AppendInt(i);
		TestString.AppendChar(' ');
	}

	UE_LOG(LogTemp, Warning, TEXT("TestPODArray updated - %s"), *TestString);
}

void ASampleGameCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestPODArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestMixedStructArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestPODStructArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestNetSerializeArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestMixedStruct, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestPODStruct, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestEnumArray, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestObjectArray, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayReplication, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayStructReplication, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestMixedStructCArrayReplication, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestEnum, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestBookend, COND_None);
}