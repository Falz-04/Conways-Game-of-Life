#include "simulation.h"
#include <vector>
#include <utility>
#include <iostream> // For debugging

void Simulation::Draw()
{
    grid.Draw();
}

void Simulation::set_cell_value(int row, int column, int value)
{
    grid.set_value(row, column, value);
}

int Simulation::count_live_neighbours(int row, int column)
{
    int live_neighbours = 0;
    std::vector<std::pair<int, int>> neighbour_offsets = {
        { -1,  0 }, // Directly Above
        {  1,  0 }, // Directly Below
        {  0, -1 }, // Left
        {  0,  1 }, // Right
        { -1, -1 }, // Top Left
        { -1,  1 }, // Top Right
        {  1, -1 }, // Below Left
        {  1,  1 }  // Below Right
    };

    for (const auto& offset : neighbour_offsets) {
        int neighbour_row = (row + offset.first + grid.get_rows()) % grid.get_rows();
        int neighbour_column = (column + offset.second + grid.get_columns()) % grid.get_columns();
        live_neighbours += grid.get_value(neighbour_row, neighbour_column);

        //// Debugging output
        //std::cout << "Checking neighbour at (" << neighbour_row << ", " << neighbour_column << "): ";
        //std::cout << "Value = " << grid.get_value(neighbour_row, neighbour_column) << std::endl;
    }
    return live_neighbours;
}

void Simulation::update()
{
    if (is_running()){
        for (int row = 0; row < grid.get_rows(); row++) {
            for (int column = 0; column < grid.get_columns(); column++) {
                int live_neighbours = count_live_neighbours(row, column);
                int cell_value = grid.get_value(row, column);
            
                if (cell_value == 1) {
                    if (live_neighbours > 3 || live_neighbours < 2) {
                        temp_grid.set_value(row, column, 0);
                    }
                    else {
                        temp_grid.set_value(row, column, 1);
                    }
                }
                else {
                    if (live_neighbours == 3) {
                        temp_grid.set_value(row, column, 1);
                    }
                    else {
                        temp_grid.set_value(row, column, 0);
                    }      
                }
            }
        }
        grid = temp_grid;
    }
}

void Simulation::clear_grid()
{
    if (!is_running()) {
		grid.clear();
	}
}

void Simulation::random_state()
{
    if (!is_running()) {
		grid.fill_random();
	}
}

void Simulation::toggle_cell(int row, int column)
{
    if (!is_running()) {
        grid.toggle_cell(row, column);
    }
}
