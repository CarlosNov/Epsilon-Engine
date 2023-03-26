cmake_minimum_required(VERSION 3.12)

file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c??)
file(GLOB_RECURSE HEADER_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

add_library(EpsilonCore SHARED ${SRC_FILES} ${HEADER_FILES})

# Set the include directories for the DLL project
target_include_directories(EpsilonCore PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

# Set the output directory for the DLL
set_target_properties(EpsilonCore PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)

set_target_properties(EpsilonCore PROPERTIES
    OUTPUT_NAME "EpsilonCore"
    PREFIX ""
    SUFFIX ".dll"
)