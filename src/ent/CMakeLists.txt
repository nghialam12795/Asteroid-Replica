set(SOURCES
      "entity.cpp"
      "player.cpp"
      )

set(HEADERS
      "entity.h"
      "player.h"
      )

add_library(GAME_ENTITIES STATIC ${SOURCES} ${HEADERS})

# Need more setting for VSC to regconize this from parent CMAKE
if (WIN32)
    link_directories(${CMAKE_MODULE_PATH})

    include(sdl2_config)
    include(sdl2_image_config)
    include(sdl2_ttf_config)

    include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
    target_link_libraries(GAME_ENTITIES SDL2_LIBRARY SDL2_IMAGE_LIBRARY SDL2_TTF_LIBRARY)
endif()