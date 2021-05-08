//
// Created by petr on 02.05.21.
//

#include "sudoku/sudoku.h"
#include "sudoku_solver.h"
#include "sudoku/simple_sudoku_serializer.h"

int main() {
    std::string simpleSudoku = SimpleSudokuSerializer::serialize(Sudoku());
    //Sudoku sudoku{};
    std::cout << simpleSudoku << std::endl;
    //sudoku.loads(std::string(matrixSS));
    return 0;
}