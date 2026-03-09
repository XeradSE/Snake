//
// Created by Kylian Betuel on 2/27/26.
//

#include "./../include/Menu.hpp"
#include "raylib.h"

void Menu::drawMainMenu() {
    int x = MeasureText("Snake", 100);
    DrawText("Snake", 500 - x, 100, 100, DARKGREEN);        
    x = MeasureText("Appuie sur Entrée pour jouer", 25);
    DrawText("Appuie sur Entrée pour jouer", 600 - x, 300, 25, DARKGREEN);
}

void Menu::drawGameOver(int score) {
    int x = MeasureText("GAME OVER", 90);
    DrawText("GAME OVER", 600 - x, 100, 90, DARKGREEN);
    x = MeasureText("Score :", 50);
    DrawText(TextFormat("Score : %i", score), 300 - x, 300, 50, DARKGREEN);
    x = MeasureText("Appuie sur Entrée pour rejouer", 25);
    DrawText("Appuie sur Entrée pour rejouer", 600 - x, 400, 25, DARKGREEN);
}

bool Menu::handleInput() {
    if (IsKeyPressed(KEY_ENTER)) {
        return true;
    }
    return false;
}
