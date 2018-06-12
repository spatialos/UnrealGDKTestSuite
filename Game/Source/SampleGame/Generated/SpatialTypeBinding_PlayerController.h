// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealPlayerController.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_PlayerController.generated.h"

UCLASS()
class USpatialTypeBinding_PlayerController : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FMigratableHandlePropertyMap& GetMigratableHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView() override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_PlayerController::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& Update) const;

	// RPC event receive functions.
	void ReceiveUpdate_ClientRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update& Update);
	void ReceiveUpdate_ServerRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update& Update);

	// RPC command sender functions.
	void OnServerStartedVisualLogger_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientWasKicked_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVoiceHandshakeComplete_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateMultipleLevelsStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUpdateLevelStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTravelInternal_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientTeamMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStopCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientStartOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSpawnCameraLensEffect_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetHUD_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetForceMipLevelsToBeResident_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCinematicMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetCameraFade_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetBlockOnAsyncLoading_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenuWithTextReason_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReturnToMainMenu_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRetryClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReset_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientRepObjRef_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientReceiveLocalizedMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrestreamTextures_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPrepareMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySoundAtLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlaySound_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientPlayCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreMoveInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientIgnoreLookInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGotoState_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientGameEnded_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientForceGarbageCollection_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientFlushLevelStreaming_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEndOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientEnableNetworkVoice_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCommitMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientClearCameraLensEffects_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCapBandwidth_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCancelPendingMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAddTextureStreamingLoc_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetRotation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientSetLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewSelf_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewPrevPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerViewNextPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerVerifyViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateMultipleLevelsVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateLevelVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUpdateCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerToggleAILogging_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerShortTimeout_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerSetSpectatorLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerRestartPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerPause_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerNotifyLoadedWorld_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossessionReliable_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCheckClientPossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerChangeName_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerAcknowledgePossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void OnServerStartedVisualLogger_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealOnServerStartedVisualLoggerRequest& EventData);
	void ClientWasKicked_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientWasKickedRequest& EventData);
	void ClientVoiceHandshakeComplete_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientVoiceHandshakeCompleteRequest& EventData);
	void ClientUpdateMultipleLevelsStreamingStatus_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUpdateMultipleLevelsStreamingStatusRequest& EventData);
	void ClientUpdateLevelStreamingStatus_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUpdateLevelStreamingStatusRequest& EventData);
	void ClientUnmutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUnmutePlayerRequest& EventData);
	void ClientTravelInternal_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientTravelInternalRequest& EventData);
	void ClientTeamMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientTeamMessageRequest& EventData);
	void ClientStopForceFeedback_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopForceFeedbackRequest& EventData);
	void ClientStopCameraShake_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopCameraShakeRequest& EventData);
	void ClientStopCameraAnim_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopCameraAnimRequest& EventData);
	void ClientStartOnlineSession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStartOnlineSessionRequest& EventData);
	void ClientSpawnCameraLensEffect_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSpawnCameraLensEffectRequest& EventData);
	void ClientSetViewTarget_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetViewTargetRequest& EventData);
	void ClientSetSpectatorWaiting_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetSpectatorWaitingRequest& EventData);
	void ClientSetHUD_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetHUDRequest& EventData);
	void ClientSetForceMipLevelsToBeResident_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetForceMipLevelsToBeResidentRequest& EventData);
	void ClientSetCinematicMode_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCinematicModeRequest& EventData);
	void ClientSetCameraMode_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCameraModeRequest& EventData);
	void ClientSetCameraFade_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCameraFadeRequest& EventData);
	void ClientSetBlockOnAsyncLoading_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetBlockOnAsyncLoadingRequest& EventData);
	void ClientReturnToMainMenuWithTextReason_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReturnToMainMenuWithTextReasonRequest& EventData);
	void ClientReturnToMainMenu_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReturnToMainMenuRequest& EventData);
	void ClientRetryClientRestart_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRetryClientRestartRequest& EventData);
	void ClientRestart_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRestartRequest& EventData);
	void ClientReset_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientResetRequest& EventData);
	void ClientRepObjRef_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRepObjRefRequest& EventData);
	void ClientReceiveLocalizedMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReceiveLocalizedMessageRequest& EventData);
	void ClientPrestreamTextures_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPrestreamTexturesRequest& EventData);
	void ClientPrepareMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPrepareMapChangeRequest& EventData);
	void ClientPlaySoundAtLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlaySoundAtLocationRequest& EventData);
	void ClientPlaySound_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlaySoundRequest& EventData);
	void ClientPlayForceFeedback_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayForceFeedbackRequest& EventData);
	void ClientPlayCameraShake_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayCameraShakeRequest& EventData);
	void ClientPlayCameraAnim_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayCameraAnimRequest& EventData);
	void ClientMutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientMutePlayerRequest& EventData);
	void ClientMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientMessageRequest& EventData);
	void ClientIgnoreMoveInput_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientIgnoreMoveInputRequest& EventData);
	void ClientIgnoreLookInput_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientIgnoreLookInputRequest& EventData);
	void ClientGotoState_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientGotoStateRequest& EventData);
	void ClientGameEnded_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientGameEndedRequest& EventData);
	void ClientForceGarbageCollection_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientForceGarbageCollectionRequest& EventData);
	void ClientFlushLevelStreaming_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientFlushLevelStreamingRequest& EventData);
	void ClientEndOnlineSession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientEndOnlineSessionRequest& EventData);
	void ClientEnableNetworkVoice_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientEnableNetworkVoiceRequest& EventData);
	void ClientCommitMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCommitMapChangeRequest& EventData);
	void ClientClearCameraLensEffects_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientClearCameraLensEffectsRequest& EventData);
	void ClientCapBandwidth_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCapBandwidthRequest& EventData);
	void ClientCancelPendingMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCancelPendingMapChangeRequest& EventData);
	void ClientAddTextureStreamingLoc_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAddTextureStreamingLocRequest& EventData);
	void ClientSetRotation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetRotationRequest& EventData);
	void ClientSetLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetLocationRequest& EventData);
	void ServerViewSelf_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewSelfRequest& EventData);
	void ServerViewPrevPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewPrevPlayerRequest& EventData);
	void ServerViewNextPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewNextPlayerRequest& EventData);
	void ServerVerifyViewTarget_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerVerifyViewTargetRequest& EventData);
	void ServerUpdateMultipleLevelsVisibility_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateMultipleLevelsVisibilityRequest& EventData);
	void ServerUpdateLevelVisibility_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateLevelVisibilityRequest& EventData);
	void ServerUpdateCamera_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateCameraRequest& EventData);
	void ServerUnmutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUnmutePlayerRequest& EventData);
	void ServerToggleAILogging_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerToggleAILoggingRequest& EventData);
	void ServerShortTimeout_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerShortTimeoutRequest& EventData);
	void ServerSetSpectatorWaiting_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerSetSpectatorWaitingRequest& EventData);
	void ServerSetSpectatorLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerSetSpectatorLocationRequest& EventData);
	void ServerRestartPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerRestartPlayerRequest& EventData);
	void ServerPause_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerPauseRequest& EventData);
	void ServerNotifyLoadedWorld_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerNotifyLoadedWorldRequest& EventData);
	void ServerMutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMutePlayerRequest& EventData);
	void ServerCheckClientPossessionReliable_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCheckClientPossessionReliableRequest& EventData);
	void ServerCheckClientPossession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCheckClientPossessionRequest& EventData);
	void ServerChangeName_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerChangeNameRequest& EventData);
	void ServerCamera_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCameraRequest& EventData);
	void ServerAcknowledgePossession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerAcknowledgePossessionRequest& EventData);
};
