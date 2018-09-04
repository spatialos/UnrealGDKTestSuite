// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_Testcase_RPCs_C.h"

#include "NetworkGuid.h"

#include "SpatialOS.h"
#include "EntityBuilder.h"

#include "SpatialConstants.h"
#include "SpatialConditionMapFilter.h"
#include "SpatialUnrealObjectRef.h"
#include "SpatialActorChannel.h"
#include "SpatialPackageMapClient.h"
#include "SpatialMemoryReader.h"
#include "SpatialMemoryWriter.h"
#include "SpatialNetDriver.h"
#include "SpatialInterop.h"

#include "TestcaseRPCsCSingleClientRepDataAddComponentOp.h"
#include "TestcaseRPCsCMultiClientRepDataAddComponentOp.h"
#include "TestcaseRPCsCHandoverDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_Testcase_RPCs_C::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FHandoverHandlePropertyMap& USpatialTypeBinding_Testcase_RPCs_C::GetHandoverHandlePropertyMap() const
{
	return HandoverHandleToPropertyMap;
}

UClass* USpatialTypeBinding_Testcase_RPCs_C::GetBoundClass() const
{
	return LoadObject<UClass>(nullptr, TEXT("/Game/EntityBlueprints/Testcase_RPCs.Testcase_RPCs_C"), nullptr, LOAD_None, nullptr);
}

void USpatialTypeBinding_Testcase_RPCs_C::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);

	RPCToSenderMap.Emplace("Test_RPC", &USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_SendRPC);

	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("Testcase_RPCs_C"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bHidden"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bReplicateMovement"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"bTearOff"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"bCanBeDamaged"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"RemoteRole"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"ReplicatedMovement"}, {0}, COND_SimulatedOrPhysics, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"AttachmentReplication", "AttachParent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"AttachmentReplication", "LocationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"AttachmentReplication", "RelativeScale3D"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"AttachmentReplication", "RotationOffset"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"AttachmentReplication", "AttachSocket"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"AttachmentReplication", "AttachComponent"}, {0, 0}, COND_Custom, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"Owner"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"Role"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"Instigator"}, {0}, COND_None, REPNOTIFY_OnChanged));

	FTestcase_Struct_with_BP_Actor__pf3877032745_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/EntityBlueprints/Testcase_Struct_with_BP_Actor.Testcase_Struct_with_BP_Actor"), NULL, LOAD_None, NULL);
	FTestcase_Struct_with_BP_Struct__pf3877032745_Struct = LoadObject<UStruct>(NULL, TEXT("/Game/EntityBlueprints/Testcase_Struct_with_BP_Struct.Testcase_Struct_with_BP_Struct"), NULL, LOAD_None, NULL);
}

void USpatialTypeBinding_Testcase_RPCs_C::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Handover(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));

	using ClientRPCCommandTypes = improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands;
	ViewCallbacks.Add(View->OnCommandRequest<ClientRPCCommandTypes::Testrpc>(std::bind(&USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_OnRPCPayload, this, std::placeholders::_1)));
	ViewCallbacks.Add(View->OnCommandResponse<ClientRPCCommandTypes::Testrpc>(std::bind(&USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_OnCommandResponse, this, std::placeholders::_1)));
}

