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
    src/core/logger.h
    src/core/logger.cpp
    src/core/Configuration.cpp
    src/core/Configuration.h
    src/core/Event.cpp
    src/core/Event.h
    src/core/EventDispatcher.h
    src/core/EventDispatcher.cpp
    
    src/math/vector3.cpp
    src/math/vector3.h
    src/math/matrix3.cpp
    src/math/matrix3.h
    src/math/vector2.cpp
    src/math/vector2.h
    src/math/matrix2.cpp
    src/math/matrix2.h
    src/math/eularAngles.cpp
    src/math/eularAngles.h
    src/math/quaternion.cpp
    src/math/quaternion.h
    src/math/transforms.cpp
    src/math/transforms.h
    src/math/numerical.cpp
    src/math/numerical.h
)