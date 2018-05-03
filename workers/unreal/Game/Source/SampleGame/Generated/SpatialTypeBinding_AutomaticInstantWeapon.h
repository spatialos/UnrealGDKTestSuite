// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/core_types.h>
#include <improbable/unreal/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealAutomaticInstantWeapon.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_AutomaticInstantWeapon.generated.h"

UCLASS()
class USpatialTypeBinding_AutomaticInstantWeapon : public USpatialTypeBinding
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
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, FFrame* const Frame) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_AutomaticInstantWeapon::*)(worker::Connection* const, struct FFrame* const, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	// Component update helper functions.
	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::UnrealAutomaticInstantWeaponSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::UnrealAutomaticInstantWeaponMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::UnrealAutomaticInstantWeaponMigratableData::Update& MigratableDataUpdate,
		bool& bMigratableDataUpdateChanged) const;
	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::UnrealAutomaticInstantWeaponSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::UnrealAutomaticInstantWeaponMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::UnrealAutomaticInstantWeaponMigratableData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::UnrealAutomaticInstantWeaponSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::UnrealAutomaticInstantWeaponMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::UnrealAutomaticInstantWeaponMigratableData::Update& Update) const;

	// RPC command sender functions.
	void ServerDidMiss_SendCommand(worker::Connection* const Connection, struct FFrame* const RPCFrame, UObject* TargetObject);
	void ServerDidHit_SendCommand(worker::Connection* const Connection, struct FFrame* const RPCFrame, UObject* TargetObject);

	// RPC command request handler functions.
	void ServerDidMiss_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::UnrealAutomaticInstantWeaponServerRPCs::Commands::Serverdidmiss>& Op);
	void ServerDidHit_OnCommandRequest(const worker::CommandRequestOp<improbable::unreal::UnrealAutomaticInstantWeaponServerRPCs::Commands::Serverdidhit>& Op);

	// RPC command response handler functions.
	void ServerDidMiss_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::UnrealAutomaticInstantWeaponServerRPCs::Commands::Serverdidmiss>& Op);
	void ServerDidHit_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::UnrealAutomaticInstantWeaponServerRPCs::Commands::Serverdidhit>& Op);
};
