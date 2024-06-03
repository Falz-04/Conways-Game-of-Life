#pragma once
#include "grid.h"
#include <raylib.h>

class Simulation {
public:
    Simulation(int width, int height, int cell_size)
        : grid(width, height, cell_size), temp_grid(width, height, cell_size), run(false) {};
    void Draw();
    void set_cell_value(int row, int column, int value);
    int count_live_neighbours(int row, int column);
    void update();
    bool is_running() { return run; }
    void start() { run = true; }
    void stop() { run = false; }
    void clear_grid();
    void random_state();
    void toggle_cell(int row, int column);
private:
    Grid grid;
    Grid temp_grid;
    bool run;
};
