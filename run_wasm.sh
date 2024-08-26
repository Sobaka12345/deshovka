SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $SCRIPT_DIR

source $SCRIPT_DIR/qt-wasm/emsdk/emsdk_env.sh

emrun $SCRIPT_DIR/build-wasm/release/frontend/deshovka_frontend.html
