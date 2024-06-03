#include "grid.h"
#include <raylib.h>

void Grid::Draw()
{
    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            Color colour = cells[row][column] ? Color{ 0, 255, 0, 255 } : Color{ 55, 55, 55, 255 };
            DrawRectangle(column * cell_size, row * cell_size, cell_size - 1, cell_size - 1, colour);
        }
    }
}

void Grid::set_value(int row, int column, int value)
{
    if (is_within_bounds(row, column)) {
        cells[row][column] = value;
    }
}

int Grid::get_value(int row, int column)
{
    if (is_within_bounds(row, column)) {
        return cells[row][column];
    }
    return 0;
}

bool Grid::is_within_bounds(int row, int column)
{
    return row >= 0 && row < rows && column >= 0 && column < columns;
}

void Grid::fill_random()
{
    for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
            cells[row][column] = (GetRandomValue(0, 4) == 4) ? 1 : 0;
		}
	}
}

void Grid::clear()
{
    for (int row = 0; row < rows; row++) {
		for (int column = 0; column < columns; column++) {
			cells[row][column] = 0;
		}
	}
}

void Grid::toggle_cell(int row, int column)
{
    if (is_within_bounds(row, column)) {
        cells[row][column] = !cells[row][column];
    }
}
