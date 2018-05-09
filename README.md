# SpatialGDK sample game: Unreal project demonstrating SpatialOS integration
Repository: [github.com/improbable/unreal-gdk-sample-game](https://github.com/improbable/unreal-gdk-sample-game)

By: [improbable.io](https://improbable.io/)

Copyright: TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

## TOC

* [Getting started](#getting-started)
    * [Pre-requisites](#pre-requisites)
        * [Hardware](#hardware)
        * [Software](#software)
        * [Operating system](#operating-system)
    * [Setup and running the SampleGame](#setup-and-running-the-samplegame)
        * [Building the SampleGame](#building-the-samplegame)
            * [For End-Users](#for-end-users)
            * [For Local development](#for-local-development)
* [Documentation](#documentation)
* [Visit](#visit)
* [Contribute](#contribute)
* [Support](#support)
* [Known issues](#known-issues)

------

Use the Unreal SpatialGDK sample game to explore how Unreal projects integrate with [SpatialOS](https://improbable.io/games) local deployment.
**Notes**:
* These instructions are for a local deployment only.

## Getting started

### Pre-requisites
To use the Unreal SpatialGDK, you need:

#### Hardware
Recommended:
* Processor: i7
* Memory: 16GB RAM
* Storage: 12GB available space

#### Software

* The SpatialOS Unreal engine built from the [UnrealEngine repo, `UnrealEngine419_SpatialGDK` branch](https://github.com/improbable/UnrealEngine/tree/UnrealEngine419_SpatialGDK).
* The Unreal SpatialGDK module and Unreal Editor plugin.
See *How to set up and run the project* below for details of these.

#### Operating system
* Windows: 10

**Note:** We haven’t tested this project on Windows version 7.

### Setup and running the SampleGame

Once you have cloned the SampleGame in this repository, follow these instructions:

#### Installing the forked UnrealEngine

1. Download and set up the SpatialOS Unreal engine from [https://github.com/improbable/UnrealEngine/tree/UnrealEngine419_SpatialGDK](https://github.com/improbable/UnrealEngine/tree/UnrealEngine419_SpatialGDK).
	* Make sure that you download the `UnrealEngine419_SpatialGDK` branch to get the correct version.
	* Look at the [readme](https://github.com/improbable/UnrealEngine/blob/UnrealEngine419_SpatialGDK/README.md) file for guidance on setting up the SpatialOS Unreal engine and follow steps 1 to 4 in the `UnrealEngine419_SpatialGDK` readme.
2. Create `UNREAL_HOME` environment variable and set to the location of the SpatialOS Unreal engine you have just downloaded.

#### Building the SampleGame

##### For End-Users

1. Locate the Unreal project file for the SampleGame. You’ll find this under the SampleGame's root directory in `/workers/unreal/Game`.
2. Right-click on `SampleGame.uproject` and select **Switch Unreal Engine version...**
3.  Select the path of the engine version you just downloaded.
4. Run `ci/build.sh`
5. Run `spatial worker build --target=local` to build the SampleGame.

##### For Local development

1. Clone the [GDK repo](https://github.com/improbable/unreal-gdk).
2. Run the script `ci/build.sh` within the cloned GDK repo.
3. Run the script `create_spatialGDK_symlink.bat` within the SampleGame repo.
4. Locate the Unreal project file for the SampleGame. You’ll find this under the SampleGame's root directory in `/workers/unreal/Game`.
5. Right-click on `SampleGame.uproject` and select **Switch Unreal Engine version...**
6.  Select the path of the engine version you just downloaded.
7. Run `spatial worker build --target=local` to build the SampleGame.

#### Running the SampleGame
1.  Start the SpatialOS local deployment by running `spatial local launch`.
2.  Double-click on the `SampleGame.uproject` to open the Unreal Editor and select the **Play** drop-down menu to see **Modes** and **Multiplayer Options**.
3.  From the drop-down menu, select **New Editor Window (PIE)**. Enter **Number of Players** as `2` and check the box for **Run Dedicated Server**.
4.	 Click **Play** to run.

## Documentation

## Visit
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

## Contribute
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

##Support
TODO [JIRA ticket DEV-2087](https://improbableio.atlassian.net/browse/DEV-2087)

## Known issues

* The interop code and schema generated for marshalling updates and RPCs has been committed directly to the source tree in `workers/unreal/Game/Source/SampleGame/Generated and schema/improbable/unreal/generated respectively`. This means you only need to re-run the commandlet if you have changed the code generator.
* There are two non-load-balanced launch scripts to assist your development:
    * 'one_worker_test.json' tests that managed workers launch correctly and ensures that entities never cross worker boundaries.
    * 'two_worker_test.json' provides a static non-overlapping worker boundary between two workers to assist your entity migration testing. As worker boundaries don't overlap, workers have no knowledge of an entity which is under the authority of a different worker.

