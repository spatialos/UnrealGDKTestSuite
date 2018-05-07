#!/usr/bin/env bash

set -e -u -x -o pipefail

cd "$(dirname "$0")/../"

source ci/force_spatial_cli_structure.sh
source ci/pinned-tools.sh
source ci/profiling.sh

if ! isWindows ; then
  echo "SampleGame can only be built on Windows."
  exit 0
fi

markStartOfBlock "$0"

markStartOfBlock "Clean gdk build directory"

rm -rf build/unreal-gdk/

markEndOfBlock "Make gdk build directory"

markStartOfBlock "Make gdk build directory"

mkdir -p "build/"

markEndOfBlock "Make gdk build directory"

markStartOfBlock "Clone the GDK from github"

pushd "build/"

git clone git@github.com:improbable/unreal-gdk.git -b feature/UNR-210-setup-script

popd

markEndOfBlock "Clone the GDK from github"

markStartOfBlock "Run the GDK setup script"

pushd "build/unreal-gdk"

./setup.sh ../../

popd

markEndOfBlock "Run the GDK setup script"

markStartOfBlock "Build the SampleGame"

runSpatial build --target=local

markEndOfBlock "Build the SampleGame"

markEndOfBlock "$0"
