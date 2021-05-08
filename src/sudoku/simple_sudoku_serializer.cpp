//
// Created by petr on 02.05.21.
//

#include "simple_sudoku_serializer.h"
#include <sstream>


Sudoku SimpleSudokuSerializer::deserialize(const std::string& simpleSudoku) {
    Sudoku matrix{};
    std::string line;
    std::istringstream iss(simpleSudoku);

    for (int row = 0; std::getline(iss, line); row++) {
        for (int col = 0; col < line.size(); col++) {
            unsigned char c = line[col];
            if (not std::isdigit(c)) {
                continue;
            }
            matrix.content[row][col] = int(c);
        }
    }
    return matrix;
}

std::string SimpleSudokuSerializer::serialize(Sudoku sudoku) {
    std::string stringRepr;
    Content content = sudoku.content;
    for (int row = 0; row < content.size(); row++) {
        unsigned long row_size = content[row].size();
        for (int col = 0; col < row_size; col++) {
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

