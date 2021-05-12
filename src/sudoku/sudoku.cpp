#include <vector>
#include <fstream>
#include "sudoku.h"
#include "../file_io/file_io.h"
#include "../serializer/simple_sudoku_serializer.h"

Sudoku::Sudoku() {
    _init(3);
}

Sudoku::Sudoku(int chunkSize) {
    _init(chunkSize);
}

int Sudoku::getSide() const {
    return side;
}

int Sudoku::getChunkSide() const {
    return chunkSide;
}

void Sudoku::_init(int chunkSize) {
    chunkSide = chunkSize;
    side = chunkSide * chunkSide;
    std::vector<int> row_vector(side, 0);
    content.assign(side, row_vector);
}

void Sudoku::dump(const char *filename) {
    std::ofstream ofs(filename, std::ofstream::out);
    ofs << dumps();
    ofs.close();
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

std::string Sudoku::dumps() {
    return SimpleSudokuSerializer::serialize(*this);
}

void Sudoku::loads(const std::string &simpleSudoku) {
    // TODO
}

void Sudoku::load(const char *filename) {
    try {
        std::string simple_sudoku = FileIO::load(filename);
        *this = SimpleSudokuSerializer::deserialize(simple_sudoku);
    }
    catch (const FileIOException& e) {
        std::cout << "NOTHING BRO" << std::endl;
    }
}