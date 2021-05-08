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
    int chunkSide{};

    Sudoku();

    explicit Sudoku(int chunkSize);

    [[nodiscard]] int getSide() const;

    [[nodiscard]] int getChunkSide() const;

private:
    void _init(int chunkSize);
};

#endif //SUDOKU_H
