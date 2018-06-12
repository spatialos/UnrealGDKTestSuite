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
	for (int i = 0; i < 8; ++i)
	{
		TestCArrayReplication[i] = 0;
	}
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
	UE_LOG(LogTemp, Warning, TEXT("%s: DebugCmd"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));

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
	UE_LOG(LogTemp, Warning, TEXT("%s: Server_TestFunc_Implementation"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));

	// modify replicated members to check network serialisation
	static float Num = 101.f;
	TestPODArray.Add(Num);
	Num += 1.f;

	static FTestMixedStruct _TestMixedStruct{ PlayerState, 42.f };
	//TestMixedStructArray.Add(_TestMixedStruct); // commented out until we support UObject* serialization in nested structs
	_TestMixedStruct.Modify();

	static FTestPODStruct _TestPODStruct{ 5.f, 5, 5.0 };

	//TestPODStructArray.Add(_TestPODStruct);
	_TestPODStruct.Modify();

	TestNetSerializeArray.Add(ReplicatedMovement);

	TestMixedStruct = _TestMixedStruct;
	_TestMixedStruct.Modify();

	TestPODStruct = _TestPODStruct;
	_TestPODStruct.Modify();

	// Enum property changes begin
	Test8Enum = (Test8Enum == ETest8Enum::Enum_0) ? ETest8Enum::Enum_1 : ETest8Enum::Enum_0;
	Test16Enum = (Test16Enum == ETest16Enum::Enum_0) ? ETest16Enum::Enum_1 : ETest16Enum::Enum_0;
	Test32Enum = (Test32Enum == ETest32Enum::Enum_0) ? ETest32Enum::Enum_1 : ETest32Enum::Enum_0;
	Test64Enum = (Test64Enum == ETest64Enum::Enum_0) ? ETest64Enum::Enum_1 : ETest64Enum::Enum_0;
	TestUEnum = (TestUEnum == EnumNamespace::Enum_0) ? EnumNamespace::Enum_1 : EnumNamespace::Enum_0;

	//static int TestEnumArrayIdx = 0;
	//TestEnumCArray[TestEnumArrayIdx] = ETest8Enum::Enum_0;
	//TestUEnumCArray[TestEnumArrayIdx] = EnumNamespace::Enum_0;
	//TestEnumArrayIdx++;

	TestEnumTArray.Push(ETest8Enum::Enum_0);
	TestUEnumTArray.Push(EnumNamespace::Enum_0);
	// Enum property changes end

	// POD property changes begin
	Test8Int = (1 << 6);
	Test16Int = (1 << 14);
	Test32Int = 0xDEADBEEF;
	Test64Int = 0xDEADBEEFDEADBEEF;
	Test8UInt = 0xDE;
	Test16UInt = 0xDEAD;
	Test32UInt = 0xDEADBEEF;
	Test64UInt = 0xDEADBEEFDEADBEEF;
	TestFloat = 42.f;
	TestDouble = 42.0;
	// POD property changes end

	// Nested struct replication begin
	FBar MyBar;
	FFoo MyFoo;
	MyFoo.FooMember = 31;
	MyBar.CantReplicateThisMember.Push(MyFoo);
	MyFoo.FooMember++;
	MyBar.CantReplicateThisMember.Push(MyFoo);
	MyFoo.FooMember++;
	MyBar.CantReplicateThisMember.Push(MyFoo);
	MyFoo.FooMember++;
	MyBar.CantReplicateThisMember.Push(MyFoo);

	BarArray.Push(MyBar);
	BarArray.Push(MyBar);

	TestBar.MyStruct.MyInt++;
	TestBar.MyStruct.MyFloat = 101.f;
	TestBar.CantReplicateThisMember.Push(MyFoo);
	MyFoo.FooMember++;
	TestBar.CantReplicateThisMember.Push(MyFoo);
	MyFoo.FooMember++;
	TestBar.CantReplicateThisMember.Push(MyFoo);
	// Nested struct replication end

	TestBookend += 1;

	TestCArrayReplication[4] += 1;
	Client_TestFunc();

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

void ASampleGameCharacter::Client_TestFunc_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("%s: Client_TestFunc_Implementation"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));
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

void ASampleGameCharacter::OnRep_TestBookend()
{
	// POD property checks begin
	check(Test8Int == (1 << 6));
	check(Test16Int == (1 << 14));
	check(Test32Int == 0xDEADBEEF);
	check(Test64Int == 0xDEADBEEFDEADBEEF);
	check(Test8UInt == 0xDE);
	check(Test16UInt == 0xDEAD);
	check(Test32UInt == 0xDEADBEEF);
	check(Test64UInt == 0xDEADBEEFDEADBEEF);
	check(TestFloat == 42.f);
	check(TestDouble == 42.0);
	// POD property checks end

	check(TestEnumTArray.Num() > 0);
	check(TestUEnumTArray.Num() > 0);

	if (Test8Enum == ETest8Enum::Enum_0)
	{
		check(Test8Enum == ETest8Enum::Enum_0);
		check(Test16Enum == ETest16Enum::Enum_0);
		check(Test32Enum == ETest32Enum::Enum_0);
		check(Test64Enum == ETest64Enum::Enum_0);
		check(TestUEnum == EnumNamespace::Enum_0);
	}
	else
	{
		check(Test8Enum == ETest8Enum::Enum_1);
		check(Test16Enum == ETest16Enum::Enum_1);
		check(Test32Enum == ETest32Enum::Enum_1);
		check(Test64Enum == ETest64Enum::Enum_1);
		check(TestUEnum == EnumNamespace::Enum_1);
	}
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

	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestObjectArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayReplication, COND_None);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayStructReplication, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestMixedStructCArrayReplication, COND_SimulatedOnly);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test8Enum, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test16Enum, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test32Enum, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test64Enum, COND_None);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestEnumCArray, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestEnumTArray, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestUEnum, COND_None);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestUEnumCArray, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestUEnumTArray, COND_None);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test8Int, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test16Int, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test32Int, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test64Int, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test8UInt, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test16UInt, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test32UInt, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, Test64UInt, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestFloat, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestDouble, COND_None);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, BarArray, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestBar, COND_None);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestBookend, COND_None);
}
