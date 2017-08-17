include(ExternalProject)

#===== OPENSSL =====#
set(OPENSSL_VERSION 1.0.2k)
set(OPENSSL "${EXTERNAL_PROJECT_DIR}/openssl-${OPENSSL_VERSION}")

find_path(OPENSSL_IN_DEPS NAMES libssl.1.0.0.dylib PATHS ${OPENSSL}/)
if(OPENSSL_IN_DEPS)

else()
    ExternalProject_Add(
        openssl_project
        DOWNLOAD_DIR ${OPENSSL}
        URL https://www.openssl.org/source/openssl-${OPENSSL_VERSION}.tar.gz
        SOURCE_DIR "${OPENSSL}"
        BUILD_IN_SOURCE 1
        UPDATE_COMMAND ""
        CONFIGURE_COMMAND CFLAGS=-fPIC ./Configure darwin64-x86_64-cc shared
        BUILD_COMMAND "make"
        INSTALL_COMMAND ""
    )
endif()

add_library(libssl SHARED IMPORTED)
add_library(libcrypto SHARED IMPORTED)
set_property(TARGET libssl PROPERTY IMPORTED_LOCATION ${OPENSSL}/libssl.1.0.0.dylib)
set_property(TARGET libcrypto PROPERTY IMPORTED_LOCATION ${OPENSSL}/libcrypto.1.0.0.dylib)
add_dependencies(libssl openssl_project)
add_dependencies(libcrypto openssl_project)
list(APPEND ExternalSharedLibraries ${OPENSSL}/libssl.1.0.0.dylib)
list(APPEND ExternalSharedLibraries ${OPENSSL}/libcrypto.1.0.0.dylib)
list(APPEND RPATH_IMPORTED "${OPENSSL};")
include_directories(${OPENSSL}/include)
