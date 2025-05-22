cmake_minimum_required(VERSION 3.15)
project(conveyor)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# Options for cross-compilation
# To build for Windows on Linux: pass -DCMAKE_SYSTEM_NAME=Windows -DCMAKE_SYSTEM_PROCESSOR=x86_64
# To build on Windows natively: just run cmake normally

# Source files
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")
file(GLOB_RECURSE SRC_FILES "${SRC_DIR}/*.cpp")

# Add executable
add_executable(conveyor ${SRC_FILES})

# Find SFML 3.0
# Usage: add -DSFML_DIR=/path/to/your/sfml3/install if using custom build
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/3rdparty/sfml/install")
find_package(SFML 3.0 COMPONENTS Graphics Window System REQUIRED)
if(TARGET SFML::Graphics)
    target_link_libraries(conveyor PRIVATE SFML::Graphics SFML::Window SFML::System)
else()
    message(FATAL_ERROR "Could not find SFML 3.0 libraries.")
endif()

# Installation rules
install(TARGETS conveyor RUNTIME DESTINATION bin)

# Include system runtime libs for packaging
include(InstallRequiredSystemLibraries)

# Packaging configuration with CPack
# For any build on Windows (native or cross), generate ZIP with exe and DLLs
if(WIN32 OR CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(CPACK_GENERATOR "ZIP")
    set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CMAKE_SYSTEM_NAME}")

    # Copy SFML DLLs (if SFML_DIR provided)
    if(DEFINED SFML_DIR)
        install(DIRECTORY "${SFML_DIR}/bin/" DESTINATION . FILES_MATCHING PATTERN "*.dll")
    endif()

    include(CPack)

    # Custom target 'dist' to build and package in one go
    add_custom_target(dist
        COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target package
        COMMENT "Building and packaging Windows distribution"
    )
endif()

