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
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
            "${ASTEROID_PATH}/build/cmake/"
            "${ASTEROID_PATH}/build/cmake/extern_lib"
            )
    include(asteroid_settings)
endif()

# Define the executable
add_subdirectory(src)
add_executable(ASTEROID ${PROJECT_SOURCE_DIR}/src/Main.cpp) # Main file

# --------------------------------------------------
# For library using in this project
# --------------------------------------------------

############## External ##############
link_directories(${CMAKE_MODULE_PATH})
# TODO(nghialam): Fix Cannot find SDL2_LIBRARY on Window (currently 32bit)
# SDL2
find_package(SDL2 REQUIRED)

if (NOT SDL2_FOUND)
    MESSAGE(FATAL_ERROR "SDL2 is required to build this game !!")
else()
    include_directories(${SDL2_INCLUDE_DIRS})
endif()

############## Internal ##############
target_link_libraries(ASTEROID GAME_SRC ${SDL2_LIBRARY})