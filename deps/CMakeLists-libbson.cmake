include(ExternalProject)

#===== LIBBSON =====#
set(LIBBSON_VERSION 1.0.0)
set(LIBBSON "${EXTERNAL_PROJECT_DIR}/libbson-${LIBBSON_VERSION}")

find_path(LIBBSON_IN_DEPS NAMES lib/libbson-${LIBBSON_VERSION}.dylib PATHS ${LIBBSON}/)
if(LIBBSON_IN_DEPS)

else()
    ExternalProject_Add(
        LIBBSON_project
        DOWNLOAD_DIR ${LIBBSON}
        URL https://github.com/mongodb/libbson/archive/master.zip
        SOURCE_DIR "${LIBBSON}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        CMAKE_ARGS
            "-DCMAKE_INSTALL_PREFIX=${LIBBSON}"
    )
endif()

add_library(libbson SHARED IMPORTED)
set_property(TARGET libbson PROPERTY IMPORTED_LOCATION ${LIBBSON}/lib/libbson-${LIBBSON_VERSION}.dylib)
add_dependencies(libbson LIBBSON_project)
list(APPEND ExternalSharedLibraries ${LIBBSON}/lib/libbson-${LIBBSON_VERSION}.dylib)
list(APPEND RPATH_IMPORTED "${LIBBSON};")
include_directories(${LIBBSON}/include)
