// CONWAYS GAME OF LIFE
// RULES:
/*
	1 Any live cell with fewer than two live neighbours dies, as if by underpopulation.
	2 Any live cell with two or three live neighbours lives on to the next generation.
	3 Any live cell with more than three live neighbours dies, as if by overpopulation.
	4 Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

*/


// DEVELOPMENT PROCESS
/*
	1 Create Blank Screen and Simulatiuon Loop
	2 Create Grid
	3 Count the live neighbours
	4 Implement the simulation rules
	5 Start and Stop simulation
	6 Create a customised initial state
*/


#include <iostream>
#include <vector>
#include <raylib.h>
#include "simulation.h"

int main() {
    // Simulation Setup
    const int screenWidth = 1000;
    const int screenHeight = 1000;
    const int CellSize = 10;
    int fps = 12;
    Color GREY = { 29, 29, 29, 29 };

    InitWindow(screenWidth, screenHeight, "Conways Game of Life");
    SetTargetFPS(fps); // Simulation Loop will cap out at fps times per second

    Simulation simulation(screenWidth, screenHeight, CellSize);


    // Simulation Loop
    while (!WindowShouldClose()) {
        // EVENT HANDLING 
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            Vector2 mouse_pos = GetMousePosition();
            int row = mouse_pos.y / CellSize;
            int column = mouse_pos.x / CellSize;
            simulation.toggle_cell(row, column);
        }


        if (IsKeyPressed(KEY_ENTER)) {
            simulation.start();
            SetWindowTitle("Conways Game of Life - Running");
        }
        else if (IsKeyPressed(KEY_SPACE)) {
			simulation.stop();
			SetWindowTitle("Conways Game of Life - Paused");
		}
        else if (IsKeyPressed(KEY_F)) {
            fps += 2;
            SetTargetFPS(fps);
        }
        else if (IsKeyPressed(KEY_S)) {
            if (fps > 5) {
                fps -= 2;
                SetTargetFPS(fps);
            }
        }
        else if (IsKeyPressed(KEY_C)) {
            simulation.clear_grid();
        }
        else if (IsKeyPressed(KEY_R)) {
            simulation.random_state();
        }

        // UPDATING STATE
        simulation.update();

        // DRAWING OBJECTS
        BeginDrawing();
        ClearBackground(GREY);
        simulation.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

