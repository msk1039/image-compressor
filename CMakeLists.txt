cmake_minimum_required(VERSION 3.10)
project(image-compression VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


if (NOT EXISTS "${CMAKE_SOURCE_DIR}/submods/stb/stb_image.h" OR NOT EXISTS "${CMAKE_SOURCE_DIR}/submods/stb/stb_image_write.h")
    message(STATUS "stb library not found, checking submods/stb/ directory...")


    if (NOT EXISTS "${CMAKE_SOURCE_DIR}/submods/stb")
        message(STATUS "submods/stb/ directory not found, creating...")
        file(MAKE_DIRECTORY "${CMAKE_SOURCE_DIR}/submods/stb")
    endif()


    message(STATUS "Cloning stb library into submods/stb/...")
    execute_process(
        COMMAND git clone https://github.com/nothings/stb.git "${CMAKE_SOURCE_DIR}/submods/stb"
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/submods"
    )
    set(STB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/submods/stb)
else()
    set(STB_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/submods/stb)
endif()


add_executable(image-compression stdmain.cpp)

target_include_directories(image-compression PRIVATE ${STB_INCLUDE_DIR})



