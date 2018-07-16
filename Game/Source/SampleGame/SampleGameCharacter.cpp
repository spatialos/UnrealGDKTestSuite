// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "DrawDebugHelpers.h"
#include "Engine/World.h"
#include "EngineGlobals.h"  // for onscreen debug
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCube.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"  // ^
#include "SampleGameGameStateBase.h"
#include "SampleGamePlayerController.h"
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// ASampleGameCharacter

ASampleGameCharacter::ASampleGameCharacter()
{
    // Hack to ensure that the game state is created and set to tick on a client as we don't
    // replicate it
    UWorld* World = GetWorld();
    if (World && World->GetGameState() == nullptr)
    {
        AGameStateBase* GameState =
            World->SpawnActor<AGameStateBase>(ASampleGameGameStateBase::StaticClass());
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
    GetCharacterMovement()->bOrientRotationToMovement =
        true;  // Character moves in the direction of input...
    GetCharacterMovement()->RotationRate =
        FRotator(0.0f, 540.0f, 0.0f);  // ...at this rotation rate
    GetCharacterMovement()->JumpZVelocity = 600.f;
    GetCharacterMovement()->AirControl = 0.2f;

    // Create a camera boom (pulls in towards the player if there is a collision)
    CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
    CameraBoom->SetupAttachment(RootComponent);
    CameraBoom->TargetArmLength =
        300.0f;  // The camera follows at this distance behind the character
    CameraBoom->bUsePawnControlRotation = true;  // Rotate the arm based on the controller

    // Create a follow camera
    FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
    FollowCamera->SetupAttachment(
        CameraBoom, USpringArmComponent::SocketName);  // Attach the camera to the end of the boom
                                                       // and let the boom adjust to match the
                                                       // controller orientation
    FollowCamera->bUsePawnControlRotation = false;     // Camera does not rotate relative to arm

    // Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from
    // Character) are set in the derived blueprint asset named MyCharacter (to avoid direct content
    // references in C++)

    static ConstructorHelpers::FObjectFinder<UBlueprint> ItemBlueprint(
        TEXT("Blueprint'/Game/EntityBlueprints/MyCube_BP.MyCube_BP'"));
    if (ItemBlueprint.Object)
    {
        CubeToSpawn = (UClass*)ItemBlueprint.Object->GeneratedClass;
    }

    // set up holding component for picking up objects
    HoldingComponent = CreateDefaultSubobject<USceneComponent>(TEXT("HoldingComponent"));
    HoldingComponent->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));
    HoldingComponent->SetupAttachment(RootComponent);

    bCanMove = true;
    bInspecting = false;
    bHoldingItem = false;

    bReplicates = true;
}

void ASampleGameCharacter::GetLifetimeReplicatedProps(
    TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(ASampleGameCharacter, CurrentItem);
    DOREPLIFETIME(ASampleGameCharacter, bHoldingItem);
}

void ASampleGameCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void ASampleGameCharacter::OnRep_Controller()
{
    Super::OnRep_Controller();

    // set default object-inspection camera
    if (Controller)
    {
        PitchMax = Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMax;
        PitchMin = Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMin;
    }
}

void ASampleGameCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    if (!HasAuthority())
    {
        RaycastSearchForItem();  // only execute on client

        GEngine->AddOnScreenDebugMessage(
            -1, 5.f, FColor::Red,
            FString::Printf(TEXT("CurrentItem: %s, bHoldingItem: %d, bInspecting: %d"),
                            CurrentItem ? *CurrentItem->GetName() : TEXT("None"), bHoldingItem,
                            bInspecting));
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
    // "turnrate" is for devices that we choose to treat as a rate of change, such as an analog
    // joystick
    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("TurnRate", this, &ASampleGameCharacter::TurnAtRate);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookUpRate", this, &ASampleGameCharacter::LookUpAtRate);

    // handle touch devices
    PlayerInputComponent->BindTouch(IE_Pressed, this, &ASampleGameCharacter::TouchStarted);
    PlayerInputComponent->BindTouch(IE_Released, this, &ASampleGameCharacter::TouchStopped);

    // spawn cube
    PlayerInputComponent->BindAction("SpawnCube", IE_Pressed, this,
                                     &ASampleGameCharacter::SpawnCube);

    // grabbing and inspecting objects
    // Bind action event (keypress E, picking up object)
    PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ASampleGameCharacter::Interact);

    // Bind Inspect event (zooming in)
    PlayerInputComponent->BindAction("Inspect", IE_Pressed, this, &ASampleGameCharacter::OnInspect);
    PlayerInputComponent->BindAction("Inspect", IE_Released, this,
                                     &ASampleGameCharacter::OnInspectStopped);
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
    if ((Controller != nullptr) && (Value != 0.0f) && bCanMove)
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
    if ((Controller != nullptr) && (Value != 0.0f) && bCanMove)
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