void USpatialTypeBinding_Testcase_RPCs_C::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_Testcase_RPCs_C::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.

	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Data SingleClientTestcase_RPCs_CData;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update SingleClientTestcase_RPCs_CUpdate;
	bool bSingleClientTestcase_RPCs_CUpdateChanged = false;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Data MultiClientTestcase_RPCs_CData;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update MultiClientTestcase_RPCs_CUpdate;
	bool bMultiClientTestcase_RPCs_CUpdateChanged = false;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Data Testcase_RPCs_CHandoverData;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update Testcase_RPCs_CHandoverDataUpdate;
	bool bTestcase_RPCs_CHandoverDataUpdateChanged = false;

	BuildSpatialComponentUpdate(InitialChanges, Channel, SingleClientTestcase_RPCs_CUpdate, bSingleClientTestcase_RPCs_CUpdateChanged, MultiClientTestcase_RPCs_CUpdate, bMultiClientTestcase_RPCs_CUpdateChanged, Testcase_RPCs_CHandoverDataUpdate, bTestcase_RPCs_CHandoverDataUpdateChanged);
	SingleClientTestcase_RPCs_CUpdate.ApplyTo(SingleClientTestcase_RPCs_CData);
	MultiClientTestcase_RPCs_CUpdate.ApplyTo(MultiClientTestcase_RPCs_CData);
	Testcase_RPCs_CHandoverDataUpdate.ApplyTo(Testcase_RPCs_CHandoverData);

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
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData>(SingleClientTestcase_RPCs_CData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData>(MultiClientTestcase_RPCs_CData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData>(Testcase_RPCs_CHandoverData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs>(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCServerRPCs>(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCCrossServerRPCs>(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCCrossServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs>(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_Testcase_RPCs_C::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update HandoverDataUpdate;
	bool bHandoverDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, HandoverDataUpdate, bHandoverDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bHandoverDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData>(EntityId.ToSpatialEntityId(), HandoverDataUpdate);
	}
}

void USpatialTypeBinding_Testcase_RPCs_C::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
{
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	auto SenderFuncIterator = RPCToSenderMap.Find(Function->GetFName());
	if (SenderFuncIterator == nullptr)
	{
		UE_LOG(LogSpatialGDKInterop, Error, TEXT("Sender for %s has not been registered with RPCToSenderMap."), *Function->GetFName().ToString());
		return;
	}
	checkf(*SenderFuncIterator, TEXT("Sender for %s has been registered as null."), *Function->GetFName().ToString());
	(this->*(*SenderFuncIterator))(Connection.Get(), Parameters, TargetObject);
}

void USpatialTypeBinding_Testcase_RPCs_C::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UTestcaseRPCsCSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
		return;
	}
	auto* MultiClientAddOp = Cast<UTestcaseRPCsCMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
		return;
	}
	auto* HandoverDataAddOp = Cast<UTestcaseRPCsCHandoverDataAddComponentOp>(AddComponentOp);
	if (HandoverDataAddOp)
	{
		auto Update = improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update::FromInitialData(*HandoverDataAddOp->Data.data());
		ReceiveUpdate_Handover(Channel, Update);
		return;
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_Testcase_RPCs_C::GetInterestOverrideMap(bool bIsClient, bool bNetOwned) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		Interest.emplace(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::ComponentId, worker::InterestOverride{bNetOwned});
		Interest.emplace(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

bool USpatialTypeBinding_Testcase_RPCs_C::UpdateEntityACL(USpatialActorChannel* Channel, bool bNetOwned) const
{
	TSharedPtr<worker::Connection> PinnedConnection = Interop->GetSpatialOS()->GetConnection().Pin();
	TSharedPtr<worker::View> PinnedView = Interop->GetSpatialOS()->GetView().Pin();
	worker::EntityId Id = Channel->GetEntityId().ToSpatialEntityId();

	if (PinnedConnection.IsValid() && PinnedView.IsValid())
	{
		worker::Option<improbable::EntityAcl::Data &> Data = PinnedView->Entities[Id].Get<improbable::EntityAcl>();
		if (Data.empty())
		{
			return false;
		}
		worker::Map<uint32_t, improbable::WorkerRequirementSet> WriteACL = Data->component_write_acl();

		std::string PlayerWorkerId;
		if (bNetOwned)
		{
			PlayerWorkerId = TCHAR_TO_UTF8(*Channel->Connection->PlayerController->PlayerState->UniqueId.ToString());
		}

		improbable::WorkerAttributeSet OwningClientAttribute{ { "workerId:" + PlayerWorkerId } };
		improbable::WorkerRequirementSet OwningClientOnly{ { OwningClientAttribute } };

		WriteACL[improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::ComponentId] = OwningClientOnly;

		improbable::EntityAcl::Update Update;
		Update.set_component_write_acl(WriteACL);
		PinnedConnection->SendComponentUpdate<improbable::EntityAcl>(Id, Update);
		return true;
	}

	return false;
}

void USpatialTypeBinding_Testcase_RPCs_C::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& HandoverDataUpdate,
	bool& bHandoverDataUpdateChanged) const
{
	const FRepHandlePropertyMap& RepPropertyMap = GetRepHandlePropertyMap();
	const FHandoverHandlePropertyMap& HandoverPropertyMap = GetHandoverHandlePropertyMap();
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
			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending property update. actor %s (%lld), property %s (handle %d)"),
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

	// Populate the handover data component update from the handover property changelist.
	for (uint16 ChangedHandle : Changes.HandoverChanged)
	{
		const FHandoverHandleData& PropertyMapData = HandoverPropertyMap[ChangedHandle];
		const uint8* Data = PropertyMapData.GetPropertyData(Changes.SourceData);
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending handover property update. actor %s (%lld), property %s (handle %d)"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*Channel->Actor->GetName(),
			Channel->GetEntityId().ToSpatialEntityId(),
			*PropertyMapData.Property->GetName(),
			ChangedHandle);
		ServerSendUpdate_Handover(Data, ChangedHandle, PropertyMapData.Property, Channel, HandoverDataUpdate);
		bHandoverDataUpdateChanged = true;
	}
}

void USpatialTypeBinding_Testcase_RPCs_C::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_Testcase_RPCs_C::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_bhidden0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bhidden0(Value);
			break;
		}
		case 2: // field_breplicatemovement0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicatemovement0(Value);
			break;
		}
		case 3: // field_btearoff0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_btearoff0(Value);
			break;
		}
		case 4: // field_bcanbedamaged0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bcanbedamaged0(Value);
			break;
		}
		case 5: // field_remoterole0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_remoterole0(uint32_t(Value));
			break;
		}
		case 6: // field_replicatedmovement0
		{
			const FRepMovement& Value = *(reinterpret_cast<FRepMovement const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 6);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRepMovement&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_replicatedmovement0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 6);
			}
			break;
		}
		case 7: // field_attachmentreplication0_attachparent0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 7);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachparent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachparent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 8: // field_attachmentreplication0_locationoffset0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 8);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_locationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 8);
			}
			break;
		}
		case 9: // field_attachmentreplication0_relativescale3d0
		{
			const FVector_NetQuantize100& Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 9);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector_NetQuantize100&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_relativescale3d0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 9);
			}
			break;
		}
		case 10: // field_attachmentreplication0_rotationoffset0
		{
			const FRotator& Value = *(reinterpret_cast<FRotator const*>(Data));

			Interop->ResetOutgoingArrayRepUpdate_Internal(Channel, 10);
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FRotator&>(Value)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));
			const std::string& Result = (std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
			if (UnresolvedObjects.Num() == 0)
			{
				OutUpdate.set_field_attachmentreplication0_rotationoffset0(Result);
			}
			else
			{
				Interop->QueueOutgoingArrayRepUpdate_Internal(UnresolvedObjects, Channel, 10);
			}
			break;
		}
		case 11: // field_attachmentreplication0_attachsocket0
		{
			FName Value = *(reinterpret_cast<FName const*>(Data));

			OutUpdate.set_field_attachmentreplication0_attachsocket0(TCHAR_TO_UTF8(*Value.ToString()));
			break;
		}
		case 12: // field_attachmentreplication0_attachcomponent0
		{
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 12);
				}
				else
				{
					OutUpdate.set_field_attachmentreplication0_attachcomponent0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_attachmentreplication0_attachcomponent0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 13: // field_owner0
		{
			AActor* Value = *(reinterpret_cast<AActor* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 13);
				}
				else
				{
					OutUpdate.set_field_owner0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_owner0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
		case 14: // field_role0
		{
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(Data));

			OutUpdate.set_field_role0(uint32_t(Value));
			break;
		}
		case 15: // field_instigator0
		{
			APawn* Value = *(reinterpret_cast<APawn* const*>(Data));

			if (Value != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(Value);
				if (!NetGUID.IsValid())
				{
					if (Value->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(Value);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					// A legal static object reference should never be unresolved.
					check(!Value->IsFullNameStableForNetworking())
					Interop->QueueOutgoingObjectRepUpdate_Internal(Value, Channel, 15);
				}
				else
				{
					OutUpdate.set_field_instigator0(ObjectRef);
				}
			}
			else
			{
				OutUpdate.set_field_instigator0(SpatialConstants::NULL_OBJECT_REF);
			}
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_Testcase_RPCs_C::ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_Testcase_RPCs_C::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCSingleClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TArray<UProperty*> RepNotifies;
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies);
}

void USpatialTypeBinding_Testcase_RPCs_C::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCMultiClientRepData::Update& Update) const
{
	AActor* TargetObject = ActorChannel->Actor;
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_bhidden0().empty())
	{
		// field_bhidden0
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bhidden0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_breplicatemovement0().empty())
	{
		// field_breplicatemovement0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicatemovement0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_btearoff0().empty())
	{
		// field_btearoff0
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_btearoff0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bcanbedamaged0().empty())
	{
		// field_bcanbedamaged0
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bcanbedamaged0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_remoterole0().empty())
	{
		// field_remoterole0
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

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_remoterole0().data())));

			// Downgrade role from AutonomousProxy to SimulatedProxy if we aren't authoritative over
			// the server RPCs component.
			if (!bIsServer && Value == ROLE_AutonomousProxy && !bAutonomousProxy)
			{
				Value = ROLE_SimulatedProxy;
			}

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_replicatedmovement0().empty())
	{
		// field_replicatedmovement0
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRepMovement Value = *(reinterpret_cast<FRepMovement const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_replicatedmovement0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRepMovement failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachparent0().empty())
	{
		// field_attachmentreplication0_attachparent0
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachparent0().data());
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
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_attachmentreplication0_locationoffset0().empty())
	{
		// field_attachmentreplication0_locationoffset0
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_locationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_relativescale3d0().empty())
	{
		// field_attachmentreplication0_relativescale3d0
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FVector_NetQuantize100 Value = *(reinterpret_cast<FVector_NetQuantize100 const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_relativescale3d0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector_NetQuantize100 failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_rotationoffset0().empty())
	{
		// field_attachmentreplication0_rotationoffset0
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FRotator Value = *(reinterpret_cast<FRotator const*>(PropertyData));

			auto& ValueDataStr = (*Update.field_attachmentreplication0_rotationoffset0().data());
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Value.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FRotator failed."));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachsocket0().empty())
	{
		// field_attachmentreplication0_attachsocket0
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			FName Value = *(reinterpret_cast<FName const*>(PropertyData));

			Value = FName(((*Update.field_attachmentreplication0_attachsocket0().data())).data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_attachmentreplication0_attachcomponent0().empty())
	{
		// field_attachmentreplication0_attachcomponent0
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			USceneComponent* Value = *(reinterpret_cast<USceneComponent* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_attachmentreplication0_attachcomponent0().data());
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
					checkf(Cast<USceneComponent>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<USceneComponent>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_owner0().empty())
	{
		// field_owner0
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			AActor* Value = *(reinterpret_cast<AActor* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_owner0().data());
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
					checkf(Cast<AActor>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<AActor>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	if (!Update.field_role0().empty())
	{
		// field_role0
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

			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			TEnumAsByte<ENetRole> Value = *(reinterpret_cast<TEnumAsByte<ENetRole> const*>(PropertyData));

			Value = TEnumAsByte<ENetRole>(uint8((*Update.field_role0().data())));

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_instigator0().empty())
	{
		// field_instigator0
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			bool bWriteObjectProperty = true;
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			APawn* Value = *(reinterpret_cast<APawn* const*>(PropertyData));

			improbable::unreal::UnrealObjectRef ObjectRef = (*Update.field_instigator0().data());
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
					checkf(Cast<APawn>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Value = Cast<APawn>(Object_Raw);
				}
				else
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Received unresolved object property. Value: %s. actor %s (%lld), property %s (handle %d)"),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef),
						*ActorChannel->Actor->GetName(),
						ActorChannel->GetEntityId().ToSpatialEntityId(),
						*RepData->Property->GetName(),
						Handle);
					// A legal static object reference should never be unresolved.
					check(ObjectRef.path().empty());
					bWriteObjectProperty = false;
					Interop->QueueIncomingObjectRepUpdate_Internal(ObjectRef, ActorChannel, TargetObject, RepData);
				}
			}

			if (bWriteObjectProperty)
			{
				ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

				UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
					*Interop->GetSpatialOS()->GetWorkerId(),
					*ActorChannel->Actor->GetName(),
					ActorChannel->GetEntityId().ToSpatialEntityId(),
					*RepData->Property->GetName(),
					Handle);
			}
		}
	}
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies.Array());
}

