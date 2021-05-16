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

Coordinates Sudoku::getBoxCoordinatesOfCell(Coordinates cellCoordinates) {
    Coordinates boxCoords = _getBoxCoordinatesOfCell(cellCoordinates);
    Coordinates coords = _getFirstCellCoordinatesOfBox(boxCoords);
    return coords;
}

Coordinates Sudoku::_getBoxCoordinatesOfCell(Coordinates cellCoordinates) const {
    int boxRowIndex = cellCoordinates.rowIndex / _boxSize;
    int boxColumnIndex = cellCoordinates.columnIndex / _boxSize;
    return Coordinates{boxRowIndex, boxColumnIndex};
}

Coordinates Sudoku::_getFirstCellCoordinatesOfBox(Coordinates boxCoordinates) const {
    int rowIndex = boxCoordinates.rowIndex * _boxSize;
    int columnIndex = boxCoordinates.columnIndex * _boxSize;
    return Coordinates{rowIndex, columnIndex};
}

std::string Sudoku::debug_dumps() {
    std::string dump;
    for (auto &row: grid) {
        for (Cell &cell: row) {
            dump.append(std::to_string(cell.number));
        }
        dump.push_back('\n');
    }
    return dump;
}

void Sudoku::_init(int boxSize) {
    _boxSize = boxSize;
    _size = _boxSize * _boxSize;
    std::vector<Cell> row_vector(_size, Cell{0, false});
    grid.assign(_size, row_vector);
}



