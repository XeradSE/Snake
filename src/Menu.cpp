//
// Created by Kylian Betuel on 2/27/26.
//

#include "./../include/Menu.hpp"
#include "./../include/ScoreManager.hpp"
#include "raylib.h"

void Menu::drawMainMenu() {
  int x = MeasureText("Snake", 100);
  DrawText("Snake", 450 - x, 100, 100, DARKGREEN);
  x = MeasureText("Appuie sur Entrée pour jouer", 25);
  DrawText("Appuie sur Entrée pour jouer", 500 - x, 300, 25, DARKGREEN);
}

void Menu::drawGameOver(int score) {
  int x = MeasureText("GAME OVER", 90);
  DrawText("GAME OVER", 575 - x, 100, 90, DARKGREEN);
  x = MeasureText("Score :", 50);
  DrawText(TextFormat("Score : %i", score), 375 - x, 300, 50, DARKGREEN);
  x = MeasureText("High Score : ", 50);
  DrawText(TextFormat("High Score : %i", ScoreManager::loadHighScore()),
           450 - x, 350, 50, DARKGREEN);
  x = MeasureText("Appuie sur Entrée pour rejouer", 25);
  DrawText("Appuie sur Entrée pour rejouer", 500 - x, 400, 25, DARKGREEN);
}

bool Menu::handleInput() {
  if (IsKeyPressed(KEY_ENTER)) {
    return true;
  }
  return false;
}
