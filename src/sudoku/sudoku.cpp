#include <vector>
#include "sudoku.h"

Sudoku::Sudoku() {
    _init(3);
}

Sudoku::Sudoku(int chunkSize) {
    _init(chunkSize);
}

int Sudoku::getSide() const {
    return int(content.size());
}

int Sudoku::getChunkSide() const {
    return chunkSide;
}

void Sudoku::_init(int chunkSize) {
    chunkSide = chunkSize;
    int side = chunkSide * chunkSide;
    std::vector<int> row_vector(side, 0);
    content.assign(side, row_vector);
}
