@ECHO OFF

set SPATIALGDK_LOCATION="%1"

if %SPATIALGDK_LOCATION% == "" (
	echo Error: Please specify the SpatialGDK clone directory.
	exit 1
)

if not exist %SPATIALGDK_LOCATION%\ (
	echo Error: SpatialGDK location not valid.
	exit 1
)

rmdir "%~dp0\workers\unreal\Game\Plugins"
mklink /J "%~dp0\workers\unreal\Game\Plugins" %SPATIALGDK_LOCATION%\Plugins
rmdir "%~dp0\workers\unreal\Game\Source\SpatialGDK"
mklink /J "%~dp0\workers\unreal\Game\Source\SpatialGDK" %SPATIALGDK_LOCATION%\SpatialGDK

echo Successfully created symlinks to %SPATIALGDK_LOCATION%

exit 0