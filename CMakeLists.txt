cmake_minimum_required(VERSION 3.16)
project(cppRecipes)

set(CMAKE_CXX_STANDARD 20)

add_executable(cppRecipes
        factory_autoReg_className.cpp
        loophole.cpp
        meta.cpp
        metaCounter.cpp
        check_type.cpp)