//
// Created by petr on 02.05.21.
//

#include "simple_sudoku_serializer.h"
#include <sstream>


Sudoku SimpleSudokuSerializer::deserialize(const std::string& simpleSudoku) {
    Sudoku sudoku;
    Grid grid;
    std::string line;
    std::istringstream sudokuStringStream(simpleSudoku);

    while(std::getline(sudokuStringStream, line)) {
        std::vector<Cell> rowOfCells;
        for (unsigned char c : line) {
            if (c == '.') {
                rowOfCells.push_back(Cell{0, false});
            } else if (isdigit(c)){
                rowOfCells.push_back(Cell{_getNumberFromCharacter(c), true});
            }
        }
        if (not rowOfCells.empty()) {
            grid.push_back(rowOfCells);
        }
    }
    sudoku.grid = grid;
    return sudoku;
}

std::string SimpleSudokuSerializer::serialize(const Sudoku& sudoku) {
    std::string stringRepr;
    Grid grid = sudoku.grid;
    int size = sudoku.getSize();
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            std::string cell = _intToString(grid[row][col].number);
            stringRepr.append(cell);
            if (_isChunkSeparator(col, sudoku)) {
                stringRepr.append("|");
            }
        }
        stringRepr.push_back('\n');
        if (_isChunkSeparator(row, sudoku)) {
            _appendUnderscore(stringRepr, sudoku);
            stringRepr.push_back('\n');
        }
    }
    return stringRepr;
}

int SimpleSudokuSerializer::_getNumberFromCharacter(unsigned char character) {
    return character - '0';
}

bool SimpleSudokuSerializer::_isChunkSeparator(int charIdx, const Sudoku& sudoku) {
    int char_order = charIdx + 1;
    if (char_order == sudoku.getSize()) {
        return false;
    }
    return (char_order % sudoku.getBoxSize() == 0);
}

std::string SimpleSudokuSerializer::_intToString(int c) {
    if (c == 0) {
        return ".";
    } else {
        return std::to_string(c);
    }
}

void SimpleSudokuSerializer::_appendUnderscore(std::string &simpleSudoku, const Sudoku &sudoku) {
    unsigned long charsPerRow = sudoku.getSize() + sudoku.getBoxSize() - 1;
    for (int i = 0; i < charsPerRow; i++) {
        simpleSudoku.append("-");
    }
}
