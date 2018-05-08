cmake_minimum_required(VERSION 2.6)
project(leptDB CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif ()

set(CXX_FLAGS
        -g
        -Wall
        -Wextra
        -Werror
        -Wconversion
        -Wshadow
        )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin) # PROJECT_BINARY_DIR 为build cmake时的目录
#set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

include_directories(${PROJECT_SOURCE_DIR}) # 设置头文件的根搜索目录为当前目录

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE) # BUILD_TYPE = TOUPPER(CMAKE_BUILD_TYPE)
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}") # CXX_FLAGS是以；为分隔符的。
message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

add_subdirectory(algorithm)
add_subdirectory(cpp)