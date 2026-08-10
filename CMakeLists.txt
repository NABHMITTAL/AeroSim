cmake_minimum_required(VERSION 4.4)

project(AeroSIM
    VERSION 0.1.0
    DESCRIPTION "Real-time 3D aerodynamic simulation and virtual wind tunnel"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(AeroSIM
    src/main.cpp
    src/core/Application.cpp
    src/core/Application.h
    src/math/vector3.cpp
    src/math/vector3.h
)