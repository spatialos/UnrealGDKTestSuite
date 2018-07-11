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

#include "Tests/TestIntReplication.h"
#include "Tests/TestFloatReplication.h"
#include "Tests/TestBoolReplication.h"
#include "Tests/TestCharReplication.h"
#include "Tests/TestFStringReplication.h"
#include "Tests/TestCArrayReplication.h"
#include "Tests/TestTArrayReplication.h"
#include "Tests/TestEnumReplication.h"
#include "Tests/TestFTextReplication.h"
#include "Tests/TestFNameReplication.h"
#include "Tests/TestUStructReplication.h"
#include "Tests/TestUObjectReplication.h"

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

	//IntRepTestCreated = false;
	//FloatRepTestCreated = false;
	//BoolRepTestCreated = false;
	//CharRepTestCreated = false;
	//FStringRepTestCreated = false;
	//CArrayRepTestCreated = false;
	//TArrayUObjectsRepTest = false;
	//EnumRepTestCreated = false;
}

void ASampleGameCharacter::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	if (World && GetNetMode() == NM_DedicatedServer)
	{
		ATestIntReplication* IntTest = World->SpawnActor<ATestIntReplication>();
		check(IntTest);
		TestCases.Add(IntTest);

		ATestFloatReplication* FloatTest = World->SpawnActor<ATestFloatReplication>();
		check(FloatTest);
		TestCases.Add(FloatTest);

		ATestBoolReplication* BoolTest = World->SpawnActor<ATestBoolReplication>();
		check(BoolTest);
		TestCases.Add(BoolTest);

		ATestCharReplication* CharTest = World->SpawnActor<ATestCharReplication>();
		check(CharTest);
		TestCases.Add(CharTest);

		ATestFStringReplication* FStringTest = World->SpawnActor<ATestFStringReplication>();
		check(FStringTest);
		TestCases.Add(FStringTest);

		ATestCArrayReplication* CArrayTest = World->SpawnActor<ATestCArrayReplication>();
		check(CArrayTest);
		TestCases.Add(CArrayTest);

		ATestTArrayReplication* TArrayTest = World->SpawnActor<ATestTArrayReplication>();
		check(TArrayTest);
		TestCases.Add(TArrayTest);

		ATestEnumReplication* EnumTest = World->SpawnActor<ATestEnumReplication>();
		check(EnumTest);
		TestCases.Add(EnumTest);

		ATestFTextReplication* FTextTest = World->SpawnActor<ATestFTextReplication>();
		check(FTextTest);
		TestCases.Add(FTextTest);

		ATestFNameReplication* FNameTest = World->SpawnActor<ATestFNameReplication>();
		check(FNameTest);
		TestCases.Add(FNameTest);

		ATestUObjectReplication* UObjectTest = World->SpawnActor<ATestUObjectReplication>();
		check(UObjectTest);
		TestCases.Add(UObjectTest);

		ATestUStructReplication* UStructTest = World->SpawnActor<ATestUStructReplication>();
		check(UStructTest);
		TestCases.Add(UStructTest);
	}
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

	if (bTestCasesReplicated)
	{
		for (AReplicationTestCase* TestCase : TestCases)
		{
			TestCase->Server_StartTest();
		}
	}
	else 
	{
		UE_LOG(LogTemp, Error, TEXT("Test suite not ready yet!"));
	}


	/*if (IntRepTestCreated && 
		FloatRepTestCreated && 
		BoolRepTestCreated && 
		CharRepTestCreated && 
		FStringRepTestCreated && 
		CArrayRepTestCreated && 
		TArrayUObjectsRepTestCreated &&
		EnumRepTestCreated)
	{
		IntRepTest->Server_StartTest();
		FloatRepTest->Server_StartTest();
		BoolRepTest->Server_StartTest();
		CharRepTest->Server_StartTest();
		FStringRepTest->Server_StartTest();
		CArrayRepTest->Server_StartTest();
		TArrayUObjectsRepTest->Server_StartTest();
		EnumRepTest->Server_StartTest();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Test suite not ready yet!"));
		UE_LOG(LogTemp, Error, TEXT("IntRepTestCreated: %s"), IntRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("FloatRepTestCreated: %s"), FloatRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("BoolRepTestCreated: %s"), BoolRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("CharRepTestCreated: %s"), CharRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("FStringRepTestCreated: %s"), FStringRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("CArrayRepTestCreated: %s"), CArrayRepTestCreated ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("TArrayUObjectsRepTest: %s"), TArrayUObjectsRepTest ? TEXT("TRUE") : TEXT("FALSE"));
		UE_LOG(LogTemp, Error, TEXT("EnumRepTestCreated: %s"), TArrayUObjectsRepTest ? TEXT("TRUE") : TEXT("FALSE"));
	}*/
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

	//static int TestEnumArrayIdx = 0;
	//TestEnumCArray[TestEnumArrayIdx] = ETest8Enum::Enum_0;
	//TestUEnumCArray[TestEnumArrayIdx] = EnumNamespace::Enum_0;
	//TestEnumArrayIdx++;

	StablyNamedObj = GetMesh()->SkeletalMesh;

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
}

//void ASampleGameCharacter::OnRep_IntRepTest()
//{
//	IntRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_FloatRepTest()
//{
//	FloatRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_BoolRepTest()
//{
//	BoolRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_CharRepTest()
//{
//	CharRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_FStringRepTest()
//{
//	FStringRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_CArrayRepTest()
//{
//	CArrayRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_TArrayUObjectsRepTest()
//{
//	TArrayUObjectsRepTestCreated = true;
//}
//
//void ASampleGameCharacter::OnRep_EnumRepTest()
//{
//	EnumRepTestCreated = true;
//}

void ASampleGameCharacter::OnRep_TestCases()
{
	bTestCasesReplicated = true;
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

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, StablyNamedObj, COND_None);

	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestObjectArray, COND_SimulatedOnly);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayReplication, COND_None);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCArrayStructReplication, COND_SimulatedOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestMixedStructCArrayReplication, COND_SimulatedOnly);


	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestEnumCArray, COND_None);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, BarArray, COND_None);
	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestBar, COND_None);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestBookend, COND_None);

	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, IntRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, FloatRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, BoolRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, CharRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, FStringRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, CArrayRepTest, COND_InitialOnly);
	//DOREPLIFETIME_CONDITION(ASampleGameCharacter, TArrayUObjectsRepTest, COND_InitialOnly);

	DOREPLIFETIME_CONDITION(ASampleGameCharacter, TestCases, COND_InitialOnly);
}

bool ASampleGameCharacter::TestMulticast_Validate()
{
	return true;
}

void ASampleGameCharacter::TestMulticast_Implementation()
{
}