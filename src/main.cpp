//
// Created by petr on 02.05.21.
//

#include "sudoku/sudoku.h"
#include "sudoku_solver.h"
#include "sudoku/serializer/simple_sudoku_serializer.h"

int main() {
    std::string simpleSudoku = SimpleSudokuSerializer::serialize(Sudoku());
    Sudoku sudoku = SimpleSudokuSerializer::deserialize(simpleSudoku);
    simpleSudoku = SimpleSudokuSerializer::serialize(sudoku);
    //Sudoku sudoku{};

    SudokuSolver solver;
    solver.load("example.ss");
    //sudoku.loads(std::string(matrixSS));
    return 0;
}