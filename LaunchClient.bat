@echo off
set /p PROJECT_PATH=<"%~dp0project.path"
"%UNREAL_HOME%\Engine\Binaries\Win64\UE4Editor.exe" "%~dp0%PROJECT_PATH%\TestSuite.uproject" -game -log -workerType UnrealClient -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -NoVerifyGC -windowed -ResX=800 -ResY=600
