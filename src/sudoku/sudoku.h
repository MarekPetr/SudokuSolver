//
// Created by petr on 02.05.21.
//

#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <vector>
#define EMPTY 0

typedef std::vector<int> Row;
typedef std::vector<Row> Grid;

struct Location {
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


    [[nodiscard]] Location getBoxLocationOfCell(Location cellLocation);

    [[nodiscard]] Location getFirstEmptyLocation() const;

private:
    int _size{};
    int _boxSize{};

    void _init(int boxSize);

    [[nodiscard]] Location _getFirstCellCoordinatesOfBox(Location boxCoordinates) const;

    [[nodiscard]] Location _getBoxIndexLocationOfCell(Location cellLocation) const;

};

#endif //SUDOKU_H
