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
            "${ASTEROID_PATH}/include/SDL2"
            "${ASTEROID_PATH}/include/SDL2_image"
            "${ASTEROID_PATH}/include/SDL2_ttf"
            )
    include(asteroid_settings)
endif()

# Define the executable
add_subdirectory(src/ent)
add_subdirectory(src/ui)
file(GLOB_RECURSE ASTEROID_SOURCE "${PROJECT_SOURCE_DIR}/src/*.cpp") # Include all sources
add_executable(ASTEROID ${ASTEROID_SOURCE})

# --------------------------------------------------
# For library using in this project
# --------------------------------------------------

link_directories(${CMAKE_MODULE_PATH})
##################### External ######################
# SDL2
if (WIN32)
    include(sdl2_config) # For fixing weird bug of not found the SDL2 library on Window
    include(sdl2_image_config)
    include(sdl2_ttf_config)
else()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR})
target_link_libraries(ASTEROID ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2TTF_LIBRARY})

##################### Internal ######################
target_link_libraries(ASTEROID ${GAME_ENTITIES} ${GAME_UI})
