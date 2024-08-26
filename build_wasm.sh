SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $SCRIPT_DIR

source $SCRIPT_DIR/qt-wasm/emsdk/emsdk_env.sh

mkdir -p build-wasm
cd build-wasm
mkdir -p release
cd release

$SCRIPT_DIR/qt-wasm/build/qtbase/bin/qt-cmake $SCRIPT_DIR -DCMAKE_BUILD_TYPE=Release
cmake --build .
