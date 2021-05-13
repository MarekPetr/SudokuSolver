cmake_minimum_required(VERSION 3.19)
project(sudoku)

set(CMAKE_CXX_STANDARD 20)

add_executable(sudoku sudoku/sudoku.cpp sudoku/sudoku.h sudoku/serializer/simple_sudoku_serializer.cpp sudoku/serializer/simple_sudoku_serializer.h solver/sudoku_solver.cpp solver/sudoku_solver.h main.cpp file_io/file_io.cpp file_io/file_io.h utils.h)