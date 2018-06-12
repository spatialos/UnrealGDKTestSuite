// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_PlayerController.h"

#include "GameFramework/PlayerState.h"
#include "NetworkGuid.h"

#include "SpatialOS.h"
#include "EntityBuilder.h"

#include "SpatialConstants.h"
#include "SpatialConditionMapFilter.h"
#include "SpatialUnrealObjectRef.h"
#include "SpatialActorChannel.h"
#include "SpatialPackageMapClient.h"
#include "SpatialNetDriver.h"
#include "SpatialInterop.h"
#include "Camera/CameraAnim.h"
#include "Camera/CameraShake.h"
#include "GameFramework/HUD.h"
#include "GameFramework/LocalMessage.h"
#include "Particles/EmitterCameraLensEffectBase.h"

#include "UnrealPlayerControllerSingleClientRepDataAddComponentOp.h"
#include "UnrealPlayerControllerMultiClientRepDataAddComponentOp.h"
#include "UnrealPlayerControllerMigratableDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_PlayerController::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FMigratableHandlePropertyMap& USpatialTypeBinding_PlayerController::GetMigratableHandlePropertyMap() const
{
	return MigratableHandleToPropertyMap;
}

UClass* USpatialTypeBinding_PlayerController::GetBoundClass() const
{
	return APlayerController::StaticClass();
}

void USpatialTypeBinding_PlayerController::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("OnServerStartedVisualLogger", &USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_SendCommand);
	RPCToSenderMap.Emplace("ClientWasKicked", &USpatialTypeBinding_PlayerController::ClientWasKicked_SendCommand);
	RPCToSenderMap.Emplace("ClientVoiceHandshakeComplete", &USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_SendCommand);
	RPCToSenderMap.Emplace("ClientUpdateMultipleLevelsStreamingStatus", &USpatialTypeBinding_PlayerController::ClientUpdateMultipleLevelsStreamingStatus_SendCommand);
	RPCToSenderMap.Emplace("ClientUpdateLevelStreamingStatus", &USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_SendCommand);
	RPCToSenderMap.Emplace("ClientUnmutePlayer", &USpatialTypeBinding_PlayerController::ClientUnmutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ClientTravelInternal", &USpatialTypeBinding_PlayerController::ClientTravelInternal_SendCommand);
	RPCToSenderMap.Emplace("ClientTeamMessage", &USpatialTypeBinding_PlayerController::ClientTeamMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientStopForceFeedback", &USpatialTypeBinding_PlayerController::ClientStopForceFeedback_SendCommand);
	RPCToSenderMap.Emplace("ClientStopCameraShake", &USpatialTypeBinding_PlayerController::ClientStopCameraShake_SendCommand);
	RPCToSenderMap.Emplace("ClientStopCameraAnim", &USpatialTypeBinding_PlayerController::ClientStopCameraAnim_SendCommand);
	RPCToSenderMap.Emplace("ClientStartOnlineSession", &USpatialTypeBinding_PlayerController::ClientStartOnlineSession_SendCommand);
	RPCToSenderMap.Emplace("ClientSpawnCameraLensEffect", &USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_SendCommand);
	RPCToSenderMap.Emplace("ClientSetViewTarget", &USpatialTypeBinding_PlayerController::ClientSetViewTarget_SendCommand);
	RPCToSenderMap.Emplace("ClientSetSpectatorWaiting", &USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_SendCommand);
	RPCToSenderMap.Emplace("ClientSetHUD", &USpatialTypeBinding_PlayerController::ClientSetHUD_SendCommand);
	RPCToSenderMap.Emplace("ClientSetForceMipLevelsToBeResident", &USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCinematicMode", &USpatialTypeBinding_PlayerController::ClientSetCinematicMode_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCameraMode", &USpatialTypeBinding_PlayerController::ClientSetCameraMode_SendCommand);
	RPCToSenderMap.Emplace("ClientSetCameraFade", &USpatialTypeBinding_PlayerController::ClientSetCameraFade_SendCommand);
	RPCToSenderMap.Emplace("ClientSetBlockOnAsyncLoading", &USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_SendCommand);
	RPCToSenderMap.Emplace("ClientReturnToMainMenuWithTextReason", &USpatialTypeBinding_PlayerController::ClientReturnToMainMenuWithTextReason_SendCommand);
	RPCToSenderMap.Emplace("ClientReturnToMainMenu", &USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_SendCommand);
	RPCToSenderMap.Emplace("ClientRetryClientRestart", &USpatialTypeBinding_PlayerController::ClientRetryClientRestart_SendCommand);
	RPCToSenderMap.Emplace("ClientRestart", &USpatialTypeBinding_PlayerController::ClientRestart_SendCommand);
	RPCToSenderMap.Emplace("ClientReset", &USpatialTypeBinding_PlayerController::ClientReset_SendCommand);
	RPCToSenderMap.Emplace("ClientRepObjRef", &USpatialTypeBinding_PlayerController::ClientRepObjRef_SendCommand);
	RPCToSenderMap.Emplace("ClientReceiveLocalizedMessage", &USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientPrestreamTextures", &USpatialTypeBinding_PlayerController::ClientPrestreamTextures_SendCommand);
	RPCToSenderMap.Emplace("ClientPrepareMapChange", &USpatialTypeBinding_PlayerController::ClientPrepareMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientPlaySoundAtLocation", &USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_SendCommand);
	RPCToSenderMap.Emplace("ClientPlaySound", &USpatialTypeBinding_PlayerController::ClientPlaySound_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayForceFeedback", &USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayCameraShake", &USpatialTypeBinding_PlayerController::ClientPlayCameraShake_SendCommand);
	RPCToSenderMap.Emplace("ClientPlayCameraAnim", &USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_SendCommand);
	RPCToSenderMap.Emplace("ClientMutePlayer", &USpatialTypeBinding_PlayerController::ClientMutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ClientMessage", &USpatialTypeBinding_PlayerController::ClientMessage_SendCommand);
	RPCToSenderMap.Emplace("ClientIgnoreMoveInput", &USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_SendCommand);
	RPCToSenderMap.Emplace("ClientIgnoreLookInput", &USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_SendCommand);
	RPCToSenderMap.Emplace("ClientGotoState", &USpatialTypeBinding_PlayerController::ClientGotoState_SendCommand);
	RPCToSenderMap.Emplace("ClientGameEnded", &USpatialTypeBinding_PlayerController::ClientGameEnded_SendCommand);
	RPCToSenderMap.Emplace("ClientForceGarbageCollection", &USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_SendCommand);
	RPCToSenderMap.Emplace("ClientFlushLevelStreaming", &USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_SendCommand);
	RPCToSenderMap.Emplace("ClientEndOnlineSession", &USpatialTypeBinding_PlayerController::ClientEndOnlineSession_SendCommand);
	RPCToSenderMap.Emplace("ClientEnableNetworkVoice", &USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_SendCommand);
	RPCToSenderMap.Emplace("ClientCommitMapChange", &USpatialTypeBinding_PlayerController::ClientCommitMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientClearCameraLensEffects", &USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_SendCommand);
	RPCToSenderMap.Emplace("ClientCapBandwidth", &USpatialTypeBinding_PlayerController::ClientCapBandwidth_SendCommand);
	RPCToSenderMap.Emplace("ClientCancelPendingMapChange", &USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_SendCommand);
	RPCToSenderMap.Emplace("ClientAddTextureStreamingLoc", &USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_SendCommand);
	RPCToSenderMap.Emplace("ClientSetRotation", &USpatialTypeBinding_PlayerController::ClientSetRotation_SendCommand);
	RPCToSenderMap.Emplace("ClientSetLocation", &USpatialTypeBinding_PlayerController::ClientSetLocation_SendCommand);
	RPCToSenderMap.Emplace("ServerViewSelf", &USpatialTypeBinding_PlayerController::ServerViewSelf_SendCommand);
	RPCToSenderMap.Emplace("ServerViewPrevPlayer", &USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerViewNextPlayer", &USpatialTypeBinding_PlayerController::ServerViewNextPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerVerifyViewTarget", &USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateMultipleLevelsVisibility", &USpatialTypeBinding_PlayerController::ServerUpdateMultipleLevelsVisibility_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateLevelVisibility", &USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_SendCommand);
	RPCToSenderMap.Emplace("ServerUpdateCamera", &USpatialTypeBinding_PlayerController::ServerUpdateCamera_SendCommand);
	RPCToSenderMap.Emplace("ServerUnmutePlayer", &USpatialTypeBinding_PlayerController::ServerUnmutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerToggleAILogging", &USpatialTypeBinding_PlayerController::ServerToggleAILogging_SendCommand);
	RPCToSenderMap.Emplace("ServerShortTimeout", &USpatialTypeBinding_PlayerController::ServerShortTimeout_SendCommand);
	RPCToSenderMap.Emplace("ServerSetSpectatorWaiting", &USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_SendCommand);
	RPCToSenderMap.Emplace("ServerSetSpectatorLocation", &USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_SendCommand);
	RPCToSenderMap.Emplace("ServerRestartPlayer", &USpatialTypeBinding_PlayerController::ServerRestartPlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerPause", &USpatialTypeBinding_PlayerController::ServerPause_SendCommand);
	RPCToSenderMap.Emplace("ServerNotifyLoadedWorld", &USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_SendCommand);
	RPCToSenderMap.Emplace("ServerMutePlayer", &USpatialTypeBinding_PlayerController::ServerMutePlayer_SendCommand);
	RPCToSenderMap.Emplace("ServerCheckClientPossessionReliable", &USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_SendCommand);
	RPCToSenderMap.Emplace("ServerCheckClientPossession", &USpatialTypeBinding_PlayerController::ServerCheckClientPossession_SendCommand);
	RPCToSenderMap.Emplace("ServerChangeName", &USpatialTypeBinding_PlayerController::ServerChangeName_SendCommand);
	RPCToSenderMap.Emplace("ServerCamera", &USpatialTypeBinding_PlayerController::ServerCamera_SendCommand);
	RPCToSenderMap.Emplace("ServerAcknowledgePossession", &USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_SendCommand);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("PlayerController"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, COND_SimulatedOrPhysics, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, COND_Custom, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"PlayerState"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"Pawn"}, COND_None, REPNOTIFY_Always, 0));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"TargetViewRotation"}, COND_OwnerOnly, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"SpawnLocation"}, COND_OwnerOnly, REPNOTIFY_OnChanged, 0));

	// Populate MigratableHandleToPropertyMap.
	MigratableHandleToPropertyMap.Add(1, FMigratableHandleData(Class, {"AcknowledgedPawn"}));
}

void USpatialTypeBinding_PlayerController::BindToView()
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerMigratableData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealPlayerControllerMigratableData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealPlayerControllerMigratableData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_Migratable(ActorChannel, Op.Update);
		}));
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealPlayerControllerClientRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_ClientRPCs(Op.EntityId, Op.Update);
	}));
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::UnrealPlayerControllerServerRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_ServerRPCs(Op.EntityId, Op.Update);
	}));
}

