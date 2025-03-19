cmake_minimum_required(VERSION 3.5 FATAL_ERROR)
cmake_policy(VERSION 3.5)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set(NAME HEngine)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(${NAME} LANGUAGES CXX)

include_directories(Engine/3rdparty)
include_directories(Engine/3rdparty/glm)
include_directories(Engine/3rdparty/imgui)
include_directories(Engine/3rdparty/tinygltf)
include_directories(Engine/3rdparty/ktx/include)
include_directories(Engine/3rdparty/ktx/other_include)

if (NOT CMAKE_VERSION VERSION_LESS 3.7.0)
	message(STATUS "Using module to find Vulkan")
	find_package(Vulkan)
endif()

IF(UNIX AND NOT APPLE)
	set(LINUX TRUE)
ENDIF()

IF(WIN32)
	IF (NOT Vulkan_FOUND)

		find_library(Vulkan_LIBRARY NAMES vulkan-1 vulkan PATHS ${CMAKE_SOURCE_DIR}/bin/vulkan)
		IF (Vulkan_LIBRARY)
			set(Vulkan_FOUND ON)
			MESSAGE("Using bundled Vulkan library version")
		ENDIF()
	ENDIF()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DVK_USE_PLATFORM_WIN32_KHR")
ENDIF()

IF (NOT Vulkan_FOUND)
    MESSAGE(FATAL_ERROR "Vulkan library not found")
ENDIF()

file(GLOB_RECURSE SOURCE_FILES "Engine/source/**/*.cpp" "Engine/source/*.cpp")

# 设置程序的工作目录
add_executable(${NAME} ${SOURCE_FILES})

# set_target_properties(${NAME} PROPERTIES
# 	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# 	# RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}
# 	# RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_CURRENT_SOURCE_DIR}
# )

target_link_directories(${NAME} PUBLIC ${CMAKE_SOURCE_DIR}/bin/vulkan ${CMAKE_SOURCE_DIR}/bin/glfw) 
target_link_libraries(${NAME} ${Vulkan_LIBRARY} glfw3)