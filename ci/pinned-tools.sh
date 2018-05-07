#!/usr/bin/env bash

# Function declarations
if [ -z "$IMPROBABLE_TOOLS" ]; then
    echo "The internal tools share is not set up correctly on this machine. Please follow the setup instructions here before running build.sh: https://brevi.link/internal-tools-share"
    exit 1
fi

function isLinux() {
  [[ "$(uname -s)" == "Linux" ]];
}

function isMacOS() {
  [[ "$(uname -s)" == "Darwin" ]];
}

function isWindows() {
  ! ( isLinux || isMacOS );
}

function getPlatformName() {
  if isLinux; then
    echo "linux"
  elif isMacOS; then
    echo "mac"
  elif isWindows; then
    echo "windows"
  else
    echo "ERROR: Unknown platform." >&2
    exit 1
  fi
}

function isTeamCity() {
  # -n == string comparison "not null"
  [ -n "${TEAMCITY_CAPTURE_ENV+x}" ]
}

function isNotTeamCity() {
  # -z == string comparison "null, that is, 0-length"
  [ -z "${TEAMCITY_CAPTURE_ENV+x}" ]
}

function runSpatial() {
  local default_flags=(
    "--log_level=debug"
  )

  forceSpatialCliStructureV2
  spatial "$@" "${default_flags[@]}"
}

# The current version of Unreal.
UNREAL_VERSION="419-SpatialGDK"
UNREAL_HOME="C:/Unreal/UnrealEngine-${UNREAL_VERSION}"

# LINUX_MULTIARCH_ROOT is used by Unreal when cross compiling Linux workers
# as Unreal only builds on windows otherwise. The Linux cross compiling tools
# should be automatically installed by puppet as part of the Unreal Engine
# installation.
LINUX_MULTIARCH_ROOT="${UNREAL_HOME}/ClangToolchain"

export UNREAL_HOME
export LINUX_MULTIARCH_ROOT