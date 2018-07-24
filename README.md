# SpatialOS Unreal GDK Test Suite

## Introduction

You can use the SpatialOS Unreal GDK Test Suite for testing and validating your development with the SpatialOS Unreal GDK.

For more information, see the [SpatialOS Unreal GDK repository](https://github.com/improbable/UnrealGDK) and its [documentation](https://github.com/improbable/UnrealGDK/blob/master/docs/readme.md).

## Helper scripts

| Helper script | Parameters | Description |
| --- | --- | --- |
| CleanGeneratedFiles.bat | `[-a]` | Cleans generated schema and/or type bindings and/or worker code. Call with `-a` flag to clean everything without prompting. |
| CreateGDKSymlinks.bat | `[Unreal GDK path]` | Creates symlinks to the directories in the Unreal GDK containing the SpatialGDK module, plugins, scripts, binaries, and schema. |
| SafeClean.bat | `[-a]` | Cleans the symlinks, uncommitted changes, and all built files. Call with `-a` flag to clean everything without prompting. Optionally calls `CreateGDKSymlinks.bat` to restore the symlinks. |