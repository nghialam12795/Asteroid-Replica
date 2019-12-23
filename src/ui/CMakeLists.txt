include_directories("${ASTEROID_PATH}/src" "../../src")

set(SOURCES
      "text.cpp"
      )

set(HEADERS
      "text.h"
      )

add_library(GAME_UI STATIC ${SOURCES} ${HEADERS})