void USpatialTypeBinding_PlayerController::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_PlayerController::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.
	improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Data SingleClientData;
	improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Data MultiClientData;
	improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::UnrealPlayerControllerMigratableData::Data MigratableData;
	improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);
	SingleClientUpdate.ApplyTo(SingleClientData);
	MultiClientUpdate.ApplyTo(MultiClientData);
	MigratableDataUpdate.ApplyTo(MigratableData);

	// Create entity.
	std::string ClientWorkerIdString = TCHAR_TO_UTF8(*ClientWorkerId);

	improbable::WorkerAttributeSet WorkerAttribute{{worker::List<std::string>{"UnrealWorker"}}};
	improbable::WorkerAttributeSet ClientAttribute{{worker::List<std::string>{"UnrealClient"}}};
	improbable::WorkerAttributeSet OwningClientAttribute{{"workerId:" + ClientWorkerIdString}};

	improbable::WorkerRequirementSet WorkersOnly{{WorkerAttribute}};
	improbable::WorkerRequirementSet ClientsOnly{{ClientAttribute}};
	improbable::WorkerRequirementSet OwningClientOnly{{OwningClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrClient{{WorkerAttribute, ClientAttribute}};
	improbable::WorkerRequirementSet AnyUnrealWorkerOrOwningClient{{WorkerAttribute, OwningClientAttribute}};

	// Set up unreal metadata.
	improbable::unreal::UnrealMetadata::Data UnrealMetadata;
	if (Channel->Actor->IsFullNameStableForNetworking())
	{
		UnrealMetadata.set_static_path({std::string{TCHAR_TO_UTF8(*Channel->Actor->GetPathName(Channel->Actor->GetWorld()))}});
	}
	if (!ClientWorkerIdString.empty())
	{
		UnrealMetadata.set_owner_worker_id({ClientWorkerIdString});
	}

	uint32 CurrentOffset = 1;
	worker::Map<std::string, std::uint32_t> SubobjectNameToOffset;
	ForEachObjectWithOuter(Channel->Actor, [&UnrealMetadata, &CurrentOffset, &SubobjectNameToOffset](UObject* Object)
	{
		// Objects can only be allocated NetGUIDs if this is true.
		if (Object->IsSupportedForNetworking() && !Object->IsPendingKill() && !Object->IsEditorOnly())
		{
			SubobjectNameToOffset.emplace(TCHAR_TO_UTF8(*(Object->GetName())), CurrentOffset);
			CurrentOffset++;
		}
	});
	UnrealMetadata.set_subobject_name_to_offset(SubobjectNameToOffset);

	// Build entity.
	const improbable::Coordinates SpatialPosition = SpatialConstants::LocationToSpatialOSCoordinates(Position);
	return improbable::unreal::FEntityBuilder::Begin()
		.AddPositionComponent(improbable::Position::Data{SpatialPosition}, WorkersOnly)
		.AddMetadataComponent(improbable::Metadata::Data{TCHAR_TO_UTF8(*Metadata)})
		.SetPersistence(true)
		.SetReadAcl(AnyUnrealWorkerOrOwningClient)
		.AddComponent<improbable::unreal::UnrealMetadata>(UnrealMetadata, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData>(SingleClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData>(MultiClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealPlayerControllerMigratableData>(MigratableData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Data{}, OwningClientOnly)
		.Build();
}

void USpatialTypeBinding_PlayerController::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bMigratableDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerMigratableData>(EntityId.ToSpatialEntityId(), MigratableDataUpdate);
	}
}

void USpatialTypeBinding_PlayerController::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
{
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	if (SenderFuncIterator == nullptr)
	{
		UE_LOG(LogSpatialOSInterop, Error, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
		return;
	}
	checkf(*SenderFuncIterator, TEXT("Sender for %s has been registered as null."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), Parameters, TargetObject);
}

void USpatialTypeBinding_PlayerController::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UUnrealPlayerControllerSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
	}
	auto* MultiClientAddOp = Cast<UUnrealPlayerControllerMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
	}
	auto* MigratableDataAddOp = Cast<UUnrealPlayerControllerMigratableDataAddComponentOp>(AddComponentOp);
	if (MigratableDataAddOp)
	{
		auto Update = improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update::FromInitialData(*MigratableDataAddOp->Data.data());
		ReceiveUpdate_Migratable(Channel, Update);
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_PlayerController::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::UnrealPlayerControllerMigratableData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_PlayerController::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& MigratableDataUpdate,
	bool& bMigratableDataUpdateChanged) const
{
	const FRepHandlePropertyMap& RepPropertyMap = GetRepHandlePropertyMap();
	const FMigratableHandlePropertyMap& MigPropertyMap = GetMigratableHandlePropertyMap();
	if (Changes.RepChanged.Num() > 0)
	{
		// Populate the replicated data component updates from the replicated property changelist.
		FChangelistIterator ChangelistIterator(Changes.RepChanged, 0);
		FRepHandleIterator HandleIterator(ChangelistIterator, Changes.RepCmds, Changes.RepBaseHandleToCmdIndex, 0, 1, 0, Changes.RepCmds.Num() - 1);
		while (HandleIterator.NextHandle())
		{
			const FRepLayoutCmd& Cmd = Changes.RepCmds[HandleIterator.CmdIndex];
			const FRepHandleData& PropertyMapData = RepPropertyMap[HandleIterator.Handle];
			const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData) + HandleIterator.ArrayOffset;
			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*Channel->Actor->GetName(),
				Channel->GetEntityId().ToSpatialEntityId(),
				*Cmd.Property->GetName(),
				HandleIterator.Handle);
			switch (GetGroupFromCondition(PropertyMapData.Condition))
			{
			case GROUP_SingleClient:
				ServerSendUpdate_SingleClient(Data, HandleIterator.Handle, Cmd.Property, Channel, SingleClientUpdate);
				bSingleClientUpdateChanged = true;
				break;
			case GROUP_MultiClient:
				ServerSendUpdate_MultiClient(Data, HandleIterator.Handle, Cmd.Property, Channel, MultiClientUpdate);
				bMultiClientUpdateChanged = true;
				break;
			}
			if (Cmd.Type == REPCMD_DynamicArray)
			{
				if (!HandleIterator.JumpOverArray())
				{
					break;
				}
			}
		}
	}

	// Populate the migrated data component update from the migrated property changelist.
	for (uint16 ChangedHandle : Changes.MigChanged)
	{
		const FMigratableHandleData& PropertyMapData = MigPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending migratable property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Migratable(Data, ChangedHandle, PropertyMapData.Property, Channel, MigratableDataUpdate);
		bMigratableDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_PlayerController::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 18: // field_targetviewrotation
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			OutUpdate.set_field_targetviewrotation(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 19: // field_spawnlocation
		{
			const FVector& Value = *(reinterpret_cast<FVector const*>(Data));

			OutUpdate.set_field_spawnlocation(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_PlayerController::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bhidden(Value);
			break;
		}
		case 2: // field_breplicatemovement
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicatemovement(Value);
			break;
		}
		case 3: // field_btearoff
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_btearoff(Value);
			break;
		}
		case 4: // field_bcanbedamaged
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bcanbedamaged(Value);
			break;
		}
		case 5: // field_remoterole
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_remoterole(uint32_t(Value));
			break;
		}
		case 6: // field_replicatedmovement
		{
			const FRepMovement& Value = *(reinterpret_cast<FRepMovement const*>(Data));

			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				bool Success;
				(const_cast<FRepMovement&>(Value)).NetSerialize(ValueDataWriter, PackageMap, Success);
				OutUpdate.set_field_replicatedmovement(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			break;
		}
		case 7: // field_attachmentreplication_attachparent
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachparent(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication_attachparent(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 8: // field_attachmentreplication_locationoffset
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			OutUpdate.set_field_attachmentreplication_locationoffset(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 9: // field_attachmentreplication_relativescale3d
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			OutUpdate.set_field_attachmentreplication_relativescale3d(improbable::Vector3f(Value.X, Value.Y, Value.Z));
			break;
		}
		case 10: // field_attachmentreplication_rotationoffset
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			OutUpdate.set_field_attachmentreplication_rotationoffset(improbable::unreal::UnrealFRotator(Value.Yaw, Value.Pitch, Value.Roll));
			break;
		}
		case 11: // field_attachmentreplication_attachsocket
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_attachmentreplication_attachsocket(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication_attachcomponent
		{
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication_attachcomponent(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication_attachcomponent(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 13: // field_owner
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 13);
				}
				else
				{
					OutUpdate.set_field_owner(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_owner(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 14: // field_role
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_role(uint32_t(Value));
			break;
		}
		case 15: // field_instigator
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_instigator(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 16: // field_playerstate
		{
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 16);
				}
				else
				{
					OutUpdate.set_field_playerstate(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_playerstate(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 17: // field_pawn
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 17);
				}
				else
				{
					OutUpdate.set_field_pawn(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_pawn(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_PlayerController::ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_acknowledgedpawn
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					Interop->QueueOutgoingObjectMigUpdate_Internal(Value, Channel, 1);
				}
				else
				{
					OutUpdate.set_field_acknowledgedpawn(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_acknowledgedpawn(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown migration property handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_PlayerController::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerSingleClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::UnrealPlayerControllerClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_targetviewrotation().empty())
	{
		// field_targetviewrotation
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			{
				auto& Rotator = (*Update.field_targetviewrotation().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_spawnlocation().empty())
	{
		// field_spawnlocation
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector Value = *(reinterpret_cast<FVector const*>(PropertyData));

			{
				auto& Vector = (*Update.field_spawnlocation().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	Interop->PostReceiveSpatialUpdate(ActorChannel, RepNotifies.Array());
}

void USpatialTypeBinding_PlayerController::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMultiClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::UnrealPlayerControllerClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_bhidden().empty())
	{
		// field_bhidden
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bhidden().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_breplicatemovement().empty())
	{
		// field_breplicatemovement
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicatemovement().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_btearoff().empty())
	{
		// field_btearoff
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_btearoff().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bcanbedamaged().empty())
	{
		// field_bcanbedamaged
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bcanbedamaged().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_remoterole().empty())
	{
		// field_remoterole
		uint16 Handle = 5;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 14;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_remoterole().data())));

			// Downgrade role from AutonomousProxy to SimulatedProxy if we aren't authoritative over
			// the server RPCs component.
			if (!bIsServer && Value == ROLE_AutonomousProxy && !bAutonomousProxy)
			{
				Value = ROLE_SimulatedProxy;
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovement().empty())
	{
		// field_replicatedmovement
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRepMovement Value = *(reinterpret_cast<FRepMovement const*>(PropertyData));

			{
				auto& ValueDataStr = (*Update.field_replicatedmovement().data());
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				bool bSuccess;
				Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachparent().empty())
	{
		// field_attachmentreplication_attachparent
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication_attachparent().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<AActor>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_attachmentreplication_locationoffset().empty())
	{
		// field_attachmentreplication_locationoffset
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			{
				auto& Vector = (*Update.field_attachmentreplication_locationoffset().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_relativescale3d().empty())
	{
		// field_attachmentreplication_relativescale3d
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			{
				auto& Vector = (*Update.field_attachmentreplication_relativescale3d().data());
				Value.X = Vector.x();
				Value.Y = Vector.y();
				Value.Z = Vector.z();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_rotationoffset().empty())
	{
		// field_attachmentreplication_rotationoffset
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			{
				auto& Rotator = (*Update.field_attachmentreplication_rotationoffset().data());
				Value.Yaw = Rotator.yaw();
				Value.Pitch = Rotator.pitch();
				Value.Roll = Rotator.roll();
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachsocket().empty())
	{
		// field_attachmentreplication_attachsocket
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_attachmentreplication_attachsocket().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication_attachcomponent().empty())
	{
		// field_attachmentreplication_attachcomponent
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication_attachcomponent().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<USceneComponent>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_owner().empty())
	{
		// field_owner
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_owner().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<AActor>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_role().empty())
	{
		// field_role
		uint16 Handle = 14;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			// On the client, we need to swap Role/RemoteRole.
			if (!bIsServer)
			{
				Handle = 5;
				RepData = &HandleToPropertyMap[Handle];
			}

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_role().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_instigator().empty())
	{
		// field_instigator
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_instigator().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<APawn>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_playerstate().empty())
	{
		// field_playerstate
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APlayerState* Value = *(reinterpret_cast<APlayerState* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_playerstate().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<APlayerState>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_pawn().empty())
	{
		// field_pawn
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			{
				improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_pawn().data());
				check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
				if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
				{
					Value = nullptr;
				}
				else
				{
					FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
					if (NetGUID.IsValid())
					{
						UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
						checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
						Value = Cast<APawn>(Object_Raw);
						checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					}
					else
					{
						UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
							*Interop->GetSpatialOS()->GetWorkerId(),
							*ObjectRefToString(ObjectRef),
							*ActorChannel->Actor->GetName(),
							ActorChannel->GetEntityId().ToSpatialEntityId(),
							*RepData->Property->GetName(),
							Handle);
						bWriteObjectProperty = false;
						Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, RepData);
					}
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	Interop->PostReceiveSpatialUpdate(ActorChannel, RepNotifies.Array());
}

void USpatialTypeBinding_PlayerController::ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealPlayerControllerMigratableData::Update& Update) const
{
	const FMigratableHandlePropertyMap& HandleToPropertyMap = GetMigratableHandlePropertyMap();

	if (!Update.field_acknowledgedpawn().empty())
	{
		// field_acknowledgedpawn
		uint16 Handle = 1;
		const FMigratableHandleData* MigratableData = &HandleToPropertyMap[Handle];
		bool bWriteObjectProperty = true;
		uint8* PropertyData = MigratableData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
		APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

		{
			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_acknowledgedpawn().data());
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Value = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Value = Cast<APawn>(Object_Raw);
					checkf(Value, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*MigratableData->Property->GetName(),
						Handle);
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectMigUpdate_Internal(ObjectRef, ActorChannel, MigratableData);
				}
			}
		}

		if (bWriteObjectProperty)
		{
			ApplyIncomingMigratablePropertyUpdate(*MigratableData, ActorChannel->Actor, static_cast<const void*>(&Value));

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received migratable property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*MigratableData->Property->GetName(),
				Handle);
		}
	}
}

void USpatialTypeBinding_PlayerController::ReceiveUpdate_ClientRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update& Update)
{
	for (auto& event : Update.playercontrolleronserverstartedvisuallogger())
	{
		OnServerStartedVisualLogger_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientwaskicked())
	{
		ClientWasKicked_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientvoicehandshakecomplete())
	{
		ClientVoiceHandshakeComplete_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientupdatemultiplelevelsstreamingstatus())
	{
		ClientUpdateMultipleLevelsStreamingStatus_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientupdatelevelstreamingstatus())
	{
		ClientUpdateLevelStreamingStatus_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientunmuteplayer())
	{
		ClientUnmutePlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclienttravelinternal())
	{
		ClientTravelInternal_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientteammessage())
	{
		ClientTeamMessage_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientstopforcefeedback())
	{
		ClientStopForceFeedback_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientstopcamerashake())
	{
		ClientStopCameraShake_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientstopcameraanim())
	{
		ClientStopCameraAnim_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientstartonlinesession())
	{
		ClientStartOnlineSession_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientspawncameralenseffect())
	{
		ClientSpawnCameraLensEffect_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetviewtarget())
	{
		ClientSetViewTarget_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetspectatorwaiting())
	{
		ClientSetSpectatorWaiting_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsethud())
	{
		ClientSetHUD_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetforcemiplevelstoberesident())
	{
		ClientSetForceMipLevelsToBeResident_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetcinematicmode())
	{
		ClientSetCinematicMode_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetcameramode())
	{
		ClientSetCameraMode_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetcamerafade())
	{
		ClientSetCameraFade_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetblockonasyncloading())
	{
		ClientSetBlockOnAsyncLoading_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientreturntomainmenuwithtextreason())
	{
		ClientReturnToMainMenuWithTextReason_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientreturntomainmenu())
	{
		ClientReturnToMainMenu_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientretryclientrestart())
	{
		ClientRetryClientRestart_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientrestart())
	{
		ClientRestart_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientreset())
	{
		ClientReset_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientrepobjref())
	{
		ClientRepObjRef_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientreceivelocalizedmessage())
	{
		ClientReceiveLocalizedMessage_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientprestreamtextures())
	{
		ClientPrestreamTextures_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientpreparemapchange())
	{
		ClientPrepareMapChange_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientplaysoundatlocation())
	{
		ClientPlaySoundAtLocation_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientplaysound())
	{
		ClientPlaySound_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientplayforcefeedback())
	{
		ClientPlayForceFeedback_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientplaycamerashake())
	{
		ClientPlayCameraShake_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientplaycameraanim())
	{
		ClientPlayCameraAnim_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientmuteplayer())
	{
		ClientMutePlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientmessage())
	{
		ClientMessage_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientignoremoveinput())
	{
		ClientIgnoreMoveInput_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientignorelookinput())
	{
		ClientIgnoreLookInput_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientgotostate())
	{
		ClientGotoState_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientgameended())
	{
		ClientGameEnded_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientforcegarbagecollection())
	{
		ClientForceGarbageCollection_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientflushlevelstreaming())
	{
		ClientFlushLevelStreaming_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientendonlinesession())
	{
		ClientEndOnlineSession_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientenablenetworkvoice())
	{
		ClientEnableNetworkVoice_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientcommitmapchange())
	{
		ClientCommitMapChange_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientclearcameralenseffects())
	{
		ClientClearCameraLensEffects_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientcapbandwidth())
	{
		ClientCapBandwidth_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientcancelpendingmapchange())
	{
		ClientCancelPendingMapChange_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientaddtexturestreamingloc())
	{
		ClientAddTextureStreamingLoc_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetrotation())
	{
		ClientSetRotation_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerclientsetlocation())
	{
		ClientSetLocation_ReceiveRPCEvent(EntityId, event);
	}


}

void USpatialTypeBinding_PlayerController::ReceiveUpdate_ServerRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update& Update)
{
	for (auto& event : Update.playercontrollerserverviewself())
	{
		ServerViewSelf_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverviewprevplayer())
	{
		ServerViewPrevPlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverviewnextplayer())
	{
		ServerViewNextPlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserververifyviewtarget())
	{
		ServerVerifyViewTarget_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverupdatemultiplelevelsvisibility())
	{
		ServerUpdateMultipleLevelsVisibility_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverupdatelevelvisibility())
	{
		ServerUpdateLevelVisibility_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverupdatecamera())
	{
		ServerUpdateCamera_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverunmuteplayer())
	{
		ServerUnmutePlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservertoggleailogging())
	{
		ServerToggleAILogging_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservershorttimeout())
	{
		ServerShortTimeout_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserversetspectatorwaiting())
	{
		ServerSetSpectatorWaiting_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserversetspectatorlocation())
	{
		ServerSetSpectatorLocation_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverrestartplayer())
	{
		ServerRestartPlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverpause())
	{
		ServerPause_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservernotifyloadedworld())
	{
		ServerNotifyLoadedWorld_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservermuteplayer())
	{
		ServerMutePlayer_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservercheckclientpossessionreliable())
	{
		ServerCheckClientPossessionReliable_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservercheckclientpossession())
	{
		ServerCheckClientPossession_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserverchangename())
	{
		ServerChangeName_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerservercamera())
	{
		ServerCamera_ReceiveRPCEvent(EntityId, event);
	}


	for (auto& event : Update.playercontrollerserveracknowledgepossession())
	{
		ServerAcknowledgePossession_ReceiveRPCEvent(EntityId, event);
	}


}

void USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventOnServerStartedVisualLogger_Parms StructuredParams = *static_cast<PlayerController_eventOnServerStartedVisualLogger_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC OnServerStartedVisualLogger queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealOnServerStartedVisualLoggerRequest EventData;
		EventData.set_field_bislogging(StructuredParams.bIsLogging);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: OnServerStartedVisualLogger, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrolleronserverstartedvisuallogger(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientWasKicked_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientWasKicked_Parms StructuredParams = *static_cast<PlayerController_eventClientWasKicked_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientWasKicked queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientWasKickedRequest EventData;
		// UNSUPPORTED UTextProperty (unhandled) EventData.set_field_kickreason(StructuredParams.KickReason)

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientWasKicked, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientwaskicked(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientVoiceHandshakeComplete queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientVoiceHandshakeCompleteRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientVoiceHandshakeComplete, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientvoicehandshakecomplete(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientUpdateMultipleLevelsStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms StructuredParams = *static_cast<PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUpdateMultipleLevelsStreamingStatus queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUpdateMultipleLevelsStreamingStatusRequest EventData;
		{
			::worker::List<std::string> List;
			for(int i = 0; i < StructuredParams.LevelStatuses.Num(); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FUpdateLevelStreamingLevelStatus::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FUpdateLevelStreamingLevelStatus*>(&StructuredParams.LevelStatuses[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			EventData.set_field_levelstatuses(List);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUpdateMultipleLevelsStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientupdatemultiplelevelsstreamingstatus(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUpdateLevelStreamingStatus_Parms StructuredParams = *static_cast<PlayerController_eventClientUpdateLevelStreamingStatus_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUpdateLevelStreamingStatus queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUpdateLevelStreamingStatusRequest EventData;
		EventData.set_field_packagename(TCHAR_TO_UTF8(*StructuredParams.PackageName.ToString()));
		EventData.set_field_bnewshouldbeloaded(StructuredParams.bNewShouldBeLoaded);
		EventData.set_field_bnewshouldbevisible(StructuredParams.bNewShouldBeVisible);
		EventData.set_field_bnewshouldblockonload(StructuredParams.bNewShouldBlockOnLoad);
		EventData.set_field_lodindex(int32_t(StructuredParams.LODIndex));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUpdateLevelStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientupdatelevelstreamingstatus(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientUnmutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventClientUnmutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientUnmutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientUnmutePlayerRequest EventData;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			EventData.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientunmuteplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientTravelInternal_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientTravelInternal_Parms StructuredParams = *static_cast<PlayerController_eventClientTravelInternal_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTravelInternal queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientTravelInternalRequest EventData;
		EventData.set_field_url(TCHAR_TO_UTF8(*StructuredParams.URL));
		EventData.set_field_traveltype(uint32_t(StructuredParams.TravelType));
		EventData.set_field_bseamless(StructuredParams.bSeamless);
		EventData.set_field_mappackageguid_a(int32_t(StructuredParams.MapPackageGuid.A));
		EventData.set_field_mappackageguid_b(int32_t(StructuredParams.MapPackageGuid.B));
		EventData.set_field_mappackageguid_c(int32_t(StructuredParams.MapPackageGuid.C));
		EventData.set_field_mappackageguid_d(int32_t(StructuredParams.MapPackageGuid.D));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientTravelInternal, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclienttravelinternal(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientTeamMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientTeamMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientTeamMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTeamMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientTeamMessageRequest EventData;
		if (StructuredParams.SenderPlayerState != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.SenderPlayerState);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientTeamMessage queued. StructuredParams.SenderPlayerState is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.SenderPlayerState};
			}
			else
			{
				EventData.set_field_senderplayerstate(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_senderplayerstate(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));
		EventData.set_field_type(TCHAR_TO_UTF8(*StructuredParams.Type.ToString()));
		EventData.set_field_msglifetime(StructuredParams.MsgLifeTime);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientTeamMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientteammessage(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientStopForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopForceFeedback_Parms StructuredParams = *static_cast<PlayerController_eventClientStopForceFeedback_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopForceFeedback queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopForceFeedbackRequest EventData;
		if (StructuredParams.ForceFeedbackEffect != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForceFeedbackEffect);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopForceFeedback queued. StructuredParams.ForceFeedbackEffect is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForceFeedbackEffect};
			}
			else
			{
				EventData.set_field_forcefeedbackeffect(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_forcefeedbackeffect(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_tag(TCHAR_TO_UTF8(*StructuredParams.Tag.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientstopforcefeedback(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopCameraShake_Parms StructuredParams = *static_cast<PlayerController_eventClientStopCameraShake_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraShake queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopCameraShakeRequest EventData;
		EventData.set_field_shake(PackageMap->GetHashFromStaticClass(StructuredParams.Shake));
		EventData.set_field_bimmediately(StructuredParams.bImmediately);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientstopcamerashake(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientStopCameraAnim_Parms StructuredParams = *static_cast<PlayerController_eventClientStopCameraAnim_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraAnim queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStopCameraAnimRequest EventData;
		if (StructuredParams.AnimToStop != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.AnimToStop);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStopCameraAnim queued. StructuredParams.AnimToStop is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.AnimToStop};
			}
			else
			{
				EventData.set_field_animtostop(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_animtostop(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStopCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientstopcameraanim(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientStartOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientStartOnlineSession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientStartOnlineSessionRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientStartOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientstartonlinesession(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSpawnCameraLensEffect_Parms StructuredParams = *static_cast<PlayerController_eventClientSpawnCameraLensEffect_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSpawnCameraLensEffect queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSpawnCameraLensEffectRequest EventData;
		EventData.set_field_lenseffectemitterclass(PackageMap->GetHashFromStaticClass(StructuredParams.LensEffectEmitterClass));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSpawnCameraLensEffect, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientspawncameralenseffect(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientSetViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetViewTarget_Parms StructuredParams = *static_cast<PlayerController_eventClientSetViewTarget_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetViewTarget queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetViewTargetRequest EventData;
		if (StructuredParams.A != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.A);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetViewTarget queued. StructuredParams.A is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.A};
			}
			else
			{
				EventData.set_field_a(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_a(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_transitionparams_blendtime(StructuredParams.TransitionParams.BlendTime);
		EventData.set_field_transitionparams_blendfunction(uint32_t(StructuredParams.TransitionParams.BlendFunction));
		EventData.set_field_transitionparams_blendexp(StructuredParams.TransitionParams.BlendExp);
		EventData.set_field_transitionparams_blockoutgoing(StructuredParams.TransitionParams.bLockOutgoing);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetviewtarget(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetSpectatorWaiting_Parms StructuredParams = *static_cast<PlayerController_eventClientSetSpectatorWaiting_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetSpectatorWaiting queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetSpectatorWaitingRequest EventData;
		EventData.set_field_bwaiting(StructuredParams.bWaiting);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetspectatorwaiting(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetHUD_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetHUD_Parms StructuredParams = *static_cast<PlayerController_eventClientSetHUD_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetHUD queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetHUDRequest EventData;
		EventData.set_field_newhudclass(PackageMap->GetHashFromStaticClass(StructuredParams.NewHUDClass));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetHUD, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsethud(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetForceMipLevelsToBeResident_Parms StructuredParams = *static_cast<PlayerController_eventClientSetForceMipLevelsToBeResident_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetForceMipLevelsToBeResident queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetForceMipLevelsToBeResidentRequest EventData;
		if (StructuredParams.Material != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Material);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetForceMipLevelsToBeResident queued. StructuredParams.Material is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Material};
			}
			else
			{
				EventData.set_field_material(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_material(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_forceduration(StructuredParams.ForceDuration);
		EventData.set_field_cinematictexturegroups(int32_t(StructuredParams.CinematicTextureGroups));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetForceMipLevelsToBeResident, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetforcemiplevelstoberesident(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetCinematicMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCinematicMode_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCinematicMode_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCinematicMode queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCinematicModeRequest EventData;
		EventData.set_field_bincinematicmode(StructuredParams.bInCinematicMode);
		EventData.set_field_baffectsmovement(StructuredParams.bAffectsMovement);
		EventData.set_field_baffectsturning(StructuredParams.bAffectsTurning);
		EventData.set_field_baffectshud(StructuredParams.bAffectsHUD);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCinematicMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetcinematicmode(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraMode_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCameraMode_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCameraMode_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCameraMode queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCameraModeRequest EventData;
		EventData.set_field_newcammode(TCHAR_TO_UTF8(*StructuredParams.NewCamMode.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCameraMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetcameramode(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraFade_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientSetCameraFade_Parms StructuredParams = *static_cast<PlayerController_eventClientSetCameraFade_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetCameraFade queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetCameraFadeRequest EventData;
		EventData.set_field_benablefading(StructuredParams.bEnableFading);
		EventData.set_field_fadecolor_b(uint32_t(StructuredParams.FadeColor.B));
		EventData.set_field_fadecolor_g(uint32_t(StructuredParams.FadeColor.G));
		EventData.set_field_fadecolor_r(uint32_t(StructuredParams.FadeColor.R));
		EventData.set_field_fadecolor_a(uint32_t(StructuredParams.FadeColor.A));
		EventData.set_field_fadealpha_x(StructuredParams.FadeAlpha.X);
		EventData.set_field_fadealpha_y(StructuredParams.FadeAlpha.Y);
		EventData.set_field_fadetime(StructuredParams.FadeTime);
		EventData.set_field_bfadeaudio(StructuredParams.bFadeAudio);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetCameraFade, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetcamerafade(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetBlockOnAsyncLoading queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetBlockOnAsyncLoadingRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetBlockOnAsyncLoading, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetblockonasyncloading(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenuWithTextReason_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReturnToMainMenuWithTextReason_Parms StructuredParams = *static_cast<PlayerController_eventClientReturnToMainMenuWithTextReason_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReturnToMainMenuWithTextReason queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReturnToMainMenuWithTextReasonRequest EventData;
		// UNSUPPORTED UTextProperty (unhandled) EventData.set_field_returnreason(StructuredParams.ReturnReason)

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReturnToMainMenuWithTextReason, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientreturntomainmenuwithtextreason(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReturnToMainMenu_Parms StructuredParams = *static_cast<PlayerController_eventClientReturnToMainMenu_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReturnToMainMenu queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReturnToMainMenuRequest EventData;
		EventData.set_field_returnreason(TCHAR_TO_UTF8(*StructuredParams.ReturnReason));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReturnToMainMenu, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientreturntomainmenu(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientRetryClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRetryClientRestart_Parms StructuredParams = *static_cast<PlayerController_eventClientRetryClientRestart_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRetryClientRestart queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRetryClientRestartRequest EventData;
		if (StructuredParams.NewPawn != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewPawn);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRetryClientRestart queued. StructuredParams.NewPawn is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.NewPawn};
			}
			else
			{
				EventData.set_field_newpawn(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_newpawn(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRetryClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientretryclientrestart(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientRestart_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRestart_Parms StructuredParams = *static_cast<PlayerController_eventClientRestart_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRestart queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRestartRequest EventData;
		if (StructuredParams.NewPawn != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.NewPawn);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRestart queued. StructuredParams.NewPawn is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.NewPawn};
			}
			else
			{
				EventData.set_field_newpawn(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_newpawn(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientrestart(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientReset_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReset queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientResetRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReset, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientreset(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientRepObjRef_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientRepObjRef_Parms StructuredParams = *static_cast<PlayerController_eventClientRepObjRef_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRepObjRef queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientRepObjRefRequest EventData;
		if (StructuredParams.Object != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Object);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientRepObjRef queued. StructuredParams.Object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Object};
			}
			else
			{
				EventData.set_field_object(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_object(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientRepObjRef, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientrepobjref(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientReceiveLocalizedMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientReceiveLocalizedMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientReceiveLocalizedMessageRequest EventData;
		EventData.set_field_message(PackageMap->GetHashFromStaticClass(StructuredParams.Message));
		EventData.set_field_switch(int32_t(StructuredParams.Switch));
		if (StructuredParams.RelatedPlayerState_1 != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.RelatedPlayerState_1);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.RelatedPlayerState_1 is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.RelatedPlayerState_1};
			}
			else
			{
				EventData.set_field_relatedplayerstate1(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_relatedplayerstate1(SpatialConstants::NULL_OBJECT_REF);
		}
		if (StructuredParams.RelatedPlayerState_2 != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.RelatedPlayerState_2);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.RelatedPlayerState_2 is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.RelatedPlayerState_2};
			}
			else
			{
				EventData.set_field_relatedplayerstate2(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_relatedplayerstate2(SpatialConstants::NULL_OBJECT_REF);
		}
		if (StructuredParams.OptionalObject != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.OptionalObject);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientReceiveLocalizedMessage queued. StructuredParams.OptionalObject is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.OptionalObject};
			}
			else
			{
				EventData.set_field_optionalobject(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_optionalobject(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientReceiveLocalizedMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientreceivelocalizedmessage(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientPrestreamTextures_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPrestreamTextures_Parms StructuredParams = *static_cast<PlayerController_eventClientPrestreamTextures_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrestreamTextures queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPrestreamTexturesRequest EventData;
		if (StructuredParams.ForcedActor != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForcedActor);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrestreamTextures queued. StructuredParams.ForcedActor is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForcedActor};
			}
			else
			{
				EventData.set_field_forcedactor(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_forcedactor(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_forceduration(StructuredParams.ForceDuration);
		EventData.set_field_benablestreaming(StructuredParams.bEnableStreaming);
		EventData.set_field_cinematictexturegroups(int32_t(StructuredParams.CinematicTextureGroups));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPrestreamTextures, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientprestreamtextures(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientPrepareMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPrepareMapChange_Parms StructuredParams = *static_cast<PlayerController_eventClientPrepareMapChange_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPrepareMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPrepareMapChangeRequest EventData;
		EventData.set_field_levelname(TCHAR_TO_UTF8(*StructuredParams.LevelName.ToString()));
		EventData.set_field_bfirst(StructuredParams.bFirst);
		EventData.set_field_blast(StructuredParams.bLast);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPrepareMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientpreparemapchange(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlaySoundAtLocation_Parms StructuredParams = *static_cast<PlayerController_eventClientPlaySoundAtLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySoundAtLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlaySoundAtLocationRequest EventData;
		if (StructuredParams.Sound != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Sound);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySoundAtLocation queued. StructuredParams.Sound is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Sound};
			}
			else
			{
				EventData.set_field_sound(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_sound(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_location(improbable::Vector3f(StructuredParams.Location.X, StructuredParams.Location.Y, StructuredParams.Location.Z));
		EventData.set_field_volumemultiplier(StructuredParams.VolumeMultiplier);
		EventData.set_field_pitchmultiplier(StructuredParams.PitchMultiplier);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlaySoundAtLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientplaysoundatlocation(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientPlaySound_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlaySound_Parms StructuredParams = *static_cast<PlayerController_eventClientPlaySound_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySound queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlaySoundRequest EventData;
		if (StructuredParams.Sound != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.Sound);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlaySound queued. StructuredParams.Sound is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.Sound};
			}
			else
			{
				EventData.set_field_sound(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_sound(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_volumemultiplier(StructuredParams.VolumeMultiplier);
		EventData.set_field_pitchmultiplier(StructuredParams.PitchMultiplier);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlaySound, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientplaysound(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayForceFeedback_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayForceFeedback_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayForceFeedback queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayForceFeedbackRequest EventData;
		if (StructuredParams.ForceFeedbackEffect != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.ForceFeedbackEffect);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayForceFeedback queued. StructuredParams.ForceFeedbackEffect is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.ForceFeedbackEffect};
			}
			else
			{
				EventData.set_field_forcefeedbackeffect(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_forcefeedbackeffect(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_blooping(StructuredParams.bLooping);
		EventData.set_field_bignoretimedilation(StructuredParams.bIgnoreTimeDilation);
		EventData.set_field_tag(TCHAR_TO_UTF8(*StructuredParams.Tag.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientplayforcefeedback(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraShake_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayCameraShake_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayCameraShake_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraShake queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayCameraShakeRequest EventData;
		EventData.set_field_shake(PackageMap->GetHashFromStaticClass(StructuredParams.Shake));
		EventData.set_field_scale(StructuredParams.Scale);
		EventData.set_field_playspace(uint32_t(StructuredParams.PlaySpace));
		EventData.set_field_userplayspacerot(improbable::unreal::UnrealFRotator(StructuredParams.UserPlaySpaceRot.Yaw, StructuredParams.UserPlaySpaceRot.Pitch, StructuredParams.UserPlaySpaceRot.Roll));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientplaycamerashake(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientPlayCameraAnim_Parms StructuredParams = *static_cast<PlayerController_eventClientPlayCameraAnim_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraAnim queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientPlayCameraAnimRequest EventData;
		if (StructuredParams.AnimToPlay != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.AnimToPlay);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientPlayCameraAnim queued. StructuredParams.AnimToPlay is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.AnimToPlay};
			}
			else
			{
				EventData.set_field_animtoplay(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_animtoplay(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_scale(StructuredParams.Scale);
		EventData.set_field_rate(StructuredParams.Rate);
		EventData.set_field_blendintime(StructuredParams.BlendInTime);
		EventData.set_field_blendouttime(StructuredParams.BlendOutTime);
		EventData.set_field_bloop(StructuredParams.bLoop);
		EventData.set_field_brandomstarttime(StructuredParams.bRandomStartTime);
		EventData.set_field_space(uint32_t(StructuredParams.Space));
		EventData.set_field_customplayspace(improbable::unreal::UnrealFRotator(StructuredParams.CustomPlaySpace.Yaw, StructuredParams.CustomPlaySpace.Pitch, StructuredParams.CustomPlaySpace.Roll));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientPlayCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientplaycameraanim(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ClientMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientMutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventClientMutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientMutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientMutePlayerRequest EventData;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			EventData.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientmuteplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientMessage_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientMessage_Parms StructuredParams = *static_cast<PlayerController_eventClientMessage_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientMessage queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientMessageRequest EventData;
		EventData.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));
		EventData.set_field_type(TCHAR_TO_UTF8(*StructuredParams.Type.ToString()));
		EventData.set_field_msglifetime(StructuredParams.MsgLifeTime);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientmessage(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientIgnoreMoveInput_Parms StructuredParams = *static_cast<PlayerController_eventClientIgnoreMoveInput_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientIgnoreMoveInput queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientIgnoreMoveInputRequest EventData;
		EventData.set_field_bignore(StructuredParams.bIgnore);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientIgnoreMoveInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientignoremoveinput(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientIgnoreLookInput_Parms StructuredParams = *static_cast<PlayerController_eventClientIgnoreLookInput_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientIgnoreLookInput queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientIgnoreLookInputRequest EventData;
		EventData.set_field_bignore(StructuredParams.bIgnore);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientIgnoreLookInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientignorelookinput(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientGotoState_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientGotoState_Parms StructuredParams = *static_cast<PlayerController_eventClientGotoState_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGotoState queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientGotoStateRequest EventData;
		EventData.set_field_newstate(TCHAR_TO_UTF8(*StructuredParams.NewState.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientGotoState, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientgotostate(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientGameEnded_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientGameEnded_Parms StructuredParams = *static_cast<PlayerController_eventClientGameEnded_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGameEnded queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientGameEndedRequest EventData;
		if (StructuredParams.EndGameFocus != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.EndGameFocus);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientGameEnded queued. StructuredParams.EndGameFocus is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.EndGameFocus};
			}
			else
			{
				EventData.set_field_endgamefocus(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_endgamefocus(SpatialConstants::NULL_OBJECT_REF);
		}
		EventData.set_field_biswinner(StructuredParams.bIsWinner);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientGameEnded, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientgameended(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientForceGarbageCollection queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientForceGarbageCollectionRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientForceGarbageCollection, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientforcegarbagecollection(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientFlushLevelStreaming queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientFlushLevelStreamingRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientFlushLevelStreaming, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientflushlevelstreaming(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientEndOnlineSession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientEndOnlineSession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientEndOnlineSessionRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientEndOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientendonlinesession(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientEnableNetworkVoice_Parms StructuredParams = *static_cast<PlayerController_eventClientEnableNetworkVoice_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientEnableNetworkVoice queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientEnableNetworkVoiceRequest EventData;
		EventData.set_field_benable(StructuredParams.bEnable);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientEnableNetworkVoice, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientenablenetworkvoice(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientCommitMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCommitMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCommitMapChangeRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCommitMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientcommitmapchange(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientClearCameraLensEffects queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientClearCameraLensEffectsRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientClearCameraLensEffects, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientclearcameralenseffects(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientCapBandwidth_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientCapBandwidth_Parms StructuredParams = *static_cast<PlayerController_eventClientCapBandwidth_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCapBandwidth queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCapBandwidthRequest EventData;
		EventData.set_field_cap(int32_t(StructuredParams.Cap));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCapBandwidth, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientcapbandwidth(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientCancelPendingMapChange queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientCancelPendingMapChangeRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientCancelPendingMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientcancelpendingmapchange(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventClientAddTextureStreamingLoc_Parms StructuredParams = *static_cast<PlayerController_eventClientAddTextureStreamingLoc_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientAddTextureStreamingLoc queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientAddTextureStreamingLocRequest EventData;
		EventData.set_field_inloc(improbable::Vector3f(StructuredParams.InLoc.X, StructuredParams.InLoc.Y, StructuredParams.InLoc.Z));
		EventData.set_field_duration(StructuredParams.Duration);
		EventData.set_field_boverridelocation(StructuredParams.bOverrideLocation);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientAddTextureStreamingLoc, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientaddtexturestreamingloc(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetRotation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
	Controller_eventClientSetRotation_Parms StructuredParams = *static_cast<Controller_eventClientSetRotation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetRotation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetRotationRequest EventData;
		EventData.set_field_newrotation(improbable::unreal::UnrealFRotator(StructuredParams.NewRotation.Yaw, StructuredParams.NewRotation.Pitch, StructuredParams.NewRotation.Roll));
		EventData.set_field_bresetcamera(StructuredParams.bResetCamera);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetRotation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetrotation(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ClientSetLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
	Controller_eventClientSetLocation_Parms StructuredParams = *static_cast<Controller_eventClientSetLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ClientSetLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealClientSetLocationRequest EventData;
		EventData.set_field_newlocation(improbable::Vector3f(StructuredParams.NewLocation.X, StructuredParams.NewLocation.Y, StructuredParams.NewLocation.Z));
		EventData.set_field_newrotation(improbable::unreal::UnrealFRotator(StructuredParams.NewRotation.Yaw, StructuredParams.NewRotation.Pitch, StructuredParams.NewRotation.Roll));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ClientSetLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerClientRPCs::Update Update;
		Update.add_playercontrollerclientsetlocation(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerClientRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerViewSelf_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerViewSelf_Parms StructuredParams = *static_cast<PlayerController_eventServerViewSelf_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewSelf queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewSelfRequest EventData;
		EventData.set_field_transitionparams_blendtime(StructuredParams.TransitionParams.BlendTime);
		EventData.set_field_transitionparams_blendfunction(uint32_t(StructuredParams.TransitionParams.BlendFunction));
		EventData.set_field_transitionparams_blendexp(StructuredParams.TransitionParams.BlendExp);
		EventData.set_field_transitionparams_blockoutgoing(StructuredParams.TransitionParams.bLockOutgoing);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewSelf, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverviewself(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewPrevPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewPrevPlayerRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewPrevPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverviewprevplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerViewNextPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerViewNextPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerViewNextPlayerRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerViewNextPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverviewnextplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerVerifyViewTarget queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerVerifyViewTargetRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerVerifyViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserververifyviewtarget(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerUpdateMultipleLevelsVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateMultipleLevelsVisibility queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateMultipleLevelsVisibilityRequest EventData;
		{
			::worker::List<std::string> List;
			for(int i = 0; i < StructuredParams.LevelVisibilities.Num(); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FUpdateLevelVisibilityLevelInfo::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FUpdateLevelVisibilityLevelInfo*>(&StructuredParams.LevelVisibilities[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			EventData.set_field_levelvisibilities(List);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateMultipleLevelsVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverupdatemultiplelevelsvisibility(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateLevelVisibility_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateLevelVisibility_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateLevelVisibility queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateLevelVisibilityRequest EventData;
		EventData.set_field_packagename(TCHAR_TO_UTF8(*StructuredParams.PackageName.ToString()));
		EventData.set_field_bisvisible(StructuredParams.bIsVisible);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateLevelVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverupdatelevelvisibility(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerUpdateCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUpdateCamera_Parms StructuredParams = *static_cast<PlayerController_eventServerUpdateCamera_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUpdateCamera queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUpdateCameraRequest EventData;
		EventData.set_field_camloc(improbable::Vector3f(StructuredParams.CamLoc.X, StructuredParams.CamLoc.Y, StructuredParams.CamLoc.Z));
		EventData.set_field_campitchandyaw(int32_t(StructuredParams.CamPitchAndYaw));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUpdateCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverupdatecamera(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerUnmutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerUnmutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventServerUnmutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerUnmutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerUnmutePlayerRequest EventData;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			EventData.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverunmuteplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerToggleAILogging_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerToggleAILogging queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerToggleAILoggingRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerToggleAILogging, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservertoggleailogging(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerShortTimeout_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerShortTimeout queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerShortTimeoutRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerShortTimeout, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservershorttimeout(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerSetSpectatorWaiting_Parms StructuredParams = *static_cast<PlayerController_eventServerSetSpectatorWaiting_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerSetSpectatorWaiting queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerSetSpectatorWaitingRequest EventData;
		EventData.set_field_bwaiting(StructuredParams.bWaiting);

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserversetspectatorwaiting(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerSetSpectatorLocation_Parms StructuredParams = *static_cast<PlayerController_eventServerSetSpectatorLocation_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerSetSpectatorLocation queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerSetSpectatorLocationRequest EventData;
		EventData.set_field_newloc(improbable::Vector3f(StructuredParams.NewLoc.X, StructuredParams.NewLoc.Y, StructuredParams.NewLoc.Z));
		EventData.set_field_newrot(improbable::unreal::UnrealFRotator(StructuredParams.NewRot.Yaw, StructuredParams.NewRot.Pitch, StructuredParams.NewRot.Roll));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerSetSpectatorLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserversetspectatorlocation(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerRestartPlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerRestartPlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerRestartPlayerRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerRestartPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverrestartplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerPause_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerPause queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerPauseRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerPause, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverpause(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerNotifyLoadedWorld_Parms StructuredParams = *static_cast<PlayerController_eventServerNotifyLoadedWorld_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerNotifyLoadedWorld queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerNotifyLoadedWorldRequest EventData;
		EventData.set_field_worldpackagename(TCHAR_TO_UTF8(*StructuredParams.WorldPackageName.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerNotifyLoadedWorld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservernotifyloadedworld(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerMutePlayer_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerMutePlayer_Parms StructuredParams = *static_cast<PlayerController_eventServerMutePlayer_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerMutePlayer queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerMutePlayerRequest EventData;
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool Success;
			(const_cast<FUniqueNetIdRepl&>(StructuredParams.PlayerId)).NetSerialize(ValueDataWriter, PackageMap, Success);
			EventData.set_field_playerid(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservermuteplayer(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCheckClientPossessionReliable queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCheckClientPossessionReliableRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCheckClientPossessionReliable, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservercheckclientpossessionreliable(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	auto Sender = [this, Connection, TargetObject]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCheckClientPossession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCheckClientPossessionRequest EventData;

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCheckClientPossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservercheckclientpossession(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ false);
}

void USpatialTypeBinding_PlayerController::ServerChangeName_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerChangeName_Parms StructuredParams = *static_cast<PlayerController_eventServerChangeName_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerChangeName queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerChangeNameRequest EventData;
		EventData.set_field_s(TCHAR_TO_UTF8(*StructuredParams.S));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerChangeName, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserverchangename(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerCamera_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerCamera_Parms StructuredParams = *static_cast<PlayerController_eventServerCamera_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerCamera queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerCameraRequest EventData;
		EventData.set_field_newmode(TCHAR_TO_UTF8(*StructuredParams.NewMode.ToString()));

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerservercamera(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
	PlayerController_eventServerAcknowledgePossession_Parms StructuredParams = *static_cast<PlayerController_eventServerAcknowledgePossession_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerAcknowledgePossession queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build request.
		improbable::unreal::generated::UnrealServerAcknowledgePossessionRequest EventData;
		if (StructuredParams.P != nullptr)
		{
			FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.P);
			improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
			if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
			{
				UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC ServerAcknowledgePossession queued. StructuredParams.P is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
				return {StructuredParams.P};
			}
			else
			{
				EventData.set_field_p(ObjectRef);
			}
		}
		else
		{
			EventData.set_field_p(SpatialConstants::NULL_OBJECT_REF);
		}

		// Send command request.
		EventData.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: ServerAcknowledgePossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));
		improbable::unreal::generated::UnrealPlayerControllerServerRPCs::Update Update;
		Update.add_playercontrollerserveracknowledgepossession(EventData);
		Connection->SendComponentUpdate<improbable::unreal::generated::UnrealPlayerControllerServerRPCs>(TargetObjectRef.entity(), Update);
		return {};
	};
	Interop->SendCommandRequest_Internal(Sender, /*bReliable*/ true);
}

void USpatialTypeBinding_PlayerController::OnServerStartedVisualLogger_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealOnServerStartedVisualLoggerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventOnServerStartedVisualLogger_Parms Parameters;

		// Extract from request data.
		Parameters.bIsLogging = EventData.field_bislogging();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: OnServerStartedVisualLogger, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("OnServerStartedVisualLogger"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: OnServerStartedVisualLogger_OnCommandRequest: Function not found. Object: %s, Function: OnServerStartedVisualLogger."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientWasKicked_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientWasKickedRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientWasKicked_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientWasKicked_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientWasKicked_Parms Parameters;

		// Extract from request data.
		// UNSUPPORTED UTextProperty (unhandled) Parameters.KickReason EventData.field_kickreason()

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientWasKicked, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientWasKicked"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientWasKicked_OnCommandRequest: Function not found. Object: %s, Function: ClientWasKicked."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientVoiceHandshakeComplete_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientVoiceHandshakeCompleteRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientVoiceHandshakeComplete, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientVoiceHandshakeComplete"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientVoiceHandshakeComplete_OnCommandRequest: Function not found. Object: %s, Function: ClientVoiceHandshakeComplete."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientUpdateMultipleLevelsStreamingStatus_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUpdateMultipleLevelsStreamingStatusRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUpdateMultipleLevelsStreamingStatus_Parms Parameters;

		// Extract from request data.
		{
			auto& List = EventData.field_levelstatuses();
			Parameters.LevelStatuses.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FUpdateLevelStreamingLevelStatus::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.LevelStatuses[i]));
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUpdateMultipleLevelsStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUpdateMultipleLevelsStreamingStatus"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUpdateMultipleLevelsStreamingStatus_OnCommandRequest: Function not found. Object: %s, Function: ClientUpdateMultipleLevelsStreamingStatus."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientUpdateLevelStreamingStatus_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUpdateLevelStreamingStatusRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUpdateLevelStreamingStatus_Parms Parameters;

		// Extract from request data.
		Parameters.PackageName = FName((EventData.field_packagename()).data());
		Parameters.bNewShouldBeLoaded = EventData.field_bnewshouldbeloaded();
		Parameters.bNewShouldBeVisible = EventData.field_bnewshouldbevisible();
		Parameters.bNewShouldBlockOnLoad = EventData.field_bnewshouldblockonload();
		Parameters.LODIndex = EventData.field_lodindex();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUpdateLevelStreamingStatus, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUpdateLevelStreamingStatus"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUpdateLevelStreamingStatus_OnCommandRequest: Function not found. Object: %s, Function: ClientUpdateLevelStreamingStatus."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientUnmutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientUnmutePlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientUnmutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = EventData.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientUnmutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientUnmutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ClientUnmutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientTravelInternal_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientTravelInternalRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTravelInternal_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientTravelInternal_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientTravelInternal_Parms Parameters;

		// Extract from request data.
		Parameters.URL = FString(UTF8_TO_TCHAR(EventData.field_url().c_str()));
		Parameters.TravelType = TEnumAsByte<ETravelType>(uint8(EventData.field_traveltype()));
		Parameters.bSeamless = EventData.field_bseamless();
		Parameters.MapPackageGuid.A = EventData.field_mappackageguid_a();
		Parameters.MapPackageGuid.B = EventData.field_mappackageguid_b();
		Parameters.MapPackageGuid.C = EventData.field_mappackageguid_c();
		Parameters.MapPackageGuid.D = EventData.field_mappackageguid_d();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientTravelInternal, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientTravelInternal"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientTravelInternal_OnCommandRequest: Function not found. Object: %s, Function: ClientTravelInternal."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientTeamMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientTeamMessageRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTeamMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientTeamMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientTeamMessage_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_senderplayerstate();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.SenderPlayerState = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.SenderPlayerState = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.SenderPlayerState, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientTeamMessage_OnCommandRequest: Parameters.SenderPlayerState %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.S = FString(UTF8_TO_TCHAR(EventData.field_s().c_str()));
		Parameters.Type = FName((EventData.field_type()).data());
		Parameters.MsgLifeTime = EventData.field_msglifetime();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientTeamMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientTeamMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientTeamMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientTeamMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientStopForceFeedback_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopForceFeedbackRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopForceFeedback_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_forcefeedbackeffect();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForceFeedbackEffect = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForceFeedbackEffect = Cast<UForceFeedbackEffect>(Object_Raw);
					checkf(Parameters.ForceFeedbackEffect, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Parameters.ForceFeedbackEffect %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.Tag = FName((EventData.field_tag()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopForceFeedback"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopForceFeedback_OnCommandRequest: Function not found. Object: %s, Function: ClientStopForceFeedback."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraShake_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopCameraShakeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopCameraShake_Parms Parameters;

		// Extract from request data.
		Parameters.Shake = PackageMap->GetStaticClassFromHash(EventData.field_shake());
		Parameters.bImmediately = EventData.field_bimmediately();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopCameraShake"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopCameraShake_OnCommandRequest: Function not found. Object: %s, Function: ClientStopCameraShake."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientStopCameraAnim_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStopCameraAnimRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientStopCameraAnim_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_animtostop();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.AnimToStop = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.AnimToStop = Cast<UCameraAnim>(Object_Raw);
					checkf(Parameters.AnimToStop, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Parameters.AnimToStop %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStopCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStopCameraAnim"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStopCameraAnim_OnCommandRequest: Function not found. Object: %s, Function: ClientStopCameraAnim."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientStartOnlineSession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientStartOnlineSessionRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientStartOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientStartOnlineSession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientStartOnlineSession_OnCommandRequest: Function not found. Object: %s, Function: ClientStartOnlineSession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSpawnCameraLensEffect_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSpawnCameraLensEffectRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSpawnCameraLensEffect_Parms Parameters;

		// Extract from request data.
		Parameters.LensEffectEmitterClass = PackageMap->GetStaticClassFromHash(EventData.field_lenseffectemitterclass());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSpawnCameraLensEffect, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSpawnCameraLensEffect"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSpawnCameraLensEffect_OnCommandRequest: Function not found. Object: %s, Function: ClientSpawnCameraLensEffect."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetViewTarget_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetViewTargetRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetViewTarget_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_a();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.A = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.A = Cast<AActor>(Object_Raw);
					checkf(Parameters.A, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Parameters.A %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.TransitionParams.BlendTime = EventData.field_transitionparams_blendtime();
		Parameters.TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(EventData.field_transitionparams_blendfunction()));
		Parameters.TransitionParams.BlendExp = EventData.field_transitionparams_blendexp();
		Parameters.TransitionParams.bLockOutgoing = EventData.field_transitionparams_blockoutgoing();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetViewTarget"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetViewTarget_OnCommandRequest: Function not found. Object: %s, Function: ClientSetViewTarget."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetSpectatorWaiting_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetSpectatorWaitingRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetSpectatorWaiting_Parms Parameters;

		// Extract from request data.
		Parameters.bWaiting = EventData.field_bwaiting();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetSpectatorWaiting"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetSpectatorWaiting_OnCommandRequest: Function not found. Object: %s, Function: ClientSetSpectatorWaiting."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetHUD_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetHUDRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetHUD_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetHUD_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetHUD_Parms Parameters;

		// Extract from request data.
		Parameters.NewHUDClass = PackageMap->GetStaticClassFromHash(EventData.field_newhudclass());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetHUD, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetHUD"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetHUD_OnCommandRequest: Function not found. Object: %s, Function: ClientSetHUD."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetForceMipLevelsToBeResident_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetForceMipLevelsToBeResidentRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetForceMipLevelsToBeResident_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_material();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Material = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Material = Cast<UMaterialInterface>(Object_Raw);
					checkf(Parameters.Material, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Parameters.Material %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.ForceDuration = EventData.field_forceduration();
		Parameters.CinematicTextureGroups = EventData.field_cinematictexturegroups();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetForceMipLevelsToBeResident, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetForceMipLevelsToBeResident"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetForceMipLevelsToBeResident_OnCommandRequest: Function not found. Object: %s, Function: ClientSetForceMipLevelsToBeResident."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetCinematicMode_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCinematicModeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCinematicMode_Parms Parameters;

		// Extract from request data.
		Parameters.bInCinematicMode = EventData.field_bincinematicmode();
		Parameters.bAffectsMovement = EventData.field_baffectsmovement();
		Parameters.bAffectsTurning = EventData.field_baffectsturning();
		Parameters.bAffectsHUD = EventData.field_baffectshud();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCinematicMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCinematicMode"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCinematicMode_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCinematicMode."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraMode_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCameraModeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCameraMode_Parms Parameters;

		// Extract from request data.
		Parameters.NewCamMode = FName((EventData.field_newcammode()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCameraMode, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCameraMode"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCameraMode_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCameraMode."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetCameraFade_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetCameraFadeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientSetCameraFade_Parms Parameters;

		// Extract from request data.
		Parameters.bEnableFading = EventData.field_benablefading();
		Parameters.FadeColor.B = uint8(uint8(EventData.field_fadecolor_b()));
		Parameters.FadeColor.G = uint8(uint8(EventData.field_fadecolor_g()));
		Parameters.FadeColor.R = uint8(uint8(EventData.field_fadecolor_r()));
		Parameters.FadeColor.A = uint8(uint8(EventData.field_fadecolor_a()));
		Parameters.FadeAlpha.X = EventData.field_fadealpha_x();
		Parameters.FadeAlpha.Y = EventData.field_fadealpha_y();
		Parameters.FadeTime = EventData.field_fadetime();
		Parameters.bFadeAudio = EventData.field_bfadeaudio();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetCameraFade, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetCameraFade"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetCameraFade_OnCommandRequest: Function not found. Object: %s, Function: ClientSetCameraFade."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetBlockOnAsyncLoading_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetBlockOnAsyncLoadingRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetBlockOnAsyncLoading, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetBlockOnAsyncLoading"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetBlockOnAsyncLoading_OnCommandRequest: Function not found. Object: %s, Function: ClientSetBlockOnAsyncLoading."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenuWithTextReason_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReturnToMainMenuWithTextReasonRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReturnToMainMenuWithTextReason_Parms Parameters;

		// Extract from request data.
		// UNSUPPORTED UTextProperty (unhandled) Parameters.ReturnReason EventData.field_returnreason()

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReturnToMainMenuWithTextReason, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReturnToMainMenuWithTextReason"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReturnToMainMenuWithTextReason_OnCommandRequest: Function not found. Object: %s, Function: ClientReturnToMainMenuWithTextReason."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientReturnToMainMenu_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReturnToMainMenuRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReturnToMainMenu_Parms Parameters;

		// Extract from request data.
		Parameters.ReturnReason = FString(UTF8_TO_TCHAR(EventData.field_returnreason().c_str()));

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReturnToMainMenu, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReturnToMainMenu"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReturnToMainMenu_OnCommandRequest: Function not found. Object: %s, Function: ClientReturnToMainMenu."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientRetryClientRestart_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRetryClientRestartRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRetryClientRestart_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_newpawn();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewPawn = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.NewPawn = Cast<APawn>(Object_Raw);
					checkf(Parameters.NewPawn, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Parameters.NewPawn %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRetryClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRetryClientRestart"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRetryClientRestart_OnCommandRequest: Function not found. Object: %s, Function: ClientRetryClientRestart."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientRestart_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRestartRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRestart_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRestart_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRestart_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_newpawn();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.NewPawn = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.NewPawn = Cast<APawn>(Object_Raw);
					checkf(Parameters.NewPawn, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRestart_OnCommandRequest: Parameters.NewPawn %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRestart, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRestart"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRestart_OnCommandRequest: Function not found. Object: %s, Function: ClientRestart."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientReset_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientResetRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReset_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReset_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReset, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReset"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReset_OnCommandRequest: Function not found. Object: %s, Function: ClientReset."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientRepObjRef_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientRepObjRefRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRepObjRef_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientRepObjRef_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientRepObjRef_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_object();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Object = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Object = Cast<UObject>(Object_Raw);
					checkf(Parameters.Object, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientRepObjRef_OnCommandRequest: Parameters.Object %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientRepObjRef, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientRepObjRef"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientRepObjRef_OnCommandRequest: Function not found. Object: %s, Function: ClientRepObjRef."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientReceiveLocalizedMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientReceiveLocalizedMessageRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientReceiveLocalizedMessage_Parms Parameters;

		// Extract from request data.
		Parameters.Message = PackageMap->GetStaticClassFromHash(EventData.field_message());
		Parameters.Switch = EventData.field_switch();
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_relatedplayerstate1();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.RelatedPlayerState_1 = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.RelatedPlayerState_1 = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.RelatedPlayerState_1, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.RelatedPlayerState_1 %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_relatedplayerstate2();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.RelatedPlayerState_2 = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.RelatedPlayerState_2 = Cast<APlayerState>(Object_Raw);
					checkf(Parameters.RelatedPlayerState_2, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.RelatedPlayerState_2 %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_optionalobject();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.OptionalObject = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.OptionalObject = Cast<UObject>(Object_Raw);
					checkf(Parameters.OptionalObject, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Parameters.OptionalObject %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientReceiveLocalizedMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientReceiveLocalizedMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientReceiveLocalizedMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientReceiveLocalizedMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPrestreamTextures_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPrestreamTexturesRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPrestreamTextures_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_forcedactor();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForcedActor = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForcedActor = Cast<AActor>(Object_Raw);
					checkf(Parameters.ForcedActor, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Parameters.ForcedActor %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.ForceDuration = EventData.field_forceduration();
		Parameters.bEnableStreaming = EventData.field_benablestreaming();
		Parameters.CinematicTextureGroups = EventData.field_cinematictexturegroups();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPrestreamTextures, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPrestreamTextures"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPrestreamTextures_OnCommandRequest: Function not found. Object: %s, Function: ClientPrestreamTextures."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPrepareMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPrepareMapChangeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPrepareMapChange_Parms Parameters;

		// Extract from request data.
		Parameters.LevelName = FName((EventData.field_levelname()).data());
		Parameters.bFirst = EventData.field_bfirst();
		Parameters.bLast = EventData.field_blast();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPrepareMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPrepareMapChange"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPrepareMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientPrepareMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPlaySoundAtLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlaySoundAtLocationRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlaySoundAtLocation_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_sound();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Sound = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Sound = Cast<USoundBase>(Object_Raw);
					checkf(Parameters.Sound, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Parameters.Sound %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			auto& Vector = EventData.field_location();
			Parameters.Location.X = Vector.x();
			Parameters.Location.Y = Vector.y();
			Parameters.Location.Z = Vector.z();
		}
		Parameters.VolumeMultiplier = EventData.field_volumemultiplier();
		Parameters.PitchMultiplier = EventData.field_pitchmultiplier();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlaySoundAtLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlaySoundAtLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlaySoundAtLocation_OnCommandRequest: Function not found. Object: %s, Function: ClientPlaySoundAtLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPlaySound_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlaySoundRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySound_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlaySound_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlaySound_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_sound();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.Sound = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.Sound = Cast<USoundBase>(Object_Raw);
					checkf(Parameters.Sound, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlaySound_OnCommandRequest: Parameters.Sound %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.VolumeMultiplier = EventData.field_volumemultiplier();
		Parameters.PitchMultiplier = EventData.field_pitchmultiplier();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlaySound, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlaySound"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlaySound_OnCommandRequest: Function not found. Object: %s, Function: ClientPlaySound."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPlayForceFeedback_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayForceFeedbackRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayForceFeedback_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_forcefeedbackeffect();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.ForceFeedbackEffect = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.ForceFeedbackEffect = Cast<UForceFeedbackEffect>(Object_Raw);
					checkf(Parameters.ForceFeedbackEffect, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Parameters.ForceFeedbackEffect %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.bLooping = EventData.field_blooping();
		Parameters.bIgnoreTimeDilation = EventData.field_bignoretimedilation();
		Parameters.Tag = FName((EventData.field_tag()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayForceFeedback, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayForceFeedback"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayForceFeedback_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayForceFeedback."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraShake_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayCameraShakeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayCameraShake_Parms Parameters;

		// Extract from request data.
		Parameters.Shake = PackageMap->GetStaticClassFromHash(EventData.field_shake());
		Parameters.Scale = EventData.field_scale();
		Parameters.PlaySpace = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(EventData.field_playspace()));
		{
			auto& Rotator = EventData.field_userplayspacerot();
			Parameters.UserPlaySpaceRot.Yaw = Rotator.yaw();
			Parameters.UserPlaySpaceRot.Pitch = Rotator.pitch();
			Parameters.UserPlaySpaceRot.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayCameraShake, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayCameraShake"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayCameraShake_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayCameraShake."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientPlayCameraAnim_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientPlayCameraAnimRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientPlayCameraAnim_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_animtoplay();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.AnimToPlay = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.AnimToPlay = Cast<UCameraAnim>(Object_Raw);
					checkf(Parameters.AnimToPlay, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Parameters.AnimToPlay %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.Scale = EventData.field_scale();
		Parameters.Rate = EventData.field_rate();
		Parameters.BlendInTime = EventData.field_blendintime();
		Parameters.BlendOutTime = EventData.field_blendouttime();
		Parameters.bLoop = EventData.field_bloop();
		Parameters.bRandomStartTime = EventData.field_brandomstarttime();
		Parameters.Space = TEnumAsByte<ECameraAnimPlaySpace::Type>(uint8(EventData.field_space()));
		{
			auto& Rotator = EventData.field_customplayspace();
			Parameters.CustomPlaySpace.Yaw = Rotator.yaw();
			Parameters.CustomPlaySpace.Pitch = Rotator.pitch();
			Parameters.CustomPlaySpace.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientPlayCameraAnim, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientPlayCameraAnim"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientPlayCameraAnim_OnCommandRequest: Function not found. Object: %s, Function: ClientPlayCameraAnim."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientMutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientMutePlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientMutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientMutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientMutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = EventData.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientMutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientMutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ClientMutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientMessage_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientMessageRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientMessage_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientMessage_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientMessage_Parms Parameters;

		// Extract from request data.
		Parameters.S = FString(UTF8_TO_TCHAR(EventData.field_s().c_str()));
		Parameters.Type = FName((EventData.field_type()).data());
		Parameters.MsgLifeTime = EventData.field_msglifetime();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientMessage, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientMessage"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientMessage_OnCommandRequest: Function not found. Object: %s, Function: ClientMessage."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreMoveInput_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientIgnoreMoveInputRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientIgnoreMoveInput_Parms Parameters;

		// Extract from request data.
		Parameters.bIgnore = EventData.field_bignore();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientIgnoreMoveInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientIgnoreMoveInput"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientIgnoreMoveInput_OnCommandRequest: Function not found. Object: %s, Function: ClientIgnoreMoveInput."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientIgnoreLookInput_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientIgnoreLookInputRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientIgnoreLookInput_Parms Parameters;

		// Extract from request data.
		Parameters.bIgnore = EventData.field_bignore();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientIgnoreLookInput, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientIgnoreLookInput"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientIgnoreLookInput_OnCommandRequest: Function not found. Object: %s, Function: ClientIgnoreLookInput."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientGotoState_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientGotoStateRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGotoState_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientGotoState_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientGotoState_Parms Parameters;

		// Extract from request data.
		Parameters.NewState = FName((EventData.field_newstate()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientGotoState, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientGotoState"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientGotoState_OnCommandRequest: Function not found. Object: %s, Function: ClientGotoState."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientGameEnded_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientGameEndedRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGameEnded_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientGameEnded_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientGameEnded_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_endgamefocus();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.EndGameFocus = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.EndGameFocus = Cast<AActor>(Object_Raw);
					checkf(Parameters.EndGameFocus, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientGameEnded_OnCommandRequest: Parameters.EndGameFocus %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		Parameters.bIsWinner = EventData.field_biswinner();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientGameEnded, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientGameEnded"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientGameEnded_OnCommandRequest: Function not found. Object: %s, Function: ClientGameEnded."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientForceGarbageCollection_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientForceGarbageCollectionRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientForceGarbageCollection, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientForceGarbageCollection"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientForceGarbageCollection_OnCommandRequest: Function not found. Object: %s, Function: ClientForceGarbageCollection."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientFlushLevelStreaming_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientFlushLevelStreamingRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientFlushLevelStreaming, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientFlushLevelStreaming"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientFlushLevelStreaming_OnCommandRequest: Function not found. Object: %s, Function: ClientFlushLevelStreaming."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientEndOnlineSession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientEndOnlineSessionRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientEndOnlineSession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientEndOnlineSession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientEndOnlineSession_OnCommandRequest: Function not found. Object: %s, Function: ClientEndOnlineSession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientEnableNetworkVoice_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientEnableNetworkVoiceRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientEnableNetworkVoice_Parms Parameters;

		// Extract from request data.
		Parameters.bEnable = EventData.field_benable();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientEnableNetworkVoice, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientEnableNetworkVoice"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientEnableNetworkVoice_OnCommandRequest: Function not found. Object: %s, Function: ClientEnableNetworkVoice."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientCommitMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCommitMapChangeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCommitMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCommitMapChange"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCommitMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientCommitMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientClearCameraLensEffects_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientClearCameraLensEffectsRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientClearCameraLensEffects, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientClearCameraLensEffects"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientClearCameraLensEffects_OnCommandRequest: Function not found. Object: %s, Function: ClientClearCameraLensEffects."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientCapBandwidth_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCapBandwidthRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientCapBandwidth_Parms Parameters;

		// Extract from request data.
		Parameters.Cap = EventData.field_cap();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCapBandwidth, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCapBandwidth"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCapBandwidth_OnCommandRequest: Function not found. Object: %s, Function: ClientCapBandwidth."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientCancelPendingMapChange_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCancelPendingMapChangeRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientCancelPendingMapChange, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientCancelPendingMapChange"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientCancelPendingMapChange_OnCommandRequest: Function not found. Object: %s, Function: ClientCancelPendingMapChange."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientAddTextureStreamingLoc_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAddTextureStreamingLocRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventClientAddTextureStreamingLoc_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = EventData.field_inloc();
			Parameters.InLoc.X = Vector.x();
			Parameters.InLoc.Y = Vector.y();
			Parameters.InLoc.Z = Vector.z();
		}
		Parameters.Duration = EventData.field_duration();
		Parameters.bOverrideLocation = EventData.field_boverridelocation();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientAddTextureStreamingLoc, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientAddTextureStreamingLoc"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientAddTextureStreamingLoc_OnCommandRequest: Function not found. Object: %s, Function: ClientAddTextureStreamingLoc."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetRotation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetRotationRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetRotation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetRotation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
		Controller_eventClientSetRotation_Parms Parameters;

		// Extract from request data.
		{
			auto& Rotator = EventData.field_newrotation();
			Parameters.NewRotation.Yaw = Rotator.yaw();
			Parameters.NewRotation.Pitch = Rotator.pitch();
			Parameters.NewRotation.Roll = Rotator.roll();
		}
		Parameters.bResetCamera = EventData.field_bresetcamera();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetRotation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetRotation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetRotation_OnCommandRequest: Function not found. Object: %s, Function: ClientSetRotation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ClientSetLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientSetLocationRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ClientSetLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ClientSetLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in Controller.generated.h (in a macro that is then put in Controller.h UCLASS macro)
		Controller_eventClientSetLocation_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = EventData.field_newlocation();
			Parameters.NewLocation.X = Vector.x();
			Parameters.NewLocation.Y = Vector.y();
			Parameters.NewLocation.Z = Vector.z();
		}
		{
			auto& Rotator = EventData.field_newrotation();
			Parameters.NewRotation.Yaw = Rotator.yaw();
			Parameters.NewRotation.Pitch = Rotator.pitch();
			Parameters.NewRotation.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ClientSetLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ClientSetLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ClientSetLocation_OnCommandRequest: Function not found. Object: %s, Function: ClientSetLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerViewSelf_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewSelfRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewSelf_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewSelf_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerViewSelf_Parms Parameters;

		// Extract from request data.
		Parameters.TransitionParams.BlendTime = EventData.field_transitionparams_blendtime();
		Parameters.TransitionParams.BlendFunction = TEnumAsByte<EViewTargetBlendFunction>(uint8(EventData.field_transitionparams_blendfunction()));
		Parameters.TransitionParams.BlendExp = EventData.field_transitionparams_blendexp();
		Parameters.TransitionParams.bLockOutgoing = EventData.field_transitionparams_blockoutgoing();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewSelf, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewSelf"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewSelf_OnCommandRequest: Function not found. Object: %s, Function: ServerViewSelf."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerViewPrevPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewPrevPlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewPrevPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewPrevPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewPrevPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerViewPrevPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerViewNextPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerViewNextPlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerViewNextPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerViewNextPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerViewNextPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerViewNextPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerVerifyViewTarget_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerVerifyViewTargetRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerVerifyViewTarget, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerVerifyViewTarget"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerVerifyViewTarget_OnCommandRequest: Function not found. Object: %s, Function: ServerVerifyViewTarget."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerUpdateMultipleLevelsVisibility_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateMultipleLevelsVisibilityRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateMultipleLevelsVisibility_Parms Parameters;

		// Extract from request data.
		{
			auto& List = EventData.field_levelvisibilities();
			Parameters.LevelVisibilities.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FUpdateLevelVisibilityLevelInfo::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.LevelVisibilities[i]));
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateMultipleLevelsVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateMultipleLevelsVisibility"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateMultipleLevelsVisibility_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateMultipleLevelsVisibility."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerUpdateLevelVisibility_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateLevelVisibilityRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateLevelVisibility_Parms Parameters;

		// Extract from request data.
		Parameters.PackageName = FName((EventData.field_packagename()).data());
		Parameters.bIsVisible = EventData.field_bisvisible();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateLevelVisibility, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateLevelVisibility"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateLevelVisibility_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateLevelVisibility."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerUpdateCamera_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUpdateCameraRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUpdateCamera_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = EventData.field_camloc();
			Parameters.CamLoc.X = Vector.x();
			Parameters.CamLoc.Y = Vector.y();
			Parameters.CamLoc.Z = Vector.z();
		}
		Parameters.CamPitchAndYaw = EventData.field_campitchandyaw();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUpdateCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUpdateCamera"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUpdateCamera_OnCommandRequest: Function not found. Object: %s, Function: ServerUpdateCamera."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerUnmutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerUnmutePlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerUnmutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = EventData.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerUnmutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerUnmutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerUnmutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerUnmutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerToggleAILogging_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerToggleAILoggingRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerToggleAILogging, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerToggleAILogging"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerToggleAILogging_OnCommandRequest: Function not found. Object: %s, Function: ServerToggleAILogging."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerShortTimeout_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerShortTimeoutRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerShortTimeout_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerShortTimeout_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerShortTimeout, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerShortTimeout"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerShortTimeout_OnCommandRequest: Function not found. Object: %s, Function: ServerShortTimeout."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorWaiting_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerSetSpectatorWaitingRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerSetSpectatorWaiting_Parms Parameters;

		// Extract from request data.
		Parameters.bWaiting = EventData.field_bwaiting();

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerSetSpectatorWaiting, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerSetSpectatorWaiting"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerSetSpectatorWaiting_OnCommandRequest: Function not found. Object: %s, Function: ServerSetSpectatorWaiting."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerSetSpectatorLocation_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerSetSpectatorLocationRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerSetSpectatorLocation_Parms Parameters;

		// Extract from request data.
		{
			auto& Vector = EventData.field_newloc();
			Parameters.NewLoc.X = Vector.x();
			Parameters.NewLoc.Y = Vector.y();
			Parameters.NewLoc.Z = Vector.z();
		}
		{
			auto& Rotator = EventData.field_newrot();
			Parameters.NewRot.Yaw = Rotator.yaw();
			Parameters.NewRot.Pitch = Rotator.pitch();
			Parameters.NewRot.Roll = Rotator.roll();
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerSetSpectatorLocation, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerSetSpectatorLocation"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerSetSpectatorLocation_OnCommandRequest: Function not found. Object: %s, Function: ServerSetSpectatorLocation."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerRestartPlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerRestartPlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerRestartPlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerRestartPlayer"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerRestartPlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerRestartPlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerPause_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerPauseRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerPause_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerPause_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerPause, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerPause"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerPause_OnCommandRequest: Function not found. Object: %s, Function: ServerPause."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerNotifyLoadedWorld_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerNotifyLoadedWorldRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerNotifyLoadedWorld_Parms Parameters;

		// Extract from request data.
		Parameters.WorldPackageName = FName((EventData.field_worldpackagename()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerNotifyLoadedWorld, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerNotifyLoadedWorld"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerNotifyLoadedWorld_OnCommandRequest: Function not found. Object: %s, Function: ServerNotifyLoadedWorld."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerMutePlayer_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMutePlayerRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerMutePlayer_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerMutePlayer_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerMutePlayer_Parms Parameters;

		// Extract from request data.
		{
			auto& ValueDataStr = EventData.field_playerid();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess;
			Parameters.PlayerId.NetSerialize(ValueDataReader, PackageMap, bSuccess);
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerMutePlayer, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerMutePlayer"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerMutePlayer_OnCommandRequest: Function not found. Object: %s, Function: ServerMutePlayer."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossessionReliable_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCheckClientPossessionReliableRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCheckClientPossessionReliable, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCheckClientPossessionReliable"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCheckClientPossessionReliable_OnCommandRequest: Function not found. Object: %s, Function: ServerCheckClientPossessionReliable."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerCheckClientPossession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCheckClientPossessionRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCheckClientPossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCheckClientPossession"))))
		{
			TargetObject->ProcessEvent(Function, nullptr);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCheckClientPossession_OnCommandRequest: Function not found. Object: %s, Function: ServerCheckClientPossession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerChangeName_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerChangeNameRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerChangeName_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerChangeName_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerChangeName_Parms Parameters;

		// Extract from request data.
		Parameters.S = FString(UTF8_TO_TCHAR(EventData.field_s().c_str()));

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerChangeName, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerChangeName"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerChangeName_OnCommandRequest: Function not found. Object: %s, Function: ServerChangeName."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerCamera_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerCameraRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerCamera_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerCamera_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerCamera_Parms Parameters;

		// Extract from request data.
		Parameters.NewMode = FName((EventData.field_newmode()).data());

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerCamera, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerCamera"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerCamera_OnCommandRequest: Function not found. Object: %s, Function: ServerCamera."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}

void USpatialTypeBinding_PlayerController::ServerAcknowledgePossession_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerAcknowledgePossessionRequest& EventData)
{
	auto Receiver = [this, EntityId, EventData]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{EntityId, EventData.target_subobject_offset()};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in PlayerController.generated.h (in a macro that is then put in PlayerController.h UCLASS macro)
		PlayerController_eventServerAcknowledgePossession_Parms Parameters;

		// Extract from request data.
		{
			improbable::unreal::UnrealObjectRef ObjectRef = EventData.field_p();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.P = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					Parameters.P = Cast<APawn>(Object_Raw);
					checkf(Parameters.P, TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
				}
				else
				{
					UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Parameters.P %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: ServerAcknowledgePossession, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("ServerAcknowledgePossession"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: ServerAcknowledgePossession_OnCommandRequest: Function not found. Object: %s, Function: ServerAcknowledgePossession."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		return {};
	};
	Interop->SendCommandResponse_Internal(Receiver);
}
