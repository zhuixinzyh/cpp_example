cmake_minimum_required(VERSION 3.0)
project(TEST)

add_definitions(-DDEBUG)

SET(CROSS_COMPILE OFF)

SET(CMAKE_SYSTEM_NAME Linux)

if(CROSS_COMPILE)
    SET(CMAKE_C_COMPILER "/usr/bin/arm-linux-gnueabihf-gcc")
    SET(CMAKE_CXX_COMPILER "/usr/bin/arm-linux-gnueabihf-g++")
else()
    SET(CMAKE_C_COMPOILER "/usr/bin/gcc")
    SET(CMAKE_CXX_COMPILER "/usr/bin/g++")
endif()


set(CMAKE_CXX_STANDARD 11)

set(SRC_LIST main.cpp)
add_executable(main ${SRC_LIST})
