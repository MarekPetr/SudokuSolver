//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>

#include <vector>

typedef std::vector<std::vector<int>> Content;

class Sudoku {
public:
    std::vector<std::vector<int>> content;

    Sudoku();

    explicit Sudoku(int chunkSize);

    [[nodiscard]] int getSide() const;

    [[nodiscard]] int getChunkSide() const;

    void load(const char *filename);

    void loads(const std::string &simpleSudoku);

    void dump(const char *filename);

    std::string dumps();

    std::string debug_dumps();

private:
    void _init(int blockSize);

    int _size{};
    int _blockSize{};


};

#endif //SUDOKU_H
