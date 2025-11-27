cmake_minimum_required(VERSION 3.16)
project(NinetyNinePoints)

if(NOT CMAKE_BUILD_TYPE)
	set(default_build_type "Debug")
	message(STATUS "Set the build type to `${default_build_type}` as none was specified.")
	set(CMAKE_BUILD_TYPE ${default_build_type} CACHE STRING "Chooce the build type." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
	"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()
message(STATUS "${PROJECT_NAME} Build Type: ${CMAKE_BUILD_TYPE}")

# Set the version for NinetyNinePoints
set(NinetyNinePoints_Version_Major 0)
set(NinetyNinePoints_Version_Minor 1)
set(NinetyNinePoints_Version_Patch 0)
set(NinetyNinePoints_Version_Status "-dev")
set(PROJECT_VERSION
	"${NinetyNinePoints_Version_Major}.${NinetyNinePoints_Version_Minor}.${NinetyNinePoints_Version_Patch}${NinetyNinePoints_Version_Status}"
)
message(STATUS "${PROJECT_NAME} version: ${PROJECT_VERSION}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_STANDARD 11)
message(STATUS "${PROJECT_NAME} C standard: ${CMAKE_C_STANDARD}")

add_subdirectory(./submodules/)

include_directories(./src/)
add_subdirectory(./src)

enable_testing()
add_subdirectory(./tests/)
