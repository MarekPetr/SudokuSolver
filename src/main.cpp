//
// Created by petr on 02.05.21.
//

#include "sudoku/sudoku.h"
#include "serializer/simple_sudoku_serializer.h"

int main() {
    Sudoku sudoku = Sudoku();
    sudoku.load("/home/petr/Dev/SudokuSolver/src/example.ss");
    std::string dumps = SimpleSudokuSerializer::serialize(sudoku);
    std::cout << "sudoku:\n" << dumps << std::endl;
    return 0;
}