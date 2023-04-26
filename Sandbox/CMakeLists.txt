cmake_minimum_required(VERSION 3.12)

project(Sandbox)

include(../CMake/CommonMacros.txt)
include_directories(../deps/src/imgui)
include_directories(../Epsilon/src)
SETUP_APP(Sandbox "")

# Set the include directories for the executable project
target_include_directories(Sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Set the link directories for the executable project
target_link_directories(Sandbox PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Link the executable to the DLL
target_link_libraries(Sandbox glad glfw Epsilon)

add_compile_definitions(EPS_PLATFORM_WINDOWS)