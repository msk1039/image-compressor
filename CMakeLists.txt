cmake_minimum_required(VERSION 3.10)
project(imgcompress VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Check if stb library is present in submods/stb/
if (NOT EXISTS "${CMAKE_SOURCE_DIR}/submods/stb/stb_image.h" OR NOT EXISTS "${CMAKE_SOURCE_DIR}/submods/stb/stb_image_write.h")
    message(STATUS "stb library not found, downloading...")
    include(FetchContent)
    FetchContent_Declare(
        stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
        GIT_TAG        master
    )
    FetchContent_MakeAvailable(stb)
    set(STB_INCLUDE_DIR ${stb_SOURCE_DIR})
else()
    set(STB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/submods/stb)
endif()

# Add the executable
add_executable(imgcompress stdmain.cpp)

# Include directories for stb_image and stb_image_write
target_include_directories(imgcompress PRIVATE ${STB_INCLUDE_DIR})



