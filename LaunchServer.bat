@echo off
set /p PROJECT_PATH=<"%~dp0project-path"
"%UNREAL_HOME%\Engine\Binaries\Win64\UE4Editor.exe" "%~dp0%PROJECT_PATH%\TestSuite.uproject" ThirdPersonExampleMap -server -log -workerType UnrealWorker -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -SaveToUserDir -NoVerifyGC -windowed -resX=400 -resY=300
