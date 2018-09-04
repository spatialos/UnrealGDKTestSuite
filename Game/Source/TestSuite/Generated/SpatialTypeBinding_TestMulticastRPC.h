// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealTestMulticastRPC.h>

#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Tests/TestMulticastRPC.h"

#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_TestMulticastRPC.generated.h"

UCLASS()
class USpatialTypeBinding_TestMulticastRPC : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FHandoverHandlePropertyMap& GetHandoverHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView(bool bIsClient) override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bNetOwned) const override;
	bool UpdateEntityACL(USpatialActorChannel* Channel, bool bNetOwned) const override;

	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::testmulticastrpc::TestMulticastRPCSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::testmulticastrpc::TestMulticastRPCMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::testmulticastrpc::TestMulticastRPCHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_TestMulticastRPC::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testmulticastrpc::TestMulticastRPCSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testmulticastrpc::TestMulticastRPCMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testmulticastrpc::TestMulticastRPCHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testmulticastrpc::TestMulticastRPCSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testmulticastrpc::TestMulticastRPCMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testmulticastrpc::TestMulticastRPCHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testmulticastrpc::TestMulticastRPCNetMulticastRPCs::Update& Update);

	// RPC command sender functions.
	void Server_ReportMulticastResult_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);
	void MulticastRPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void Server_ReportMulticastResult_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::testmulticastrpc::TestMulticastRPCServerRPCs::Commands::Serverreportmulticastresult>& Op);
	void MulticastRPC_OnRPCPayload(const worker::EntityId EntityId, const improbable::unreal::generated::testmulticastrpc::MulticastRPCRequest& EventData);

	// RPC command response handler functions.
	void Server_ReportMulticastResult_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::testmulticastrpc::TestMulticastRPCServerRPCs::Commands::Serverreportmulticastresult>& Op);
};
