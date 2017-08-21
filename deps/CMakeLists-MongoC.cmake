include(ExternalProject)

#===== MONGOC =====#
set(MONGOC_VERSION 1.0.0)
set(MONGOC "${EXTERNAL_PROJECT_DIR}/mongoc-${MONGOC_VERSION}")
list(APPEND CMAKE_ARGS_MONGOC "-DCMAKE_INSTALL_PREFIX=${MONGOC}/lib/cmake" "-DCMAKE_PREFIX_PATH=${LIBBSON}/lib/cmake")

find_path(MONGOC_IN_DEPS NAMES libmongoc-1.0.0.dylib PATHS ${MONGOC}/)
if(MONGOC_IN_DEPS)

else()
    ExternalProject_Add(
        MONGOC_project
        DOWNLOAD_DIR ${MONGOC}
        URL https://github.com/mongodb/mongo-c-driver/archive/master.zip
        SOURCE_DIR "${MONGOC}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        CMAKE_ARGS ${CMAKE_ARGS_MONGOC} 
    )
endif()

add_library(libmongoc SHARED IMPORTED)
set_property(TARGET libmongoc PROPERTY IMPORTED_LOCATION ${MONGOC}/libmongoc-1.0.0.dylib)
add_dependencies(libmongoc MONGOC_project)
list(APPEND ExternalSharedLibraries ${MONGOC}/libmongoc-1.0.0.dylib)
list(APPEND RPATH_IMPORTED "${MONGOC};")
include_directories(${MONGOC}/include)
