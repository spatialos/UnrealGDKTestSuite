// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
#pragma optimize("", off)

#include "TestNestedStructs.h"
#include "Engine/World.h"
#include "SampleGameGameStateBase.h"
#include "SpatialNetDriver.h"
#include "UnrealNetwork.h"


UTestNestedStructs::UTestNestedStructs()
{

}


void UTestNestedStructs::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UTestNestedStructs, TestContainerStructArray);
}

//bool FTestStruct::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
//{
//	Ar << TestInt;
//
//	return true;
//}