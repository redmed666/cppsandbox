cmake_minimum_required(VERSION 2.8.12)
project(MyApp)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Widgets REQUIRED)
find_package(Doxygen)

if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
add_custom_target(doc
  ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE MyApp_SOURCES "src/*.cpp")
file(GLOB_RECURSE MyApp_HEADERS "src/*.h")

set (MyApp_INCLUDE_DIRS "")
foreach (_headerFile ${MyApp_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND MyApp_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES MyApp_INCLUDE_DIRS)

include_directories("./src")

include_directories(${MyApp_INCLUDE_DIRS})
set (CMAKE_CXX_STANDARD 14)
add_executable (MyApp ${MyApp_SOURCES})
target_compile_features(MyApp PRIVATE cxx_range_for)
target_link_libraries(MyApp ${CONAN_LIBS})

qt5_use_modules(MyApp Widgets)
