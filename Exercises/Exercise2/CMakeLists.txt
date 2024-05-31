cmake_minimum_required(VERSION 3.28)
project(Exercise2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS "-static")

include_directories(.)

add_executable(Exercise2
        Int2.cpp
        Int2.h
        main.cpp
        Int2.cpp
        MinesweeperCell.h
        MinesweeperCell.h
        MinesweeperCell.cpp
        MinesweeperGrid.cpp
        MinesweeperGrid.h)
