//
// Created by Kylian Betuel on 24/02/2026.
//

#include "./../include/Game.hpp"

int main()
{
    const int screenWidth = 600;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Snake");

    SetTargetFPS(60);

    Game game;

    Vector2 direction;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_RIGHT)) {
            direction = {1, 0};
        }

        if (IsKeyPressed(KEY_LEFT)) {
            direction = {-1, 0};
        }

        if (IsKeyPressed(KEY_UP)) {
            direction = {0, -1};
        }

        if (IsKeyPressed(KEY_DOWN)) {
            direction = {0, 1};
        }

        game.draw();
        game.update(direction);
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();

    }

    CloseWindow();
    return 0;
}