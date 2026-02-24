//
// Created by Kylian Betuel on 24/02/2026.
//

#include "./../include/Snake.hpp"

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 600;

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