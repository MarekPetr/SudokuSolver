//
// Created by petr on 02.05.21.
//

#include <fstream>
#include "sudoku_solver.h"
#include "sudoku/serializer/simple_sudoku_serializer.h"
#include "file_io/file_io.h"

SudokuSolver::SudokuSolver(Sudoku &sudoku) {
    _sudoku = sudoku;
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

void SudokuSolver::load(const char *filename) {
    try {
        std::string sudoku = FileIO::load(filename);
        std::cout << sudoku << std::endl;
    }
    catch (const FileIOException& e) {
        std::cout << "NOTHING BRO" << std::endl;
    }
}



