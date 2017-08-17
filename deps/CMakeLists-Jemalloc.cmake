include(ExternalProject)

#===== JEMALLOC =====#
set(JEMALLOC_VERSION 4.5.0)
set(JEMALLOC "${EXTERNAL_PROJECT_DIR}/jemalloc-${JEMALLOC_VERSION}")

find_path(JEMALLOC_IN_DEPS NAMES lib/libjemalloc.2.dylib PATHS ${JEMALLOC}/)
if(JEMALLOC_IN_DEPS)

else()
    ExternalProject_Add(
        jemalloc_project
        DOWNLOAD_DIR ${JEMALLOC}
        GIT_REPOSITORY git@github.com:jemalloc/jemalloc.git
        SOURCE_DIR "${JEMALLOC}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        GIT_TAG ${JEMALLOC_VERSION}
        CONFIGURE_COMMAND "./autogen.sh"
        BUILD_COMMAND "make"
        INSTALL_COMMAND ""
    )
endif()

add_library(jemalloc SHARED IMPORTED)
set_property(TARGET jemalloc PROPERTY IMPORTED_LOCATION ${JEMALLOC}/lib/libjemalloc.2.dylib)
add_dependencies(jemalloc jemalloc_project)
list(APPEND ExternalSharedLibraries ${JEMALLOC}/lib/libjemalloc.2.dylib)
list(APPEND RPATH_IMPORTED "${JEMALLOC}/lib;")
include_directories(${JEMALLOC}/include)
