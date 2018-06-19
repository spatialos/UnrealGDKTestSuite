@ECHO OFF

REM When flexible project structure is implemented we can gather this information from the project structure descriptor file.
set GENERATED_SCHEMA="%~dp0spatial\schema\improbable\unreal\generated"
set GENERATED_TYPE_BINDINGS="%~dp0Game\Source\SampleGame\Generated"
set GENERATED_WORKER_FILES="%~dp0Game\Source\SpatialGDK\Generated"

:: If '-a' argument is specified, clean all without prompt 
IF /I "%1"=="-a" (
   CALL :clean_schema
   CALL :clean_type_bindings
   CALL :clean_worker_files
) ELSE (
    GOTO main
)
EXIT /B 0

:: If '-a' does not exist, prompt the user
:main
ECHO This script is intended to clean SampleGame generated files and therefore assumes its project structure.

set /p CLEAN_SCHEMA=Clean generated schema?[Y/N]: 
IF /I %CLEAN_SCHEMA% == Y (
    CALL :clean_schema
)

set /p CLEAN_TYPE_BINDINGS=Clean generated type bindings?[Y/N]: 
IF /I %CLEAN_TYPE_BINDINGS% == Y (
    CALL :clean_type_bindings
)

set /p CLEAN_WORKER_FILES=Clean generated worker code?[Y/N]: 
IF /I %CLEAN_WORKER_FILES% == Y (
    CALL :clean_worker_files
)
EXIT /B 0

:clean_schema
IF EXIST %GENERATED_SCHEMA% (
    rmdir /s /q %GENERATED_SCHEMA%
    echo Generated schema have been sucessfully removed.
) ELSE (
    echo %GENERATED_SCHEMA% did not exist when performing the clean.
)
EXIT /B 0

:clean_type_bindings
IF EXIST %GENERATED_TYPE_BINDINGS% (
    rmdir /s /q %GENERATED_TYPE_BINDINGS%
    echo Generated type bindings have been sucessfully removed.
) ELSE (
    echo %GENERATED_TYPE_BINDINGS% did not exist when performing the clean.
)
EXIT /B 0

:clean_worker_files
IF EXIST %GENERATED_WORKER_FILES% (
    rmdir /s /q %GENERATED_WORKER_FILES%
    echo Generated worker code has been sucessfully removed.
) ELSE (
    echo %GENERATED_WORKER_FILES% did not exist when performing the clean.
)
EXIT /B 0

:done