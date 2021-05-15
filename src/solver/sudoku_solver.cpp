//
// Created by petr on 02.05.21.
//

#include "sudoku_solver.h"
#include <algorithm>

Sudoku SudokuSolver::solve(Sudoku &sudoku) {
    _sudoku = sudoku;
    bool solved = _solveUtil(0);
    return _sudoku;
}

bool SudokuSolver::_solveUtil(int rowIndex) {
    auto row = _sudoku.content[rowIndex];
    if (rowIndex >= _sudoku.getSize()) {
        return false;
    }
    for (int columnIndex = 0; columnIndex < row.size(); columnIndex++) {
        int number = row[columnIndex];
        if (number != 0) { continue; }
        int safeNumber = _getNextSafeNumber(rowIndex, columnIndex);
        std::cout << safeNumber << " ";
        _sudoku.content[rowIndex][columnIndex] = safeNumber;
    }
    std::cout << std::endl;
    return false;
}

int SudokuSolver::_getNextSafeNumber(int rowIndex, int columnIndex) {
    auto row = _sudoku.content[rowIndex];
    int nextCandidate = row[columnIndex]++;
    for (int candidate = nextCandidate; candidate <= _sudoku.getSize(); candidate++) {
        if (_isPresentInRow(candidate, rowIndex)) { continue; }
        if (_isPresentInColumn(candidate, columnIndex)) { continue; }
        return candidate;
    }
    return 0;
}

bool SudokuSolver::_isPresentInRow(int number, int rowIndex) {
    auto row = _sudoku.content[rowIndex];
    bool isPresent = std::find(row.begin(), row.end(), number) != row.end();
    return isPresent;
}

bool SudokuSolver::_isPresentInColumn(int number, int columnIndex) {
    for (int rowIndex = 0; rowIndex < _sudoku.getSize(); rowIndex++) {
        int currentNumber = _sudoku.content[rowIndex][columnIndex];
        if (number == currentNumber) {
            return true;
        }
    }
    return false;
}

bool SudokuSolver::_isPresentInBox(int number, int rowIndex, int columnIndex) {
    int boxSize = _sudoku.getBoxSize();
    // TODO implement
    return false;
}

