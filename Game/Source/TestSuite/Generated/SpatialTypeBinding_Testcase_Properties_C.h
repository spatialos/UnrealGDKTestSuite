// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically
#pragma once

#include "CoreMinimal.h"
#include <improbable/worker.h>
#include <improbable/view.h>
#include <improbable/unreal/gdk/core_types.h>
#include <improbable/unreal/gdk/unreal_metadata.h>
#include <improbable/unreal/generated/UnrealTestcasePropertiesC.h>

#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "TestSuiteCharacter.h"

#include "ScopedViewCallbacks.h"
#include "SpatialTypeBinding.h"
#include "SpatialTypeBinding_Testcase_Properties_C.generated.h"

UCLASS()
class USpatialTypeBinding_Testcase_Properties_C : public USpatialTypeBinding
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
	worker::Map<worker::ComponentId, worker::InterestOverride> GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const override;

	void BuildSpatialComponentUpdate(
		const FPropertyChangeState& Changes,
		USpatialActorChannel* Channel,
		improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCSingleClientRepData::Update& SingleClientUpdate,
		bool& bSingleClientUpdateChanged,
		improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCMultiClientRepData::Update& MultiClientUpdate,
		bool& bMultiClientUpdateChanged,
		improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCHandoverData::Update& HandoverDataUpdate,
		bool& bHandoverDataUpdateChanged) const;

private:
	improbable::unreal::callbacks::FScopedViewCallbacks ViewCallbacks;

	// RPC to sender map.
	using FRPCSender = void (USpatialTypeBinding_Testcase_Properties_C::*)(worker::Connection* const, void*, UObject*);
	TMap<FName, FRPCSender> RPCToSenderMap;

	FRepHandlePropertyMap RepHandleToPropertyMap;
	FHandoverHandlePropertyMap HandoverHandleToPropertyMap;

	void ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCSingleClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCMultiClientRepData::Update& OutUpdate) const;
	void ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCHandoverData::Update& OutUpdate) const;
	void ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCSingleClientRepData::Update& Update) const;
	void ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCMultiClientRepData::Update& Update) const;
	void ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCHandoverData::Update& Update) const;
	void ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testcasepropertiesc::TestcasePropertiesCNetMulticastRPCs::Update& Update);

	// RPC command sender functions.

	// RPC command request handler functions.

	// RPC command response handler functions.

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
