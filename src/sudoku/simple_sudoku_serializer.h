//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H
#define SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H


#include <string>
#include "sudoku.h"

class SimpleSudokuSerializer {
public:
    [[nodiscard]] static std::string serialize(Sudoku sudoku);

    static Sudoku deserialize(const std::string& simpleSudoku);

private:
    [[nodiscard]] static bool _isChunkSeparator(int charIdx, Sudoku &sudoku);

    static void _appendUnderscore(std::string &simpleSudoku, Sudoku &sudoku);

    static std::string _intToString(int c);
};


#endif //SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H
