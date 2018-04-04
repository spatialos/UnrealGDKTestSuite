# Spatial GDK Sample Game: Unreal project demonstrating SpatialOS integration

## How to run:

- Build the engine fork, which can be found at `https://github.com/improbable/UnrealEngine`. Make sure to check out the `UnrealEngine417_NUF` branch.
- Set UNREAL_HOME environment variable to the engine fork location.
- Set the uproject to use the engine fork.
- Download the Spatial GDK code and tools from `https://github.com/improbable/native-unreal-framework`.
- `create_spatialGDK_symlink.bat <Spatial GDK path>`
- `spatial worker build --target=local`
- `spatial local launch`
- Launch PIE with dedicated server + 1 player.

The interop code and schema generated for marshalling updates and RPCs has been committed directly to the source tree in `workers/unreal/Game/Source/SampleGame/Generated` and `schema/improbable/unreal/generated` respectively. This means you only need to re-run the commandlet if you have changed the code generator.

There are also two non-load-balanced launch scripts to assist your development: 'one_worker_test.json' tests that managed workers launch correctly and ensures that entities never cross worker boundaries. 'two_worker_test.json' provides a static non-overlapping worker boundary between two workers to assist your entity migration testing. As worker boundaries don't overlap, workers have no knowledge of an entity which is under the authority of a different worker.
