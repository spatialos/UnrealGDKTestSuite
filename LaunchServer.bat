@echo off

pushd "%~dp0\spatial"

spatial worker build build-config

popd

call "%~dp0ProjectPaths.bat"
"%UNREAL_HOME%\Engine\Binaries\Win64\UE4Editor.exe" "%~dp0%PROJECT_PATH%\%GAME_NAME%.uproject" ThirdPersonExampleMap -server -log -workerType UnrealWorker -stdout -nowrite -unattended -nologtimes -nopause -noin -messaging -SaveToUserDir -NoVerifyGC -windowed -resX=400 -resY=300
