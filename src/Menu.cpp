//
// Created by Kylian Betuel on 2/27/26.
//

#include "./../include/Menu.hpp"
#include "raylib.h"
#include <charconv>
#include <string>

void Menu::drawMainMenu() {
    int x = MeasureText("Snake", 200);
    DrawText("Snake", 300 - x, 100, 200, DARKGREEN);
    x = MeasureText("Appuie sur Entrée pour jouer", 100);
    DrawText("Appuie sur Entrée pour jouer", 300 - x, 100, 100, DARKGREEN);
}

void Menu::drawGameOver(int score) {
    int x = MeasureText("GAME OVER", 200);
    DrawText("GAME OVER", 300 - x, 100, 200, DARKGREEN);
    const char* score_string = "Score : " + static_cast<char>(score);
    x = MeasureText(score_string, 100);
    DrawText(score_string, 300 - x, 100, 100, DARKGREEN);
    x = MeasureText("Appuie sur Entrée pour rejouer", 100);
    DrawText("Appuie sur Entrée pour rejouer", 300 - x, 100, 100, DARKGREEN);
}

bool Menu::handleInput() {
    if (IsKeyPressed(KEY_ENTER)) {
        return true;
    }
    return false;
}
