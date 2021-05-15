#include <vector>
#include <fstream>
#include "sudoku.h"
#include "../file_io/file_io.h"
#include "serializer/simple_sudoku_serializer.h"

Sudoku::Sudoku() {
    _init(3);
}

Sudoku::Sudoku(int chunkSize) {
    _init(chunkSize);
}

int Sudoku::getSize() const {
    return _size;
}

int Sudoku::getBoxSize() const {
    return _boxSize;
}

void Sudoku::_init(int blockSize) {
    _boxSize = blockSize;
    _size = _boxSize * _boxSize;
    std::vector<int> row_vector(_size, 0);
    content.assign(_size, row_vector);
}

std::string Sudoku::debug_dumps() {
    std::string dump;
    for (auto& row: content) {
        for (auto& item: row) {
            dump.append(std::to_string(item));
        }
        dump.push_back('\n');
    }
    return dump;
}

void Sudoku::dump(const char *filename) {
    std::ofstream ofs(filename, std::ofstream::out);
    ofs << dumps();
    ofs.close();
}

std::string Sudoku::dumps() {
    return SimpleSudokuSerializer::serialize(*this);
}

void Sudoku::load(const char *filename) {
    std::string simpleSudoku = FileIO::load(filename);
    loads(simpleSudoku);
}

void Sudoku::loads(const std::string &simpleSudoku) {
    *this = SimpleSudokuSerializer::deserialize(simpleSudoku);
}