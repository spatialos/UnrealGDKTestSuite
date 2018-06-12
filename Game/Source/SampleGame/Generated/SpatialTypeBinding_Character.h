// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealCharacter.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_Character.generated.h"

UCLASS()
class USpatialTypeBinding_Character : public USpatialTypeBinding
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
	using FRPCSender = void (USpatialTypeBinding_Character::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FMigratableHandlePropertyMap MigratableHandleToPropertyMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::UnrealCharacterSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::UnrealCharacterMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::UnrealCharacterMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealCharacterSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealCharacterMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::UnrealCharacterMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealCharacterSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealCharacterMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::UnrealCharacterMigratableData::Update& Update) const;

	// RPC event receive functions.
	void ReceiveUpdate_ClientRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealCharacterClientRPCs::Update& Update);
	void ReceiveUpdate_ServerRPCs(worker::EntityId EntityId, const improbable::unreal::generated::UnrealCharacterServerRPCs::Update& Update);

	// RPC command sender functions.
	void RootMotionDebugClientPrintOnScreen_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientVeryShortAdjustPosition_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatWalk_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatGhost_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientCheatFly_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionSourcePosition_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustRootMotionPosition_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAdjustPosition_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ClientAckGoodMove_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveOld_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveNoBase_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualNoBase_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDualHybridRootMotion_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMoveDual_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void ServerMove_SendCommand(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void RootMotionDebugClientPrintOnScreen_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealRootMotionDebugClientPrintOnScreenRequest& EventData);
	void ClientVeryShortAdjustPosition_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientVeryShortAdjustPositionRequest& EventData);
	void ClientCheatWalk_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCheatWalkRequest& EventData);
	void ClientCheatGhost_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCheatGhostRequest& EventData);
	void ClientCheatFly_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientCheatFlyRequest& EventData);
	void ClientAdjustRootMotionSourcePosition_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAdjustRootMotionSourcePositionRequest& EventData);
	void ClientAdjustRootMotionPosition_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAdjustRootMotionPositionRequest& EventData);
	void ClientAdjustPosition_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAdjustPositionRequest& EventData);
	void ClientAckGoodMove_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealClientAckGoodMoveRequest& EventData);
	void ServerMoveOld_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveOldRequest& EventData);
	void ServerMoveNoBase_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveNoBaseRequest& EventData);
	void ServerMoveDualNoBase_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveDualNoBaseRequest& EventData);
	void ServerMoveDualHybridRootMotion_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveDualHybridRootMotionRequest& EventData);
	void ServerMoveDual_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveDualRequest& EventData);
	void ServerMove_ReceiveRPCEvent(const worker::EntityId EntityId, const improbable::unreal::generated::UnrealServerMoveRequest& EventData);
};
