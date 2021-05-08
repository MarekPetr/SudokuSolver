cmake_minimum_required(VERSION 3.19)
project(sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku sudoku/sudoku.cpp sudoku/sudoku.h sudoku/simple_sudoku_serializer.cpp sudoku/simple_sudoku_serializer.h sudoku_solver.cpp sudoku_solver.h main.cpp)