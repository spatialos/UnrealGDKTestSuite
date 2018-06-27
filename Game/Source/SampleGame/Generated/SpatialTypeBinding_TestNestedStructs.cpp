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


	UClass* Class = FindObject<UClass>(ANY_PACKAGE, TEXT("TestNestedStructs"));

	// Populate RepHandleToPropertyMap.
	RepHandleToPropertyMap.Add(1, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(2, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(3, FRepHandleData(Class, {"TestContainerStruct", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(4, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(5, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(6, FRepHandleData(Class, {"TestContainerStruct", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(7, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(8, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(9, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(10, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(11, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(12, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(13, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(14, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(15, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(16, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(17, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(18, FRepHandleData(Class, {"TestContainerStruct", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(19, FRepHandleData(Class, {"TestContainerStruct", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(20, FRepHandleData(Class, {"TestContainerStruct", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(21, FRepHandleData(Class, {"TestContainerStruct", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(22, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(23, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(24, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(25, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(26, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(27, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(28, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(29, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(30, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(31, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(32, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(33, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(34, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(35, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(36, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(37, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(38, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(39, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(40, FRepHandleData(Class, {"TestContainerStructArray", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(41, FRepHandleData(Class, {"TestContainerStructArray", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(42, FRepHandleData(Class, {"TestContainerStructArray", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(43, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(44, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(45, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(46, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(47, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(48, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(49, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(50, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(51, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(52, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(53, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(54, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(55, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(56, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(57, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(58, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(59, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(60, FRepHandleData(Class, {"TestContainerStructArray", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(61, FRepHandleData(Class, {"TestContainerStructArray", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(62, FRepHandleData(Class, {"TestContainerStructArray", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(63, FRepHandleData(Class, {"TestContainerStructArray", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(64, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(65, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(66, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(67, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(68, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(69, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(70, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(71, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(72, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(73, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(74, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(75, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(76, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(77, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(78, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(79, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(80, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(81, FRepHandleData(Class, {"TestContainerStructTheSecond", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(82, FRepHandleData(Class, {"TestContainerStructTheSecond", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(83, FRepHandleData(Class, {"TestContainerStructTheSecond", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(84, FRepHandleData(Class, {"TestContainerStructTheSecond", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(85, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(86, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(87, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(88, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(89, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(90, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(91, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(92, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(93, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(94, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(95, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(96, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(97, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(98, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(99, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(100, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(101, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(102, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(103, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(104, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(105, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerCar", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(106, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(107, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(108, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(109, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(110, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(111, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(112, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(113, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(114, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(115, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(116, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(117, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(118, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(119, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(120, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(121, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(122, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(123, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(124, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(125, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(126, FRepHandleData(Class, {"TestContainerContainerStruct", "Struct_ContainerPlane", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(127, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(128, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(129, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(130, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(131, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(132, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(133, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(134, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(135, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(136, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(137, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(138, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(139, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(140, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(141, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(142, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(143, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(144, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(145, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(146, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(147, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerCar", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(148, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(149, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(150, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(151, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(152, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(153, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(154, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(155, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(156, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(157, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(158, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(159, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(160, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(161, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(162, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(163, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(164, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(165, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(166, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(167, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(168, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerDog", "Struct_ContainerPlane", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(169, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(170, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(171, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(172, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(173, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(174, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(175, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(176, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(177, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(178, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(179, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(180, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(181, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(182, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(183, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(184, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(185, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(186, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(187, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(188, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(189, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerCar", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(190, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Red", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(191, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(192, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Red", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(193, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Blue", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(194, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(195, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Blue", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(196, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(197, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(198, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(199, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(200, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(201, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(202, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(203, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(204, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(205, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "RootProp"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(206, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(207, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Struct_Array_ANOTHER", "Root_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(208, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(209, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Container_Int_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
	RepHandleToPropertyMap.Add(210, FRepHandleData(Class, {"TestContainerContainerContainerStruct", "Struct_ContainerContainerCat", "Struct_ContainerPlane", "Dynamic_Struct_Array"}, COND_None, REPNOTIFY_OnChanged, 0));
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
		case 1: // field_testcontainerstruct_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structred_rootprop(int32_t(Value));
			break;
		}
		case 2: // field_testcontainerstruct_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structred_rootarray0(int32_t(Value));
			break;
		}
		case 3: // field_testcontainerstruct_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structred_rootarray1(int32_t(Value));
			break;
		}
		case 4: // field_testcontainerstruct_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structblue_rootprop(int32_t(Value));
			break;
		}
		case 5: // field_testcontainerstruct_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 6: // field_testcontainerstruct_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 7: // field_testcontainerstruct_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 8: // field_testcontainerstruct_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 9: // field_testcontainerstruct_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 10: // field_testcontainerstruct_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 11: // field_testcontainerstruct_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 12: // field_testcontainerstruct_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 13: // field_testcontainerstruct_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 14: // field_testcontainerstruct_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 15: // field_testcontainerstruct_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 16: // field_testcontainerstruct_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 17: // field_testcontainerstruct_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 18: // field_testcontainerstruct_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 19: // field_testcontainerstruct_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_containerintarray0(int32_t(Value));
			break;
		}
		case 20: // field_testcontainerstruct_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstruct_containerintarray1(int32_t(Value));
			break;
		}
		case 21: // field_testcontainerstruct_dynamicstructarray
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
			OutUpdate.set_field_testcontainerstruct_dynamicstructarray(List);
			break;
		}
		case 22: // field_testcontainerstructarray0_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structred_rootprop(int32_t(Value));
			break;
		}
		case 23: // field_testcontainerstructarray0_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structred_rootarray0(int32_t(Value));
			break;
		}
		case 24: // field_testcontainerstructarray0_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structred_rootarray1(int32_t(Value));
			break;
		}
		case 25: // field_testcontainerstructarray0_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structblue_rootprop(int32_t(Value));
			break;
		}
		case 26: // field_testcontainerstructarray0_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 27: // field_testcontainerstructarray0_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 28: // field_testcontainerstructarray0_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 29: // field_testcontainerstructarray0_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 30: // field_testcontainerstructarray0_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 31: // field_testcontainerstructarray0_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 32: // field_testcontainerstructarray0_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 33: // field_testcontainerstructarray0_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 34: // field_testcontainerstructarray0_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 35: // field_testcontainerstructarray0_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 36: // field_testcontainerstructarray0_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 37: // field_testcontainerstructarray0_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 38: // field_testcontainerstructarray0_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 39: // field_testcontainerstructarray0_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 40: // field_testcontainerstructarray0_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_containerintarray0(int32_t(Value));
			break;
		}
		case 41: // field_testcontainerstructarray0_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray0_containerintarray1(int32_t(Value));
			break;
		}
		case 42: // field_testcontainerstructarray0_dynamicstructarray
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
			OutUpdate.set_field_testcontainerstructarray0_dynamicstructarray(List);
			break;
		}
		case 43: // field_testcontainerstructarray1_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structred_rootprop(int32_t(Value));
			break;
		}
		case 44: // field_testcontainerstructarray1_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structred_rootarray0(int32_t(Value));
			break;
		}
		case 45: // field_testcontainerstructarray1_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structred_rootarray1(int32_t(Value));
			break;
		}
		case 46: // field_testcontainerstructarray1_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structblue_rootprop(int32_t(Value));
			break;
		}
		case 47: // field_testcontainerstructarray1_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 48: // field_testcontainerstructarray1_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 49: // field_testcontainerstructarray1_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 50: // field_testcontainerstructarray1_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 51: // field_testcontainerstructarray1_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 52: // field_testcontainerstructarray1_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 53: // field_testcontainerstructarray1_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 54: // field_testcontainerstructarray1_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 55: // field_testcontainerstructarray1_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 56: // field_testcontainerstructarray1_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 57: // field_testcontainerstructarray1_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 58: // field_testcontainerstructarray1_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 59: // field_testcontainerstructarray1_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 60: // field_testcontainerstructarray1_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 61: // field_testcontainerstructarray1_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_containerintarray0(int32_t(Value));
			break;
		}
		case 62: // field_testcontainerstructarray1_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructarray1_containerintarray1(int32_t(Value));
			break;
		}
		case 63: // field_testcontainerstructarray1_dynamicstructarray
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
			OutUpdate.set_field_testcontainerstructarray1_dynamicstructarray(List);
			break;
		}
		case 64: // field_testcontainerstructthesecond_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structred_rootprop(int32_t(Value));
			break;
		}
		case 65: // field_testcontainerstructthesecond_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structred_rootarray0(int32_t(Value));
			break;
		}
		case 66: // field_testcontainerstructthesecond_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structred_rootarray1(int32_t(Value));
			break;
		}
		case 67: // field_testcontainerstructthesecond_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structblue_rootprop(int32_t(Value));
			break;
		}
		case 68: // field_testcontainerstructthesecond_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 69: // field_testcontainerstructthesecond_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 70: // field_testcontainerstructthesecond_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 71: // field_testcontainerstructthesecond_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 72: // field_testcontainerstructthesecond_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 73: // field_testcontainerstructthesecond_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 74: // field_testcontainerstructthesecond_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 75: // field_testcontainerstructthesecond_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 76: // field_testcontainerstructthesecond_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 77: // field_testcontainerstructthesecond_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 78: // field_testcontainerstructthesecond_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 79: // field_testcontainerstructthesecond_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 80: // field_testcontainerstructthesecond_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 81: // field_testcontainerstructthesecond_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 82: // field_testcontainerstructthesecond_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_containerintarray0(int32_t(Value));
			break;
		}
		case 83: // field_testcontainerstructthesecond_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainerstructthesecond_containerintarray1(int32_t(Value));
			break;
		}
		case 84: // field_testcontainerstructthesecond_dynamicstructarray
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
			OutUpdate.set_field_testcontainerstructthesecond_dynamicstructarray(List);
			break;
		}
		case 85: // field_testcontainercontainerstruct_structcontainercar_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structred_rootprop(int32_t(Value));
			break;
		}
		case 86: // field_testcontainercontainerstruct_structcontainercar_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structred_rootarray0(int32_t(Value));
			break;
		}
		case 87: // field_testcontainercontainerstruct_structcontainercar_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structred_rootarray1(int32_t(Value));
			break;
		}
		case 88: // field_testcontainercontainerstruct_structcontainercar_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structblue_rootprop(int32_t(Value));
			break;
		}
		case 89: // field_testcontainercontainerstruct_structcontainercar_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 90: // field_testcontainercontainerstruct_structcontainercar_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 91: // field_testcontainercontainerstruct_structcontainercar_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 92: // field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 93: // field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 94: // field_testcontainercontainerstruct_structcontainercar_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 95: // field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 96: // field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 97: // field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 98: // field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 99: // field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 100: // field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 101: // field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 102: // field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 103: // field_testcontainercontainerstruct_structcontainercar_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_containerintarray0(int32_t(Value));
			break;
		}
		case 104: // field_testcontainercontainerstruct_structcontainercar_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_containerintarray1(int32_t(Value));
			break;
		}
		case 105: // field_testcontainercontainerstruct_structcontainercar_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainerstruct_structcontainercar_dynamicstructarray(List);
			break;
		}
		case 106: // field_testcontainercontainerstruct_structcontainerplane_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structred_rootprop(int32_t(Value));
			break;
		}
		case 107: // field_testcontainercontainerstruct_structcontainerplane_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structred_rootarray0(int32_t(Value));
			break;
		}
		case 108: // field_testcontainercontainerstruct_structcontainerplane_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structred_rootarray1(int32_t(Value));
			break;
		}
		case 109: // field_testcontainercontainerstruct_structcontainerplane_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structblue_rootprop(int32_t(Value));
			break;
		}
		case 110: // field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 111: // field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 112: // field_testcontainercontainerstruct_structcontainerplane_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 113: // field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 114: // field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 115: // field_testcontainercontainerstruct_structcontainerplane_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 116: // field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 117: // field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 118: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 119: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 120: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 121: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 122: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 123: // field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 124: // field_testcontainercontainerstruct_structcontainerplane_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_containerintarray0(int32_t(Value));
			break;
		}
		case 125: // field_testcontainercontainerstruct_structcontainerplane_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_containerintarray1(int32_t(Value));
			break;
		}
		case 126: // field_testcontainercontainerstruct_structcontainerplane_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainerstruct_structcontainerplane_dynamicstructarray(List);
			break;
		}
		case 127: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootprop(int32_t(Value));
			break;
		}
		case 128: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray0(int32_t(Value));
			break;
		}
		case 129: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray1(int32_t(Value));
			break;
		}
		case 130: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootprop(int32_t(Value));
			break;
		}
		case 131: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 132: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 133: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 134: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 135: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 136: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 137: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 138: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 139: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 140: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 141: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 142: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 143: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 144: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 145: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray0(int32_t(Value));
			break;
		}
		case 146: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray1(int32_t(Value));
			break;
		}
		case 147: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_dynamicstructarray(List);
			break;
		}
		case 148: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootprop(int32_t(Value));
			break;
		}
		case 149: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray0(int32_t(Value));
			break;
		}
		case 150: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray1(int32_t(Value));
			break;
		}
		case 151: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootprop(int32_t(Value));
			break;
		}
		case 152: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 153: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 154: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 155: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 156: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 157: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 158: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 159: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 160: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 161: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 162: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 163: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 164: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 165: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 166: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray0(int32_t(Value));
			break;
		}
		case 167: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray1(int32_t(Value));
			break;
		}
		case 168: // field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_dynamicstructarray(List);
			break;
		}
		case 169: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootprop(int32_t(Value));
			break;
		}
		case 170: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray0(int32_t(Value));
			break;
		}
		case 171: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray1(int32_t(Value));
			break;
		}
		case 172: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootprop(int32_t(Value));
			break;
		}
		case 173: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 174: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 175: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 176: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 177: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 178: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 179: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 180: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 181: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 182: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 183: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 184: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 185: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 186: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 187: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray0(int32_t(Value));
			break;
		}
		case 188: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray1(int32_t(Value));
			break;
		}
		case 189: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_dynamicstructarray(List);
			break;
		}
		case 190: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootprop(int32_t(Value));
			break;
		}
		case 191: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray0(int32_t(Value));
			break;
		}
		case 192: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray1(int32_t(Value));
			break;
		}
		case 193: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootprop(int32_t(Value));
			break;
		}
		case 194: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray0(int32_t(Value));
			break;
		}
		case 195: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray1(int32_t(Value));
			break;
		}
		case 196: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootprop(int32_t(Value));
			break;
		}
		case 197: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray0(int32_t(Value));
			break;
		}
		case 198: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray1(int32_t(Value));
			break;
		}
		case 199: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootprop(int32_t(Value));
			break;
		}
		case 200: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray0(int32_t(Value));
			break;
		}
		case 201: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray1(int32_t(Value));
			break;
		}
		case 202: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootprop(int32_t(Value));
			break;
		}
		case 203: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray0(int32_t(Value));
			break;
		}
		case 204: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray1(int32_t(Value));
			break;
		}
		case 205: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootprop
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootprop(int32_t(Value));
			break;
		}
		case 206: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray0(int32_t(Value));
			break;
		}
		case 207: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray1(int32_t(Value));
			break;
		}
		case 208: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray0
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray0(int32_t(Value));
			break;
		}
		case 209: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray1
		{
			int32 Value = *(reinterpret_cast<int32 const*>(Data));

			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray1(int32_t(Value));
			break;
		}
		case 210: // field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_dynamicstructarray
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
			OutUpdate.set_field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_dynamicstructarray(List);
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

	if (!Update.field_testcontainerstruct_structred_rootprop().empty())
	{
		// field_testcontainerstruct_structred_rootprop
		uint16 Handle = 1;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structred_rootarray0().empty())
	{
		// field_testcontainerstruct_structred_rootarray0
		uint16 Handle = 2;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structred_rootarray1().empty())
	{
		// field_testcontainerstruct_structred_rootarray1
		uint16 Handle = 3;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structblue_rootprop().empty())
	{
		// field_testcontainerstruct_structblue_rootprop
		uint16 Handle = 4;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structblue_rootarray0().empty())
	{
		// field_testcontainerstruct_structblue_rootarray0
		uint16 Handle = 5;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structblue_rootarray1().empty())
	{
		// field_testcontainerstruct_structblue_rootarray1
		uint16 Handle = 6;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray0_rootprop().empty())
	{
		// field_testcontainerstruct_structarray0_rootprop
		uint16 Handle = 7;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray0_rootarray0().empty())
	{
		// field_testcontainerstruct_structarray0_rootarray0
		uint16 Handle = 8;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray0_rootarray1().empty())
	{
		// field_testcontainerstruct_structarray0_rootarray1
		uint16 Handle = 9;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray1_rootprop().empty())
	{
		// field_testcontainerstruct_structarray1_rootprop
		uint16 Handle = 10;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray1_rootarray0().empty())
	{
		// field_testcontainerstruct_structarray1_rootarray0
		uint16 Handle = 11;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarray1_rootarray1().empty())
	{
		// field_testcontainerstruct_structarray1_rootarray1
		uint16 Handle = 12;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother0_rootprop().empty())
	{
		// field_testcontainerstruct_structarrayanother0_rootprop
		uint16 Handle = 13;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainerstruct_structarrayanother0_rootarray0
		uint16 Handle = 14;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainerstruct_structarrayanother0_rootarray1
		uint16 Handle = 15;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother1_rootprop().empty())
	{
		// field_testcontainerstruct_structarrayanother1_rootprop
		uint16 Handle = 16;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainerstruct_structarrayanother1_rootarray0
		uint16 Handle = 17;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainerstruct_structarrayanother1_rootarray1
		uint16 Handle = 18;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_containerintarray0().empty())
	{
		// field_testcontainerstruct_containerintarray0
		uint16 Handle = 19;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_containerintarray1().empty())
	{
		// field_testcontainerstruct_containerintarray1
		uint16 Handle = 20;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstruct_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstruct_dynamicstructarray().empty())
	{
		// field_testcontainerstruct_dynamicstructarray
		uint16 Handle = 21;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainerstruct_dynamicstructarray().data());
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
	if (!Update.field_testcontainerstructarray0_structred_rootprop().empty())
	{
		// field_testcontainerstructarray0_structred_rootprop
		uint16 Handle = 22;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structred_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structred_rootarray0
		uint16 Handle = 23;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structred_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structred_rootarray1
		uint16 Handle = 24;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structblue_rootprop().empty())
	{
		// field_testcontainerstructarray0_structblue_rootprop
		uint16 Handle = 25;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structblue_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structblue_rootarray0
		uint16 Handle = 26;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structblue_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structblue_rootarray1
		uint16 Handle = 27;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray0_rootprop().empty())
	{
		// field_testcontainerstructarray0_structarray0_rootprop
		uint16 Handle = 28;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray0_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structarray0_rootarray0
		uint16 Handle = 29;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray0_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structarray0_rootarray1
		uint16 Handle = 30;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray1_rootprop().empty())
	{
		// field_testcontainerstructarray0_structarray1_rootprop
		uint16 Handle = 31;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray1_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structarray1_rootarray0
		uint16 Handle = 32;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarray1_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structarray1_rootarray1
		uint16 Handle = 33;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother0_rootprop().empty())
	{
		// field_testcontainerstructarray0_structarrayanother0_rootprop
		uint16 Handle = 34;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structarrayanother0_rootarray0
		uint16 Handle = 35;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structarrayanother0_rootarray1
		uint16 Handle = 36;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother1_rootprop().empty())
	{
		// field_testcontainerstructarray0_structarrayanother1_rootprop
		uint16 Handle = 37;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainerstructarray0_structarrayanother1_rootarray0
		uint16 Handle = 38;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainerstructarray0_structarrayanother1_rootarray1
		uint16 Handle = 39;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_containerintarray0().empty())
	{
		// field_testcontainerstructarray0_containerintarray0
		uint16 Handle = 40;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_containerintarray1().empty())
	{
		// field_testcontainerstructarray0_containerintarray1
		uint16 Handle = 41;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray0_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray0_dynamicstructarray().empty())
	{
		// field_testcontainerstructarray0_dynamicstructarray
		uint16 Handle = 42;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainerstructarray0_dynamicstructarray().data());
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
	if (!Update.field_testcontainerstructarray1_structred_rootprop().empty())
	{
		// field_testcontainerstructarray1_structred_rootprop
		uint16 Handle = 43;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structred_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structred_rootarray0
		uint16 Handle = 44;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structred_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structred_rootarray1
		uint16 Handle = 45;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structblue_rootprop().empty())
	{
		// field_testcontainerstructarray1_structblue_rootprop
		uint16 Handle = 46;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structblue_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structblue_rootarray0
		uint16 Handle = 47;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structblue_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structblue_rootarray1
		uint16 Handle = 48;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray0_rootprop().empty())
	{
		// field_testcontainerstructarray1_structarray0_rootprop
		uint16 Handle = 49;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray0_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structarray0_rootarray0
		uint16 Handle = 50;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray0_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structarray0_rootarray1
		uint16 Handle = 51;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray1_rootprop().empty())
	{
		// field_testcontainerstructarray1_structarray1_rootprop
		uint16 Handle = 52;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray1_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structarray1_rootarray0
		uint16 Handle = 53;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarray1_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structarray1_rootarray1
		uint16 Handle = 54;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother0_rootprop().empty())
	{
		// field_testcontainerstructarray1_structarrayanother0_rootprop
		uint16 Handle = 55;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structarrayanother0_rootarray0
		uint16 Handle = 56;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structarrayanother0_rootarray1
		uint16 Handle = 57;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother1_rootprop().empty())
	{
		// field_testcontainerstructarray1_structarrayanother1_rootprop
		uint16 Handle = 58;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainerstructarray1_structarrayanother1_rootarray0
		uint16 Handle = 59;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainerstructarray1_structarrayanother1_rootarray1
		uint16 Handle = 60;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_containerintarray0().empty())
	{
		// field_testcontainerstructarray1_containerintarray0
		uint16 Handle = 61;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_containerintarray1().empty())
	{
		// field_testcontainerstructarray1_containerintarray1
		uint16 Handle = 62;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructarray1_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructarray1_dynamicstructarray().empty())
	{
		// field_testcontainerstructarray1_dynamicstructarray
		uint16 Handle = 63;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainerstructarray1_dynamicstructarray().data());
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
	if (!Update.field_testcontainerstructthesecond_structred_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structred_rootprop
		uint16 Handle = 64;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structred_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structred_rootarray0
		uint16 Handle = 65;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structred_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structred_rootarray1
		uint16 Handle = 66;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structblue_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structblue_rootprop
		uint16 Handle = 67;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structblue_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structblue_rootarray0
		uint16 Handle = 68;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structblue_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structblue_rootarray1
		uint16 Handle = 69;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray0_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structarray0_rootprop
		uint16 Handle = 70;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray0_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structarray0_rootarray0
		uint16 Handle = 71;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray0_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structarray0_rootarray1
		uint16 Handle = 72;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray1_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structarray1_rootprop
		uint16 Handle = 73;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray1_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structarray1_rootarray0
		uint16 Handle = 74;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarray1_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structarray1_rootarray1
		uint16 Handle = 75;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother0_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother0_rootprop
		uint16 Handle = 76;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother0_rootarray0
		uint16 Handle = 77;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother0_rootarray1
		uint16 Handle = 78;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother1_rootprop().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother1_rootprop
		uint16 Handle = 79;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother1_rootarray0
		uint16 Handle = 80;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainerstructthesecond_structarrayanother1_rootarray1
		uint16 Handle = 81;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_containerintarray0().empty())
	{
		// field_testcontainerstructthesecond_containerintarray0
		uint16 Handle = 82;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_containerintarray1().empty())
	{
		// field_testcontainerstructthesecond_containerintarray1
		uint16 Handle = 83;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainerstructthesecond_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainerstructthesecond_dynamicstructarray().empty())
	{
		// field_testcontainerstructthesecond_dynamicstructarray
		uint16 Handle = 84;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainerstructthesecond_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structred_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structred_rootprop
		uint16 Handle = 85;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structred_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structred_rootarray0
		uint16 Handle = 86;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structred_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structred_rootarray1
		uint16 Handle = 87;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structblue_rootprop
		uint16 Handle = 88;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structblue_rootarray0
		uint16 Handle = 89;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structblue_rootarray1
		uint16 Handle = 90;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray0_rootprop
		uint16 Handle = 91;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray0
		uint16 Handle = 92;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray1
		uint16 Handle = 93;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray1_rootprop
		uint16 Handle = 94;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray0
		uint16 Handle = 95;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray1
		uint16 Handle = 96;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootprop
		uint16 Handle = 97;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray0
		uint16 Handle = 98;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray1
		uint16 Handle = 99;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootprop
		uint16 Handle = 100;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray0
		uint16 Handle = 101;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray1
		uint16 Handle = 102;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_containerintarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_containerintarray0
		uint16 Handle = 103;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_containerintarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_containerintarray1
		uint16 Handle = 104;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainercar_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainercar_dynamicstructarray().empty())
	{
		// field_testcontainercontainerstruct_structcontainercar_dynamicstructarray
		uint16 Handle = 105;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainerstruct_structcontainercar_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structred_rootprop
		uint16 Handle = 106;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structred_rootarray0
		uint16 Handle = 107;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structred_rootarray1
		uint16 Handle = 108;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structblue_rootprop
		uint16 Handle = 109;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray0
		uint16 Handle = 110;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray1
		uint16 Handle = 111;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray0_rootprop
		uint16 Handle = 112;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray0
		uint16 Handle = 113;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray1
		uint16 Handle = 114;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray1_rootprop
		uint16 Handle = 115;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray0
		uint16 Handle = 116;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray1
		uint16 Handle = 117;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootprop
		uint16 Handle = 118;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray0
		uint16 Handle = 119;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray1
		uint16 Handle = 120;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootprop
		uint16 Handle = 121;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray0
		uint16 Handle = 122;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray1
		uint16 Handle = 123;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_containerintarray0().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_containerintarray0
		uint16 Handle = 124;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_containerintarray1().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_containerintarray1
		uint16 Handle = 125;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainerstruct_structcontainerplane_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainerstruct_structcontainerplane_dynamicstructarray().empty())
	{
		// field_testcontainercontainerstruct_structcontainerplane_dynamicstructarray
		uint16 Handle = 126;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainerstruct_structcontainerplane_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootprop
		uint16 Handle = 127;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray0
		uint16 Handle = 128;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray1
		uint16 Handle = 129;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootprop
		uint16 Handle = 130;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray0
		uint16 Handle = 131;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray1
		uint16 Handle = 132;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootprop
		uint16 Handle = 133;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray0
		uint16 Handle = 134;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray1
		uint16 Handle = 135;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootprop
		uint16 Handle = 136;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray0
		uint16 Handle = 137;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray1
		uint16 Handle = 138;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootprop
		uint16 Handle = 139;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray0
		uint16 Handle = 140;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray1
		uint16 Handle = 141;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootprop
		uint16 Handle = 142;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray0
		uint16 Handle = 143;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray1
		uint16 Handle = 144;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray0
		uint16 Handle = 145;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray1
		uint16 Handle = 146;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_dynamicstructarray().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_dynamicstructarray
		uint16 Handle = 147;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainercar_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootprop
		uint16 Handle = 148;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray0
		uint16 Handle = 149;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray1
		uint16 Handle = 150;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootprop
		uint16 Handle = 151;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray0
		uint16 Handle = 152;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray1
		uint16 Handle = 153;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootprop
		uint16 Handle = 154;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray0
		uint16 Handle = 155;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray1
		uint16 Handle = 156;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootprop
		uint16 Handle = 157;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray0
		uint16 Handle = 158;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray1
		uint16 Handle = 159;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootprop
		uint16 Handle = 160;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray0
		uint16 Handle = 161;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray1
		uint16 Handle = 162;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootprop
		uint16 Handle = 163;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray0
		uint16 Handle = 164;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray1
		uint16 Handle = 165;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray0
		uint16 Handle = 166;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray1
		uint16 Handle = 167;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_dynamicstructarray().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_dynamicstructarray
		uint16 Handle = 168;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainerdog_structcontainerplane_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootprop
		uint16 Handle = 169;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray0
		uint16 Handle = 170;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray1
		uint16 Handle = 171;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootprop
		uint16 Handle = 172;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray0
		uint16 Handle = 173;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray1
		uint16 Handle = 174;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootprop
		uint16 Handle = 175;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray0
		uint16 Handle = 176;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray1
		uint16 Handle = 177;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootprop
		uint16 Handle = 178;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray0
		uint16 Handle = 179;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray1
		uint16 Handle = 180;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootprop
		uint16 Handle = 181;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray0
		uint16 Handle = 182;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray1
		uint16 Handle = 183;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootprop
		uint16 Handle = 184;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray0
		uint16 Handle = 185;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray1
		uint16 Handle = 186;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray0
		uint16 Handle = 187;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray1
		uint16 Handle = 188;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_dynamicstructarray().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_dynamicstructarray
		uint16 Handle = 189;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainercar_dynamicstructarray().data());
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
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootprop
		uint16 Handle = 190;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray0
		uint16 Handle = 191;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray1
		uint16 Handle = 192;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structred_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootprop
		uint16 Handle = 193;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray0
		uint16 Handle = 194;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray1
		uint16 Handle = 195;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structblue_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootprop
		uint16 Handle = 196;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray0
		uint16 Handle = 197;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray1
		uint16 Handle = 198;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootprop
		uint16 Handle = 199;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray0
		uint16 Handle = 200;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray1
		uint16 Handle = 201;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarray1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootprop
		uint16 Handle = 202;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray0
		uint16 Handle = 203;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray1
		uint16 Handle = 204;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother0_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootprop().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootprop
		uint16 Handle = 205;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootprop().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray0
		uint16 Handle = 206;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray1
		uint16 Handle = 207;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_structarrayanother1_rootarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray0().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray0
		uint16 Handle = 208;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray0().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray1().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray1
		uint16 Handle = 209;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			int32 Value = *(reinterpret_cast<int32 const*>(PropertyData));

			Value = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_containerintarray1().data());

			ApplyIncomingReplicatedPropertyUpdate(*RepData, ActorChannel->Actor, static_cast<const void*>(&Value), RepNotifies);

			UE_LOG(LogSpatialOSInterop, Verbose, TEXT("%s: Received replicated property update. actor %s (%lld), property %s (handle %d)"),
				*Interop->GetSpatialOS()->GetWorkerId(),
				*ActorChannel->Actor->GetName(),
				ActorChannel->GetEntityId().ToSpatialEntityId(),
				*RepData->Property->GetName(),
				Handle);
		}
	}
	if (!Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_dynamicstructarray().empty())
	{
		// field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_dynamicstructarray
		uint16 Handle = 210;
		const FRepHandleData* RepData = &HandleToPropertyMap[Handle];
		if (bIsServer || ConditionMap.IsRelevant(RepData->Condition))
		{
			uint8* PropertyData = RepData->GetPropertyData(reinterpret_cast<uint8*>(ActorChannel->Actor));
			TArray<FRootStruct> Value = *(reinterpret_cast<TArray<FRootStruct> *>(PropertyData));

			{
				auto& List = (*Update.field_testcontainercontainercontainerstruct_structcontainercontainercat_structcontainerplane_dynamicstructarray().data());
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
