@ECHO OFF

set SPATIALGDK_PATH="%1\"
set SPATIALGDK_PLUGINSPATH="%1\Plugins"
set SPATIALGDK_MODULEPATH="%1\SpatialGDK"

if %SPATIALGDK_PATH% == "" (
	echo Error: Please specify the SpatialGDK path.
	pause > nul
	exit 1
)

if not exist %SPATIALGDK_PATH%\ (
	echo Error: SpatialGDK path %SPATIALGDK_PATH% does not exist.
	exit 1
)

set PATH_VALID=true
if not exist %SPATIALGDK_PLUGINSPATH% set PATH_VALID=false
if not exist %SPATIALGDK_MODULEPATH% set PATH_VALID=false

if %PATH_VALID%==false (
 	echo Error: SpatialGDK path %SPATIALGDK_PATH% is invalid. Provide path to cloned SpatialGDK git repository.
	exit 1
)

rmdir "%~dp0\workers\unreal\Game\Plugins"
mklink /J "%~dp0\workers\unreal\Game\Plugins" %SPATIALGDK_PLUGINSPATH%
rmdir "%~dp0\workers\unreal\Game\Source\SpatialGDK"
mklink /J "%~dp0\workers\unreal\Game\Source\SpatialGDK" %SPATIALGDK_MODULEPATH%

echo Successfully created symlinks to %SPATIALGDK_PATH%

exit 0