cmake_minimum_required(VERSION 3.12)

project(EpsilonEngine CXX C)

if(WIN32)
	set(PYTHON_EXECUTABLE "python")
else()
	set(PYTHON_EXECUTABLE "python")
endif()

if((NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/deps/.bootstrap.json") OR ("${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt" IS_NEWER_THAN "${CMAKE_CURRENT_SOURCE_DIR}/deps/.bootstrap.json"))
	execute_process(
		COMMAND ${PYTHON_EXECUTABLE} "bootstrap.py"
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
		RESULT_VARIABLE bootstrap_result
	)
	if (NOT (${bootstrap_result} EQUAL 0))
		message(FATAL_ERROR "Cannot run bootstrap.py")
	endif()
endif()

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")

add_subdirectory(deps/src/glfw)

include_directories(.)
include_directories(deps/src)
include_directories(deps/src/glfw/include)
include_directories(deps/src/glm)
include_directories(deps/glad/include)
include_directories(deps/src/ImGuizmo/src)

include_directories(EpsilonCore/src)

add_subdirectory(deps/cmake/ImGuizmo)

#Glad Library
set(GLAD_SOURCES deps/glad/src/gl.c deps/glad/src/vulkan.c)
if(WIN32)
	set(GLAD_SOURCES ${GLAD_SOURCES} deps/glad/src/wgl.c)
	message(STATUS "Using GLAD for WIN32")
endif()

add_library(glad ${GLAD_SOURCES})

#Set Properties
set_property(TARGET glfw          PROPERTY FOLDER "ThirdPartyLibraries")
set_property(TARGET glad          PROPERTY FOLDER "ThirdPartyLibraries")
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(Sandbox)
add_subdirectory(EpsilonCore)
