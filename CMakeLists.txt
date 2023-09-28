cmake_minimum_required(VERSION 3.25)
project(Labs)

set(CMAKE_CXX_STANDARD 17)

add_executable(Labs
        main.cpp
        Player.hpp
        Player.cpp
        PlayerController.hpp
        PlayerController.cpp
        )