void USpatialTypeBinding_Testcase_RPCs_C::ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCHandoverData::Update& Update) const
{
}

void USpatialTypeBinding_Testcase_RPCs_C::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCNetMulticastRPCs::Update& Update)
{
}
void USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_SendRPC(worker::Connection* const Connection, void* Parameters, UObject* TargetObject)
{
	struct Testcase_RPCs_C_eventTest_RPC_Parms
	{
		TEnumAsByte<Testcase_enum> Enum;
		ATestSuiteCharacter* BP_Actor;
		FTestcase_Struct_with_BP_Struct__pf3877032745 BP_Struct;
	};

	Testcase_RPCs_C_eventTest_RPC_Parms StructuredParams = *static_cast<Testcase_RPCs_C_eventTest_RPC_Parms*>(Parameters);

	auto Sender = [this, Connection, TargetObject, StructuredParams]() mutable -> FRPCCommandRequestResult
	{
		// Resolve TargetObject.
		improbable::unreal::UnrealObjectRef TargetObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(PackageMap->GetNetGUIDFromObject(TargetObject));
		if (TargetObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
		{
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC Test_RPC queued. Target object is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
			return {TargetObject};
		}

		// Build RPC Payload.
		improbable::unreal::generated::testcaserpcsc::TestRPCRequest RPCPayload;
		{
			RPCPayload.set_field_enum0(uint32_t(StructuredParams.Enum));
		}
		{
			if (StructuredParams.BP_Actor != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.BP_Actor);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.BP_Actor->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.BP_Actor);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC Test_RPC queued. StructuredParams.BP_Actor is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.BP_Actor)};
				}
				else
				{
					RPCPayload.set_field_bpactor0(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_bpactor0(SpatialConstants::NULL_OBJECT_REF);
			}
		}
		{
			RPCPayload.set_field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testbool15c1b5d454f54993b19d77fb6b2ef91cb0(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bool_1_5C1B5D454F54993B19D77FB6B2EF91CB);
		}
		{
			TSet<const UObject*> UnresolvedObjects;
			TArray<uint8> ValueData;
			FSpatialMemoryWriter ValueDataWriter(ValueData, PackageMap, UnresolvedObjects);
			bool bSuccess = true;
			(const_cast<FVector&>(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_struct_4_0F09344D4EF4517FD0409DA7F7B80E9B)).NetSerialize(ValueDataWriter, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
			RPCPayload.set_field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_teststruct40f09344d4ef4517fd0409da7f7b80e9b0(std::string(reinterpret_cast<char*>(ValueData.GetData()), ValueData.Num()));
		}
		{
			RPCPayload.set_field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testenum7dbcadacd42bccad755cab5a2e92afe320(uint32_t(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_enum_7_DBCADACD42BCCAD755CAB5A2E92AFE32));
		}
		{
			if (StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090 != nullptr)
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromObject(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090);
				if (!NetGUID.IsValid())
				{
					if (StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090->IsFullNameStableForNetworking())
					{
						NetGUID = PackageMap->ResolveStablyNamedObject(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090);
					}
				}
				improbable::unreal::UnrealObjectRef ObjectRef = PackageMap->GetUnrealObjectRefFromNetGUID(NetGUID);
				if (ObjectRef == SpatialConstants::UNRESOLVED_OBJECT_REF)
				{
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: RPC Test_RPC queued. StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090 is unresolved."), *Interop->GetSpatialOS()->GetWorkerId());
					return {Cast<UObject>(StructuredParams.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090)};
				}
				else
				{
					RPCPayload.set_field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testbpactor1044234d3f42f700435b69db9dc87f40900(ObjectRef);
				}
			}
			else
			{
				RPCPayload.set_field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testbpactor1044234d3f42f700435b69db9dc87f40900(SpatialConstants::NULL_OBJECT_REF);
			}
		}

		// Send RPC
		RPCPayload.set_target_subobject_offset(TargetObjectRef.offset());
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Sending RPC: Test_RPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

			auto RequestId = Connection->SendCommandRequest<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>(TargetObjectRef.entity(), RPCPayload, 0);
			return {RequestId.Id};
	};
	Interop->InvokeRPCSendHandler_Internal(Sender, /*bReliable*/ false);
}
void USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_OnRPCPayload(const worker::CommandRequestOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>& Op)
{
	auto Receiver = [this, Op]() mutable -> FRPCCommandResponseResult
	{
		improbable::unreal::UnrealObjectRef TargetObjectRef{Op.EntityId, Op.Request.target_subobject_offset(), {}, {}};
		FNetworkGUID TargetNetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(TargetObjectRef);
		if (!TargetNetGUID.IsValid())
		{
			// A legal static object reference should never be unresolved.
			checkf(TargetObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
			UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Test_RPC_OnRPCPayload: Target object %s is not resolved on this worker."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ObjectRefToString(TargetObjectRef));
			return {TargetObjectRef};
		}
		UObject* TargetObject = PackageMap->GetObjectFromNetGUID(TargetNetGUID, false);
		checkf(TargetObject, TEXT("%s: Test_RPC_OnRPCPayload: Object Ref %s (NetGUID %s) does not correspond to a UObject."),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*ObjectRefToString(TargetObjectRef),
			*TargetNetGUID.ToString());

		// Declare parameters.
		struct Testcase_RPCs_C_eventTest_RPC_Parms
		{
			TEnumAsByte<Testcase_enum> Enum;
			ATestSuiteCharacter* BP_Actor;
			FTestcase_Struct_with_BP_Struct__pf3877032745 BP_Struct;
		};

		Testcase_RPCs_C_eventTest_RPC_Parms Parameters;

		// Extract from request data.
		{
			Parameters.Enum = TEnumAsByte<Testcase_enum>(uint8(Op.Request.field_enum0()));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_bpactor0();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.BP_Actor = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<ATestSuiteCharacter>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.BP_Actor = Cast<ATestSuiteCharacter>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Test_RPC_OnRPCPayload: Parameters.BP_Actor %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}
		{
			Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bool_1_5C1B5D454F54993B19D77FB6B2EF91CB = Op.Request.field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testbool15c1b5d454f54993b19d77fb6b2ef91cb0();
		}
		{
			auto& ValueDataStr = Op.Request.field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_teststruct40f09344d4ef4517fd0409da7f7b80e9b0();
			TArray<uint8> ValueData;
			ValueData.Append(reinterpret_cast<const uint8*>(ValueDataStr.data()), ValueDataStr.size());
			FSpatialMemoryReader ValueDataReader(ValueData, PackageMap);
			bool bSuccess = true;
			Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_struct_4_0F09344D4EF4517FD0409DA7F7B80E9B.NetSerialize(ValueDataReader, PackageMap, bSuccess);
			checkf(bSuccess, TEXT("NetSerialize on FVector failed."));
		}
		{
			Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_enum_7_DBCADACD42BCCAD755CAB5A2E92AFE32 = TEnumAsByte<Testcase_enum>(uint8(Op.Request.field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testenum7dbcadacd42bccad755cab5a2e92afe320()));
		}
		{
			improbable::unreal::UnrealObjectRef ObjectRef = Op.Request.field_bpstruct0_internalstruct3c866974d477750e22e863d91ba350aa80_testbpactor1044234d3f42f700435b69db9dc87f40900();
			check(ObjectRef != SpatialConstants::UNRESOLVED_OBJECT_REF);
			if (ObjectRef == SpatialConstants::NULL_OBJECT_REF)
			{
				Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090 = nullptr;
			}
			else
			{
				FNetworkGUID NetGUID = PackageMap->GetNetGUIDFromUnrealObjectRef(ObjectRef);
				if (NetGUID.IsValid())
				{
					UObject* Object_Raw = PackageMap->GetObjectFromNetGUID(NetGUID, true);
					checkf(Object_Raw, TEXT("An object ref %s should map to a valid object."), *ObjectRefToString(ObjectRef));
					checkf(Cast<ACharacter>(Object_Raw), TEXT("Object ref %s maps to object %s with the wrong class."), *ObjectRefToString(ObjectRef), *Object_Raw->GetFullName());
					Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090 = Cast<ACharacter>(Object_Raw);
				}
				else
				{
					// A legal static object reference should never be unresolved.
					checkf(ObjectRef.path().empty(), TEXT("A stably named object should not need resolution."));
					UE_LOG(LogSpatialGDKInterop, Log, TEXT("%s: Test_RPC_OnRPCPayload: Parameters.BP_Struct.InternalStruct_3_C866974D477750E22E863D91BA350AA8.Test_bp_actor_10_44234D3F42F700435B69DB9DC87F4090 %s is not resolved on this worker."),
						*Interop->GetSpatialOS()->GetWorkerId(),
						*ObjectRefToString(ObjectRef));
					return {ObjectRef};
				}
			}
		}

		// Call implementation.
		UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received RPC: Test_RPC, target: %s %s"),
			*Interop->GetSpatialOS()->GetWorkerId(),
			*TargetObject->GetName(),
			*ObjectRefToString(TargetObjectRef));

		if (UFunction* Function = TargetObject->FindFunction(FName(TEXT("Test_RPC"))))
		{
			TargetObject->ProcessEvent(Function, &Parameters);
		}
		else
		{
			UE_LOG(LogSpatialGDKInterop, Error, TEXT("%s: Test_RPC_OnRPCPayload: Function not found. Object: %s, Function: Test_RPC."),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*TargetObject->GetFullName());
		}

		// Send command response.
		TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
		Connection->SendCommandResponse<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>(Op.RequestId, {});
		return {};
	};
	Interop->InvokeRPCReceiveHandler_Internal(Receiver);
}

void USpatialTypeBinding_Testcase_RPCs_C::Test_RPC_OnCommandResponse(const worker::CommandResponseOp<improbable::unreal::generated::testcaserpcsc::TestcaseRPCsCClientRPCs::Commands::Testrpc>& Op)
{
	Interop->HandleCommandResponse_Internal(TEXT("Test_RPC"), Op.RequestId.Id, Op.EntityId, Op.StatusCode, FString(UTF8_TO_TCHAR(Op.Message.c_str())));
}
