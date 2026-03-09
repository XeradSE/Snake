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

    Vector2 direction = {0, 0}; // Initialisation par défaut dans aucune direction

    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        
        if (game.getMenu().getMainMenu()) {
            game.getMenu().drawMainMenu();
            if (game.getMenu().handleInput()) {
                game.getMenu().setMainMenu(false);
            }
        } else if (game.getMenu().getGameOver()) {
            game.getMenu().drawGameOver(game.getScore());
            if (game.getMenu().handleInput()) {
                game.reset();
                direction = {0, 0};
                game.getMenu().setGameOver(false);
                game.setIsRunning(true);
            } 
        } else {

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

            game.update(direction);
            game.draw();
        }

        EndDrawing();

    }

    CloseWindow();
    return 0;
}