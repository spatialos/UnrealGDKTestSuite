// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "TestSuiteGameStateBase.h"

void ATestSuiteGameStateBase::FakeServerHasBegunPlay()
{
	if (!GetWorld()) 
	{
		return;
	}
	Role = ROLE_SimulatedProxy;
	
	bReplicatedHasBegunPlay = true;
	OnRep_ReplicatedHasBegunPlay();
}
