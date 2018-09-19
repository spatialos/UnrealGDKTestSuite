@echo off
echo Starting a local Spatial deployment with the default launch configuration. Modify LaunchSpatial.bat if you want to use a different launch configuration.

pushd "%~dp0\spatial"

rem To launch a local Spatial deployment with a different launch configuration, change the default_launch.json argument to the name of your configuration file, 
rem for example one_worker_test.json or two_worker_test.json
spatial worker build build-config default_launch.json

spatial local launch
popd