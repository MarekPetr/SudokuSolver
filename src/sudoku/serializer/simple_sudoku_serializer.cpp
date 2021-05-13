//
// Created by petr on 02.05.21.
//

#include "simple_sudoku_serializer.h"
#include <sstream>


Sudoku SimpleSudokuSerializer::deserialize(const std::string& simpleSudoku) {
    Sudoku sudoku;
    Content content;
    std::string line;
    std::istringstream iss(simpleSudoku);

    while(std::getline(iss, line)) {
        std::vector<int> row_numbers;
        for (unsigned char c : line) {
            if (c == '.') {
                row_numbers.push_back(0);
            } else if (isdigit(c)){
                row_numbers.push_back(c - '0');
            }
        }
        if (not row_numbers.empty()) {
            content.push_back(row_numbers);
        }
    }
    sudoku.content = content;
    return sudoku;
}

std::string SimpleSudokuSerializer::serialize(Sudoku &sudoku) {
    std::string stringRepr;
    Content content = sudoku.content;
    int side = sudoku.getSide();
    for (int row = 0; row < side; row++) {
        for (int col = 0; col < side; col++) {
            std::string cell = _intToString(content[row][col]);
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

bool SimpleSudokuSerializer::_isChunkSeparator(int charIdx, Sudoku &sudoku) {
    int char_order = charIdx + 1;
    if (char_order == sudoku.getSide()) {
        return false;
    }
    return (char_order % sudoku.getChunkSide() == 0);
}

std::string SimpleSudokuSerializer::_intToString(int c) {
    if (c == 0) {
        return ".";
    } else {
        return std::to_string(c);
    }
}

void SimpleSudokuSerializer::_appendUnderscore(std::string &simpleSudoku, Sudoku &sudoku) {
    unsigned long charsPerRow = sudoku.getSide() + sudoku.getChunkSide() - 1;
    for (int i = 0; i < charsPerRow; i++) {
        simpleSudoku.append("-");
    }
}

