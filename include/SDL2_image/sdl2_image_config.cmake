set(SDL2_IMAGE_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include")

# Support both 32 and 64 bit builds
if (${CMAKE_SIZEOF_VOID_P} MATCHES 8)
    set(SDL2_IMAGE_LIBRARY "${CMAKE_CURRENT_LIST_DIR}/lib/x64/SDL2_image.lib")
else ()
    set(SDL2_IMAGE_LIBRARY "${CMAKE_CURRENT_LIST_DIR}/lib/x86/SDL2_image.lib")
endif ()

string(STRIP "${SDL2_IMAGE_LIBRARY}" SDL2_IMAGE_LIBRARY)

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(SDL2_IMAGE
        REQUIRED_VARS SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY
        VERSION_VAR SDL2_IMAGE_VERSION_STRING)

mark_as_advanced(SDL2_IMAGE_INCLUDE_DIR SDL2_IMAGE_LIBRARY)