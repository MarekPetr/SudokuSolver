//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_SUDOKU_SOLVER_H
#define SUDOKU_SUDOKU_SOLVER_H


#include "../sudoku/sudoku.h"

class SudokuSolver {
public:
    explicit SudokuSolver() = default;;

    bool solve(Sudoku *sudoku);

    Sudoku generate();

private:
    Sudoku *_sudoku;

    bool _isNumberInRow(int number, int row);

    bool _isNumberInColumn(int number, int columnIndex);

    bool _isNumberInBox(int number, Location coordinates);

    bool _isNumberInRowOrColumn(int number, int index, bool isIndexOfRow);

    bool _isNumberSafe(int number, Location coords);
};

class UnsolvableException : std::exception {
public:
    explicit
    UnsolvableException(const std::string &msg) {
        message = msg;
    }

    ~UnsolvableException() override = default;

    [[nodiscard]] const char *what() const noexcept override {
        return this->message.c_str();
    }

private:
    std::string message;
};
#endif //SUDOKU_SUDOKU_SOLVER_H