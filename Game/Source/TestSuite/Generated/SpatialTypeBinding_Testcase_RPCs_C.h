// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealTestcaseRPCsC.h>

#include "Components/SceneComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "GameFramework/Pawn.h"
#include "TestSuiteCharacter.h"

#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_Testcase_RPCs_C.generated.h"

UCLASS()
class USpatialTypeBinding_Testcase_RPCs_C : public USpatialTypeBinding
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
		improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_Testcase_RPCs_C::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs::Update& Update);

	// RPC command sender functions.
	void Test_RPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject);

	// RPC command request handler functions.
	void Test_RPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>& Op);

	// RPC command response handler functions.
	void Test_RPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>& Op);

	enum Testcase_enum
	{
		NewEnumerator0,
		Testcase_MAX,
	};

	struct FTestcase_Struct_with_BP_Actor__pf3877032745
	{
		bool Test_bool_1_5C1B5D454F54993B19D77FB6B2EF91CB;
		FVector Test_struct_4_0F09344D4EF4517FD0409DA7F7B80E9B;
		TEnumAsByte<Testcase_enum> Test_enum_7_DBCADACD42BCCAD755CAB5A2E92AFE32;
		ACharacter* Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090;
	};

	UPROPERTY()
	UStruct* FTestcase_Struct_with_BP_Actor__pf3877032745_Struct;

	struct FTestcase_Struct_with_BP_Struct__pf3877032745
	{
		FTestcase_Struct_with_BP_Actor__pf3877032745 InternalStruct_3_C866974D477750E22E863D91BA350AA8;
	};

	UPROPERTY()
	UStruct* FTestcase_Struct_with_BP_Struct__pf3877032745_Struct;
};
