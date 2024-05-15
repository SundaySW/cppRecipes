cmake_minimum_required(VERSION 3.16)
project(cppRecipes)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS_DEBUG     "-O0 -g3"   CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3"   CACHE STRING "" FORCE)
set(CMAKE_C_FLAGS_RELEASE   "-Os -g0"   CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-Os -g0"   CACHE STRING "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS             ON)

add_executable(cppRecipes
        factory_autoReg_className.cpp
        loophole.cpp
        meta.cpp
        metaCounter.cpp
        strange.cpp
)