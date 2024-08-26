#!/bin/bash

EMSDK_VERSION='3.1.50'
QT_VERSION_MINOR='1'
QT_VERSION_BASE='6.7'
QT_VERSION="$QT_VERSION_BASE.$QT_VERSION_MINOR"

QT_PACKAGE="qt-everywhere-src-$QT_VERSION"
QT_CMAKE_PREFIX='/usr/lib/cmake'
SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cd $SCRIPT_DIR
echo $SCRIPT_DIR

mkdir -p qt-wasm
cd qt-wasm

if [ ! -d "emsdk" ]; then
    git clone https://github.com/emscripten-core/emsdk
fi

cd emsdk
./emsdk install $EMSDK_VERSION
./emsdk activate $EMSDK_VERSION
source ./emsdk_env.sh
cd ..


if [ ! -d "$QT_PACKAGE" ]; then
    wget "https://download.qt.io/official_releases/qt/$QT_VERSION_BASE/$QT_VERSION/single/$QT_PACKAGE.tar.xz"
    tar xf "$QT_PACKAGE.tar.xz"
    rm "$QT_PACKAGE.tar.xz"
fi

mkdir -p build
cd build

../$QT_PACKAGE/configure -qt-host-path "/usr/" -platform wasm-emscripten -prefix $PWD/qtbase -- "-DQt6HostInfo_DIR=$QT_CMAKE_PREFIX/Qt6HostInfo/" "-DQt6CoreTools_DIR=$QT_CMAKE_PREFIX/Qt6CoreTools/" "-DQt6WidgetsTools_DIR=$QT_CMAKE_PREFIX/Qt6WidgetsTools/" "-DQt6GuiTools_DIR=$QT_CMAKE_PREFIX/Qt6GuiTools/" "-DQt6ShaderToolsTools_DIR=$QT_CMAKE_PREFIX/Qt6ShaderToolsTools/" "-DQt6QmlTools_DIR=$QT_CMAKE_PREFIX/Qt6QmlTools/" "-DQt6Quick3DTools_DIR=$QT_CMAKE_PREFIX/Qt6Quick3DTools/" "-DQt6LinguistTools_DIR=$QT_CMAKE_PREFIX/Qt6LinguistTools/" "-DQt6ToolsTools_DIR=$QT_CMAKE_PREFIX/Qt6ToolsTools/" "-DQt6RemoteObjectsTools_DIR=$QT_CMAKE_PREFIX/Qt6RemoteObjectsTools/" "-DQt6ScxmlTools_DIR=$QT_CMAKE_PREFIX/Qt6ScxmlTools/"

cmake --build . -t qtbase -t qtdeclarative -t qtsvg -t qtimageformats

