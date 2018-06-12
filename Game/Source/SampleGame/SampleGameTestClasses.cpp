// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameTestClasses.h"
#include "UnrealNetwork.h"

//////////////////////////////////////////////////////////////////////////
// AS_TestUnderscoreClassName

AS_TestUnderscoreClassName::AS_TestUnderscoreClassName()
{
	
}

void AS_TestUnderscoreClassName::ClientUnderscoreRPC_Implementation()
{

}

ARepCmdConfusion::ARepCmdConfusion()
{

}

void ARepCmdConfusion::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION(ARepCmdConfusion, MyStruct, COND_None);
}
