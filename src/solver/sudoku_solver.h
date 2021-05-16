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

    int _getNextSafeNumber(Coordinates coords);

    bool _isNumberInRow(int number, int row);

    bool _isNumberInColumn(int number, int columnIndex);

    bool _isNumberInBox(int number, Coordinates coordinates);

    bool _isNumberInRowOrColumn(int number, int index, bool isIndexOfRow);

    bool _isNumberSafe(int number, Coordinates coords);
};


#endif //SUDOKU_SUDOKU_SOLVER_H
