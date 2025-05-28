#!/bin/bash
set -e

if [[ $HOST == "" ]] then
    HOST=Windows
fi

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
SDL_DIR="$(realpath ${SCRIPT_DIR}/..)/3rdparty/SDL"
SRC_DIR="${SDL_DIR}/src"
INSTALL_DIR="${SDL_DIR}/install"

CONFIG_FLAGS="-DCMAKE_INSTALL_PREFIX=${INSTALL_DIR}"
if [[ $HOST == "Windows" ]] then
    CONFIG_FLAGS="$CONFIG_FLAGS -DCMAKE_TOOLCHAIN_FILE=${SCRIPT_DIR}/../scripts/sdl2-mingw-toolchain.cmake"
fi

mkdir -pv $SDL_DIR

if [[ ! -d $SRC_DIR ]]; then
    git clone --depth=1 https://github.com/libsdl-org/SDL.git -b SDL2 $SRC_DIR
fi

cd $SRC_DIR
rm -rf build
mkdir -v build
cd build

cmake .. \
    $CONFIG_FLAGS

cmake --build .
cmake --install .

cd $SDL_DIR

rm -rf $SRC_DIR
echo -------------------------------------------------------
echo SDL library successfully installed to $INSTALL_DIR
