//
// Created by Kylian Betuel on 24/02/2026.
//

#include "raylib.h"

int main()
{
    const int screenWidth = 1280;
    const int screenHeight = 720;
    const int cellSize = 15;
    const int rows = screenHeight/cellSize;
    const int cols = screenWidth/cellSize;

    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Click cells to change color", 10, 10, 20, DARKGRAY);
        DrawText("Press SPACE to pause", 10, 35, 20, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}