// Copyright (c) Improbable Worlds Ltd, All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "SampleGameGameStateBase.generated.h"

USTRUCT(BlueprintType)
struct FS_TeamGameState
{
	GENERATED_BODY()

		UPROPERTY(BlueprintReadOnly)
		int32 Score;

	UPROPERTY(NotReplicated)
		uint8 Flags;

	UPROPERTY(BlueprintReadOnly, NotReplicated)
		TSet<FString> PlayerStates;
};

UCLASS()
class SAMPLEGAME_API ASampleGameGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:

	UPROPERTY(Replicated)
		int32 m_numberOfPlayers;

	UPROPERTY(Replicated)
		TArray<int32> m_scorePerPlayer;

	UPROPERTY(Replicated)
		TArray<FS_TeamGameState> m_gameStatePerTeam;

	UPROPERTY(Replicated)
		int32 m_scoreToWin;

	UPROPERTY(Replicated)
		int32 m_timeRemaining;

	UPROPERTY(Replicated)
		int32 m_numberOfJoinedPlayers;

	UPROPERTY(Replicated)
		int32 m_numberOfNeededPlayers;

	TArray<class AActor *> m_interactableActors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		FString m_timeOfDayAndWeatherComponent;

	UPROPERTY(ReplicatedUsing = NotifyReplicatedCurrentWeatherState)
		FString m_currentWeatherState;

	UFUNCTION()
		void NotifyReplicatedCurrentWeatherState();

	TBitArray<> m_usedPlayerIndices;

	UPROPERTY(Replicated)
		int32 m_sessionHighScore;

	UPROPERTY(Replicated)
		FString m_sessionHighScoreName;

	UPROPERTY(Replicated)
		int32 m_numberOfLifetimeHighScores;

	static constexpr int32 k_maximumNumberOfLifetimeHighScores = 3;

	UPROPERTY(Replicated)
		int32 m_lifetimeHighScores[k_maximumNumberOfLifetimeHighScores];

	UPROPERTY(Replicated)
		FString m_lifetimeHighScoreNames[k_maximumNumberOfLifetimeHighScores];


	void FakeServerHasBegunPlay();
};
