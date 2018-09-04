// Copyright (c) Improbable Worlds Ltd, All Rights Reserved
// Note that this file has been generated automatically

#include "SpatialTypeBinding_TestComponent.h"

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

#include "TestComponentSingleClientRepDataAddComponentOp.h"
#include "TestComponentMultiClientRepDataAddComponentOp.h"
#include "TestComponentHandoverDataAddComponentOp.h"

const FRepHandlePropertyMap& USpatialTypeBinding_TestComponent::GetRepHandlePropertyMap() const
{
	return RepHandleToPropertyMap;
}

const FHandoverHandlePropertyMap& USpatialTypeBinding_TestComponent::GetHandoverHandlePropertyMap() const
{
	return HandoverHandleToPropertyMap;
}

UClass* USpatialTypeBinding_TestComponent::GetBoundClass() const
{
	return UTestComponent::StaticClass();
}

void USpatialTypeBinding_TestComponent::Init(USpatialInterop* InInterop, USpatialPackageMapClient* InPackageMap)
{
	Super::Init(InInterop, InPackageMap);


	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("TestComponent"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"bReplicates"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"bIsActive"}, {0}, COND_None, REPNOTIFY_OnChanged));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"TestProperty"}, {0}, COND_None, REPNOTIFY_OnChanged));

}

void USpatialTypeBinding_TestComponent::BindToView(bool bIsClient)
{
	TSharedPtr<worker::View> View = Interop->GetSpatialOS()->GetView().Pin();
	ViewCallbacks.Init(View);

	if (Interop->GetNetDriver()->GetNetMode() == NM_Client)
	{
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_SingleClient(ActorChannel, Op.Update);
		}));
		ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData>([this](
			const worker::ComponentUpdateOp<improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData>& Op)
		{
			// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
			if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::ComponentId))
			{
				return;
			}
			USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
			check(ActorChannel);
			ReceiveUpdate_MultiClient(ActorChannel, Op.Update);
		}));
		if (!bIsClient)
		{
			ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentHandoverData>([this](
				const worker::ComponentUpdateOp<improbable::unreal::generated::testcomponent::TestComponentHandoverData>& Op)
			{
				// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
				if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcomponent::TestComponentHandoverData::ComponentId))
				{
					return;
				}
				USpatialActorChannel* ActorChannel = Interop->GetActorChannelByEntityId(Op.EntityId);
				check(ActorChannel);
				ReceiveUpdate_Handover(ActorChannel, Op.Update);
			}));
		}
	}
	ViewCallbacks.Add(View->OnComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs>([this](
		const worker::ComponentUpdateOp<improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs>& Op)
	{
		// TODO: Remove this check once we can disable component update short circuiting. This will be exposed in 14.0. See TIG-137.
		if (HasComponentAuthority(Interop->GetSpatialOS()->GetView(), Op.EntityId, improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs::ComponentId))
		{
			return;
		}
		ReceiveUpdate_NetMulticastRPCs(Op.EntityId, Op.Update);
	}));
}

void USpatialTypeBinding_TestComponent::UnbindFromView()
{
	ViewCallbacks.Reset();
}

