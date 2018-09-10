// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealTestComponent.h>
#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_TestComponent.generated.h"

UCLASS()
class USpatialTypeBinding_TestComponent : public USpatialTypeBinding
{
	GENERATED_BODY()

public:
	const FRepHandlePropertyMap& GetRepHandlePropertyMap() const override;
	const FHandoverHandlePropertyMap& GetHandoverHandlePropertyMap() const override;
	UClass* GetBoundClass() const override;

	void Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap) override;
	void BindToView(bool bIsClient) override;
	void UnbindFromView() override;

	worker::Entity CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* ActorChannel) const override;
	void SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* ActorChannel, const FEntityId& EntityId) const override;
	void SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters) override;

	void ReceiveAddComponent(USpatialActorChannel* ActorChannel, UAddComponentOpWrapperBase* AddComponentOp) const override;
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* ActorChannel,
		improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_TestComponent::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, const uint8* RESTRICT SourceData, int32 Handle, UProperty* Property, USpatialActorChannel* ActorChannel, improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, const uint8* RESTRICT SourceData, int32 Handle, UProperty* Property, USpatialActorChannel* ActorChannel, improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, const uint8* RESTRICT SourceData, int32 Handle, UProperty* Property, USpatialActorChannel* ActorChannel, improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs::Update& Update);

	// RPC command sender functions.

	// RPC command request handler functions.

	// RPC command response handler functions.
};
