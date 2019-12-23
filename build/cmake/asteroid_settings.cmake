# C++17 Support
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
endif()

# Setting output path
if(APPLE)
    set(OUTPUT_DIR "${ASTEROID_PATH}/out/mac")
elseif(UNIX)
    set(OUTPUT_DIR "${ASTEROID_PATH}/out/linux")
else()
    set(OUTPUT_DIR "${ASTEROID_PATH}/out/window")
endif()

# Setting release path
if(APPLE)
    set(RELEASE_DIR "${ASTEROID_PATH}/release/mac")
elseif(UNIX)
    set(RELEASE_DIR "${ASTEROID_PATH}/release/linux")
else()
    set(RELEASE_DIR "${ASTEROID_PATH}/release/window")
endif()


# Setting structure
set(ASTEROID_BIN "bin")
set(ASTEROID_LIB "lib")
if (MSVC)
    if(NOT "${CMAKE_GENERATOR}" MATCHES "(Win64|IA64)")
        set(ASTEROID_BIN "bin32")
        set(ASTEROID_LIB "lib32")
    endif()
endif()

# DEBUG
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR}/${ASTEROID_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/${ASTEROID_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DIR}/${ASTEROID_BIN})

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${OUTPUT_DIR}/${ASTEROID_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/${ASTEROID_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DIR}/${ASTEROID_BIN})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${OUTPUT_DIR}/${ASTEROID_LIB})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${OUTPUT_DIR}/${ASTEROID_LIB})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELWITHDEBINFO ${OUTPUT_DIR}/${ASTEROID_LIB})

# RELEASE
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RELEASE_DIR}/${ASTEROID_BIN})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${RELEASE_DIR}/${ASTEROID_BIN})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${RELEASE_DIR}/${ASTEROID_LIB})


file(COPY ${ASTEROID_PATH}/res DESTINATION ${OUTPUT_DIR})
file(COPY ${ASTEROID_PATH}/res DESTINATION ${RELEASE_DIR})
