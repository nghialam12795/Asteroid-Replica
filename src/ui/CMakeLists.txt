include_directories("../")

set(SOURCES
      "text.cpp"
      )

set(HEADERS
      "text.h"
      )

add_library(GAME_UI SHARED STATIC ${SOURCES} ${HEADERS})

# Need more setting for VSC to regconize this from parent CMAKE
link_directories(${CMAKE_MODULE_PATH})

if (WIN32)
    include(sdl2_config) # For fixing weird bug of not found the SDL2 library on Window
    include(sdl2_image_config)
    include(sdl2_ttf_config)
else()
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
endif()

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR})
target_link_libraries(GAME_UI SDL2_LIBRARY SDL2_IMAGE_LIBRARY SDL2TTF_LIBRARY)
