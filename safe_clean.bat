@ECHO OFF

SET SPATIALGDK_PLUGINSPATH="%~dp0\Game\Plugins\SpatialGDK"
SET SPATIALGDK_MODULEPATH="%~dp0\Game\Source\SpatialGDK"
SET SPATIALGDK_SCRIPTSPATH="%~dp0\Game\Scripts"
SET SPATIALGDK_BINARIESPATH="%~dp0\Game\Binaries\ThirdParty\Improbable"
SET SPATIALGDK_SCHEMAPATH="%~dp0\spatial\schema\improbable\unreal\gdk"

:: First section is for cleaning known UnrealGDK symlinks and running git clean.
SET /p NUKE=Would you like to clean all symlinks, uncommited changes and all built files (git clean -xdf)?[Y/N]: 
IF /I %NUKE% == Y (
    CALL :clean_all_symlinks
    CALL :git_clean_xdf
    GOTO :build_symlinks
)
EXIT /B 0

:: Second section is for rebuilding these symlinks.
:build_symlinks
SET /p BUILDBRIDGES=Would you like to remake symlinks to your Unreal GDK?[Y/N]: 
IF /I %BUILDBRIDGES% == Y (
    SET /p GDKPATH=Please provide the path to your Unreal GDK: 
    CALL :make_symlinks
)
EXIT /B 0

:: All helper methods are below.
:make_symlinks
CALL create_gdk_symlink.bat %GDKPATH% 
EXIT /B 0

:clean_all_symlinks
ECHO Cleaning old symlinks
CALL :clean_path %SPATIALGDK_PLUGINSPATH%
CALL :clean_path %SPATIALGDK_MODULEPATH%
CALL :clean_path %SPATIALGDK_SCRIPTSPATH%
CALL :clean_path %SPATIALGDK_BINARIESPATH%
CALL :clean_path %SPATIALGDK_SCHEMAPATH%
ECHO Finished cleaning up old symlinks
EXIT /B 0

:clean_path
IF EXIST "%~1" (
    RMDIR /s /q "%~1"
    ECHO The symlink "%~1" removed
) ELSE (
    ECHO "%~1" did not exist when performing the clean
)
EXIT /B 0

:git_clean_xdf
ECHO Performing git clean
git clean -xdf
ECHO Finished git clean
EXIT /B 0
