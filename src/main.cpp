//
// Created by petr on 02.05.21.
//

#include "sudoku/sudoku.h"
#include "file_io/file_io.h"
#include "solver/sudoku_solver.h"

void load(Sudoku &sudoku, const char* filename) {
    try {
        sudoku.load(filename);
    }
    catch (const FileIOException& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
}

int main() {
    Sudoku sudoku{};
    load(sudoku, "/home/petr/Dev/SudokuSolver/src/example.ss");
    SudokuSolver solver{};
    bool solved = solver.solve(&sudoku);
    if (solved) {
        std::cout << "SOLVED" << std::endl;
    } else {
        std::cout << "NOT SOLVED" << std::endl;
    }
    std::cout << sudoku.dumps() << std::endl;
    return 0;
}

