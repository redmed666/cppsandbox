include(ExternalProject)

#===== CURL =====#
set(CURL_VERSION 7.54.1)
set(CURL "${EXTERNAL_PROJECT_DIR}/curl-${CURL_VERSION}")

find_path(CURL_IN_DEPS NAMES lib/libcurl.dylib PATHS ${CURL}/)
if(CURL_IN_DEPS)

else()
    ExternalProject_Add(
        CURL_project
        DOWNLOAD_DIR ${CURL}
        URL https://curl.haxx.se/download/curl-${CURL_VERSION}.tar.gz
        SOURCE_DIR "${CURL}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        BUILD_COMMAND make
        INSTALL_COMMAND make install
        CMAKE_ARGS
            "-DCMAKE_INSTALL_PREFIX=${CURL}"
    )
endif()

add_library(libcurl SHARED IMPORTED)
set_property(TARGET libcurl PROPERTY IMPORTED_LOCATION ${CURL}/lib/libcurl.dylib)
add_dependencies(libcurl CURL_project)
list(APPEND ExternalSharedLibraries ${CURL}/lib/libcurl.dylib)
list(APPEND RPATH_IMPORTED "${CURL};")
include_directories(${CURL}/include)
