//
// Created by petr on 02.05.21.
//

#include "sudoku/sudoku.h"
#include "sudoku/serializer/simple_sudoku_serializer.h"
#include "file_io/file_io.h"

int main() {
    Sudoku sudoku = Sudoku();
    try {
        sudoku.load("/home/petr/Dev/SudokuSolver/src/example.ss");
    }
    catch (const FileIOException& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
    std::cout << sudoku.dumps() << std::endl;
    return 0;
}