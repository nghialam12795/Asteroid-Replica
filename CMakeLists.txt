# ---------------------------
# Default setup
# ---------------------------
cmake_minimum_required(VERSION 3.1)
set(ASTEROID_VERSION_MAJOR 0)
set(ASTEROID_VERSION_MINOR 0)
set(ASTEROID_VERSION_PATCH 1)
set(ASTEROID_VERSION ${ASTEROID_VERSION_MAJOR}.${ASTEROID_VERSION_MINOR}.${ASTEROID_VERSION_PATCH})

project(ASTEROID)

# for multi arch LIBDIR support (requires cmake>=2.8.8)
INCLUDE(GNUInstallDirs)

# ---------------------------
# Load settings
# ---------------------------
if (NOT ASTEROID_SETTINGS)
    set(ASTEROID_PATH ${CMAKE_CURRENT_SOURCE_DIR})
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${ASTEROID_PATH}/build/cmake/")
    include(asteroid_settings)
endif()

# Define the executable
add_executable(ASTEROID ${PROJECT_SOURCE_DIR}/src/Main.cpp src/game.cpp src/game.h)