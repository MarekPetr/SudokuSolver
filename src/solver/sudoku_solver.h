//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_SUDOKU_SOLVER_H
#define SUDOKU_SUDOKU_SOLVER_H


#include "../sudoku/sudoku.h"

class SudokuSolver {
public:
    explicit SudokuSolver(Sudoku &sudoku);

    Sudoku solve();

    Sudoku generate();

    void load(const char *filename);

    void loads(const std::string& matrixSS);

    void dump(const char *filename);

    std::string dumps();

private:
    Sudoku _sudoku;
};


#endif //SUDOKU_SUDOKU_SOLVER_H
