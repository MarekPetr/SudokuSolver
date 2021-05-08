//
// Created by petr on 02.05.21.
//

#include <fstream>
#include "sudoku_solver.h"
#include "sudoku/simple_sudoku_serializer.h"

SudokuSolver::SudokuSolver() {
    _sudoku = Sudoku();
}

void SudokuSolver::dump(const char *filename) {
    std::ofstream ofs(filename, std::ofstream::out);
    ofs << dumps();
    ofs.close();
}

std::string SudokuSolver::dumps() {
    return SimpleSudokuSerializer::serialize(_sudoku);
}

void SudokuSolver::loads(const std::string &matrixSS) {
    // TODO
}


