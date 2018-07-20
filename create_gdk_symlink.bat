@echo off

set SPATIALGDK_PATH="%1"
set SPATIALGDK_PLUGINSPATH="%1\Plugins\SpatialGDK"
set SPATIALGDK_MODULEPATH="%1\Source\SpatialGDK"
set SPATIALGDK_SCRIPTSPATH="%1\Scripts"
set SPATIALGDK_BINARIESPATH="%1\Binaries\ThirdParty\Improbable"
set SPATIALGDK_SCHEMAPATH="%1\schema\improbable\unreal\gdk"

if %SPATIALGDK_PATH% == "" (
	echo Error: Please specify the SpatialGDK path.
	pause
	exit /b 1
)

if not exist %SPATIALGDK_PATH%\ (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% does not exist.
	pause
	exit /b 1
)

set PATH_VALID=true
if not exist %SPATIALGDK_PLUGINSPATH% set PATH_VALID=false
if not exist %SPATIALGDK_MODULEPATH% set PATH_VALID=false
if not exist %SPATIALGDK_SCHEMAPATH% set PATH_VALID=false

if %PATH_VALID% == false (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% is invalid. Provide path to cloned SpatialGDK git repository.
	pause
	exit /b 1
)

set REPO_PREPARED=true
if not exist %SPATIALGDK_SCRIPTSPATH% set REPO_PREPARED=false
if not exist %SPATIALGDK_BINARIESPATH% set REPO_PREPARED=false

if %REPO_PREPARED% == false (
	echo Error: The specified SpatialGDK directory has not been prepared. Please run Build.bat in that directory.
	pause
	exit /b 1
)

rem Cleanup old symlinks
rd "%~dp0Game\Plugins\SpatialGDK" 2>nul
rd "%~dp0Game\Source\SpatialGDK" 2>nul
rd "%~dp0Game\Scripts" 2>nul
rd "%~dp0Game\Binaries\ThirdParty\Improbable" 2>nul
rd "%~dp0spatial\schema\improbable\unreal\gdk" 2>nul

rem Ensure plugins folder exists, mklink doesn't recursively create
if not exist %~dp0Game\Plugins\ (
	md %~dp0Game\Plugins\
)

rem Ensure codegen folder exists, mklink doesn't recursively create
if not exist %~dp0Game\Binaries\ThirdParty\ (
	md %~dp0Game\Binaries\ThirdParty\
)

rem Ensure schema folder exists, mklink doesn't recursively create
if not exist %~dp0spatial\schema\improbable\unreal\ (
	md %~dp0spatial\schema\improbable\unreal\
)

rem Make new symlinks
mklink /J "%~dp0Game\Plugins\SpatialGDK" %SPATIALGDK_PLUGINSPATH%
mklink /J "%~dp0Game\Source\SpatialGDK" %SPATIALGDK_MODULEPATH%
mklink /J "%~dp0Game\Scripts" %SPATIALGDK_SCRIPTSPATH%
mklink /J "%~dp0Game\Binaries\ThirdParty\Improbable" %SPATIALGDK_BINARIESPATH%
mklink /J "%~dp0spatial\schema\improbable\unreal\gdk" %SPATIALGDK_SCHEMAPATH%

echo Successfully created symlinks to %SPATIALGDK_PATH%

exit /b 0
