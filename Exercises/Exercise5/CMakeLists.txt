cmake_minimum_required(VERSION 3.28)
project(Exercise5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)
add_executable(new_target City.cpp
        City.h
        Individual.cpp
        Individual.h
        Individual.h
        GeneticAlgorithm.cpp
        GeneticAlgorithm.h
        Main.cpp
        Main.h)
