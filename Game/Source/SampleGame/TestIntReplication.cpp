// Fill out your copyright notice in the Description page of Project Settings.

#include "TestIntReplication.h"

#include "UnrealNetwork.h"

// Sets default values
ATestIntReplication::ATestIntReplication()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestIntReplication::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestIntReplication::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATestIntReplication::Server_TestFunc_Validate()
{
	return true;
}

void ATestIntReplication::Server_TestFunc_Implementation()
{
	Test8Int = (1 << 6);
	Test16Int = (1 << 14);
	Test32Int = 0xDEADBEEF;
	Test64Int = 0xDEADBEEFDEADBEEF;
	Test8UInt = 0xDE;
	Test16UInt = 0xDEAD;
	Test32UInt = 0xDEADBEEF;
	Test64UInt = 0xDEADBEEFDEADBEEF;

	// Nested struct replication end
	TestBookend += 1;
}

void ATestIntReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test8Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test16Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test32Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test64Int, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test8UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test16UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test32UInt, COND_None);
	DOREPLIFETIME_CONDITION(ATestIntReplication, Test64UInt, COND_None);
}

bool ATestIntReplication::Server_ReportReplication_Validate(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt)
{
	return true;
}

void ATestIntReplication::Server_ReportReplication_Implementation(int8 Rep8Int, int16 Rep16Int, int32 Rep32Int, int64 Rep64Int, uint8 Rep8UInt, uint16 Rep16UInt, uint32 Rep32UInt, uint64 Rep64UInt)
{

}

void ATestIntReplication::OnRep_TestBookend()
{
	check(Test8Int == (1 << 6));
	check(Test16Int == (1 << 14));
	check(Test32Int == 0xDEADBEEF);
	check(Test64Int == 0xDEADBEEFDEADBEEF);
	check(Test8UInt == 0xDE);
	check(Test16UInt == 0xDEAD);
	check(Test32UInt == 0xDEADBEEF);
	check(Test64UInt == 0xDEADBEEFDEADBEEF);
}
