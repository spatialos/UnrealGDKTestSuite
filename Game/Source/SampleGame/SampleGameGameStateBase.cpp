// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#include "SampleGameGameStateBase.h"

void ASampleGameGameStateBase::FakeServerHasBegunPlay()
{
	if (!GetWorld()) 
	{
		return;
	}
	Role = ROLE_SimulatedProxy;
	
	bReplicatedHasBegunPlay = true;
	OnRep_ReplicatedHasBegunPlay();
}

void ASampleGameGameStateBase::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//DOREPLIFETIME(ASampleGameGameStateBase, m_numberOfPlayers);
}

void ASampleGameGameStateBase::NotifyReplicatedCurrentWeatherState()
{

}