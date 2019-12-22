set(SOURCES
      "entity.cpp"
      "player.cpp"
      )

set(HEADERS
      "entity.h"
      "player.h"
      )

add_library(GAME_ENTITIES STATIC ${SOURCES} ${HEADERS})