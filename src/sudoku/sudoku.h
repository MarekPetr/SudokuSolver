//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>

struct Cell {
    int number = 0;
    bool isLocked = false;
};

typedef std::vector<std::vector<Cell>> Grid;

struct Coordinates {
    int rowIndex;
    int columnIndex;
};

class Sudoku {
public:
    Grid grid;

    Sudoku();

    explicit Sudoku(int chunkSize);

    [[nodiscard]] int getSize() const;

    [[nodiscard]] int getBoxSize() const;

    void load(const char *filename);

    void loads(const std::string &simpleSudoku);

    void dump(const char *filename);

    std::string dumps();

    std::string debug_dumps();

    [[nodiscard]] Coordinates getBoxCoordinatesOfCell(Coordinates cellCoordinates);

private:
    int _size{};
    int _boxSize{};

    void _init(int boxSize);

    [[nodiscard]] Coordinates _getBoxCoordinatesOfCell(Coordinates cellCoordinates) const;

    [[nodiscard]] Coordinates _getFirstCellCoordinatesOfBox(Coordinates boxCoordinates) const;
};

#endif //SUDOKU_H
