// Fill out your copyright notice in the Description page of Project Settings.

#include "TestEnumReplication.h"

#include "GameFramework/GameModeBase.h"
#include "UnrealNetwork.h"

void ATestEnumReplication::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test8Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test16Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test32Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, Test64Enum, COND_None);
	DOREPLIFETIME_CONDITION(ATestEnumReplication, TestUEnum, COND_None);
}

bool ATestEnumReplication::Server_ReportReplication_Validate(ETest8Enum Rep8, ETest16Enum Rep16, ETest32Enum Rep32, ETest64Enum Rep64, EnumNamespace::EUnrealTestEnum RepU)
{
	return true;
}

void ATestEnumReplication::Server_ReportReplication_Implementation(ETest8Enum Rep8, ETest16Enum Rep16, ETest32Enum Rep32, ETest64Enum Rep64, EnumNamespace::EUnrealTestEnum RepU)
{
	Validate(Rep8, Rep16, Rep32, Rep64, RepU);

	SignalResponseRecieved();
}


void ATestEnumReplication::StartTestImpl()
{
	Test8Enum = (Test8Enum == ETest8Enum::Enum_0) ? ETest8Enum::Enum_1 : ETest8Enum::Enum_0;
	Test16Enum = (Test16Enum == ETest16Enum::Enum_0) ? ETest16Enum::Enum_1 : ETest16Enum::Enum_0;
	Test32Enum = (Test32Enum == ETest32Enum::Enum_0) ? ETest32Enum::Enum_1 : ETest32Enum::Enum_0;
	Test64Enum = (Test64Enum == ETest64Enum::Enum_0) ? ETest64Enum::Enum_1 : ETest64Enum::Enum_0;
	TestUEnum = (TestUEnum == EnumNamespace::Enum_0) ? EnumNamespace::Enum_1 : EnumNamespace::Enum_0;

	SignalReplicationSetup();
}

void ATestEnumReplication::ValidateClientReplicationImpl()
{
	Validate(Test8Enum, Test16Enum, Test32Enum, Test64Enum, TestUEnum);
}

void ATestEnumReplication::SendTestResponseRPCImpl()
{
	Server_ReportReplication(Test8Enum, Test16Enum, Test32Enum, Test64Enum, TestUEnum);
}

void ATestEnumReplication::Validate(ETest8Enum Test8, ETest16Enum Test16, ETest32Enum Test32, ETest64Enum Test64, EnumNamespace::EUnrealTestEnum TestU)
{
	if (Test8 == ETest8Enum::Enum_0)
	{
		check(Test8 == ETest8Enum::Enum_0);
		check(Test16 == ETest16Enum::Enum_0);
		check(Test32 == ETest32Enum::Enum_0);
		check(Test64 == ETest64Enum::Enum_0);
		check(TestU == EnumNamespace::Enum_0);
	}
	else
	{
		check(Test8 == ETest8Enum::Enum_1);
		check(Test16 == ETest16Enum::Enum_1);
		check(Test32 == ETest32Enum::Enum_1);
		check(Test64 == ETest64Enum::Enum_1);
		check(TestU == EnumNamespace::Enum_1);
	}
}
