#pragma once
#include <vector>

class Grid {
public:
    Grid(int width, int height, int cell_size)
        : rows(height / cell_size), columns(width / cell_size), cell_size(cell_size), cells(rows, std::vector<int>(columns, 0))
    {};

    void Draw();
    void set_value(int row, int column, int value);
    int get_value(int row, int column);
    bool is_within_bounds(int row, int column);
    int get_rows() { return rows; }
    int get_columns() { return columns; }
    void fill_random();
    void clear();
    void toggle_cell(int row, int column);

private:
    int rows;
    int columns;
    int cell_size;
    std::vector<std::vector<int>> cells;
};
