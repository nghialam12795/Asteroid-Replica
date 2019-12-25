include_directories("../")

set(SOURCES
      "text.cpp"
      )

set(HEADERS
      "text.h"
      )

add_library(GAME_UI STATIC ${SOURCES} ${HEADERS})

# Need more setting for VSC to regconize this from parent CMAKE
if (WIN32)
      link_directories(${CMAKE_MODULE_PATH})

      include(sdl2_config)
      include(sdl2_image_config)
      include(sdl2_ttf_config)

      include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2TTF_INCLUDE_DIR})
      target_link_libraries(GAME_UI SDL2_LIBRARY SDL2_IMAGE_LIBRARY SDL2TTF_LIBRARY)
endif()