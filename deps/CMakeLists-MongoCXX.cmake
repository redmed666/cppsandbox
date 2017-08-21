include(ExternalProject)

#===== MONGOCXX =====#
set(MONGOCXX_VERSION 3.1.2)
set(MONGOCXX "${EXTERNAL_PROJECT_DIR}/mongocxx-${MONGOCXX_VERSION}")

list(APPEND CMAKE_ARGS_MONGOCXX "-DCMAKE_INSTALL_PREFIX=${MONGOCXX}" "-DLIBMONGOC_DIR=${MONGOC}/lib/cmake" "-DLIBBSON_DIR=${LIBBSON}/lib/cmake")


find_path(MONGOCXX_IN_DEPS NAMES lib/libmongocxx.dylib PATHS ${MONGOCXX}/)
if(MONGOCXX_IN_DEPS)

else()
    ExternalProject_Add(
        MONGOCXX_project
        DOWNLOAD_DIR ${MONGOCXX}
        URL https://github.com/mongodb/mongo-cxx-driver/archive/r${MONGOCXX_VERSION}.tar.gz
        SOURCE_DIR "${MONGOCXX}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        CMAKE_ARGS ${CMAKE_ARGS_MONGOCXX}
    )
endif()

add_library(libmongocxx SHARED IMPORTED)
set_property(TARGET libmongocxx PROPERTY IMPORTED_LOCATION ${MONGOCXX}/lib/libmongocxx.dylib)
add_dependencies(libmongocxx MONGOCXX_project)
list(APPEND ExternalSharedLibraries ${MONGOCXX}/lib/libmongocxx.dylib)
list(APPEND RPATH_IMPORTED "${MONGOCXX};")
include_directories(${MONGOCXX}/include)
