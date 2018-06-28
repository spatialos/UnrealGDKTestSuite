// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_TestNestedStructs.h"

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
#include "TestNestedStructs.h"

#include "TestNestedStructsSingleClientRepDataAddComponentOp.h"
#include "TestNestedStructsMultiClientRepDataAddComponentOp.h"
#include "TestNestedStructsMigratableDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_TestNestedStructs::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FMigratableHandlePropertyMap& USpatialTypeBinding_TestNestedStructs::GetMigratableHandlePropertyMap() const
{
	return MigratableHandleToPropertyMap;
}

UClass* USpatialTypeBinding_TestNestedStructs::GetBoundClass() const
{
	return UTestNestedStructs::StaticClass();
}

void USpatialTypeBinding_TestNestedStructs::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("DoTheThingCStyleArray", &USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_SendRPC);
	RPCToSenderMap.Emplace("DoTheThing", &USpatialTypeBinding_TestNestedStructs::DoTheThing_SendRPC);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("TestNestedStructs"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(20, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(21, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(22, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(23, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(24, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(25, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(26, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(27, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(28, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(29, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(30, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "String_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(31, FRepHandleData(Class, {"TestContainerStruct", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(32, FRepHandleData(Class, {"TestContainerStruct", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(33, FRepHandleData(Class, {"TestContainerStruct", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
}

void USpatialTypeBinding_TestNestedStructs::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Migratable(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));

	using ServerRPCCommandTypes = improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Dothethingcstylearray>(std::bind(&USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandRequest<ServerRPCCommandTypes::Dothething>(std::bind(&USpatialTypeBinding_TestNestedStructs::DoTheThing_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Dothethingcstylearray>(std::bind(&USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_OnCommandResponse, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ServerRPCCommandTypes::Dothething>(std::bind(&USpatialTypeBinding_TestNestedStructs::DoTheThing_OnCommandResponse, this, std::placeholders::_1)));
}

void USpatialTypeBinding_TestNestedStructs::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_TestNestedStructs::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.
	improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Data SingleClientData;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Data MultiClientData;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Data MigratableData;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update MigratableDataUpdate;
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
		.SetReadAcl(AnyUnrealWorkerOrClient)
		.AddComponent<improbable::unreal::UnrealMetadata>(UnrealMetadata, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData>(SingleClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData>(MultiClientData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData>(MigratableData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsClientRPCs>(improbable::unreal::generated::testnestedstructs::TestNestedStructsClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs>(improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs>(improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_TestNestedStructs::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update MigratableDataUpdate;
	bool bMigratableDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, MigratableDataUpdate, bMigratableDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bMigratableDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData>(EntityId.ToSpatialEntityId(), MigratableDataUpdate);
	}
}

void USpatialTypeBinding_TestNestedStructs::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
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

void USpatialTypeBinding_TestNestedStructs::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UTestNestedStructsSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
	}
	auto* MultiClientAddOp = Cast<UTestNestedStructsMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
	}
	auto* MigratableDataAddOp = Cast<UTestNestedStructsMigratableDataAddComponentOp>(AddComponentOp);
	if (MigratableDataAddOp)
	{
		auto Update = improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update::FromInitialData(*MigratableDataAddOp->Data.data());
		ReceiveUpdate_Migratable(Channel, Update);
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_TestNestedStructs::GetInterestOverrideMap(bool bIsClient, bool bAutonomousProxy) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		if (!bAutonomousProxy)
		{
			Interest.emplace(improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::ComponentId, worker::InterestOverride{false});
		}
		Interest.emplace(improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

void USpatialTypeBinding_TestNestedStructs::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update& MigratableDataUpdate,
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

void USpatialTypeBinding_TestNestedStructs::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_TestNestedStructs::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_testcontainerstruct0_structred0_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structred0_rootprop0(int32_t(Value));
			break;
		}
		case 2: // field_testcontainerstruct0_structred0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structred0_rootarray0(int32_t(Value));
			break;
		}
		case 3: // field_testcontainerstruct0_structred0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structred0_rootarray1(int32_t(Value));
			break;
		}
		case 4: // field_testcontainerstruct0_structred0_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structred0_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 5: // field_testcontainerstruct0_structred0_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structred0_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 6: // field_testcontainerstruct0_structblue0_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structblue0_rootprop0(int32_t(Value));
			break;
		}
		case 7: // field_testcontainerstruct0_structblue0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structblue0_rootarray0(int32_t(Value));
			break;
		}
		case 8: // field_testcontainerstruct0_structblue0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structblue0_rootarray1(int32_t(Value));
			break;
		}
		case 9: // field_testcontainerstruct0_structblue0_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structblue0_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 10: // field_testcontainerstruct0_structblue0_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structblue0_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 11: // field_testcontainerstruct0_structarray0_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray0_rootprop0(int32_t(Value));
			break;
		}
		case 12: // field_testcontainerstruct0_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 13: // field_testcontainerstruct0_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 14: // field_testcontainerstruct0_structarray0_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray0_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 15: // field_testcontainerstruct0_structarray0_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray0_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 16: // field_testcontainerstruct0_structarray1_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray1_rootprop0(int32_t(Value));
			break;
		}
		case 17: // field_testcontainerstruct0_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 18: // field_testcontainerstruct0_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 19: // field_testcontainerstruct0_structarray1_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray1_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 20: // field_testcontainerstruct0_structarray1_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarray1_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 21: // field_testcontainerstruct0_structarrayanother0_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother0_rootprop0(int32_t(Value));
			break;
		}
		case 22: // field_testcontainerstruct0_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 23: // field_testcontainerstruct0_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 24: // field_testcontainerstruct0_structarrayanother0_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother0_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 25: // field_testcontainerstruct0_structarrayanother0_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother0_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 26: // field_testcontainerstruct0_structarrayanother1_rootprop0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother1_rootprop0(int32_t(Value));
			break;
		}
		case 27: // field_testcontainerstruct0_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 28: // field_testcontainerstruct0_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 29: // field_testcontainerstruct0_structarrayanother1_stringarray0
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother1_stringarray0(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 30: // field_testcontainerstruct0_structarrayanother1_stringarray1
		{
			FString Value = *(reinterpret_cast<FString const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_structarrayanother1_stringarray1(TCHAR_TO_UTF8(*Value));
			break;
		}
		case 31: // field_testcontainerstruct0_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_containerintarray0(int32_t(Value));
			break;
		}
		case 32: // field_testcontainerstruct0_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct0_containerintarray1(int32_t(Value));
			break;
		}
		case 33: // field_testcontainerstruct0_dynamicstructarray0
		{
			const TArray<FRootStruct>& Value = *(reinterpret_cast<TArray<FRootStruct> const*>(Data));

			::worker::List<std::string> List;
			for(int i = 0; i < Value.Num(); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FRootStruct::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FRootStruct*>(&Value[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			OutUpdate.set_field_testcontainerstruct0_dynamicstructarray0(List);
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_TestNestedStructs::ServerSendUpdate_Migratable(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_TestNestedStructs::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testnestedstructs::TestNestedStructsSingleClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TArray<UProperty*> RepNotifies;
	Interop->PostReceiveSpatialUpdate(ActorChannel, RepNotifies);
}

void USpatialTypeBinding_TestNestedStructs::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testnestedstructs::TestNestedStructsMultiClientRepData::Update& Update) const
{
	Interop->PreReceiveSpatialUpdate(ActorChannel);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::testnestedstructs::TestNestedStructsClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_testcontainerstruct0_structred0_rootprop0().empty())
	{
		// field_testcontainerstruct0_structred0_rootprop0
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structred0_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structred0_rootarray0().empty())
	{
		// field_testcontainerstruct0_structred0_rootarray0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structred0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structred0_rootarray1().empty())
	{
		// field_testcontainerstruct0_structred0_rootarray1
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structred0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structred0_stringarray0().empty())
	{
		// field_testcontainerstruct0_structred0_stringarray0
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structred0_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structred0_stringarray1().empty())
	{
		// field_testcontainerstruct0_structred0_stringarray1
		uint16 Handle = 5;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structred0_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structblue0_rootprop0().empty())
	{
		// field_testcontainerstruct0_structblue0_rootprop0
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structblue0_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structblue0_rootarray0().empty())
	{
		// field_testcontainerstruct0_structblue0_rootarray0
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structblue0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structblue0_rootarray1().empty())
	{
		// field_testcontainerstruct0_structblue0_rootarray1
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structblue0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structblue0_stringarray0().empty())
	{
		// field_testcontainerstruct0_structblue0_stringarray0
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structblue0_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structblue0_stringarray1().empty())
	{
		// field_testcontainerstruct0_structblue0_stringarray1
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structblue0_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray0_rootprop0().empty())
	{
		// field_testcontainerstruct0_structarray0_rootprop0
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray0_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray0_rootarray0().empty())
	{
		// field_testcontainerstruct0_structarray0_rootarray0
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray0_rootarray1().empty())
	{
		// field_testcontainerstruct0_structarray0_rootarray1
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray0_stringarray0().empty())
	{
		// field_testcontainerstruct0_structarray0_stringarray0
		uint16 Handle = 14;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarray0_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray0_stringarray1().empty())
	{
		// field_testcontainerstruct0_structarray0_stringarray1
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarray0_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray1_rootprop0().empty())
	{
		// field_testcontainerstruct0_structarray1_rootprop0
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray1_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray1_rootarray0().empty())
	{
		// field_testcontainerstruct0_structarray1_rootarray0
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray1_rootarray1().empty())
	{
		// field_testcontainerstruct0_structarray1_rootarray1
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray1_stringarray0().empty())
	{
		// field_testcontainerstruct0_structarray1_stringarray0
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarray1_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarray1_stringarray1().empty())
	{
		// field_testcontainerstruct0_structarray1_stringarray1
		uint16 Handle = 20;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarray1_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother0_rootprop0().empty())
	{
		// field_testcontainerstruct0_structarrayanother0_rootprop0
		uint16 Handle = 21;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother0_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainerstruct0_structarrayanother0_rootarray0
		uint16 Handle = 22;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainerstruct0_structarrayanother0_rootarray1
		uint16 Handle = 23;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother0_stringarray0().empty())
	{
		// field_testcontainerstruct0_structarrayanother0_stringarray0
		uint16 Handle = 24;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarrayanother0_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother0_stringarray1().empty())
	{
		// field_testcontainerstruct0_structarrayanother0_stringarray1
		uint16 Handle = 25;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarrayanother0_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother1_rootprop0().empty())
	{
		// field_testcontainerstruct0_structarrayanother1_rootprop0
		uint16 Handle = 26;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother1_rootprop0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainerstruct0_structarrayanother1_rootarray0
		uint16 Handle = 27;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainerstruct0_structarrayanother1_rootarray1
		uint16 Handle = 28;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother1_stringarray0().empty())
	{
		// field_testcontainerstruct0_structarrayanother1_stringarray0
		uint16 Handle = 29;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarrayanother1_stringarray0().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_structarrayanother1_stringarray1().empty())
	{
		// field_testcontainerstruct0_structarrayanother1_stringarray1
		uint16 Handle = 30;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			FString Value = *(reinterpret_cast<FString const*>(PropertyData));

			Value = FString(UTF8_TO_TCHAR((*Update.field_testcontainerstruct0_structarrayanother1_stringarray1().data()).c_str()));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_containerintarray0().empty())
	{
		// field_testcontainerstruct0_containerintarray0
		uint16 Handle = 31;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_containerintarray1().empty())
	{
		// field_testcontainerstruct0_containerintarray1
		uint16 Handle = 32;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct0_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct0_dynamicstructarray0().empty())
	{
		// field_testcontainerstruct0_dynamicstructarray0
		uint16 Handle = 33;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainerstruct0_dynamicstructarray0().data());
				Value.SetNum(List.size());
				for(int i = 0; i < List.size(); i++)
				{
					auto& ValueDataStr = List[i];
					TArray<uint8> ValueData;
					ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
					FMemoryReader ValueDataReader(ValueData);
					FRootStruct::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Value[i]));
				}
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

void USpatialTypeBinding_TestNestedStructs::ReceiveUpdate_Migratable(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testnestedstructs::TestNestedStructsMigratableData::Update& Update) const
{
}

void USpatialTypeBinding_TestNestedStructs::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testnestedstructs::TestNestedStructsNetMulticastRPCs::Update& Update)
{
}
void USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in TestNestedStructs.generated.h (in a macro that is then put in TestNestedStructs.h UCLASS macro)
	TestNestedStructs_eventDoTheThingCStyleArray_Parms StructuredParams = *static_cast<TestNestedStructs_eventDoTheThingCStyleArray_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC DoTheThingCStyleArray queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::testnestedstructs::DoTheThingCStyleArrayRequest RPCPayload;
		RPCPayload.set_field_printme0(TCHAR_TO_UTF8(*StructuredParams.PrintMe));
		RPCPayload.set_field_theteststructcstylearrayrpc0_nonserializedint0(int32_t(StructuredParams.TheTestStructCStyleArrayRPC.NonSerializedInt));
		RPCPayload.set_field_theteststructcstylearrayrpc0_testint0(int32_t(StructuredParams.TheTestStructCStyleArrayRPC.TestInt));
		{
			::worker::List<std::int32_t> List;
			for(int i = 0; i < sizeof(StructuredParams.TheTestStructCStyleArrayRPC.TestIntArray) / sizeof(StructuredParams.TheTestStructCStyleArrayRPC.TestIntArray[0]); i++)
			{
				List.emplace_back(int32_t(StructuredParams.TheTestStructCStyleArrayRPC.TestIntArray[i]));
			}
			RPCPayload.set_field_theteststructcstylearrayrpc0_testintarray0(List);
		}
		{
			::worker::List<std::string> List;
			for(int i = 0; i < sizeof(StructuredParams.TheTestStructCStyleArrayRPC.NetSerializeStruct) / sizeof(StructuredParams.TheTestStructCStyleArrayRPC.NetSerializeStruct[0]); i++)
			{
				{
					TArray<uint8> ValueData;
					FMemoryWriter ValueDataWriter(ValueData);
					bool bSuccess = true;
					(const_cast<FTestStruct&>(StructuredParams.TheTestStructCStyleArrayRPC.NetSerializeStruct[i])).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
					checkf(bSuccess, TEXT("NetSerialize on FTestStruct failed."));
					List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
				}
			}
			RPCPayload.set_field_theteststructcstylearrayrpc0_netserializestruct0(List);
		}
		{
			::worker::List<std::string> List;
			for(int i = 0; i < sizeof(StructuredParams.TheTestStructCStyleArrayRPC.NoNetSerializeStruct) / sizeof(StructuredParams.TheTestStructCStyleArrayRPC.NoNetSerializeStruct[0]); i++)
			{
				TArray<uint8> ValueData;
				FMemoryWriter ValueDataWriter(ValueData);
				FTestStructNoNetSerialize::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FTestStructNoNetSerialize*>(&StructuredParams.TheTestStructCStyleArrayRPC.NoNetSerializeStruct[i])));
				List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			}
			RPCPayload.set_field_theteststructcstylearrayrpc0_nonetserializestruct0(List);
		}
		::worker::List<std::string> List;
		for(int i = 0; i < StructuredParams.DynamicStructArrayRPC.Num(); i++)
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			FTestStructCStyleArray::StaticStruct()->SerializeBin(ValueDataWriter, reinterpret_cast<void*>(const_cast<FTestStructCStyleArray*>(&StructuredParams.DynamicStructArrayRPC[i])));
			List.emplace_back(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		RPCPayload.set_field_dynamicstructarrayrpc0(List);

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: DoTheThingCStyleArray, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothethingcstylearray>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_TestNestedStructs::DoTheThing_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	// This struct is declared in TestNestedStructs.generated.h (in a macro that is then put in TestNestedStructs.h UCLASS macro)
	TestNestedStructs_eventDoTheThing_Parms StructuredParams = *static_cast<TestNestedStructs_eventDoTheThing_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: RPC DoTheThing queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::testnestedstructs::DoTheThingRequest RPCPayload;
		RPCPayload.set_field_printme0(TCHAR_TO_UTF8(*StructuredParams.PrintMe));
		{
			TArray<uint8> ValueData;
			FMemoryWriter ValueDataWriter(ValueData);
			bool bSuccess = true;
			(const_cast<FTestStruct&>(StructuredParams.TheTestStructRPC)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FTestStruct failed."));
			RPCPayload.set_field_theteststructrpc0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Sending RPC: DoTheThing, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothething>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ true);
}
void USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothethingcstylearray>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: DoTheThingCStyleArray_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: DoTheThingCStyleArray_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in TestNestedStructs.generated.h (in a macro that is then put in TestNestedStructs.h UCLASS macro)
		TestNestedStructs_eventDoTheThingCStyleArray_Parms Parameters;

		// Extract from request data.
		Parameters.PrintMe = FString(UTF8_TO_TCHAR(Op.Request.field_printme0().c_str()));
		Parameters.TheTestStructCStyleArrayRPC.NonSerializedInt = Op.Request.field_theteststructcstylearrayrpc0_nonserializedint0();
		Parameters.TheTestStructCStyleArrayRPC.TestInt = Op.Request.field_theteststructcstylearrayrpc0_testint0();
		{
			auto& List = Op.Request.field_theteststructcstylearrayrpc0_testintarray0();
			for(int i = 0; i < List.size(); i++)
			{
				Parameters.TheTestStructCStyleArrayRPC.TestIntArray[i] = List[i];
			}
		}
		{
			auto& List = Op.Request.field_theteststructcstylearrayrpc0_netserializestruct0();
			for(int i = 0; i < List.size(); i++)
			{
				{
					auto& ValueDataStr = List[i];
					TArray<uint8> ValueData;
					ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
					FMemoryReader ValueDataReader(ValueData);
					bool bSuccess = true;
					Parameters.TheTestStructCStyleArrayRPC.NetSerializeStruct[i].NetSerialize(ValueDataReader, PackageMap, bSuccess);
					checkf(bSuccess, TEXT("NetSerialize on FTestStruct failed."));
				}
			}
		}
		{
			auto& List = Op.Request.field_theteststructcstylearrayrpc0_nonetserializestruct0();
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FTestStructNoNetSerialize::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.TheTestStructCStyleArrayRPC.NoNetSerializeStruct[i]));
			}
		}
		{
			auto& List = Op.Request.field_dynamicstructarrayrpc0();
			Parameters.DynamicStructArrayRPC.SetNum(List.size());
			for(int i = 0; i < List.size(); i++)
			{
				auto& ValueDataStr = List[i];
				TArray<uint8> ValueData;
				ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
				FMemoryReader ValueDataReader(ValueData);
				FTestStructCStyleArray::StaticStruct()->SerializeBin(ValueDataReader, reinterpret_cast<void*>(&Parameters.DynamicStructArrayRPC[i]));
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: DoTheThingCStyleArray, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("DoTheThingCStyleArray"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: DoTheThingCStyleArray_OnRPCPayload: Function not found. Object: %s, Function: DoTheThingCStyleArray."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothethingcstylearray>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}
void USpatialTypeBinding_TestNestedStructs::DoTheThing_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothething>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialOSInterop, Log, TEXT("%s: DoTheThing_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: DoTheThing_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		// This struct is declared in TestNestedStructs.generated.h (in a macro that is then put in TestNestedStructs.h UCLASS macro)
		TestNestedStructs_eventDoTheThing_Parms Parameters;

		// Extract from request data.
		Parameters.PrintMe = FString(UTF8_TO_TCHAR(Op.Request.field_printme0().c_str()));
		{
			auto& ValueDataStr = Op.Request.field_theteststructrpc0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FMemoryReader ValueDataReader(ValueData);
			bool bSuccess = true;
			Parameters.TheTestStructRPC.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FTestStruct failed."));
		}

		// Call implementation.
		UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received RPC: DoTheThing, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("DoTheThing"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialOSInterop, Error, TEXT("%s: DoTheThing_OnRPCPayload: Function not found. Object: %s, Function: DoTheThing."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothething>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}

void USpatialTypeBinding_TestNestedStructs::DoTheThingCStyleArray_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothethingcstylearray>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("DoTheThingCStyleArray"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}

void USpatialTypeBinding_TestNestedStructs::DoTheThing_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::testnestedstructs::TestNestedStructsServerRPCs::Commands::Dothething>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("DoTheThing"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}
