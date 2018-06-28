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

	DOREPLIFETIME(UTestNestedStructs, TestContainerStruct);
}

void UTestNestedStructs::DoTheThing_Implementation(const FString& PrintMe, const FTestStruct& TheTestStructRPC)
{
	//// Get the value of the non-serialized int which should have been replicated thanks to the custom NetSerialize.
	//FString IntString = FString::FromInt(TheTestStructRPC.TestInt);
	//FString NonSerializedIntString = FString::FromInt(TheTestStructRPC.NonSerializedInt);

	//UE_LOG(LogTemp, Warning, TEXT("%s: Server_DoTheThing_Implementation"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));
	//UE_LOG(LogTemp, Warning, TEXT("Doing the thing: %s"), *PrintMe);
	//UE_LOG(LogTemp, Warning, TEXT("                 TestInt:          %s"), *IntString);
	//UE_LOG(LogTemp, Warning, TEXT("                 NonSerializedInt: %s"), *NonSerializedIntString);
}

bool UTestNestedStructs::DoTheThing_Validate(const FString& PrintMe, const FTestStruct& TheTestStructRPC)
{
	return true;
};

void UTestNestedStructs::DoTheThingCStyleArray_Implementation(const FString& PrintMe, const FTestStructCStyleArray& TheTestStructCStyleArrayRPC, const TArray<FTestStructCStyleArray>& DynamicStructArrayRPC)
{
	//FString IntString = "";
	//for (int i = 0; i < 3; i++)
	//{
	//	IntString += FString::FromInt(TheTestStructCStyleArrayRPC.TestIntArray[i]);
	//	IntString += " ";
	//}
	//UE_LOG(LogTemp, Warning, TEXT("%s: Server_DoTheThingCStyleArray_Implementation"), GetNetMode() == NM_Client ? TEXT("Client") : TEXT("Server"));
	//UE_LOG(LogTemp, Warning, TEXT("Doing the thing c-style array: %s"), *PrintMe);
	//UE_LOG(LogTemp, Warning, TEXT("                 TestIntArray: %s"), *IntString);
}

bool UTestNestedStructs::DoTheThingCStyleArray_Validate(const FString& PrintMe, const FTestStructCStyleArray& TheTestStructCStyleArrayRPC, const TArray<FTestStructCStyleArray>& DynamicStructArrayRPC)
{
	return true;
};


bool FTestStruct::NetSerialize(FArchive& Ar, class UPackageMap* Map, bool& bOutSuccess)
{
	Ar << TestInt;

	return true;
}
