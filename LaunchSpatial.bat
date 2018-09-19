@echo off
echo Starting Spatial with the default launch configuration. Modify LaunchSpatial.bat if you want to use a different launch configuration.

pushd "%~dp0\spatial"
spatial worker build build-config

spatial local launch
popd