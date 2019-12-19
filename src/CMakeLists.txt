set(SOURCES
        "assets.cpp"
        "constant.cpp"
        "entity.cpp"
        "game.cpp"
        )

set(HEADERS
        "assets.h"
        "entity.h"
        "game.h"
        )

add_library(GAME_SRC STATIC ${SOURCES} ${HEADERS})
target_include_directories(GAME_SRC PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})