#!/usr/bin/env bash
set -euo pipefail

###
# build-sfml.sh — сборка SFML 3.0 для Linux или Windows (cross-compile).
# По умолчанию:
#   HOST=Windows -> сборка под Windows (MinGW)
#   иначе       -> сборка под Linux
#
# Устанавливает в $SFML_INSTALL (по умолчанию 3rdparty/sfml/install).
###

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" &> /dev/null && pwd)"
SFML_DIR="$(realpath ${SCRIPT_DIR}/..)/3rdparty/sfml"
SRC_DIR="${SFML_DIR}/src"
BUILD_DIR="${SRC_DIR}/build"
SFML_INSTALL="${SFML_DIR}/install"

SFML_REPO="https://github.com/SFML/SFML.git"
SFML_TAG="2.6.2"

# Компиляторы по-умолчанию
CC_LINUX="gcc"
CXX_LINUX="g++"
CC_WIN="x86_64-w64-mingw32-gcc"
CXX_WIN="x86_64-w64-mingw32-g++"

# Опции CMake
COMMON_CMAKE_FLAGS=(
  "--fresh"
  "-DCMAKE_BUILD_TYPE=Release"
  "-DBUILD_SHARED_LIBS=ON"
  "-DSFML_BUILD_EXAMPLES=OFF"
  "-DSFML_BUILD_DOC=OFF"
  "-DSFML_BUILD_AUDIO=ON"
  "-DSFML_INSTALL_CMAKE_PACKAGE=ON"
  "-DCMAKE_INSTALL_PREFIX=${SFML_INSTALL}"
)

WINDOWS_CMAKE_FLAGS=(
  "-DCMAKE_SYSTEM_NAME=Windows"
  "-DCMAKE_C_COMPILER=${CC_WIN}"
  "-DCMAKE_CXX_COMPILER=${CXX_WIN}"
  "-DCMAKE_SYSTEM_PROCESSOR=x86_64"
)

# 1) Клонируем репозиторий, если нужно
if [[ ! -d "${SRC_DIR}" ]]; then
  mkdir -p "$(dirname "${SRC_DIR}")"
  git clone --branch "${SFML_TAG}" --depth 1 "${SFML_REPO}" "${SRC_DIR}"
fi

# 2) Создаём build-папку
rm -rf "${BUILD_DIR}"
mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

# 3) Формируем флаги в зависимости от хоста
if [[ "${HOST-}" == "Windows" ]]; then
  echo ">>> Cross-compiling SFML ${SFML_TAG} for Windows..."
  CMAKE_FLAGS=("${COMMON_CMAKE_FLAGS[@]}" "${WINDOWS_CMAKE_FLAGS[@]}")
else
  echo ">>> Building SFML ${SFML_TAG} for Linux..."
  CMAKE_FLAGS=("${COMMON_CMAKE_FLAGS[@]}")
fi

# 4) Конфигурируем
cmake .. "${CMAKE_FLAGS[@]}"

# 5) Сборка и установка
cmake --build . --config Release -- -j$(nproc)
cmake --install . --config Release

echo
echo "SFML ${SFML_TAG} has been built and installed to:"
echo "  ${SFML_INSTALL}"

