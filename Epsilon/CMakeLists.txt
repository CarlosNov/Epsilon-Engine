cmake_minimum_required(VERSION 3.12)

file(GLOB_RECURSE SRC_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.c??)
file(GLOB_RECURSE HEADER_FILES LIST_DIRECTORIES false RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)

add_library(Epsilon SHARED ${SRC_FILES} ${HEADER_FILES})

# Set the include directories for the DLL project
target_include_directories(Epsilon PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} src/*.h)
# Set the library link for the DLL project
target_link_libraries(Epsilon glfw)

# Set the output directory for the DLL
set_target_properties(Epsilon PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib
)



set_target_properties(Epsilon PROPERTIES
    OUTPUT_NAME "Epsilon"
    PREFIX ""
    SUFFIX ".dll"
)

target_precompile_headers(Epsilon PRIVATE src/EpsilonPCHeader.h)

# Folder structure
ASSIGN_SOURCE_GROUP("${SRC_FILES}")
ASSIGN_SOURCE_GROUP("${HEADER_FILES}")

#Compilation definitions
add_compile_definitions(EPS_PLATFORM_WINDOWS)
add_compile_definitions(EPS_BUILD_DLL)
add_compile_definitions(EPS_DEBUG)
