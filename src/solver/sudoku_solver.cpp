//
// Created by petr on 02.05.21.
//

#include "sudoku_solver.h"

#include <utility>

Sudoku SudokuSolver::solve(Sudoku &sudoku) {
    _sudoku = sudoku;
    bool solved = _solveUtil(0);
    return _sudoku;
}

bool SudokuSolver::_solveUtil(int rowIndex) {
    auto row = _sudoku.grid[rowIndex];
    if (rowIndex >= _sudoku.getSize()) {
        return false;
    }
    for (int columnIndex = 0; columnIndex < row.size(); columnIndex++) {
        Cell cell = row[columnIndex];
        if (cell.isLocked) { continue; }
        if (cell.number != 0) { continue; }
        int safeNumber = _getNextSafeNumber(Coordinates{rowIndex, columnIndex});
        _sudoku.grid[rowIndex][columnIndex].number = safeNumber;
    }
    std::cout << std::endl;
    return false;
}

int SudokuSolver::_getNextSafeNumber(Coordinates coords) {
    int rowIndex = coords.rowIndex;
    int columnIndex = coords.columnIndex;
    auto row = _sudoku.grid[rowIndex];
    int nextNumber = row[columnIndex].number++;
    for (int number = nextNumber; number <= _sudoku.getSize(); number++) {
        if (_isNumberSafe(number, coords)) {
            return number;
        }
    }
    return 0;
}

bool SudokuSolver::_isNumberSafe(int number, Coordinates coords) {
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
    for (int i = 0; i < _sudoku.getSize(); i++) {
        int currentNumber;
        if (isIndexOfRow) {
            currentNumber = _sudoku.grid[index][i].number;
        } else {
            currentNumber = _sudoku.grid[i][index].number;
        }
        if (number == currentNumber) {
            return true;
        }
    }
    return false;
}

bool SudokuSolver::_isNumberInBox(int number, Coordinates coordinates) {
    Coordinates firstCoordsOfBox = _sudoku.getBoxCoordinatesOfCell(coordinates);
    int lastBoxRow = firstCoordsOfBox.rowIndex + _sudoku.getBoxSize();
    int lastBoxColumn = firstCoordsOfBox.columnIndex + _sudoku.getBoxSize();

    for (int rowIdx = firstCoordsOfBox.rowIndex; rowIdx < lastBoxRow; rowIdx++) {
        for (int colIdx = firstCoordsOfBox.columnIndex; colIdx < lastBoxColumn; colIdx++) {
            int currentNumber = _sudoku.grid[rowIdx][colIdx].number;
            if (currentNumber == number) {
                return true;
            }
        }
    }
    return false;
}

