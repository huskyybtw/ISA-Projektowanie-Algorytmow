cmake_minimum_required(VERSION 3.27)
project(Projekt2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ISA_Projektowanie_Algorytmow main.cpp
        MovieLoader.h
        MovieLoader.cpp
        algorythms.cpp
        algorythms.h
        tests.cpp
        didntWork.cpp
)
