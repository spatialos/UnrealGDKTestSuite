# SpatialOS GDK Test Suite
LICENSE: Use of the contents of this repository is subject to the [Improbable license](LICENSE.md)
REPOSITORY: [github.com/spatialos/UnrealGDKTestSuite](https://github.com/spatialos/UnrealGDKTestSuite)

This project contains a test suite which uses the [SpatialOS GDK for Unreal](https://github.com/spatialos/UnrealGDK). 

You can use the Test Suite to to validate the functionality of the SpatialOS GDK. The test suite has tests for several key components of the GDK such as Actor replication and the execution of RPCs.

For setup instructions, follow the [Get started](https://docs.improbable.io/unreal/latest/content/get-started/introduction) guide in the GDK for Unreal documentation. This guide uses the [GDK for Unreal Starter Project](https://github.com/spatialos/UnrealGDKStarterProject) as an example. When you follow the installation instructions, you need to replace the "Starter Project" repository with the [Test Suite](https://github.com/spatialos/UnrealGDKTestSuite) one.

For more information, see the [SpatialOS GDK for Unreal documentation](https://docs.improbable.io/unreal/latest/).

####  Helper scripts

This repository contains a set of helper scripts to get you started.

| Helper script | Description |
| --- | --- |
| `LaunchSpatial.bat` | Starts a local SpatialOS deployment with the default launch configuration. |
| `LaunchServer.bat` | Starts an Unreal server-worker, and connects it to the local deployment. |
| `LaunchClient.bat` | Starts an Unreal client-worker, and connects it to the local deployment. |
| `ProjectPaths.bat` | Used by the `LaunchClient.bat`, `LaunchServer.bat` and `LaunchSpatial.bat` to specify the project environment when those scripts are run. |

#### Game controls

The following controls are bound in-game, for gameplay and testing.

| Key binding | Function |
| --- | --- |
| W,A,S,D | Standard movement |
| Space | Jump |
| Shift | Sprint |
| K | Trigger test suite execution |

#### Give us feedback
We have released the GDK for Unreal this early in development because we want your feedback. Please come and talk to us about the software and the documentation via: [Discord](https://discordapp.com/channels/311273633307951114/339471548647866368) - [Forums](https://forums.improbable.io/) - [GitHub issues in this repository](https://github.com/spatialos/UnrealGDK/issues).

#### Where to get the GDK and example projects
The GDK and its starter projects are available on GitHub.
* [GDK: github.com/spatialos/UnrealGDK](https://github.com/spatialos/UnrealGDK)
* [The SpatialOS Unreal Engine](https://github.com/improbableio/UnrealEngine/tree/4.20-SpatialOSUnrealGDK)
**NOTE:** This link may give you a 404.
* [Starter Project](https://github.com/spatialos/UnrealGDKStarterProject)
* [Third-Person Shooter game](https://github.com/spatialos/UnrealGDKThirdPersonShooter) (Not actively developed)
* [The Test Suite](https://github.com/spatialos/UnrealGDKTestSuite)

#### Public contributors
We are not currently accepting public contributions. However, we are accepting [issues](https://github.com/spatialos/UnrealGDK/issues) and we do want your feedback.

#### Known issues

* The character currently fires without animations while mid-jump.
* The character sometimes rotates very quickly when running and looking in different directions.
* The scoreboard occasionally does not initialize properly.

&copy; 2018 Improbable