void ASampleGameCharacter::SpawnCube_Implementation()
{
    FVector CameraCenter = GetFollowCamera()->GetComponentLocation();
    FVector SpawnLocation = CameraCenter + GetFollowCamera()->GetForwardVector() * 200.f;
    FTransform SpawnTranform(FRotator::ZeroRotator, SpawnLocation);
    GetWorld()->SpawnActor<AActor>(CubeToSpawn, SpawnTranform);
}

bool ASampleGameCharacter::SpawnCube_Validate()
{
    return true;
}

bool ASampleGameCharacter::TestMulticast_Validate()
{
    return true;
}

void ASampleGameCharacter::TestMulticast_Implementation() {}

bool ASampleGameCharacter::TestRPC_Validate()
{
    return true;
}

void ASampleGameCharacter::TestRPC_Implementation() {}

// this is called locally to draw the debug lines and set camera/visuals
// we will call server RPCs for SetCurrentItem
void ASampleGameCharacter::RaycastSearchForItem()
{
    Start = GetActorLocation();
    ForwardVector = GetFollowCamera()->GetForwardVector();
    End = ((ForwardVector * 500.f) + Start);

    DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

    if (!bHoldingItem)
    {
        if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility,
                                                 DefaultComponentQueryParams, DefaultResponseParam))
        {
            if (Hit.GetActor()->GetClass()->IsChildOf(APickupAndRotateActor::StaticClass()))
            {
                // focus on item
                SetCurrentItem(Cast<APickupAndRotateActor>(Hit.GetActor()));
            }
        }
        else
        {
            SetCurrentItem(nullptr);
        }
    }

    if (bInspecting)
    {
        if (bHoldingItem)
        {
            GetFollowCamera()->SetFieldOfView(
                FMath::Lerp(GetFollowCamera()->FieldOfView, 90.0f, 0.1f));
            HoldingComponent->SetRelativeLocation(FVector(0.0f, 50.0f, 50.0f));
            Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMax =
                179.9000002f;
            Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMin =
                -179.9000002f;

			if (CurrentItem) CurrentItem->RotateActor();
        }
        else
        {
            GetFollowCamera()->SetFieldOfView(
                FMath::Lerp(GetFollowCamera()->FieldOfView, 45.0f, 0.1f));
        }
    }
    else
    {
        GetFollowCamera()->SetFieldOfView(FMath::Lerp(GetFollowCamera()->FieldOfView, 90.0f, 0.1f));

        if (bHoldingItem)
        {
            HoldingComponent->SetRelativeLocation(FVector(50.0f, 0.0f, 0.f));
        }
    }
}

void ASampleGameCharacter::SetCurrentItem_Implementation(class APickupAndRotateActor* currItem)
{
    CurrentItem = currItem;
}

bool ASampleGameCharacter::SetCurrentItem_Validate(class APickupAndRotateActor* currItem)
{
    return true;
}

void ASampleGameCharacter::Interact()
{
    if (CurrentItem && !bInspecting)
    {
        if (CurrentItem) CurrentItem->LinkToPlayer(this);  // call this on client side
														   // since we want to link the cube only to THIS player
														   // the cube function LinkToPlayer is server side anyways, so its changes will replicate

        ToggleItemPickup();  // this is executed on the server, so it won't know which player to link cube to
    }
}

// inspecting is a local action; no broadcast needed
void ASampleGameCharacter::OnInspect()
{
    if (bHoldingItem)
    {
        LastRotation = GetControlRotation();
        ToggleMovement();
    }
    else
    {
        bInspecting = true;
    }
}

void ASampleGameCharacter::OnInspectStopped()
{
    if (bInspecting && bHoldingItem)
    {
        Controller->SetControlRotation(LastRotation);
        Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMax = PitchMax;
        Cast<ASampleGamePlayerController>(Controller)->PlayerCameraManager->ViewPitchMin = PitchMin;
        ToggleMovement();
    }
    else
    {
        bInspecting = false;
    }
}

void ASampleGameCharacter::ToggleMovement()
{
    bCanMove = !bCanMove;
    bInspecting = !bInspecting;
    GetFollowCamera()->bUsePawnControlRotation = !GetFollowCamera()->bUsePawnControlRotation;
    bUseControllerRotationYaw = !bUseControllerRotationYaw;
}

// this, however, needs to be called server side to set the flags
void ASampleGameCharacter::ToggleItemPickup_Implementation()
{
    if (CurrentItem)
    {
        bHoldingItem = !bHoldingItem;
        CurrentItem->Pickup();

        if (!bHoldingItem)
        {
            CurrentItem = nullptr;
        }
    }
}

bool ASampleGameCharacter::ToggleItemPickup_Validate() {
    return true;
}