worker::Entity USpatialTypeBinding_TestComponent::CreateActorEntity(const FString& ClientWorkerId, const FVector& Position, const FString& Metadata, const FPropertyChangeState& InitialChanges, USpatialActorChannel* Channel) const
{
	// Validate replication list.
	const uint16 RepHandlePropertyMapCount = GetRepHandlePropertyMap().Num();
	for (auto& Rep : InitialChanges.RepChanged)
	{
		checkf(Rep <= RepHandlePropertyMapCount, TEXT("Attempting to replicate a property with a handle that the type binding is not aware of. Have additional replicated properties been added in a non generated child object?"))
	}

	// Setup initial data.

	improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Data SingleClientTestComponentData;
	improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update SingleClientTestComponentUpdate;
	bool bSingleClientTestComponentUpdateChanged = false;
	improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Data MultiClientTestComponentData;
	improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update MultiClientTestComponentUpdate;
	bool bMultiClientTestComponentUpdateChanged = false;
	improbable::unreal::generated::testcomponent::TestComponentHandoverData::Data TestComponentHandoverData;
	improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update TestComponentHandoverDataUpdate;
	bool bTestComponentHandoverDataUpdateChanged = false;

	FPropertyChangeState TestComponentChangeState = Channel->CreateSubobjectChangeState(Channel->Actor->FindComponentByClass<UTestComponent>());
	USpatialTypeBinding_TestComponent* TestComponentTypeBinding = Cast<USpatialTypeBinding_TestComponent>(Interop->GetTypeBindingByClass(UTestComponent::StaticClass()));
	TestComponentTypeBinding->BuildSpatialComponentUpdate(TestComponentChangeState, Channel, SingleClientTestComponentUpdate, bSingleClientTestComponentUpdateChanged, MultiClientTestComponentUpdate, bMultiClientTestComponentUpdateChanged, TestComponentHandoverDataUpdate, bTestComponentHandoverDataUpdateChanged);
	SingleClientTestComponentUpdate.ApplyTo(SingleClientTestComponentData);
	MultiClientTestComponentUpdate.ApplyTo(MultiClientTestComponentData);
	TestComponentHandoverDataUpdate.ApplyTo(TestComponentHandoverData);

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
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData>(SingleClientTestComponentData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData>(MultiClientTestComponentData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentHandoverData>(TestComponentHandoverData, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentClientRPCs>(improbable::unreal::generated::testcomponent::TestComponentClientRPCs::Data{}, OwningClientOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentServerRPCs>(improbable::unreal::generated::testcomponent::TestComponentServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentCrossServerRPCs>(improbable::unreal::generated::testcomponent::TestComponentCrossServerRPCs::Data{}, WorkersOnly)
		.AddComponent<improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs>(improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs::Data{}, WorkersOnly)
		.Build();
}

void USpatialTypeBinding_TestComponent::SendComponentUpdates(const FPropertyChangeState& Changes, USpatialActorChannel* Channel, const FEntityId& EntityId) const
{
	// Build SpatialOS updates.
	improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update SingleClientUpdate;
	bool bSingleClientUpdateChanged = false;
	improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update MultiClientUpdate;
	bool bMultiClientUpdateChanged = false;
	improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update HandoverDataUpdate;
	bool bHandoverDataUpdateChanged = false;
	BuildSpatialComponentUpdate(Changes, Channel, SingleClientUpdate, bSingleClientUpdateChanged, MultiClientUpdate, bMultiClientUpdateChanged, HandoverDataUpdate, bHandoverDataUpdateChanged);

	// Send SpatialOS updates if anything changed.
	TSharedPtr<worker::Connection> Connection = Interop->GetSpatialOS()->GetConnection().Pin();
	if (bSingleClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData>(EntityId.ToSpatialEntityId(), SingleClientUpdate);
	}
	if (bMultiClientUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData>(EntityId.ToSpatialEntityId(), MultiClientUpdate);
	}
	if (bHandoverDataUpdateChanged)
	{
		Connection->SendComponentUpdate<improbable::unreal::generated::testcomponent::TestComponentHandoverData>(EntityId.ToSpatialEntityId(), HandoverDataUpdate);
	}
}

void USpatialTypeBinding_TestComponent::SendRPCCommand(UObject* TargetObject, const UFunction* const Function, void* Parameters)
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

void USpatialTypeBinding_TestComponent::ReceiveAddComponent(USpatialActorChannel* Channel, UAddComponentOpWrapperBase* AddComponentOp) const
{
	auto* SingleClientAddOp = Cast<UTestComponentSingleClientRepDataAddComponentOp>(AddComponentOp);
	if (SingleClientAddOp)
	{
		auto Update = improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update::FromInitialData(*SingleClientAddOp->Data.data());
		ReceiveUpdate_SingleClient(Channel, Update);
		return;
	}
	auto* MultiClientAddOp = Cast<UTestComponentMultiClientRepDataAddComponentOp>(AddComponentOp);
	if (MultiClientAddOp)
	{
		auto Update = improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update::FromInitialData(*MultiClientAddOp->Data.data());
		ReceiveUpdate_MultiClient(Channel, Update);
		return;
	}
	auto* HandoverDataAddOp = Cast<UTestComponentHandoverDataAddComponentOp>(AddComponentOp);
	if (HandoverDataAddOp)
	{
		auto Update = improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update::FromInitialData(*HandoverDataAddOp->Data.data());
		ReceiveUpdate_Handover(Channel, Update);
		return;
	}
}

worker::Map<worker::ComponentId, worker::InterestOverride> USpatialTypeBinding_TestComponent::GetInterestOverrideMap(bool bIsClient, bool bNetOwned) const
{
	worker::Map<worker::ComponentId, worker::InterestOverride> Interest;
	if (bIsClient)
	{
		Interest.emplace(improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::ComponentId, worker::InterestOverride{bNetOwned});
		Interest.emplace(improbable::unreal::generated::testcomponent::TestComponentHandoverData::ComponentId, worker::InterestOverride{false});
	}
	return Interest;
}

bool USpatialTypeBinding_TestComponent::UpdateEntityACL(USpatialActorChannel* Channel, bool bNetOwned) const
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

		WriteACL[improbable::unreal::generated::testcomponent::TestComponentClientRPCs::ComponentId] = OwningClientOnly;

		improbable::EntityAcl::Update Update;
		Update.set_component_write_acl(WriteACL);
		PinnedConnection->SendComponentUpdate<improbable::EntityAcl>(Id, Update);
		return true;
	}

	return false;
}

void USpatialTypeBinding_TestComponent::BuildSpatialComponentUpdate(
	const FPropertyChangeState& Changes,
	USpatialActorChannel* Channel,
	improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& SingleClientUpdate,
	bool& bSingleClientUpdateChanged,
	improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& MultiClientUpdate,
	bool& bMultiClientUpdateChanged,
	improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& HandoverDataUpdate,
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

void USpatialTypeBinding_TestComponent::ServerSendUpdate_SingleClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_TestComponent::ServerSendUpdate_MultiClient(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& OutUpdate) const
{
	switch (Handle)
	{
		case 1: // field_breplicates0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_breplicates0(Value);
			break;
		}
		case 2: // field_bisactive0
		{
			bool Value = static_cast<UBoolProperty*>(Property)->GetPropertyValue(Data);

			OutUpdate.set_field_bisactive0(Value);
			break;
		}
		case 3: // field_testproperty0
		{
			float Value = *(reinterpret_cast<float const*>(Data));

			OutUpdate.set_field_testproperty0(Value);
			break;
		}
	default:
		checkf(false, TEXT("Unknown replication handle %d encountered when creating a SpatialOS update."));
		break;
	}
}

void USpatialTypeBinding_TestComponent::ServerSendUpdate_Handover(const uint8* RESTRICT Data, int32 Handle, UProperty* Property, USpatialActorChannel* Channel, improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& OutUpdate) const
{
}

void USpatialTypeBinding_TestComponent::ReceiveUpdate_SingleClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentSingleClientRepData::Update& Update) const
{
	UActorComponent* TargetObject = ActorChannel->Actor->FindComponentByClass<UTestComponent>();
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TArray<UProperty*> RepNotifies;
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies);
}

void USpatialTypeBinding_TestComponent::ReceiveUpdate_MultiClient(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentMultiClientRepData::Update& Update) const
{
	UActorComponent* TargetObject = ActorChannel->Actor->FindComponentByClass<UTestComponent>();
	ActorChannel->PreReceiveSpatialUpdate(TargetObject);
	TSet<UProperty*> RepNotifies;

	const bool bIsServer = Interop->GetNetDriver()->IsServer();
	const bool bAutonomousProxy = ActorChannel->IsClientAutonomousProxy(improbable::unreal::generated::testcomponent::TestComponentClientRPCs::ComponentId);
	const FRepHandlePropertyMap& HandleToPropertyMap = GetRepHandlePropertyMap();
	FSpatialConditionMapFilter ConditionMap(ActorChannel, bAutonomousProxy);

	if (!Update.field_breplicates0().empty())
	{
		// field_breplicates0
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_breplicates0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_bisactive0().empty())
	{
		// field_bisactive0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			bool Value = static_cast<UBoolProperty*>(RepData->Property)->GetPropertyValue(PropertyData);

			Value = (*Update.field_bisactive0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testproperty0().empty())
	{
		// field_testproperty0
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(TargetObject));
			float Value = *(reinterpret_cast<float const*>(PropertyData));

			Value = (*Update.field_testproperty0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, TargetObject, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialGDKInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	ActorChannel->PostReceiveSpatialUpdate(TargetObject, RepNotifies.Array());
}

void USpatialTypeBinding_TestComponent::ReceiveUpdate_Handover(USpatialActorChannel* ActorChannel, const improbable::unreal::generated::testcomponent::TestComponentHandoverData::Update& Update) const
{
}

void USpatialTypeBinding_TestComponent::ReceiveUpdate_NetMulticastRPCs(worker::EntityId EntityId, const improbable::unreal::generated::testcomponent::TestComponentNetMulticastRPCs::Update& Update)
{
}
