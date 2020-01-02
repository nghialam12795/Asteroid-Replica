set(SDL2TTF_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2TTF_LIBRARY "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_ttf.lib")
else ()
    set(SDL2TTF_LIBRARY "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_ttf.lib")
endif ()

string(STRIP "${SDL2TTF_LIBRARY}" SDL2TTF_LIBRARY)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2_TTF
        REQUIRED_VARS SDL2TTF_INCLUDE_DIR SDL2TTF_LIBRARY
        VERSION_VAR SDL2_TTF_VERSION_STRING)

mark_as_advanced(SDL2TTF_INCLUDE_DIR SDL2TTF_LIBRARY)