//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H
#define SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H


#include <string>
#include "../sudoku.h"

class SimpleSudokuSerializer {
public:
    [[nodiscard]] static std::string serialize(const Sudoku& sudoku);

    static Sudoku deserialize(const std::string& simpleSudoku);

private:
    [[nodiscard]] static bool _isChunkSeparator(int charIdx, const Sudoku& sudoku);

    static void _appendUnderscore(std::string &simpleSudoku, const Sudoku &sudoku);

    static std::string _intToString(int c);

    static int _getNumberFromCharacter(unsigned char character);
};


#endif //SUDOKU_SIMPLE_SUDOKU_SERIALIZER_H
