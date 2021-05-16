#include <vector>
#include <fstream>
#include "sudoku.h"
#include "../file_io/file_io.h"
#include "serializer/simple_sudoku_serializer.h"
#include "../utils.h"

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

Location Sudoku::getFirstEmptyLocation() const {
    int row;
    int col;
    for (row = 0; row < _size; row++) {
        for (col = 0; col < _size; col++) {
            if (grid[row][col] == EMPTY) {
                return Location{row, col};
            }
        }
    }
    std::string err = "No empty location found!";
    throw std::out_of_range(err);
}

Location Sudoku::getBoxLocationOfCell(Location cellLocation) {
    Location boxLocation{_getBoxIndexLocationOfCell(cellLocation)};
    Location coords = _getFirstCellCoordinatesOfBox(boxLocation);
    return coords;
}

Location Sudoku::_getBoxIndexLocationOfCell(Location cellLocation) const {
    int boxRowIndex = cellLocation.rowIndex / _boxSize;
    int boxColumnIndex = cellLocation.columnIndex / _boxSize;
    return Location{boxRowIndex, boxColumnIndex};
}

Location Sudoku::_getFirstCellCoordinatesOfBox(Location boxCoordinates) const {
    int rowIndex = boxCoordinates.rowIndex * _boxSize;
    int columnIndex = boxCoordinates.columnIndex * _boxSize;
    return Location{rowIndex, columnIndex};
}

std::string Sudoku::debug_dumps() {
    std::string dump;
    for (auto &row: grid) {
        for (int &number: row) {
            dump.append(std::to_string(number));
        }
        dump.push_back('\n');
    }
    return dump;
}

void Sudoku::_init(int boxSize) {
    _boxSize = boxSize;
    _size = _boxSize * _boxSize;
    Row row_vector(_size, EMPTY);
    grid.assign(_size, row_vector);
}



