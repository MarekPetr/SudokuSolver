//
// Created by petr on 02.05.21.
//

#include "sudoku_solver.h"

bool SudokuSolver::solve(Sudoku *sudoku) {
    _sudoku = sudoku;
    Location location{};
    try {
        location = _sudoku->getFirstEmptyLocation();
    } catch (std::out_of_range &err) {
        return true;
    }
    for (int number = 1; number <= 9; number++) {
        if (not _isNumberSafe(number, location)) {
            continue;
        }
        int *currentNumber = &_sudoku->grid[location.rowIndex][location.columnIndex];
        *currentNumber = number;
        if (solve(_sudoku)) {
            return true;
        }
        *currentNumber = EMPTY;
    }
    return false;
}

Sudoku SudokuSolver::generate() {
    Sudoku sudoku = Sudoku{};
    solve(&sudoku);
    return sudoku;
}

bool SudokuSolver::_isNumberSafe(int number, Location coords) {
    if (_isNumberInRow(number, coords.rowIndex) ||
        _isNumberInColumn(number, coords.columnIndex) ||
        _isNumberInBox(number, coords)) {
        return false;
    }
    return true;
}

bool SudokuSolver::_isNumberInRow(int number, int rowIndex) {
    return _isNumberInRowOrColumn(number, rowIndex, true);
}

bool SudokuSolver::_isNumberInColumn(int number, int columnIndex) {
    return _isNumberInRowOrColumn(number, columnIndex, false);
}

bool SudokuSolver::_isNumberInRowOrColumn(int number, int index, bool isIndexOfRow) {
    for (int i = 0; i < _sudoku->getSize(); i++) {
        int currentNumber;
        if (isIndexOfRow) {
            currentNumber = _sudoku->grid[index][i];
        } else {
            currentNumber = _sudoku->grid[i][index];
        }
        if (number == currentNumber) {
            return true;
        }
    }
    return false;
}

bool SudokuSolver::_isNumberInBox(int number, Location coordinates) {
    Location firstCoordsOfBox = _sudoku->getBoxLocationOfCell(coordinates);
    int lastBoxRow = firstCoordsOfBox.rowIndex + _sudoku->getBoxSize();
    int lastBoxColumn = firstCoordsOfBox.columnIndex + _sudoku->getBoxSize();

    for (int rowIdx = firstCoordsOfBox.rowIndex; rowIdx < lastBoxRow; rowIdx++) {
        for (int colIdx = firstCoordsOfBox.columnIndex; colIdx < lastBoxColumn; colIdx++) {
            int currentNumber = _sudoku->grid[rowIdx][colIdx];
            if (currentNumber == number) {
                return true;
            }
        }
    }
    return false;
}

