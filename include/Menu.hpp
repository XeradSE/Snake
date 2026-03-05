//
// Created by Betuel Kylian on 2/27/26.
//

#pragma once

class Menu {

    bool MAIN_MENU = true;
    bool GAME_OVER = false;

public:

    void drawMainMenu();
    void drawGameOver(int score);
    bool handleInput();

    bool getMainMenu() {return MAIN_MENU;};
    bool getGameOver() {return GAME_OVER;};

    void setMainMenu(bool mm) {MAIN_MENU = mm;};
    void setGameOver(bool go) {GAME_OVER = go;};

};
