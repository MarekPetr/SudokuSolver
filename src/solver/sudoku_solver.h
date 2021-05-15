//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_SUDOKU_SOLVER_H
#define SUDOKU_SUDOKU_SOLVER_H


#include "../sudoku/sudoku.h"

class SudokuSolver {
public:
    explicit SudokuSolver() = default;;

    Sudoku solve(Sudoku &sudoku);

    Sudoku generate();

private:
    Sudoku _sudoku;

    bool _solveUtil(int rowIndex);

    int _getNextSafeNumber(int rowIndex, int columnIndex);

    bool _isPresentInRow(int number, int row);

    bool _isPresentInColumn(int number, int columnIndex);

    bool _isPresentInBox(int number, int rowIndex, int columnIndex);
};


#endif //SUDOKU_SUDOKU_SOLVER_H
